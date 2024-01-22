#include <iostream>
using namespace std;

// return most left repeating char index
// it is brute force approach using two for loop time- n*n

int leftMost(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                return i;
            }
        }
    }
    // if its not repeating then return false;
    return -1;
}

// optimized in time - n and const time -256
int leftMost2(string &s)
{
   const int CHAR= 256;
   int count[CHAR]={0};
   for(int i = 0; i<s.length();i++){
    count[s[i]]++;
   }

   for(int i = 0;i<CHAR;i++){
    if(count[s[i]]>1){
        return i;
    }
   }

   return -1;
}


int main()
{

    string s1;
    cout << "Enter a string: ";
    getline(cin, s1);

    // cout << leftMost(s1) << endl;
    cout << leftMost2(s1) << endl;
}