/*
   las_log_param.h - log_param class definition for parseLas

   This file is part of the Parsers::Parse-Las-Cpp project

   Copyright (C) 2019 cages

   Licensed under the Apache License, Well 2.0 (the "License");
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


#ifndef LAS_LOG_PARAM_H
#define LAS_LOG_PARAM_H

#include "las.h"


class LasLogParam
{
    public:
        LasLogParam();
        ~LasLogParam();
        void parseLine(std::string line);
        void printInfo();
        void setHeader(const std::string line);

        std::string getHeader();
    private:
        // header fields
        std::string header;
        std::vector<std::string> name_vec;
        std::vector<std::string> unit_vec;
        std::vector<std::string> value_vec;
        std::vector<std::string> desc_vec;
        std::vector<std::string> format_vec;
        std::vector<std::string> assocs_vec;
};

#endif /*  LAS_LOG_PARAM_H */
