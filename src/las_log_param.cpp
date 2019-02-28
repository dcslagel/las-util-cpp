/*
   las_log_param.cpp - LasLogParam class methods for ~Log_Parameters

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

LasLogParam::LasLogParam()
{
}

LasLogParam::~LasLogParam()
{
}

/* -------------------------------------------------------------------
 * Line formats:
 *
 * 1. Section Header
 * ~[section-name]
 * Example:
 * ~Well Information
 *
 * 2. name/value line
 * [name].[optional unit][space][value]:[description]|[optional associations]
 * Example:
 * STRT.M 1649.0000 : Description | Associations 
 *
 * -------------------------------------------------------------------*/
void LasLogParam::parseLine(std::string line)
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


void LasLogParam::setHeader(const std::string line)
{
    header = line;
}


std::string LasLogParam::getHeader()
{
    return header;
}


void LasLogParam::printInfo()
{
    std::cout
        << "# ------------------------------------------------------\n"
        << "#  " << getHeader() << "\n"
        << "# ------------------------------------------------------\n";
    std::cout
        << std::left
        << std::setw(14) << "Name"
        << " :: "
        << std::setw(7) << "Unit"
        << " :: "
        << std::setw(10) << "Value"
        << " :: "
        << std::setw(35) << "Desc"
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
            << std::setw(14) << name_vec[idx]
            << " :: "
            << std::setw(7) << unit_vec[idx]
            << " :: "
            << std::setw(10) << value_vec[idx]
            << " :: "
            << std::setw(35) << desc_vec[idx]
            << " :: "
            << assocs_vec[idx]
            << "\n";
    }
}
