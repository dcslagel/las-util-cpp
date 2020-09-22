/*
   las_other.cpp - LasOther class methods for ~Other section

   This file is part of the Las-Util-Cpp project

   Copyright (C) 2019 DC Slagel

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

LasOther::LasOther()
{
}

LasOther::~LasOther()
{
}

/* -------------------------------------------------------------------
 * Line formats:
 *
 * 1. Section Header (any case)
 * ~[section-name]
 * Examples:
 * ~Other Information
 * ~OTHER
 *
 * 2. line of text
 * Examples:
 *   Note: The logging tools became stuck at 625 metres causing the data
 *   between 625 metres and 615 metres to be invalid.
 *
 * -------------------------------------------------------------------*/
void LasOther::parseLine(std::string line)
{
    std::string field_name;
    std::string unit;
    std::string value;
    std::string desc;
    std::string assocs;


    // Get section title or field name
    std::stringstream ss(line);
    // std::getline(ss, field_name, '.');
    std::getline(ss, field_name);
    trim(field_name);

    if (field_name[0] == '~') {
        setHeader(field_name);
    } else if ( field_name.size() == 0) {
        return;
    } else {
        other_info_vec.push_back(field_name);
    }
}


void LasOther::setHeader(const std::string line)
{
    header = line;
}


std::string LasOther::getHeader()
{
    return header;
}


void LasOther::printInfo()
{
    const int width_name = 14;
    std::cout
        << "# -------------------------------------------------"
        << "---------------------------------------------\n"
        << "#  " << getHeader() << "\n"
        << "# -------------------------------------------------"
        << "---------------------------------------------\n";

    size_t record_count = other_info_vec.size();
    for(size_t idx = 0; idx < record_count; idx++) {
        std::string rec_name = other_info_vec[idx];
        std::cout
            << std::left
            << std::setw(width_name) << other_info_vec[idx]
            << "\n";
    }
}

void LasOther::printDataHeader()
{
    const int width_name = 6;
    size_t record_count = other_info_vec.size();

    for(size_t idx = 0; idx < record_count; idx++) {
        std::string rec_name = other_info_vec[idx];
        std::cout
            << std::left
            << std::setw(width_name) << other_info_vec[idx];
        if (idx == 0) {
            std::cout << " | ";
        } else if (idx < record_count - 1) {
            std::cout << "| ";
        }
    }
    std::cout
        << "\n"
        << "# -------------------------------------------------"
        << "---------------------------------------------\n";

}
