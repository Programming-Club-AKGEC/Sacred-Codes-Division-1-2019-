#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int moves = 0;
    if (a.size() != b.size())
    {
        int mn = min(a.size(), b.size());
        moves += a.size() - mn;
        moves += b.size() - mn;
        a = a.substr(a.size() - mn);
        b = b.substr(b.size() - mn);
    }
    int i = a.size() - 1;
    while (i >= 0)
    {
        if (a[i] != b[i])
        {
            break;
        }
        i--;
    }
    cout << moves + 2 * (i + 1);
    return 0;
}
