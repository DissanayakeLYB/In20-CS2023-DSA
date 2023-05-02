#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root; 
    int left = 2 * root + 1; // left child index
    int right = 2 * root + 2; // right child index
  
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
  
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // extracting elements from heap one by one
    for (int i=n-1; i>=0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);
  
        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
  
// main program
int main()
{
    int heap_arr[] = { 10, 8, 6, 4, 2, 0};
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    displayArray(heap_arr, n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);
  
    return 0;
}
