/*
   las_args.cpp - argument parsing functions for lasUtil

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

#include <getopt.h>  // getopt(), optarg

#include "las.h"


static char *filename_to_parse = nullptr;
static char *sections_to_print = nullptr;
static const char *helptext = 
"Usage: lasUtil -f <las_filename> [-p <sections_to_print>]\n"
" \n"
"- Sections to print:\n"
"  By default all sections are displayed\n"
"  Specify which sections to display by listing the letters following '-p'\n"
"  Example:\n"
"  lasUtil -f myfile -p vw\n"
"    Letter  : Section\n"
"    v       : Version Information Section\n"
"    w       : Well Information Section\n"
"    c       : Curve Section\n"
"    p       : Parameter Section\n"
"    o       : Other Section\n"
"    a       : Drilling Data Section\n";



int arg_parse(int argc, char *argv[])
{
    int ch;
    const char *optstring = "hf:p:";

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " -f <las_filename> [-p <sections_to_print>]\n";
        return(1);
    }

    while ((ch = getopt(argc, argv, optstring)) !=  -1)
    {
        switch (ch)
        {
            case 'f':
                filename_to_parse = strdup(optarg);
                if (filename_to_parse == nullptr) {
                    perror("strdup");
                    return 1;
                }
                break;
            case 'h':
                std::cout << helptext;
                exit(0);
            case 'p':
                sections_to_print = new char[strlen(optarg + 1)];
                if (sections_to_print == nullptr) {
                    perror("new");
                    return 1;
                }
                strncpy(sections_to_print, optarg, strlen(optarg));
                break;
            default:
                std::cerr << helptext;
                return(1);
        }
    }

    // if -f <filename> wasn't used, then display help and exit
    if (filename_to_parse == nullptr) {
      std::cout << helptext;
      exit(0);
    }

    return 0;
}


char *get_filename_arg(void)
{
    return filename_to_parse;
}


bool is_section_printable(char section)
{
  bool result = false;

  // if sections_to_print is not set then print all sections
  if (sections_to_print == nullptr) {
    result = true;
    return result;
  }

  size_t mylen = strlen(sections_to_print);

  for(size_t idx = 0; idx < mylen; idx++) { 
    if (sections_to_print[idx] == section) {
      result = true;
      return result;
    }
  }
  return result;
}


void release_arg_memory(void)
{
    delete [] filename_to_parse;
    delete [] sections_to_print;
    delete [] helptext;
}
