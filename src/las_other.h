/*
   las_other.h - 'other' header class definition for lasUtil

   This file is part of the Las-Util-Cpp project

   Copyright (C) 2019 DC Slagel

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


#ifndef LAS_OTHER_H
#define LAS_OTHER_H

#include "las.h"


class LasOther
{
    public:
        LasOther();
        ~LasOther();
        void parseLine(std::string line);
        void printInfo();
        void setHeader(const std::string line);
        void printDataHeader();

        std::string getHeader();
    private:
        // header fields
        std::string header;
        std::vector<std::string> other_info_vec;
};

#endif /*  LAS_OTHER_H */
