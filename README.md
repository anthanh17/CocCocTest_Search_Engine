# Problem:
- Give a directory that have hundreds of files, please write a program that print all the files that
contain a list of words. 
- The words do not need to appear in any particular order, but they
must be complete words. 
- That is, "book" does not match "bookkeeper."

## For example:
`books` appears in file2 and file3, `many` appears in file3 and file4.
- If you search `books`, the program will print:
```
file2
file3
```
- If you search `many books`, the program will print:
```
file3
```
> Please note that directory can have subdirectories, you must find in the subdirectories too.

# Requirements
- [x] Programming language: C++
- [x] OS: Windows, OS X or Linux
- [x] Design program in Object-Oriented
## How to run ##
```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ coccoc “many words” [path to directory]
```
- Ex: coccoc “This article is about the concept of” ../test