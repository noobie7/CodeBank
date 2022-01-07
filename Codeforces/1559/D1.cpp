/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ff first
#define Shazam                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ss second
#define all(c) c.begin(), c.end()
#define endl "\n"
#define test() \
    int t;     \
    cin >> t;  \
    while (t--)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define get(a) fl(i, 0, a.size()) cin >> a[i];
#define pra(a)                              \
    fl(i, 0, a.size()) cout << a[i] << " "; \
    cout << endl;
#define pr(a, n)                     \
    fl(i, 0, n) cout << a[i] << " "; \
    cout << endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

int main()
{
    Shazam;
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<list<int>> xlist(n), ylist(n);
    vector<int> xlead(n), ylead(n);
    iota(all(xlead), 0);
    iota(all(ylead), 0);
    for (int i = 0; i < n; i++)
    {
        xlist[i].push_back(i);
        ylist[i].push_back(i);
    }

    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = xlead[a];
        b = xlead[b];
        if (xlist[a].size() > xlist[b].size())
            swap(a, b);
        for (int i : xlist[a])
        {
            xlead[i] = b;
            xlist[b].push_back(i);
        }
    }
    for (int i = 0; i < y; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        a = ylead[a];
        b = ylead[b];
        if (ylist[a].size() > ylist[b].size())
            swap(a, b);
        for (int i : ylist[a])
        {
            ylead[i] = b;
            ylist[b].push_back(i);
        }
    }
    vector<pair<int, int>> ans;
    set<pair<int, int>> xgot, ygot;
    
    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            int oa = a;
            int ob = b;
            if (xlead[a] != xlead[b] && ylead[a] != ylead[b])
            {
                ans.push_back({a + 1, b + 1});
                a = ylead[oa];
                b = ylead[ob];
                if (ylist[a].size() > ylist[b].size())
                    swap(a, b);
                for (int i : ylist[a])
                {
                    ylead[i] = b;
                    ylist[b].push_back(i);
                }
                a = oa;
                b = ob;
                a = xlead[a];
                b = xlead[b];
                if (xlist[a].size() > xlist[b].size())
                    swap(a, b);
                for (int i : xlist[a])
                {
                    xlead[i] = b;
                    xlist[b].push_back(i);
                }
            }
            a = oa;
            b = ob;
        }
    }
    cout << ans.size() << endl;
    for (auto pp : ans)
    {
        cout << pp.ff << " " << pp.ss << endl;
    }
    return 0;
}