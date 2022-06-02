#include <iostream>
#include <utility>

void heapify(int arr[], int number, int i)
{
	int biggest = i; 
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	if (left < number && arr[left] > arr[biggest])
		biggest = left;

	if (right < number && arr[right] > arr[biggest])
		biggest = right;

	if (biggest != i) {
		std::swap(arr[i], arr[biggest]);

		heapify(arr, number, biggest);
	}
}

void heap_sort(int arr[], int number)
{
	for (int i = number / 2 - 1; i >= 0; i--)
		heapify(arr, number, i);

	for (int i = number - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void print_array(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	    std::cout << arr[i] << " ";

}

int main()
{
	int arr[] = { 12, 11, 13,8,77,854,18,78,5,2,368,1,12,1,21,3,9,33,9,92,5,77,4,23,9,28,6, 5, 6, 7 };
	int number = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, number);
	std::cout << "Heap sort  element is "<<std::endl;
	print_array(arr, number);
}

