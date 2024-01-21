#include <iostream>
using namespace std;

const int CHAR_COUNT = 256; // Assuming ASCII characters
void countCharacters(string &str)
{

    int charFrequency[CHAR_COUNT] = {0};

    for (char ch : str)
    {
        // Increment the count for the current character
        charFrequency[(ch)]++;
    }

    // Display the character count
    for (int i = 0; i < CHAR_COUNT; ++i)
    {
        if (charFrequency[i] > 0)
        {
            cout << char(i) << ": " << charFrequency[i] << endl;
        }
    }
}

int main()
{

    string inputString;

    // Get input string
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Count and display character occurrences
    countCharacters(inputString);

    return 0;
}
