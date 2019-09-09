/*
   las_version.cpp - LasVersion class methods

   This file is part of the Parsers::Parse-Las-Cpp project

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

#include "las.h"

LasVersion::LasVersion()
{
}

LasVersion::~LasVersion()
{
}

void LasVersion::setHeader(const std::string line)
{
    header = line;
}

void LasVersion::setVersion(const std::string line)
{
    std::string token;
    std::stringstream ss(line);
    while (ss >> token) {
        if (token[0] == ':') {
            break;
        } else if (token.front() == '.' || token.back() == '.') {
            ss >> token;
            version = token;
            break;
        }
    }
}

void LasVersion::setLineWrap(const std::string line)
{
    std::string token;
    std::stringstream ss(line);
    while (ss >> token) {
        if (token[0] == ':') {
            break;
        } else if (token.front() == '.' || token.back() == '.') {
            ss >> token;
            line_wrap = token;
            break;
        }
    }
}

void LasVersion::setDelimiter(const std::string line)
{
    std::string token;
    std::stringstream ss(line);
    while (ss >> token) {
        if (token[0] == ':') {
            break;
        } else if (token.front() == '.' || token.back() == '.') {
            ss >> token;
            field_delimiter = token;
            break;
        }
    }
}

std::string LasVersion::getHeader()
{
    return header;
}

std::string LasVersion::getVersion()
{
    return version;
}
std::string LasVersion::getLineWrap()
{
    return line_wrap;
}
std::string LasVersion::getDelimiter()
{
    return field_delimiter;
}

void LasVersion::printInfo()
{
    std::cout << "\n"
        << "# ------------------------------------------------------\n"
        << "#  " << getHeader() << "\n"
        << "# ------------------------------------------------------\n"
        << std::left
        << std::setw(17) << "Version-string"
        << ": [" << getVersion() << "]\n"
        << std::setw(17) << "Is LineWrap on"
        << ": [" << getLineWrap() << "]\n"
        << std::setw(17) << "Field Delimiter"
        << ": [" << getDelimiter() << "]\n"
        << "# ------------------------------------------------------\n\n";
}
