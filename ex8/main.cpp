#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to swap two digits in a number
void swapDigit(string &num, int i, int j)
{
    char temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

// Function to find the largest number possible from M, by making at most K digit swaps
string findLargestNumber(string num, int k)
{
    int n = num.size();
    // Make at most K digit swaps to find the largest number
    for (int i = 0; i < n && k > 0; i++)
    {
        int posMax = i;
        // Find the position of the largest digit from position i
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] >= num[posMax])
            {
                posMax = j;
            }
        }
        // If the maximum digit found is in a different position than i, swap it
        if (posMax != i)
        {
            swapDigit(num, i, posMax);
            k--;
        }
    }
    return num;
}

int main()
{
    string num;
    int k;
    while (cin >> num >> k)
    {
        string largestNum = findLargestNumber(num, k);
        cout << largestNum << endl;
    }
    return 0;
}