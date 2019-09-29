#include <bits/stdc++.h>
using namespace std;

// Include necessary libraries for Policy Based Data Structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Invoke namespace
using namespace __gnu_pbds;

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> st; 

int main()
{
    const int s = 100001;
    long long d[s];
    memset(d, 0, sizeof(d));
    for(int i = 1;i < s;i++)
    {
        for(int j = i;j < s;j += i)
        {
            d[j]++;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t, a;
        cin >> t >> a;
        if(t == 1)
        {
            st.insert(pair<int, int>(a, q));
        }
        else
        {
            auto x = st.find_by_order(a - 1);
            cout << d[(*x).first] << endl;
            st.erase(x);
        }
    }
    return 0;
}

