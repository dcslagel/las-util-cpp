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

basic LAS (Log Ascii Standard) parser in c++

'parselas` currently reads in a basic qif formatted file.  It parses the
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

- Functionality is very basic.


AUTHOR
------

cages

COPYRIGHT
------

Copyright (c) 2019 cages

