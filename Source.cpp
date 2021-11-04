#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>
#include<array>

double median(int *array, int size);

int main() {
	srand(time(NULL));
	int arr[10];
	int arr2[15];
	int arrSize = *(&arr + 1) - arr; //take the memory address of the end of arr, then subtracts the beginning, to get the length.
	int arr2Size = *(&arr2 + 1) - arr2;
	for (int i = 0; i < arrSize; i++) {
		arr[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < arr2Size; i++) {
		arr2[i] = rand() % 100 + 1;
	}
	std::sort(arr, arr + arrSize);
	std::sort(arr2, arr2 + arr2Size);
	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
	for (int i = 0; i < arr2Size; i++) {
		std::cout << arr2[i] << ", ";
	}
	std::cout << std::endl;
	std::cout << median(arr, arrSize) << "\n";
	std::cout << median(arr2, arr2Size) << "\n";
}

double median(int *array, int size) {
	double median;
	int midpoint = size / 2;
	if (size % 2 == 0) {
		//std::cout << *(array + midpoint) + *(array + midpoint - 1) << "\n";
		median = (double(*(array + midpoint)) + double(*(array + midpoint - 1))) / 2;
	}
	else
		median = *(array + midpoint);

	return median;
}