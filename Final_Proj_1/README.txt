
 
Names: Kylee Webb, Martin Phillip
 
Class Account Usernames: cssc2159, cssc2126
 
Class Information: CS 570, Summer 2020
 
Assignment Information: Assignment #1, Semaphores
 
Filename of this file: README.txt
 
 
File Manifest: bots.cpp bots.h README.txt Makefile
 
Compile Instructions: navigate to the projects folder a1 and type make then hit enter
 
Operating Instructions: ./bots
 
List/description of novel/significant design decisions: We have one function outside of main called void *bot(void *t); and then everything else is written written within main().
 
List/description of any extra features/algorithms/functionality you included which were not required: Nothing extra 
 
List/description of all known deficiencies or bugs: There are no known bugs.
 
Lessons Learned: Make sure you understand semaphores before implementing it. Also make sure you stay aware which is set to 0 and 1. There is a critical sections where the threads
share the same code which it starts with setting the semaphore flag and ends with relasing the flag.  

