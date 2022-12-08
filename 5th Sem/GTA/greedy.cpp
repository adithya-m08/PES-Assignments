#include <bits/stdc++.h>

using namespace std;

int main()
{
    clock_t start, end;

    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(n, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> color(n, -1);
    int c = 0;
    start = clock();
    while (true)
    {
        unordered_set<int> neigh;
        for (int i = 0; i < n; i++)
        {
            if (neigh.find(i) == neigh.end() && color[i] == -1)
            {
                color[i] = c;
                for (auto &x : v[i])
                    neigh.insert(x);
            }
        }
        c++;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
                flag = 1;
        }
        if (!flag)
            break;
    }
    end = clock();
    cout << "Colors: " << c << endl;
    cout << "Time: " << (float)(end - start) / CLOCKS_PER_SEC << 's' << endl;
    return 0;
}