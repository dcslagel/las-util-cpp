/*
   las_version.h - version class definition for lasUtil

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


#ifndef LAS_VERSION_H
#define LAS_VERSION_H


class LasVersion
{
    public:
        LasVersion();
        ~LasVersion();
        void printInfo();
        void setHeader(const std::string line);
        void setVersion(const std::string line);
        void setLineWrap(const std::string line);
        void setDelimiter(const std::string line);
        std::string getHeader();
        std::string getVersion();
        std::string getLineWrap();
        std::string getDelimiter();
        std::string current_line;

    private:
        // header fields
        std::string header;
        std::string version;
        std::string line_wrap;
        std::string field_delimiter;
};

#endif /*  LAS_VERSION_H */
