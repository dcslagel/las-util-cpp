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

The parser currently parses and displays the Version and Well-Information
sections. Additional sections to be added in future iterations.


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

- Functionality is very basic. 


AUTHOR
------

D'Cage

COPYRIGHT
------

Copyright (c) 2019 cages

