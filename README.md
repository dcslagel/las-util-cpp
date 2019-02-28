# parser-las-cpp
NAME
----
parselas - LAS parser in C

SYNOPSIS
--------

`parseLas -f` example.las

DESCRIPTION
-----------
Caution: This is very beta software!

basic LAS (Log Ascii Standard) well-log parser in c++

`parseLas` partially reads a las formatted file. 

The parser currently parses and displays the following sections:
- Version
- Well-Information
- Log-Parameter

Additional sections to be added in future iterations.


OPTIONS
-------

`-f`
  LAS file to parse

COMPILE AND RUN
---------------

```bash
cd parse-las-cpp/src  
make clean
make  
./parseLas -f example.las  
```

BUGS
----

- Seg fault if '-f' used.
- Functionality is very basic. 


AUTHOR
------

dCage

COPYRIGHT
------

Copyright (c) 2019 cages

