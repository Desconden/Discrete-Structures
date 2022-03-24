#include <iostream>
#include <ctime> // for random value
#include <cstdlib> // for random value
#define SIZE 1000
using namespace std;

int arr[2000];
int unarr[SIZE];

void sortedArray_generator() {
	for (int i = 0; i < 2000; i++) 
		arr[i] = i + 1;
}
void unsortedArray_generator() {
	for (int i = 0; i < SIZE; i++) 
		unarr[i] = rand() % 1000;
}
int binarySearch(int number, int size) {
	// I implemented the loop that was on the annoucments.
	int first = 0, last = size - 1, comparisons = 0, mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (arr[mid] == number) {
			comparisons++;
			cout << "\nItem found at " << arr[mid] << "\nNumber of comparisons = " << comparisons;
			return 0;      // If it found the number that we were looking for it return 0 and exits function.
		}
		else if (arr[mid] > number) {
			last = mid - 1;
			comparisons++;
		}
		else {
			first = mid + 1;
			comparisons++;
		}
	}
	cout << "\n" << number << " is not in the list." << "\nNumber of comparisons = " << comparisons;
}
int sequntialSearch(int number, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			cout << "\nItem found at position " << i + 1 << "\n" << "Number of comparisons = " << i + 2;
			// i + 1 because array starts from 0. i + 2 is because first reason and + 1 for the last comparison. 
			return 0; 
		} //It quits the loop by returning if the number is found.
	}
		cout << "\n" << number << " is not in the list." << "\nNumber of comparisons = " << size;                                         
		return 0; // If it cannot be found total number of comparison will be the size of the array.
}
void Unsorted_bubbleSort() {
	int temp, comparisons = 0; // There is temp for replacing the values and comparison for count.
	for (int i = 0; i < SIZE - 1; i++) {
		//Ever time the main loop end last part of the loop is fixed as much as we progress(i++) so we don't need to check that parts thats why it is "SIZE - i"
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (unarr[j] > unarr[j + 1]) { // if arr[j] is bigger than the next one that change places.
				temp = unarr[j];
				unarr[j] = unarr[j + 1];
				unarr[j + 1] = temp;
			}
			comparisons++; //for every comprasion +1
		}
	}
	cout << "\nBubble Sort # of Comparisons : " << comparisons;
}
void Unsorted_insertionSort() {
	// I implemented the loop that was given on the assigment.
	int comparision = 0, j;
	for (int i = 2; i < SIZE; i++) {
		int key = unarr[i];
		j = i - 1;
		while (i >= 0 && unarr[j] > key) {
			unarr[j + 1] = unarr[j];
			j = j - 1;
			unarr[j + 1] = key;
			comparision++;
		}
		comparision++;
	}
	cout << "\nInsertion Sort # of Comparisons : " << comparision;
}
void Sorted_bubbleSort() { //Same with the Unsorted_bubbleSort I just replaced the array's.
	int temp, comparisons = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			comparisons++;
		}
	}
	cout << "\nBubble Sort # of Comparisons : " << comparisons;
}
void Sorted_insertionSort() {
	// I implemented the loop that was given on the assigment.
	int comparision = 0, j;
	for (int i = 1; i < SIZE; i++) {
		int key = arr[i];
		j = i - 1;
		while (i >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
			arr[j + 1] = key;
			comparision++;
		}
		comparision++;
	}
	cout << "\nInsertion Sort # of Comparisons : " << comparision;
}
int main() {
	srand((unsigned)time(0)); // for the random value if I don't add this the random value always will be the same.
	int size, number;
	sortedArray_generator();
	unsortedArray_generator(); //Calling generators for the array
	cout << " Q1 - 1 Number of Comparions for Searching Algorithms\n" << " Size of the sorted Array > ";
	cin >> size;
	cout << "\n Enter a number to search: ";
	cin >> number;

	cout << "\n\n*****Binary Search*****\n";
	binarySearch(number, size);

	cout << "\n\n*****Sequential Search*****\n";
	sequntialSearch(number, size);

	cout << "\n\n\nQ2 - Number of Comparisons on Sorted ( in Ascending Order ) Arrays\nSIZE: 1000\n";
	Sorted_bubbleSort();
	Sorted_insertionSort();

	cout << "\n\n\nQ2 - Number of Comparisons on Randomly Generated (Unsorted) Arrays\nSIZE: 1000\n";
	Unsorted_bubbleSort();
	unsortedArray_generator(); // I called the generator since the bubblesort organized the array.
	Unsorted_insertionSort();
}
