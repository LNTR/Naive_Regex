#include <iostream>
#include <string>
#include <vector>

using namespace std;

string pattern = "ababaca";

string text = "bacbababaabcbab";

int prefixFuncton[7];

void initializePrefixFunction()
{
    prefixFuncton[0] = 0;

    int k = 0;

    for (int q = 1; q < pattern.length(); q++)
    {
        while ((k > 0) && (pattern[k] != pattern[q]))
        {
            k = prefixFuncton[k];
        }

        if (pattern[k] == pattern[q])
        {
            k++;
        }
        prefixFuncton[q] = k;
    }
}

main(int, char **)
{
    initializePrefixFunction();
    for (auto value : prefixFuncton)
    {
        cout << value << "\n";
    }
}
