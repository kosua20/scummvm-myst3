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

#ifndef STARK_GFX_OPENGL_S_ACTOR_H
#define STARK_GFX_OPENGL_S_ACTOR_H

#include "common/hashmap.h"

#include "engines/stark/hash-ptr.h"
#include "engines/stark/visual/actor.h"

namespace Graphics {
	class Shader;
}

namespace Stark {
namespace Gfx {

class OpenGLSActorRenderer : public VisualActor {
public:
	OpenGLSActorRenderer();
	virtual ~OpenGLSActorRenderer();

	void render(Gfx::Driver *gfx, const Math::Vector3d position, float direction) override;

protected:
	typedef Common::HashMap<FaceNode *, uint32> FaceBufferMap;

	Graphics::Shader *_shader;

	FaceBufferMap _faceVBO;
	FaceBufferMap _faceEBO;

	void clearVertices();
	void uploadVertices();
	uint32 createFaceVBO(const FaceNode *face);
	uint32 createFaceEBO(const FaceNode *face);
	void setBonePositionArrayUniform(const char *uniform);
	void setBoneRotationArrayUniform(const char *uniform);
};

} // End of namespace Gfx
} // End of namespace Stark

#endif // STARK_GFX_OPENGL_S_ACTOR_H
