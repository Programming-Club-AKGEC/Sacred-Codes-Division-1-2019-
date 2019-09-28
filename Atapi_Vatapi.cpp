#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int s = 100001;
    const int MOD = 1000000007;
    long long fact[s];
    long long sol[s];

    // precompute the solution
    fact[1] = 1ll;
    for (int i = 2; i < s; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    sol[1] = 1;
    for (int i = 2; i < s; i++)
    {
        sol[i] = (fact[i] - sol[i - 1] + MOD) % MOD;
    }

    // output the solution
    int t;
    cin >> t;
    if(t > 20)
    {
        return 0;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << sol[n] << endl;
    }
    return 0;
}
