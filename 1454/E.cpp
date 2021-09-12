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
        int n; cin >> n;
        vector<set<int>> g(n);
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            x--;
            y--;
            g[x].insert(y);
            g[y].insert(x);
        }
        vector<ll> val(n,1LL);
        queue<int> leaf;
        for(int i = 0; i < n; i++){
            if(g[i].size() == 1){
                leaf.push(i);
            }
        }
        while(!leaf.empty()){
            int v = leaf.front();
            leaf.pop();
            int to = *g[v].begin();
            val[to] += val[v];
            val[v] = 0;
            g[v].clear();
            g[to].erase(v);
            if(g[to].size() == 1){
                leaf.push(to);
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += val[i] * ( val[i] - 1 ) / 2;
            ans += val[i] * ( n - val[i]);
        }
        cout << ans << endl;
    }
    return 0;
}