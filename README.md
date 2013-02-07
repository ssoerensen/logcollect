logcollect
==========
Log collect is a project which aims to provide a simple, easy and
cheap way if indexing and searching log files. the project is based
on the clucene library and is primary developed using C++ and a little
PHP.


Dependencies
------------
Log collect have several dependencies

- jansson (C library for creating and reading JSON)
- Clucene (C++ implementation of apache lucene fulltext index)
- PCRE (C Library for using perl regular expressions)
- libconfig (C/C++ library for parsing configuration files)

You will also need a system that has support for kqueue (*BSD or Mac OS X)


Compiling
---------
To compile it just run make, if you have a ny trouble you might need to
the include and library paths specified within the Makefile


Indexing data
-------------
The logdcollectd command reads log data from standard input, 
in order to make it start indexing, just pass some log data
via a pipe into logcollectd and it will index using the rules
specified in the command line arguments.


Usage: logcollectd -f <format> -i <index> -r <rules>  
  
   -r format rule file location  
   -c config file location
   -i index location 
   -f format to match data against  
  

Searching data
--------------
Simply add a alias to the www folder form you webserver and
access the test.php file and start searching. the query format
must conform the the standard lucene query syntax

http://lucene.apache.org/core/3_6_2/queryparsersyntax.html


Searching can also be done from the command line, however
the search tool returns json, and can be called using the
following arguments.

Usage: search -f &gt;format> -i <index> -r <rules>  
  
   -i Index location  
   -f Default search field field  
   -q Lucene query string  



