/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "engines/stark/ui/menu/saveloadmenu.h"
#include "engines/stark/services/services.h"
#include "engines/stark/services/userinterface.h"
#include "engines/stark/services/stateprovider.h"
#include "engines/stark/services/global.h"
#include "engines/stark/services/settings.h"

#include "engines/stark/gfx/driver.h"
#include "engines/stark/gfx/texture.h"
#include "engines/stark/gfx/surfacerenderer.h"

#include "engines/stark/stark.h"
#include "engines/stark/savemetadata.h"

#include "engines/engine.h"

#include "common/config-manager.h"
#include "common/savefile.h"

#include "gui/message.h"

namespace Stark {

SaveLoadMenuScreen::SaveLoadMenuScreen(Gfx::Driver *gfx, Cursor *cursor, Screen::Name screenName) :
		StaticLocationScreen(gfx, cursor, "LoadSaveLocation", screenName) {
}

SaveLoadMenuScreen::~SaveLoadMenuScreen() {
}

void SaveLoadMenuScreen::open() {
	StaticLocationScreen::open();

	_page = StarkSettings->getIntSetting(Settings::kSaveLoadPage);

	_widgets.push_back(new StaticLocationWidget(
			"loadsavebg",
			nullptr,
			nullptr));
	
	_widgets.push_back(new StaticLocationWidget(
			"back to index",
			CLICK_HANDLER(SaveLoadMenuScreen, backHandler),
			nullptr));
	_widgets.back()->setupSounds(0, 1);
	
	_widgets.push_back(new StaticLocationWidget(
			"Cancel",
			CLICK_HANDLER(SaveLoadMenuScreen, backHandler),
			nullptr));
	_widgets.back()->setupSounds(0, 1);
	
	_widgets.push_back(new StaticLocationWidget(
			"SaveText",
			nullptr,
			nullptr));
	
	_widgets.push_back(new StaticLocationWidget(
			"LoadText",
			nullptr,
			nullptr));
	
	_widgets.push_back(new StaticLocationWidget(
			"Back",
			CLICK_HANDLER(SaveLoadMenuScreen, prevPageHandler),
			nullptr));
	_widgets.back()->setupSounds(0, 1);
	_widgets.back()->setTextColor(_textColorBlack);
	_widgets.back()->setVisible(_page > 0);
	
	_widgets.push_back(new StaticLocationWidget(
			"Next",
			CLICK_HANDLER(SaveLoadMenuScreen, nextPageHandler),
			nullptr));
	_widgets.back()->setupSounds(0, 1);
	_widgets.back()->setTextColor(_textColorBlack);
	_widgets.back()->setVisible(_page < 10);

	loadSaveData(_page);
}

void SaveLoadMenuScreen::close() {
	ConfMan.flushToDisk();
	StaticLocationScreen::close();
}

void SaveLoadMenuScreen::backHandler() {
	StarkUserInterface->backPrevScreen();
}

void SaveLoadMenuScreen::checkError(Common::Error error) {
	if (error.getCode() != Common::kNoError) {
		GUI::MessageDialog dialog(error.getDesc());
		dialog.runModal();
	}
}

void SaveLoadMenuScreen::removeSaveDataWidgets() {
	assert(_widgets.size() == 16);

	for (int i = 0; i < 9; ++i) {
		delete _widgets.back();
		_widgets.pop_back();
	}
}

void SaveLoadMenuScreen::loadSaveData(int page) {
	for (int i = 0; i < 9; ++i) {
		_widgets.push_back(new SaveDataWidget(i + page * 9, _gfx, this));
	}
}

void SaveLoadMenuScreen::changePage(int page) {
	assert(page >= 0 && page <= 10);

	removeSaveDataWidgets();
	loadSaveData(page);

	_widgets[kWidgetBack]->setVisible(page > 0);
	_widgets[kWidgetNext]->setVisible(page < 10);

	StarkSettings->setIntSetting(Settings::kSaveLoadPage, page);
	_page = page;
}

void SaveMenuScreen::open() {
	SaveLoadMenuScreen::open();
	_widgets[kWidgetLoadText]->setVisible(false);
}

void SaveMenuScreen::onSlotSelected(int slot) {
	int chapter = StarkGlobal->getCurrentChapter() / 10;

	Common::String desc;
	if (chapter == 0) {
		desc = "Prologue";
	} else {
		desc = Common::String::format("Chapter %d", chapter);
	}

	g_engine->saveGameState(slot, desc);
	StarkUserInterface->backPrevScreen();
}

void LoadMenuScreen::open() {
	SaveLoadMenuScreen::open();
	_widgets[kWidgetSaveText]->setVisible(false);
}

void LoadMenuScreen::onSlotSelected(int slot) {
	g_engine->loadGameState(slot);
}

SaveDataWidget::SaveDataWidget(int slot, Gfx::Driver *gfx, SaveLoadMenuScreen *screen) :
		StaticLocationWidget(nullptr, nullptr, nullptr),
		_slot(slot),
		_screen(screen),
		_thumbWidth(StarkUserInterface->kThumbnailWidth),
		_thumbHeight(StarkUserInterface->kThumbnailHeight),
		_texture(gfx->createTexture()),
		_outline(gfx->createTexture()),
		_surfaceRenderer(gfx->createSurfaceRenderer()),
		_textDesc(gfx),
		_textTime(gfx),
		_isMouseHovered(false) {
	// Load the corresponding save slot data
	Common::String filename = StarkEngine::formatSaveName(ConfMan.getActiveDomainName().c_str(), _slot);
	Common::InSaveFile *save = g_system->getSavefileManager()->openForLoading(filename);
	if (save) {
		SaveMetadata metadata;
		StateReadStream stream(save);
		Common::ErrorCode metadataErrorCode = metadata.read(&stream, filename);
		if (metadataErrorCode != Common::kNoError) {
			error("Unable to read save metadata with error code %d.", metadataErrorCode);
		}

		// Obtain the thumbnail
		Graphics::Surface *thumb = metadata.readGameScreenThumbnail(&stream);
		_texture->update(thumb);
		thumb->free();
		delete thumb;

		// Obtain the text
		_textDesc.setText(metadata.description);
		_textDesc.setColor(_textColor);
		_textDesc.setFont(FontProvider::kCustomFont, 3);

		_textTime.setText(Common::String::format("%02d:%02d:%02d %02d/%02d/%02d",
				metadata.saveHour, metadata.saveMinute, metadata.saveSecond,
				metadata.saveMonth, metadata.saveDay, metadata.saveYear % 100));
		_textTime.setColor(_textColor);
		_textTime.setFont(FontProvider::kCustomFont, 3);
	} else {
		setVisible(_screen->isSaveMenu());
	}


	// Create the outline texture
	Graphics::Surface lineSurface;
	lineSurface.create(_thumbWidth, _thumbHeight, Gfx::Driver::getRGBAPixelFormat());
	lineSurface.drawThickLine(0, 0, _thumbWidth - 1, 0, 2, 2, _outlineColor);
	lineSurface.drawThickLine(0, 0, 0, _thumbHeight - 1, 2, 2, _outlineColor);
	lineSurface.drawThickLine(_thumbWidth - 2, 0, _thumbWidth - 2, _thumbHeight - 2, 2, 2, _outlineColor);
	lineSurface.drawThickLine(0, _thumbHeight - 2, _thumbWidth - 2, _thumbHeight - 2, 2, 2, _outlineColor);

	_outline->update(&lineSurface);

	// Set the position
	_thumbPos.x = 41 + (_slot % 3) * (_thumbWidth + 39);
	_thumbPos.y = 61 + (_slot % 9 / 3) * (_thumbHeight + 38);

	_textDescPos.x = _thumbPos.x;
	_textDescPos.y = _thumbPos.y + _thumbHeight + 2;

	_textTimePos.x = _thumbPos.x;
	_textTimePos.y = _textDescPos.y + 12;
}

SaveDataWidget::~SaveDataWidget() {
	delete _texture;
	delete _outline;
	delete _surfaceRenderer;
}

void SaveDataWidget::render() {
	_surfaceRenderer->render(_texture, _thumbPos);
	_textDesc.render(_textDescPos);
	_textTime.render(_textTimePos);
	if (_isMouseHovered) {
		_surfaceRenderer->render(_outline, _thumbPos);
	}
}

bool SaveDataWidget::isMouseInside(const Common::Point &mousePos) const {
	return mousePos.x >= _thumbPos.x && mousePos.x <= _thumbPos.x + _thumbWidth &&
		   mousePos.y >= _thumbPos.y && mousePos.y <= _thumbPos.y + _thumbHeight;
}

void SaveDataWidget::onClick() {
	StaticLocationWidget::onClick();
	_screen->onSlotSelected(_slot);
}

void SaveDataWidget::onMouseMove(const Common::Point &mousePos) {
	StaticLocationWidget::onMouseMove(mousePos);
	_isMouseHovered = isMouseInside(mousePos);
}

void SaveDataWidget::resetTextTexture() {
	StaticLocationWidget::resetTextTexture();
	_textDesc.resetTexture();
	_textTime.resetTexture();
}

} // End of namespace Stark
