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

#ifndef BACKENDS_NETWORKING_ENET_SOCKET_H
#define BACKENDS_NETWORKING_ENET_SOCKET_H

#ifdef WIN32
// Including winsock2.h will result in errors, we have to define
// SOCKET ourselves.
#include <basetsd.h>
typedef UINT_PTR SOCKET;

typedef SOCKET ENetSocket;
#else
typedef int ENetSocket;
#endif

#include "common/str.h"

namespace Networking {

class Socket {
public:
	Socket(ENetSocket socket);
	~Socket();

	bool send(Common::String address, int port, const char *data);
	bool receive();

	Common::String getData();

	Common::String getHost();
	int getPort();
private:
	ENetSocket _socket;
	Common::String _recentData;
	Common::String _recentHost;
	int _recentPort;
};

} // End of namespace Networking

#endif
