/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;


int main(){
    Shazam;
    test(){
        int n, m; cin >> n >> m;
        vector<long double> a(n), b(n);
        vector<pair<long double, int>> info(n);
        get(a);
        get(b);
        vector<long double> data(n);
        for(int i = 0; i < n; i++){
            info[i] = {a[i]/b[i], i};
            data[i] = a[i] / b[i];
        }
        sort(all(info));
        vector<set<int>> g(n);
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            x--;
            y--;
            g[x].insert(y);
            g[y].insert(x);
        }
        int ans = 0;
        vector<int> f;
        long double mx = info.back().ff;
        while(info.size() && info.back().ff == mx){
            int id = info.back().ss;
            int curr = 0;
            vector<int> l;
            l.push_back(id + 1);
            for(auto pp : g[id]){
                curr += (data[pp] == mx);
                if(data[pp] == mx){
                    l.push_back(pp + 1);
                }
            }
            ans = max(curr + 1, ans);
            if(ans = curr + 1){
                f = l;
            }
            info.pop_back();
        }
        cout << ans << endl;
        pra(f);
    }
    return 0;
}