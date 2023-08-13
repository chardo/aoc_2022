# Advent of Code 2022

Been meaning to get some practical C under my belt, so decided to work through
at least a few [AOC](https://adventofcode.com/) problems using C.

Each directory is a separate day's solutions, organized in the following way:
 - `p1.c` and `p2.c` contain source code for programs that solve parts 1 
 and 2 of that day's problems
 - `p1` and `p2` are executable programs that solve the problems in question
 - `input.txt` contains the problem's input
 - when applicable, other `.txt` files contain test/debugging input

Programs generally read from stdin and write to stdout, so solutions can be 
discovered with commands like:
```bash
cat input.txt | ./p1
```

or 

```bash
echo "...test input..." | ./p2
```

In most cases, programs will simply output the computed answer. In some cases, 
they may also output some additional debugging info, though I try to remember
to at least comment that out when possible.

Solutions are written with _extremely_ narrow problem interpretations, and are
not generalizable at all. If the input only contains lower-case alphabetical
chars, the program will likely not know how to read upper-case alphabetical 
chars or numbers.
