// Heap Sort in C++

#include <iostream>
#include <fstream>

using namespace std;

// Function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  // Find largest among root, left child and right child
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
  }
}

// Print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver code
int main() {

  ifstream inFile("heap_sort_data.txt");
  if (!inFile) {
    cerr << "Error opening file" << endl;
    return 1;
  }

  const int numValues = 10000000;
  int *arr = new int[numValues];
  int val;

  // Read values from first row into arr array
  for (int i = 0; i < numValues; i++) {
    inFile >> val;
    arr[i] = val;
  }

  inFile.close();

  int n = numValues;

  heapSort(arr, n);

  cout << "Sorted" << endl;

  delete[] arr;

  return 0;
}
