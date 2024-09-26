#include <iostream>

using namespace std;

int main ()
{
    int i = 32; 
    int j = 20;  // Initialize j to a non-zero value (e.g., 20)
    int k, l, m;

    k = i / j;          // Safe division
    l = i & j;          // Bitwise AND
    m = k ^ l;          // Bitwise XOR

    printf("%d, %d, %d, %d, %d\n", i, j, k, l, m); // C-style output
    // Alternatively, you could use:
    // cout << i << ", " << j << ", " << k << ", " << l << ", " << m << endl;

    return 0;
}
//32, 20, 1, 0, 1
