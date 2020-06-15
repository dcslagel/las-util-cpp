# las-util-cpp
NAME
----
LAS-Util - LAS parser  in C++

DESCRIPTION
-----------
Caution: This is beta software!

basic LAS (Log Ascii Standard) well-log parser in c++

LAS file format versions are written and maintained by   
the Canadian Well Logging Society at    
https://www.cwls.org/products/

`lasUtil` partially reads a las formatted file. 

The parser currently parses and displays the following sections:
- Version
- Well-Information

Currently tested on darwin-amd64.

GOALS
-----

The current goal of LAS-Util are:
- Parse LAS header meta-data records(lines)
- Explore the LAS file format specifications
- Explore design decisions related to CPP-Lang

SYNOPSIS
--------

Usage: lasUtil -f <las_filename> [-p <sections_to_print>]    
     
Sections to print:    
Specify which sections to display by listing the letters following '-p'    

|Letter  | Section  |
|--------|----------|
|v       | Version Information Section  |
|w       | Well Information Section  |
|p       | Log Parameter Section  |
|d       | Log Definition Section  |
|e       | Drilling Definition Section  |
|a       | Drilling Data Section  |

INSTALL AND BUILD
-----------------

```bash
git clone https://github.com/dcslagel/las-util-cpp
cd las-util-cpp/src  
make clean
make  
./lasUtil -f ../examples/sample_2.0.las  
```

EXAMPLES
--------

* Display help   
`lasUtil -h`

* Display all sections of a given LAS file    
`lasUtil -f ../examples/sample_2.0.las`

* Display only the well information section of a given LAS file    
`lasUtil -p w -f ../examples/sample_2.0.las`

* Display the version and well information sections of a given LAS file    
`lasUtil -p vw -f ../examples/sample_2.0.las`


OPTIONS
-------

`-f`
  LAS file to parse

`-p`
  options for displaying section information

`-h`
  display help


BUGS
----

- Functionality is very basic. 
- Report bugs by creating an issue at:
  - https://github.com/dcslagel/las-header-parser-c/issues


COPYRIGHT
------

Copyright (c) 2019 DC Slagel

