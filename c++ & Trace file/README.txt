1. main.cpp is the client code that will generate the simulation result from the given file. To use this program, all you need to do is to change 
   the file name in line 35. For now, the file name is "blocksize.trace" which is the second trace file. After changing the file name to the one
   that you want to process, compile and run the program. The result file will be placed in to the same folder as the main.cpp with the same file 
   name except that the postfix will be set to ".result". For example, if your input file name is "test1.trace", the output file will be "test1.result".
2. Cache.h and Cache.cpp is a class that will do the calculation for hit time, bytes from memory to cache and bytes from cache to memory. User do not 
   need to worry about these two file.