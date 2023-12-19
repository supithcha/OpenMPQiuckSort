// Group Assignment: OpenMP Quick Sort
// Miss Supithcha    	Jongphoemwatthanaphon  		6488045
// Miss  Sasasuang  	Pattanakitjaroenchai        6488052
// Miss  Nisakorn 	    Ngaosri                     6488226

#include <stdio.h>
#include <omp.h>
// #include "/usr/local/opt/libomp/include/omp.h"
#include <math.h>
#include <stdlib.h>
#include <time.h> 

#define ARRAY_SIZE 2000000
#define RANGE 100000       // Range of random numbers (0 to 99999)
int arr[ARRAY_SIZE];       // Declare an array to store the random numbers

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// [Partition] --> Perform partitioning
int partition(int arr[], int low, int high, int pivotIndex) {
    int pivot = arr[pivotIndex];
    int i = low - 1;
    swap(&arr[pivotIndex], &arr[high]); // Swap the pivot to the end of the subarray
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// [Insertion Sort]
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// [Quicksort (left)] reference: https://github.com/koszio/QuickSort-with-OpenMP/blob/master/quickSortOpenMP.c
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high, low); // Use arr[low] as the pivot
        if (high - low > 1000) { // Parallelize only if the size of the array is large enough
			// The number of compute nodes (MPI) or the number of threads (OpenMP) is varied from 1, 4, 8, 12 and 16.
            #pragma omp parallel sections num_threads(8) // Specify the number of threads here
            {
                #pragma omp section
                quickSort(arr, low, pi - 1); // Recurse on the left partition
                #pragma omp section
                quickSort(arr, pi + 1, high); // Recurse on the right partition
            }
        } else { // [Threshold Check] --> Check if threshold reached
            insertionSort(arr, low, high); // [Insertion Sort] --> Apply insertion sort
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	srand(time(NULL));
	// Generate a random number between 0 and RANGE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % (RANGE + 1); 
    }
    printf("Random numbers: ");
    int countnum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
        countnum ++;
    }
    printf("\nTotal numbers: %d\n", countnum);

    // [Start Timing] --> Record start time
	double start_time, run_time;
	start_time = omp_get_wtime();

    // [Parallel Section] --> Begin parallel sorting
	#pragma omp parallel 
	{
        #pragma omp single nowait
        quickSort(arr, 0, ARRAY_SIZE - 1);
    }
	
    // [End Timing] --> Record end time
	run_time = omp_get_wtime() - start_time;
	
    // [Print Sorted Array]
	printf("Sorted array: ");
	printArray(arr, ARRAY_SIZE);
    // [Print Execution Time]
	printf("Execution time was %lf seconds\n ", run_time);
	return 0;
}