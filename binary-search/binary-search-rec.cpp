#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid; // return the index of the found element
        }
        else if (arr[mid] < key)
        {
            return binarySearchRecursive(arr, mid + 1, end, key);
        }
        else // arr[mid] > key
        {
            return binarySearchRecursive(arr, start, mid - 1, key);
        }
    }

    return -1; // return -1 if the key is not found
}


int binarySearchRec(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    return binarySearchRecursive(arr, start, end, key);
}

int main()
{

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter your number to search in array : ";
    cin >> key;

    int search = binarySearchRec(arr, n, key);
    // cout << " " << search << " ";

    if (search == -1)
    {
        cout << "Element not Found!" << endl;
    }
    else
    {
        cout << "Element at index: " << search << endl;
    }

    return 0;
}