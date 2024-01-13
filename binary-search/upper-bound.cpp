#include <iostream>
using namespace std;

int upperBound(int arr[], int n, int key){
    int start = 0;
    int end = n -1;
    while(start<end){
        int mid=start + (end - start) / 2;
        
        if(arr[mid]<=key){
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }

    return start;
}

int main(){


    int arr[] = {1,2,3,4,5,6,6,7,7,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter your number to search in array : ";
    cin >> key;

    int search = upperBound(arr, n, key);
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