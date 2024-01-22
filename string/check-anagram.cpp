#include<iostream>
#include<algorithm>
using namespace std;

// it is brute force approach using sort both string and compare both
// time-nlogn and space 1

bool isAnagram1(string &s1, string &s2){
    // corner case if s1.lenth() != s2.length() return false
    if(s1.length() != s2.length()){
        return false;
    }

    // now sort both string
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // now return true if s1 and s2 are equal or false if not equal
    return (s1 == s2);

}

// this is optimsed approach using CHAR Array in  time -n and space-256 which is constant or 1
bool isAnagram2(string &s1, string &s2){
    if(s1.length() != s2.length()){
        return false;
    }

    const int CHAR = 256;
    // now create array of size 256 and initilized array with zero
    int count[CHAR]={0};

    for(int i = 0; i<s1.length(); i++){
        // increment and decrement the cout of char for both s1 and s2
        count[s1[i]]++;
        count[s2[i]]--;
    }

    // now if the count[CHAR]=[i]>0 then return false aor return true;
    for(int i = 0; i<CHAR;i++){
        if(count[i] != 0){
            return false;
        }
    }
    // if all the cout[CHAR]={0} then return false;
    return true;

}

int main(){

    string str1,str2;

    cout << "Enter first string: ";
    getline(cin,str1);
    cout << "Enter first string: ";
    getline(cin,str2);

    // if(isAnagram1(str1,str2) == true){
    //     cout << "They are Anagram!" << endl;
    // } else {
    //     cout << "They are not Anagram!" << endl;
    // }

    if(isAnagram2(str1,str2) == true){
        cout << "They are Anagram!" << endl;
    } else {
        cout << "They are not Anagram!" << endl;
    }

}