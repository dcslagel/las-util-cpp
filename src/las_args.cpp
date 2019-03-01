/*
   las_args.cpp - argument parsing functions for parseLas

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

#include <getopt.h>  // getopt(), optarg

#include "las.h"


static char *filename_to_parse = nullptr;


int arg_parse(int argc, char *argv[])
{
    int ch;
    const char *optstring = "f:";

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " -f <las_filename>\n";
        return(1);
    }

    while ((ch = getopt(argc, argv, optstring)) !=  -1)
    {
        switch (ch)
        {
            case 'f':
                filename_to_parse = new char[strlen(optarg + 1)];
                if (filename_to_parse == nullptr) {
                    perror("new");
                    return 1;
                }
                strncpy(filename_to_parse, optarg, strlen(optarg));
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -f <las_filename>\n";
                return(1);
        }
    }

    return 0;
}


char *get_filename_arg(void)
{
    return filename_to_parse;
}

void release_arg_memory(void)
{
    delete [] filename_to_parse;
}
