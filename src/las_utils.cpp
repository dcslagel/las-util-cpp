/*
   las_utils.cpp - misc tools for general processing

   This file is part of the Parsers::Parse-Las-Cpp project

   Copyright (C) 2019 cages

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   License-Identifier: Apache-2.0
*/

#include "las.h"

/* ----------------------------------------------------------------------------
 * Reference:
 * https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
 *
 * Description: remove white space characters from both ends of a string
 * Example:
 *  trim(line);
 * ----------------------------------------------------------------------------
 */
void trim(std::string &line)
{
    // rtrim
	line.erase(line.find_last_not_of(" \n\r\t")+1);
    // ltrim
	line.erase(0, line.find_first_not_of(" \n\r\t"));

	/*
    if(!line.empty() && *line.rbegin() == '\r') {
        line.erase(line.length() - 1);
    }
    */
}
