/*
   Las-Test-Main - Main for Las-Util test suite

   This file is part of the Las-Util-Cpp project

   Copyright (C) 2020 DC Slagel

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

#include <stdio.h>  // printf()
#include <stdlib.h> // exit, EXIT_SUCCESS

#include "las.h"

const char *test_rec_001 = "VERS.  2.0 : CWLS LOG ASCII STANDARD -VERSION 2.0";


int main(void)
{
  int passed = 0;
  int failed = 0;

  LasVersion LVer;
  LVer.setVersion(test_rec_001);

  if (LVer.getVersion() == "2.0") {
    passed = passed + 1;
  } else {
    failed = failed + 1;
  }

  printf("Total: [%d], Passed: [%d], Failed: [%d]\n",
    passed + failed, passed, failed
  );

  exit(EXIT_SUCCESS);
}
