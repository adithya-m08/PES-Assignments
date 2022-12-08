#include <bits/stdc++.h>
using namespace std;

int cmp(pair<int, vector<int>> a, pair<int, vector<int>> b)
{
    return a.second.size() > b.second.size();
}

int main()
{
    clock_t start, end;

    int n, e;
    cin >> n >> e;
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
        v[i].first = i;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].second.push_back(b);
        v[b].second.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> color(n, -1);
    int c = 0;
    start = clock();

    while (true)
    {
        unordered_set<int> neigh;
        for (int i = 0; i < n; i++)
        {
            if (neigh.find(v[i].first) == neigh.end() && color[v[i].first] == -1)
            {
                color[v[i].first] = c;
                for (auto &x : v[i].second)
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
    cout << "Number of colors " << c << endl;
    cout << "Time " << (float)(end - start) / CLOCKS_PER_SEC;
    return 0;
}