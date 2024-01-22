#include <iostream>
#include <algorithm>
using namespace std;


// this is brute force aproach using 2N time and N space 
bool isPalindrome1(string &s){
    // create a string 
    string rev = s;
    // now reverse this rev 
    reverse(rev.begin(), rev.end());

    // check if s and rev are equal then return true
    if(rev == s){
        return true;
    }

    // else return false
    return false;
}

// this is optimised approach using N time and 1 space 
bool isPalindrome2(string &s){
    int start = 0;
    int end = s.length() - 1;
    // compare first element with last element of string  and so on second first with second last
    while(start <= end){
        if(s[start] != s[end]){
            // if any comparison is false it will return false
            return false;
        }
        start++;
        end--;
    }
    return true;
    // if all comparison successful then return true
}



int main(){


    string string;



    cout << "Enter a string: ";
    getline(cin, string);
    // example- abba, aaaa, a

    // if (isPalindrome1(string) == true){
    //     cout << "Its palindrome!" << endl;
    // }
    // else{
    //     cout << "Its not palindrome!" << endl;

    // }
    if (isPalindrome2(string) == true){
        cout << "Its palindrome!" << endl;
    }
    else{
        cout << "Its not palindrome!" << endl;

    }

}