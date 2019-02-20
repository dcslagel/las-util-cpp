/*
   parselas - parse las formated files and display the fields

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

void remove_carriage_return(std::string& line);


void remove_carriage_return(std::string& line)
{
    if(!line.empty() && *line.rbegin() == '\r') {
        line.erase(line.length() - 1);
    }
}

int main(int argc, char *argv[])
{
    if (arg_parse(argc, argv) != 0) {
        exit(EXIT_FAILURE);
    }

    LasVersion LVer;
    char *file_to_parse = get_filename_arg();
    std::cout << "INFO: filename: [" << file_to_parse << "]\n";


    std::ifstream DataSrc(file_to_parse);
    if (DataSrc.is_open()) {
        std::cout
            << "INFO: "
            << file_to_parse
            << " is open, next action: parse the file\n";
    }
    if (DataSrc.fail()) {
        std::cout << "WARNING: Cannot open " << file_to_parse << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;


    std::getline(DataSrc, line);
	remove_carriage_return(line);
    LVer.setHeader(line);

    std::getline(DataSrc, line);
	remove_carriage_return(line);
    LVer.setVersion(line);

    std::getline(DataSrc, line);
    remove_carriage_return(line);
    LVer.setLineWrap(line);

    std::getline(DataSrc, line);
    remove_carriage_return(line);
    LVer.setDelimiter(line);

    std::string token;

    std::cout << "Section Header: [" << LVer.getHeader() << "]\n";
    std::cout << "Version-string: [" << LVer.getVersion() << "]\n";
    std::cout << "Is LineWrap on: [" << LVer.getLineWrap() << "]\n";
    std::cout << "Field Delimiter: [" << LVer.getDelimiter() << "]\n";

    DataSrc.close();

    return 0;
}
