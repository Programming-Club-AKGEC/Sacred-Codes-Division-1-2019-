    #include <bits/stdc++.h>
    using namespace std;
     
    long long power(long long a, long long n)
    {
        if (n == 0)
            return 1ll;
        long long sol = 1ll;
        while (n)
        {
            if (n % 2)
            {
                sol *= a;
            }
            a *= a;
            n /= 2;
        }
        return sol;
    }
     
    int main()
    {
        int n, c, k;
        cin >> n >> c >> k;
        int mod = power(10, k);
        string s;
        cin >> s;
        long long dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 0ll;
            long long curr = 0ll;
            for (int j = i; j >= max(i - 11, 0); j--)
            {
                curr += (s[j] - '0') * power(10, i - j);
                if (curr == 0 and i - j > 0)
                {
                    continue;
                }
                if (i - j > 0 and s[j] == '0')
                {
                    continue;
                }
                if (curr <= c)
                {
                    if (j > 0)
                    {
                        dp[i] += dp[j - 1];
                    }
                    else
                    {
                        dp[i]++;
                    }
                    dp[i] %= mod;
                }
            }
        }
        cout << dp[n - 1];
        return 0;
    } 
