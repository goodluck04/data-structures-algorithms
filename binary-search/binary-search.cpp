#include <iostream>
using namespace std;



// time O(log n) 
int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return mid; // return the index of the found element
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else // arr[mid] > key
        {
            end = mid - 1;
        }
    }

    return -1; // return -1 if the key is not found
}

int main()
{

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter your number to search in array : ";
    cin >> key;

    int search = binarySearch(arr, n, key);
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