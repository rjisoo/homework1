/*
CS325 - Homework 1 - 4
The program reads input values from data.txt
and sort the data using merge sort
*/

// headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int *arr, int, int, int);
void merge(int *arr, int, int, int, int);

int main() {
  FILE *filePointer;
  FILE *fileOutPointer;
	int size = 0;
	int index = 0;

  // temp array to hole values from the file
	char temp[50];

  // count valid rows in file
	filePointer = fopen("data.txt", "r");
  // create new files
	fileOutPointer = fopen("merge.out", "a");
	while (fgets(temp, 2147483647, filePointer) != NULL) {
		int value = atoi(temp);
		if (value > 0) {
			index++;
    }
	}
	fclose(filePointer);
	filePointer = fopen("data.txt", "r");
	while (index != 0) {
    // count new line and assigne counts to size var
    fscanf(filePointer, "%d ", &size);

    // create array according to the size value
		int *line = malloc(size * sizeof(int));
		memset(line, 0, size * sizeof(int));
    for (int i = 0; i < size; i++) {
      fscanf(filePointer, "%d ", &line[i]);
    }

    mergeSort(line, 0, (size - 1), size);

    // print out to file
    int sizeIndex = 0;
    fileOutPointer = fopen("merge.out", "a");
    while (sizeIndex < size) {
      fprintf(fileOutPointer, "%d ", line[sizeIndex++]);
    }
    fprintf(fileOutPointer, "\n");

    // decrease index and free memory
		index--;
		free(line);
	}

  // close files
	fclose(filePointer);
  fclose(fileOutPointer);

  return 0;
}

/*
split the array, and recursively operate mergeSort
for smaller partial of the array
*/
void mergeSort(int *line, int low, int high, int size) {
  // if more than two element, split it
	if (low < high)	{
		int mid = (low + high) / 2;
		mergeSort(line, low, mid, size);
		mergeSort(line, (mid + 1), high, size);
		merge(line, low, mid, high, size);
	}
}

/*
merge back two given arrays to one array
*/
void merge(int *line, int low, int split, int high, int size)
{
	int *temp = malloc(size * sizeof(int));
	int left = low;
	int right = split+1;
	int i = 0;

	while (left <= split && right <= high) {
		if (line[left] < line[right]) {
      // switch the temp value to the left one when smaller
			temp[i] = line[left];
			i++;
			left++;
		} else {
      // switch the temp value to the right one when smaller
			temp[i] = line[right];
			i++;
			right++;
		}
	}

  // check through left side of the array
	while (left <= split) {
		temp[i] = line[left];
		i++;
		left++;
	}

  // check through right side of the array
	while (right <= high) {
		temp[i] = line[right];
		i++;
		right++;
	}

	while (--i >= 0) {
		line[low + i] = temp[i];
		i--;
	}

	free(temp);
}
