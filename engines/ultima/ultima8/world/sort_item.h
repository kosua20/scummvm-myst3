/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ULTIMA8_WORLD_SORTITEM_H
#define ULTIMA8_WORLD_SORTITEM_H

#include "common/str.h"
#include "ultima/ultima8/misc/common_types.h"
#include "ultima/ultima8/misc/rect.h"
#include "ultima/ultima8/misc/box.h"

//#define SORTITEM_OCCLUSION_EXPERIMENTAL 1

namespace Ultima {
namespace Ultima8 {

class Shape;

/**
 * This class is basically private to ItemSorter, but is in a separate header
 * to enable unit testing.
 *
 * Other code should have no reason to include it.
 */
struct SortItem {
	SortItem() : _next(nullptr), _prev(nullptr), _itemNum(0),
			_shape(nullptr), _order(-1), _depends(), _shapeNum(0),
			_frame(0), _flags(0), _extFlags(0), _sr(),
			_x(0), _y(0), _z(0), _xLeft(0),
			_yFar(0), _zTop(0), _sxLeft(0), _sxRight(0), _sxTop(0),
			_syTop(0), _sxBot(0), _syBot(0),_fbigsq(false), _flat(false),
			_occl(false), _solid(false), _draw(false), _roof(false),
			_noisy(false), _anim(false), _trans(false), _fixed(false),
			_land(false), _occluded(false), _sprite(false),
			_invitem(false) { }

	SortItem                *_next;
	SortItem                *_prev;

	uint16                  _itemNum;   // Owner item number

	const Shape             *_shape;
	uint32                  _shapeNum;
	uint32                  _frame;
	uint32                  _flags;     // Item flags
	uint32                  _extFlags;  // Item extended flags

	Rect                    _sr; // Screenspace rect for shape frame
	/*
	            Bounding Box layout

	       1
	     /   \
	   /       \     1 = Left  Far  Top LFT --+
	 2           3   2 = Left  Near Top LNT -++
	 | \       / |   3 = Right Far  Top RFT +-+
	 |   \   /   |   4 = Right Near Top RNT +++
	 |     4     |   5 = Left  Near Bot LNB -+-
	 |     |     |   6 = Right Far  Bot RFB +--
	 5     |     6   7 = Right Near Bot RNB ++-
	   \   |   /     8 = Left  Far  Bot LFB --- (not shown)
	     \ | /
	       7

	*/

	int32   _x, _xLeft;   // Worldspace bounding box x (xright = x)
	int32   _y, _yFar;    // Worldspace bounding box y (ynear = y)
	int32   _z, _zTop;    // Worldspace bounding box z (_zTop = z)

	int32   _sxLeft;     // Screenspace bounding box left extent    (LNT x coord)
	int32   _sxRight;    // Screenspace bounding box right extent   (RFT x coord)

	int32   _sxTop;      // Screenspace bounding box top x coord    (LFT x coord)
	int32   _syTop;      // Screenspace bounding box top extent     (LFT y coord)

	int32   _sxBot;      // Screenspace bounding box bottom x coord (RNB x coord) ss origin
	int32   _syBot;      // Screenspace bounding box bottom extent  (RNB y coord) ss origin

#ifdef SORTITEM_OCCLUSION_EXPERIMENTAL
	SortItem *_xAdjoin; // Item sharing a right x edge with the left x edge - used for occlusion
	SortItem *_yAdjoin; // Item sharing a near y edge with the far y edge - used for occlusion
	int32 _groupNum;   // Identifier for a member of an occlusion group
#endif // SORTITEM_OCCLUSION_EXPERIMENTAL


	bool    _fbigsq : 1;         // Needs 1 bit  0
	bool    _flat : 1;           // Needs 1 bit  1
	bool    _occl : 1;           // Needs 1 bit  2
	bool    _solid : 1;          // Needs 1 bit  3
	bool    _draw : 1;           // Needs 1 bit  4
	bool    _roof : 1;           // Needs 1 bit  5
	bool    _noisy : 1;          // Needs 1 bit  6
	bool    _anim : 1;           // Needs 1 bit  7
	bool    _trans : 1;          // Needs 1 bit  8
	bool    _fixed : 1;
	bool    _land : 1;
	bool 	_sprite : 1;         // Always-on-top sprite, for Crusader (U8 sprites appear in z order)
	bool 	_invitem : 1;        // Crusader inventory item, should appear above other things

	bool    _occluded : 1;       // Set true if occluded

	int32   _order;      // Rendering _order. -1 is not yet drawn

	// Note that Std::priority_queue could be used here, BUT there is no guarentee that it's implementation
	// will be friendly to insertions
	// Alternatively i could use Std::list, BUT there is no guarentee that it will keep wont delete
	// the unused nodes after doing a clear
	// So the only reasonable solution is to write my own list
	struct DependsList {
		struct Node {
			Node        *_next;
			Node        *_prev;
			SortItem    *val;
			Node() : _next(nullptr), _prev(nullptr), val(nullptr) { }
		};

		Node *list;
		Node *tail;
		Node *unused;

		struct iterator {
			Node *n;
			SortItem *&operator *() {
				return n->val;
			}
			iterator(Node *node) : n(node) { }
			iterator &operator++() {
				n = n->_next;
				return *this;
			}
			bool operator != (const iterator &o) const {
				return n != o.n;
			}
		};

		iterator begin() const {
			return iterator(list);
		}
		iterator end() const {
			return iterator(nullptr);
		}

		void clear() {
			if (tail) {
				tail->_next = unused;
				unused = list;
				tail = nullptr;
				list = nullptr;
			}
		}

		void push_back(SortItem *other) {
			if (!unused) unused = new Node();
			Node *nn = unused;
			unused = unused->_next;
			nn->val = other;

			// Put it at the end
			if (tail) tail->_next = nn;
			if (!list) list = nn;
			nn->_next = nullptr;
			nn->_prev = tail;
			tail = nn;
		}

		void insert_sorted(SortItem *other) {
			if (!unused) unused = new Node();
			Node *nn = unused;
			unused = unused->_next;
			nn->val = other;

			for (Node *n = list; n != nullptr; n = n->_next) {
				// Get the insert point... which is before the first item that has higher z than us
				if (other->listLessThan(*(n->val))) {
					nn->_next = n;
					nn->_prev = n->_prev;
					n->_prev = nn;
					if (nn->_prev) nn->_prev->_next = nn;
					else list = nn;
					return;
				}
			}

			// No suitable, so put at end
			if (tail) tail->_next = nn;
			if (!list) list = nn;
			nn->_next = nullptr;
			nn->_prev = tail;
			tail = nn;
		}

		DependsList() : list(nullptr), tail(nullptr), unused(nullptr) { }

		~DependsList() {
			clear();
			while (unused)  {
				Node *n = unused->_next;
				delete unused;
				unused = n;
			}
		}
	};

	// All this Items dependencies (i.e. all objects behind)
	DependsList _depends;

	// Functions

	// Set worldspace bounds and calculate screenspace at center point
	inline void setBoxBounds(const Box &box, int32 sx, int32 sy);

	inline Box getBoxBounds() const;

	// Check if the given point is inside the screenpace bounds.
	inline bool contains(int32 sx, int32 sy) const;

	// Screenspace check to see if this overlaps si2
	inline bool overlap(const SortItem &si2) const;

	// Screenspace check to see if this occludes si2. Assumes this is above of si2
	inline bool occludes(const SortItem &si2) const;

	// Screenspace check to see if this is below si2. Assumes this overlaps si2
	inline bool below(const SortItem &si2) const;

	// Comparison for the sorted lists
	inline bool listLessThan(const SortItem &si2) const {
		const SortItem &si1 = *this;
		if (si1._sprite != si2._sprite)
			return si1._sprite < si2._sprite;

		if (si1._z != si2._z)
			return si1._z < si2._z;

		return si1._flat > si2._flat;
	}

	Common::String dumpInfo() const;
};

inline void SortItem::setBoxBounds(const Box& box, int32 sx, int32 sy) {
	_x = box._x;
	_y = box._y;
	_z = box._z;
	_xLeft = _x - box._xd;
	_yFar = _y - box._yd;
	_zTop = _z + box._zd;

	// NOTE: Precision loss from integer division is intention to fix
	// rendering issue at MainActor::teleport 37 18168 17656 104

	// Screenspace bounding box left extent    (LNT x coord)
	_sxLeft = _xLeft / 4 - _y / 4 - sx;
	// Screenspace bounding box right extent   (RFT x coord)
	_sxRight = _x / 4 - _yFar / 4 - sx;

	// Screenspace bounding box top x coord    (LFT x coord)
	_sxTop = _xLeft / 4 - _yFar / 4 - sx;
	// Screenspace bounding box top extent     (LFT y coord)
	_syTop = _xLeft / 8 + _yFar / 8 - _zTop - sy;

	// Screenspace bounding box bottom x coord (RNB x coord)
	_sxBot = _x / 4 - _y / 4 - sx;
	// Screenspace bounding box bottom extent  (RNB y coord)
	_syBot = _x / 8 + _y / 8 - _z - sy;

	// Screenspace rect - replace with shape frame calculations
	_sr.left = _sxLeft;
	_sr.top = _syTop;
	_sr.right = _sxRight;
	_sr.bottom = _syBot;

	// These help out with sorting. We calc them now, so it will be faster
	_fbigsq = box._xd == box._yd && box._xd >= 128;
	_flat = box._zd == 0;
}

inline Box SortItem::getBoxBounds() const {
	Box box;
	box._x = _x;
	box._y = _y;
	box._z = _z;
	box._xd = _x - _xLeft;
	box._yd = _y - _yFar;
	box._zd = _zTop - _z;
	return box;
}

inline bool SortItem::contains(int32 sx, int32 sy) const {
	if (!_sr.contains(sx, sy))
		return false;

	const int point_top_diff[2] = { _sxTop - sx, _syTop - sy };
	const int point_bot_diff[2] = { _sxBot - sx, _syBot - sy };

	// This function is a bit of a hack. It uses dot products between
	// points and the lines. Nothing is normalized since that isn't
	// important

	// 'normal' of top  left line ( 2,-1) of the bounding box
	const int32 dot_top_left = point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of top right line ( 2, 1) of the bounding box
	const int32 dot_top_right = -point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of bot  left line (-2,-1) of the bounding box
	const int32 dot_bot_left = point_bot_diff[0] - point_bot_diff[1] * 2;

	// 'normal' of bot right line (-2, 1) of the bounding box
	const int32 dot_bot_right = -point_bot_diff[0] - point_bot_diff[1] * 2;

	const bool right_clear = _sxRight < sx;
	const bool left_clear = _sxLeft > sx;
	const bool top_left_clear = dot_top_left > 0;
	const bool top_right_clear = dot_top_right > 0;
	const bool bot_left_clear = dot_bot_left > 0;
	const bool bot_right_clear = dot_bot_right > 0;

	const bool clear = right_clear || left_clear ||
					   (bot_right_clear || bot_left_clear) ||
					   (top_right_clear || top_left_clear);

	return !clear;
}

inline bool SortItem::overlap(const SortItem &si2) const {
	if (!_sr.intersects(si2._sr))
		return false;

	const int point_top_diff[2] = { _sxTop - si2._sxBot, _syTop - si2._syBot };
	const int point_bot_diff[2] = { _sxBot - si2._sxTop, _syBot - si2._syTop };

	// This function is a bit of a hack. It uses dot products between
	// points and the lines. Nothing is normalized since that isn't
	// important

	// 'normal' of top  left line ( 2,-1) of the bounding box
	const int32 dot_top_left = point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of top right line ( 2, 1) of the bounding box
	const int32 dot_top_right = -point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of bot  left line (-2,-1) of the bounding box
	const int32 dot_bot_left =  point_bot_diff[0] - point_bot_diff[1] * 2;

	// 'normal' of bot right line (-2, 1) of the bounding box
	const int32 dot_bot_right = -point_bot_diff[0] - point_bot_diff[1] * 2;

	const bool right_clear = _sxRight < si2._sxLeft;
	const bool left_clear = _sxLeft > si2._sxRight;
	const bool top_left_clear = dot_top_left >= 0;
	const bool top_right_clear = dot_top_right >= 0;
	const bool bot_left_clear = dot_bot_left >= 0;
	const bool bot_right_clear = dot_bot_right >= 0;

	const bool clear = right_clear || left_clear ||
	                   (bot_right_clear || bot_left_clear) ||
	                   (top_right_clear || top_left_clear);

	return !clear;
}

inline bool SortItem::occludes(const SortItem &si2) const {
	if (!_sr.contains(si2._sr))
		return false;

	const int point_top_diff[2] = { _sxTop - si2._sxTop, _syTop - si2._syTop };
	const int point_bot_diff[2] = { _sxBot - si2._sxBot, _syBot - si2._syBot };

	// This function is a bit of a hack. It uses dot products between
	// points and the lines. Nothing is normalized since that isn't
	// important

	// 'normal' of top left line ( 2, -1) of the bounding box
	const int32 dot_top_left = point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of top right line ( 2, 1) of the bounding box
	const int32 dot_top_right = -point_top_diff[0] + point_top_diff[1] * 2;

	// 'normal' of bot  left line (-2,-1) of the bounding box
	const int32 dot_bot_left =  point_bot_diff[0] - point_bot_diff[1] * 2;

	// 'normal' of bot right line (-2, 1) of the bounding box
	const int32 dot_bot_right = -point_bot_diff[0] - point_bot_diff[1] * 2;


	const bool right_res = _sxRight >= si2._sxRight;
	const bool left_res = _sxLeft <= si2._sxLeft;
	const bool top_left_res = dot_top_left <= 0;
	const bool top_right_res = dot_top_right <= 0;
	const bool bot_left_res = dot_bot_left <= 0;
	const bool bot_right_res = dot_bot_right <= 0;

	return right_res && left_res && bot_right_res && bot_left_res &&
		top_right_res && top_left_res;
}

inline bool SortItem::below(const SortItem &si2) const {
	const SortItem &si1 = *this;

	if (si1._sprite != si2._sprite)
		return si1._sprite < si2._sprite;

	// Clearly in Z and one must not be flat - lower cannot be inventory
	if (si1._zTop <= si2._z && !(si1._flat && si2._flat) && !si1._invitem)
		return true;
	if (si1._z >= si2._zTop && !(si1._flat && si2._flat) && !si2._invitem)
		return false;

	// Clearly in Y and one must not be flat
	bool yFlat1 = si1._yFar == si1._y;
	bool yFlat2 = si2._yFar == si2._y;
	if (si1._y <= si2._yFar && !(yFlat1 && yFlat2))
		return true;
	if (si1._yFar >= si2._y && !(yFlat1 && yFlat2))
		return false;

	// Clearly in X and one must not be flat
	bool xFlat1 = si1._xLeft == si1._x;
	bool xFlat2 = si2._xLeft == si2._x;
	if (si1._x <= si2._xLeft && !(xFlat1 && xFlat2))
		return true;
	if (si1._xLeft >= si2._x && !(xFlat1 && xFlat2))
		return false;

	// Specialist z flat handling
	if (si1._flat || si2._flat) {
		// Lower z-bottom drawn before
		if (si1._z != si2._z)
			return si1._z < si2._z;

		// Inv items always drawn after
		if (si1._invitem != si2._invitem)
			return si1._invitem < si2._invitem;

		// Flat gets drawn before
		if (si1._flat != si2._flat)
			return si1._flat > si2._flat;

		// Trans always gets drawn after
		if (si1._trans != si2._trans)
			return si1._trans < si2._trans;

		// Animated always gets drawn after
		if (si1._anim != si2._anim)
			return si1._anim < si2._anim;

		// Draw always gets drawn first
		if (si1._draw != si2._draw)
			return si1._draw > si2._draw;

		// Solid always gets drawn first
		if (si1._solid != si2._solid)
			return si1._solid > si2._solid;

		// Occludes always get drawn first
		if (si1._occl != si2._occl)
			return si1._occl > si2._occl;

		// Large flats squares get drawn first
		if (si1._fbigsq != si2._fbigsq)
			return si1._fbigsq > si2._fbigsq;
	}

	// Y-flat vs non-flat handling
	if (yFlat1 != yFlat2 && si1._fixed == si2._fixed) {
		if (yFlat1) {
			if (si2._y - 32 > si2._yFar) {
				int32 yCenter2 = (si2._yFar + si2._y) / 2;
				return si1._y <= yCenter2;
			}
			return false;
		} else {
			if (si1._y - 32 > si1._yFar) {
				int32 yCenter1 = (si1._yFar + si1._y) / 2;
				return yCenter1 < si2._y;
			}
			return true;
		}
	}

	// X-flat vs non-flat handling
	if (xFlat1 != xFlat2 && si1._fixed == si2._fixed) {
		if (xFlat1) {
			if (si2._x - 32 > si2._xLeft) {
				int32 xCenter2 = (si2._xLeft + si2._x) / 2;
				return si1._x <= xCenter2;
			}
			return false;
		} else {
			if (si1._x - 32 > si1._xLeft) {
				int32 xCenter1 = (si1._xLeft + si1._x) / 2;
				return xCenter1 < si2._x;
			}
			return true;
		}
	}

	// Check z-bottom with a tolerance
	if (si1._z != si2._z) {
		if (si1._z < si2._z - 8)
			return true;
		else if (si1._z - 8 > si2._z)
			return false;
	}

	// Specialist handling for same location
	if (si1._x == si2._x && si1._y == si2._y) {
		// Trans always gets drawn after
		if (si1._trans != si2._trans)
			return si1._trans < si2._trans;
	}

	// Disabled: Land always gets drawn first
	// if (si1._land != si2._land)
	//	return si1._land > si2._land;

	// Land always gets drawn before roof
	if (si1._land && si2._land && si1._roof != si2._roof)
		return si1._roof < si2._roof;

	// Roof always gets drawn first
	if (si1._roof != si2._roof)
		return si1._roof > si2._roof;

	// Lower z-bottom drawn before
	if (si1._z != si2._z)
		return si1._z < si2._z;

	// Partial in X + Y front
	if (si1._x + si1._y != si2._x + si2._y)
		return (si1._x + si1._y < si2._x + si2._y);

	// Partial in X + Y back
	if (si1._xLeft + si1._yFar != si2._xLeft + si2._yFar)
		return (si1._xLeft + si1._yFar < si2._xLeft + si2._yFar);

	// Partial in y?
	if (si1._y != si2._y)
		return si1._y < si2._y;

	// Partial in x?
	if (si1._x != si2._x)
		return si1._x < si2._x;

	// Just sort by shape number
	if (si1._shapeNum != si2._shapeNum)
		return si1._shapeNum < si2._shapeNum;

	// And then by _frame
	return si1._frame < si2._frame;
}

Common::String SortItem::dumpInfo() const {
	Box b = getBoxBounds();
	Common::String info = Common::String::format("%u:%u (%d, %d, %d, %d, %d, %d): ",
								_shapeNum, _frame, b._x, b._y, b._z, b._xd, b._yd, b._zd);
	if (_sprite)
		info += "sprite ";
	if (_flat)
		info += "flat ";
	if (_anim)
		info += "anim ";
	if (_trans)
		info += "trans ";
	if (_draw)
		info += "draw ";
	if (_solid)
		info += "solid ";
	if (_occl)
		info += "occl ";
	if (_fbigsq)
		info += "fbigsq ";
	if (_roof)
		info += "roof ";
	if (_land)
		info += "land ";
	if (_noisy)
		info += "noisy ";
	if (_fixed)
		info += "fixed ";

	return info;
}

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
