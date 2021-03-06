// File: gw2formats/pf/MapMetadataPackFile.h

/*	Copyright (C) 2012 Rhoot <https://github.com/rhoot>

    This file is part of gw2formats.

    gw2formats is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED
#define GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED

#include <gw2formats/fcc.h>
#include <gw2formats/pf/PackFile.h>

#include <gw2formats/pf/chunks/mMet/PackMapMetadata.h>

namespace gw2f {
	namespace pf {

		typedef PackFile<fcc::mMet> MmetPackFile;
		typedef PackFile<fcc::mMet> MapMetadataPackFile;

		namespace MapMetadataChunks {
			enum {
				Main = fcc::Main,
				MapMetadata = fcc::Main,
			}; // anon enum
		}; // namespace MapMetadataChunks

	}; // namespace pf
}; // namespace gw2formats

#endif // GW2FORMATS_PF_MAPMETADATAPACKFILE_H_INCLUDED
