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
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 1; i <= m; i++){
        ll a, b, c; 
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
    }

    vector<int> ans;
    vector<double> d(n, -inf);
    vector<int> par(n, -1);
    auto ok = [&](double x){
        for(int i = 0; i < n; i++){
            par[i] = -1;
            d[i]   = -inf;
        }    
        d[0] = 0;
        priority_queue<pair<double,int>> q;
        q.push({0,0});
        while(!q.empty()){
            double dis = -q.top().ff;
            int u = q.top().ss;
            q.pop();
            if(d[u] != dis) continue;
            for(auto pp : g[u]){
                int v = pp.ff;
                double ap = pp.ss - x;
                if(d[v] <= dis - ap){
                    d[v] = dis - ap;
                    par[v] = u;
                    q.push({-d[v], v});
                }
            }
        }
        

        if(d[n - 1] >= 0.0){
            ans.clear();
            int curr = n - 1;
            while(par[curr] != -1){
                ans.push_back(curr + 1);
                curr = par[curr];
            }
            ans.push_back(1);
            reverse(all(ans));            
            return true;
        }
        return false;
    };

    auto bs = [&](double lo, double hi){
        while(hi - lo > 1e-5){
            double mid = lo + (hi - lo) / 2.0;
            if(ok(mid)) hi = mid;
            else        lo = mid;
        }

    };
    bs(-1e-5, 1e9 + 5);

    cout << ans.size() - 1 << endl;
    pra(ans);

    return 0;
}