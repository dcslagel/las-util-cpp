NAME
----
LAS-Util-Cpp - LAS parser in C++

TABLE-OF-CONTENTS
-----------------
- [DESCRIPTION](#description)
- [SYNOPSIS](#synopsis)
- [OPTIONS](#options)
- [INSTALL-COMPILE-AND-RUN](#install-compile-and-run)
- [EXAMPLES](#examples)
- [PROJECT-ROADMAP](#project-roadmap)
- [FEATURE-REQUEST](#feature-request)
- [BUGS](#bugs)
- [COPYRIGHT](#copyright)

[DESCRIPTION](#name)
------------

Caution: This is beta software!

basic LAS (Log Ascii Standard) well-log parser in c++

`lasUtil` partially reads a las formatted file. 

The parser currently parses and displays the following sections:
- Version
- Well-Information
- Curve

Currently tested on darwin-amd64.

The current goal of LAS-Util are:
- Parse LAS header meta-data records(lines)
- Explore the LAS file format specifications
- Explore design decisions related to CPP-Lang

LAS file format versions are written and maintained by   
the Canadian Well Logging Society at    
https://www.cwls.org/products/

[SYNOPSIS](#name)
----------

Usage: lasUtil -f <las_filename> [-p <sections_to_print>]    
     
Sections to print:    
Specify which sections to display by listing the letters following '-p'    

|Letter  | Section  |
|--------|----------|
|v       | Version Information Section  |
|w       | Well Information Section  |
|c       | Curve Section
|p       | Log Parameter Section  |
|e       | Drilling Definition Section  |
|a       | Drilling Data Section  |

[INSTALL-COMPILE-AND-RUN](#name)
-------------------------

```bash
git clone https://github.com/dcslagel/las-util-cpp
cd las-util-cpp/src  
make clean
make  
cd ..
./src/lasUtil -f examples/sample_2.0.las
```

[EXAMPLES](#name)
---------

* Display help   
`./src/lasUtil -h`

* Display all sections of a given LAS file    
`./src/lasUtil -f examples/sample_2.0.las`

* Display only the well information section of a given LAS file    
`./src/lasUtil -p w -f examples/sample_2.0.las`

* Display the version and well information sections of a given LAS file    
`./src/lasUtil -p vw -f examples/sample_2.0.las`


[OPTIONS](#name)
--------

`-f`
  LAS file to parse

`-p`
  options for displaying section information

`-h`
  display help


[PROJECT-ROADMAP](#name)
----------------
The current work-in-progress milestone is 0.0.2:

https://github.com/dcslagel/las-util-cpp/projects/1

- Goals:
  - Add parsing for the other major metadata sections Some iterative
    improvements to the project structure and design.

las-util-cpp's project road-map is managed in github milestones at:

https://github.com/dcslagel/las-util-cpp/milestones


[FEATURE-REQUEST](#name)
----------------

To request and discuss a potential feature create an issue at:
  - https://github.com/dcslagel/las-util-cpp/issues


[BUGS](#name)
-----

- Functionality is very basic. 

- Report bugs by creating an issue at:
  - https://github.com/dcslagel/las-util-cpp/issues

[COPYRIGHT](#name)
------

Copyright (c) 2019, 2020 DC Slagel and contributors
