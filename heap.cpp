// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root; // initialize largest as root
    int left = 2 * root + 1; // index of left child
    int right = 2 * root + 2; // index of right child

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
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
    // Step 1: Build max heap using heapify function
    for (int k = n / 2 - 1; k >= 0; k--)
        heapify(arr, n, k);

    // Step 2: Extract elements from heap one by one
    int k = n - 1;
    while (k >= 0)
    {
        // Step 2a: Move current root to end
        swap(arr[0], arr[k]);

        // Step 2b: Call max heapify on the reduced heap
        heapify(arr, k, 0);

        // Step 2c: Decrement k to move to the next element
        k--;
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* heap_arr = new int[n];

    // get array elements from user or randomly generate them
    char choice;
    cout << "Do you want to enter array elements (Y/N)? ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++)
            cin >> heap_arr[i];
    }
    else
    {
        // generate random array elements
        srand(time(0));
        cout << "Random array elements: ";
        for (int i = 0; i < n; i++)
        {
            heap_arr[i] = rand() % 100; // generate random numbers between 0 and 99
            cout << heap_arr[i] << " ";
        }
        cout << "\n";
    }

    cout << "Input array: ";
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array: ";
    displayArray(heap_arr, n);

    // free dynamically allocated memory
    delete[] heap_arr;

    return 0;
}
