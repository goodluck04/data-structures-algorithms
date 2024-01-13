#include <iostream>
using namespace std;


// linear search in n(1) time & n(1) space 
int linearSearch(int arr[], int n, int key){

    for(int i = 0; i < n; i++){
        if(arr[i] == key) return arr[i];
    }

    return -1;
}



int main(){ 

    int arr[] = {1,3,2,4,6,7,8,9,5,12,32,12};
    int key;
    int n = sizeof(arr) / sizeof(arr[0]);

    // key to search
    cout << "Enter your number to search in array : ";
    cin>>key;

    int search = linearSearch(arr,n, key);

    if(search == -1){
        cout << "Element not Found!" << endl;
    }
    else {
        cout << "Element at index: " << search << endl;
    }

    return 0;
}