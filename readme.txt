Subject: ITCS443_Parallel and Distributed Systems
Group Assignment: OpenMP Quick Sort
Members: 
6488045 Supithcha Jongphoemwatthanaphon 
6488052 Sasasuang Pattanakitjaroenchai
6488226 Nisakorn Ngaosri  

# Objective
OpenMPQuickSort file is a parallel implementation program to quicksort the random integer numbers and measure the execution time for each data group and number of compute nodes.
The README file will guideline how to compile and run the OpenMPQuickSort file

Before running the program, ensure that your device has the following installed on your system:
1. GCC command with OpenMP support 
(If the error message 'gcc is not recognized as an internal or external command, operable program, or batch file', you must install GCC compiler to resolve this error.)
2. C/C++ file of source code
3. The command prompt

# This program does not implement the command to receive the input from the user so that it does not have any parameters to put in. 
You can adjust dataset sizes defined by '#define ARRAY_SIZE 2000000', where replace the 2000000 with your desired number of random numbers.
Moreover, to change the number of threads, locate the line '#pragma omp parallel sections num_threads(8)', where replace the 8 with your desired number of threads.


# Compilation and running
1. Download OpenMPQuickSort.c file into your device.
2. Open a terminal or command prompt.
3. Navigate the terminal to the directory where OpenMPQuickSort.c file is stored.
   - Using 'cd' command following with path to source code
   - E.g. cd C:\path\path\OpenMPQuickSort.c
4. Compile the program using this command.
   'gcc -o OpenMPQuickSort OpenMPQuickSort.c'
   or 'gcc -o OpenMPQuickSort OpenMPQuickSort.c -fopenmp' (If the terminal cannot link to the OpenMP library.)
5. After successful compilation, you can run the program using this command.
   './OpenMPQuickSort'
   - To capture the program's output effectively, we recommend redirecting the output to a text file using the following command: './OpenMPQuickSort > output.txt' 
   - This command allows you to review the output conveniently within a text file instead of the terminal, where large outputs may be challenging to inspect.
6. After that, the program will print the sorted array and the execution time to the terminal. 

