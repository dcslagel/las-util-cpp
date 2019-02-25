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

`parseLas` currently reads in a basic las formatted file.  It parses the
account type, each of the records and displays both the account type and
records

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

- Functionality is very basic. The parser currently parses and displays the
  Version and Well-Information sections. Additional sections to be added in
  future iterations.


AUTHOR
------

D'Cage

COPYRIGHT
------

Copyright (c) 2019 cages

