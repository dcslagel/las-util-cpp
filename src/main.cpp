/*
   parselas - parse las formatted files and display the fields

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


// ParseLas includes
#include "las.h"


int main(int argc, char *argv[])
{
    if (arg_parse(argc, argv) != 0) {
        exit(EXIT_FAILURE);
    }

    LasVersion LVer;
    char *file_to_parse = get_filename_arg();


    std::ifstream DataSrc(file_to_parse);
    if (DataSrc.fail()) {
        std::cout << "WARNING: Cannot open " << file_to_parse << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    /* ----------------------------------------------------
     * Get Version Section
     * ----------------------------------------------------*/
    std::getline(DataSrc, line);
	trim(line);
    LVer.setHeader(line);

    std::getline(DataSrc, line);
	trim(line);
    LVer.setVersion(line);

    std::getline(DataSrc, line);
    trim(line);
    LVer.setLineWrap(line);

    std::getline(DataSrc, line);
    trim(line);
    LVer.setDelimiter(line);

    LVer.printInfo();


    /* ----------------------------------------------------
     * Get Well Section
     * ----------------------------------------------------*/
    LasWell LWell;

    while (std::getline(DataSrc, line))
    {
        if (line[0] == '#') {
            continue;
        }

        LWell.parseLine(line);
    }

    LWell.printInfo();

    DataSrc.close();

    return 0;
}
