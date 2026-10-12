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

#include "common/system.h"

#include "director/director.h"
#include "director/sound.h"
#include "director/window.h"
#include "director/lingo/lingo.h"
#include "director/lingo/lingo-object.h"
#include "director/lingo/lingo-utils.h"
#include "director/lingo/xlibs/s/setglobalvolumexcmd.h"

/**************************************************
 *
 * USED IN:
 * jman
 *
 **************************************************/

namespace Director {

const char *const SetGlobalVolumeXCMD::xlibName = "SetGlobalVolume";
const XlibFileDesc SetGlobalVolumeXCMD::fileNames[] = {
	{ "SetGlobalVolume",	nullptr },
	{ nullptr,				nullptr },
};

static const BuiltinProto builtins[] = {
	{ "SetGlobalVolume", SetGlobalVolumeXCMD::m_SetGlobalVolume, 1, 1, 300, CBLTIN },
	{ nullptr, nullptr, 0, 0, 0, VOIDSYM }
};

void SetGlobalVolumeXCMD::open(ObjectType type, const Common::Path &path) {
	g_lingo->initBuiltIns(builtins);
}

void SetGlobalVolumeXCMD::close(ObjectType type) {
	g_lingo->cleanupBuiltIns(builtins);
}

void SetGlobalVolumeXCMD::m_SetGlobalVolume(int nargs) {
	// Sets the Macintosh system volume, range 0-7, same as "the soundLevel"
	int level = g_lingo->pop().asInt();
	g_director->getCurrentWindow()->getSoundManager()->setChannelVolume(-1, MAX(0, MIN(level * 32, 255)));
}

}
