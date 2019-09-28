    #include <bits/stdc++.h>
    using namespace std;
    const int s = 100001;
    vector<int> adj[s];
    vector<bool> visited(s, false);
     
    int dfs(int source)
    {
        visited[source] = true;
        int sol = 1;
        for (auto child : adj[source])
        {
            if (visited[child] == false)
            {
                sol += dfs(child);
            }
        }
        return sol;
    }
     
    int main()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int gaitonde = dfs(1);
        bool solution = true;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                int gang_count = dfs(i);
                if (gang_count >= gaitonde)
                {
                    solution = false;
                }
            }
        }
        if (solution)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        return 0;
    } 
