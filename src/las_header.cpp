/*
   las_header.cpp - LasHeader class methods for ~Log_Parameters

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

LasHeader::LasHeader()
{
}

LasHeader::~LasHeader()
{
}

/* -------------------------------------------------------------------
 * Line formats:
 *
 * 1. Section Header
 * ~[section-name]
 * Example:
 * ~Curve Information
 *
 * 2. name/value line
 * [name].[optional unit][space][value]:[description]|[optional associations]
 * Example:
 * DEPT   .M                                       :  1  DEPTH
 * DT     .US/M           60 520 32 00             :  2  SONIC TRANSIT TIME
 *
 * -------------------------------------------------------------------*/
void LasHeader::parseLine(std::string line)
{
    std::string field_name;
    std::string unit;
    std::string value;
    std::string desc;
    std::string assocs;


    // Get section title or field name
    std::stringstream ss(line);
    std::getline(ss, field_name, '.');
    trim(field_name);

    if (field_name[0] == '~') {
        setHeader(field_name);
    } else if ( field_name.size() == 0) {
        return;
    } else {
        name_vec.push_back(field_name);

        // Get unit is there is one
        std::getline(ss, unit, ' ');
        unit_vec.push_back(unit);

        // Get value if there is one
        std::getline(ss, value, ':');
        trim(value);
        value_vec.push_back(value);

        // Get description
        std::getline(ss, desc, '|');
        trim(desc);
        desc_vec.push_back(desc);

        // TODO: Add parsing for formats

        // Get associations
        std::getline(ss, assocs);
        trim(assocs);
        assocs_vec.push_back(assocs);

    }
}


void LasHeader::setHeader(const std::string line)
{
    header = line;
}


std::string LasHeader::getHeader()
{
    return header;
}


void LasHeader::printInfo()
{
    const int width_name = 14;
    const int width_unit = 7;
    const int width_value = 11;
    const int width_desc = 40;
    std::cout
        << "# -------------------------------------------------"
        << "---------------------------------------------\n"
        << "#  " << getHeader() << "\n"
        << "# -------------------------------------------------"
        << "---------------------------------------------\n";
    std::cout
        << std::left
        << std::setw(width_name) << "Name"
        << " :: "
        << std::setw(width_unit) << "Unit"
        << " :: "
        << std::setw(width_value) << "Value"
        << " :: "
        << std::setw(width_desc) << "Desc"
        << " :: "
        << "Assocs"
        << "\n"
        << "# -------------------------------------------------"
        << "---------------------------------------------\n"
        << "\n";

    size_t record_count = name_vec.size();
    for(size_t idx = 0; idx < record_count; idx++) {
        std::string rec_name = name_vec[idx];
        std::cout
            << std::left
            << std::setw(width_name) << name_vec[idx]
            << " :: "
            << std::setw(width_unit) << unit_vec[idx]
            << " :: "
            << std::setw(width_value) << value_vec[idx]
            << " :: "
            << std::setw(width_desc) << desc_vec[idx]
            << " :: "
            << assocs_vec[idx]
            << "\n";
    }
}

void LasHeader::printDataHeader()
{
    const int width_name = 6;
    size_t record_count = name_vec.size();
    
    for(size_t idx = 0; idx < record_count; idx++) {
        std::string rec_name = name_vec[idx];
        std::cout
            << std::left
            << std::setw(width_name) << name_vec[idx];
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
