/*
CS325 - Homework 1 - 4
The program reads input values from data.txt
and sort the data using insert sort
*/

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int *line, int);

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
	fileOutPointer = fopen("insert.out", "a");

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
		int i;
    for (i = 0; i < size; i++) {
      fscanf(filePointer, "%d ", &line[i]);
    }

		insertionSort(line, size);

    // print out to file
    int sizeIndex = 0;
    fileOutPointer = fopen("insert.out", "a");
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
compare the tempvalue to all previous elements,
and repeat until go through the entire array
*/

void insertionSort(int *line, int size) {
	int marker;
	int tempVal;

	int insertIndex;
	for (insertIndex = 1; insertIndex < size; insertIndex++)
	{
		tempVal = line[insertIndex];
		marker = insertIndex - 1;

    // swap the value and decrease the marker value
		while (marker >= 0 && line[marker] > tempVal) {
			line[marker + 1] = line[marker];
			marker = marker - 1;
		}

		line[marker + 1] = tempVal;
	}
}
