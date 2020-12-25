#include"Algorithms.h"

int BinarySearsh(int* array, int size, int search) {
	int middle = size / 2,
		left = 0,
		right = size - 1;
 	while (left <= right) {
		if (array[middle] < search) {
			left = middle + 1;
			middle = (right + left) / 2;
		}
		if (array[middle] > search) {
			right = middle - 1;
			middle = (right + left) / 2;
		}
		if (array[middle] == search) {
			return middle;
			break;
		}
	}
	if (left > right) return -1;
}

void quickSort(int* array, int left, int right) {
	int pivot = array[(right + left) / 2];
	int i = left, j = right;
	do
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j) 
		{
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);
	if (i < right) 
		quickSort(array, i, right);
	if (j > left)
		quickSort(array, left, j);
}

void QuickSort(int* array, int size) {
	quickSort(array, 0, size - 1);
}

void InsertionSort(int* array, int size)
{
	int i, j, key = 0, temp = 0;
	for (i = 0; i < size - 1; i++)
	{	
		key = i + 1;
		temp = array[key];
		for (j = i + 1; j > 0; j--)
		{
			if (temp < array[j - 1])
			{
				array[j] = array[j - 1];
				key = j - 1;
			}
		}
		array[key] = temp;
	}
}

	int correct(int* array, int size)
	{
		while (--size > 0)
			if (array[size - 1] > array[size])
				return 0;
		return 1;
	}

	void shuffle(int* array, int size)
	{
		int i;
		for (i = 0; i < size; ++i)
		{
			int next = (rand() % size);
			int temp = array[i];
			array[i] = array[next];
			array[next] = temp;
		}
	}

	void BogoSort(int* array, int size) 
	{
		while (!correct(array, size))
			shuffle(array, size);
	}

void CountingSort(char* array, int size) 
{
	unsigned int max = array[0], min = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] > max) max = array[i];
		if (array[i] < min) min = array[i];
	}
	unsigned int rasn = max - min;
	unsigned int* count = new unsigned[rasn + 1];
	for (int i = 0; i < rasn + 1; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		count[(int)array[i] - min] ++;
	}
	int counter = 0;
	if (count) {
		for (int i = 0; i < rasn + 1; i++) {
			for (unsigned j = 0; j < count[i]; j++) {
				array[counter] = (char)i + min;
				counter++;
			}
		}
	}
}