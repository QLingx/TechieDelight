#include <iostream>
#include <bitset>
using namespace std;

// Function to generate binary numbers between 1 to n using bitset
int generate(int n)
{
    int i = 1;

    // run n times
    while (i <= n)
    {
        // convert i to 8-bit binary number
        bitset<8> binary(i);

        // print the current binary number
        cout << binary.to_string() << ' ';

        // move to next number
        i++;
    }
}

// main function
int main()
{
    int n = 16;
    generate(n);

    return 0;
}
