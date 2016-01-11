/*
Copyright (C) 2012 Rhoot <https://github.com/rhoot>

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

//
// This sample is not likely to work as intended in non-windows OSes, due to
// wchar_t not being UTF-16 encoded. As such, wcout will probably freak out.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <locale>
#include <codecvt>

#include <gw2formats/StringsFile.h>

int main( int argc, char** argv ) {
	if ( argc <= 1 ) {
		std::cout << "Usage: " << argv[0] << " <strs file>" << std::endl;
		return 0;
	}

	// Characters below 128 are the same as for ANSI
	auto isAbove127 = []( gw2f::char16 c ) { return ( c >= 0x80 ); };

	gw2f::StringsFile stringFile( argv[1] );
	for ( size_t i = 0; i < stringFile.entryCount( ); i++ ) {
		auto& entry = stringFile.entry( i );

		// Under windows, this poses the same problem as the Eula sample. When
		// it encounters a character that the console cannot output, any
		// subsequent characters sent to the stream are discarded. To prevent
		// this, I am replacing all potentially invalid characters with a
		// question mark.

		std::basic_string<gw2f::char16> str;
		if ( entry.isEncrypted( ) ) {
			str = GW2F_U16( "Encrypted string" );
		} else {
			str = entry.get( );
			if ( str.empty( ) ) {
				str = GW2F_U16( "Empty string" );
			}
			std::replace_if( std::begin( str ), std::end( str ), isAbove127, '?' );
		}
#if defined(_MSC_VER)
		std::wcout << i << L";\"" << str << L"\"" << std::endl;
#elif defined(__GNUC__) || defined(__GNUG__)
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> temp;
		std::string mbs = temp.to_bytes( str );

		std::cout << i << ";\"" << mbs.c_str( ) << "\"" << std::endl;
#endif
	}

	return 0;
}
