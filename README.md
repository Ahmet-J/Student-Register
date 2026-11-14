# Student Result Register

This is my C++ coursework project for keeping student results. A student record has a registration number, name, course and mark.
The program stores the records in a dynamic array. The array can increase its capacity when more students are added. The array code is in ResultArray.h, and the sorting code is in Sorts.h.

Files in the projects CW1
|-- main.cpp
|-- ResultArray.h
|-- Sorts.h
|-- results.txt
|-- test.cpp
|-- timing.cpp
|-- timing.csv
|-- README.md

Compile and run
Open the terminal in the CW1 folder
Compile the main program
open your terminal then write (g++ main.cpp -o main), then click  write  (main.exe)


Run the tests
Compile the test file
write in your terminal (g++ test.cpp -o test) then write (test.exe)
The tests check different situations, including an empty array, adding and removing records, increasing the capacity, invalid positions, sorting, searching and copying the array.


Run the timing program
Compile the timing file
write in your terminal (g++ timing.cpp -o timing) then write (timing.exe)
The program measures the time taken by the sorting algorithms. The results are saved in timing.csv.
