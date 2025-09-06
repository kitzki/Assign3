# Word Count Project

## Overview
This project focused on building a word-count utility in C, reinforcing concepts in linked lists, dynamic memory, and basic systems programming. It emphasized development workflow, debugging, and multi-file program organization.

## Tools Learned
- **gcc**: Compiling multi-file C programs with debugging symbols  
- **make**: Automating compilation and linking with Makefiles  
- **gdb**: Debugging program execution, inspecting variables, and analyzing stack frames  
- **vim**: Efficient command-line code editing  
- **valgrind**: Detecting memory leaks and tracking dynamic memory usage  

## Core Tasks
### Word Count Implementation
Developed a utility that:
- Reads text from files or standard input  
- Counts lines, words, and characters  
- Tracks frequency of each word using a linked list  
- Sorts words by count or alphabetically using a comparator  
- Prints results to the console  

### System Analysis
- **Debugging with gdb**:  
  - Loaded programs with command-line arguments  
  - Set breakpoints and inspected the stack, function arguments, and local variables  
- **Memory management**:  
  - Implemented dynamic allocation for word storage  
  - Managed linked lists and ensured proper memory deallocation  

## Key Challenges
- **Linker errors** due to missing function implementations (`wordcount_sort`)  
- **Multiple definitions of `main`** across different files  
- **Unused parameter warnings** cluttering compilation  
- **Incomplete helper functions** like `add_word`, `find_word`, and `len_words` requiring proper implementation  

## Insights Gained
This project provided practical experience with:
- Dynamic data structures (linked lists) for counting and sorting  
- File I/O handling and standard input processing  
- Writing modular C programs with multiple source files  
- Debugging and linking in a multi-file C project  
- Sorting and frequency analysis using custom comparators  

