#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 70, e = 1000;
    cout << n << ' ' << e << endl;
    set<pair<int, int>> s;
    while (e)
    {
        int a = rand() % n;
        int b = rand() % n;
        if (a == b)
            continue;
        if (s.find({a, b}) == s.end())
        {
            s.insert({a, b});
            s.insert({b, a});
            cout << a << ' ' << b << endl;
            e--;
        }
    }
}