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
#define iii pair<pair<ll,ll>,ll> 
#define test() int t; cin>>t; while(t--)
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

vector<vector<pair<ll,ll>>> g(2e5 + 5);
priority_queue<pair<ll,ll>> pq;
vector<ll> subnodes(2e5 + 5);
map<iii,int> invedgeid;
vector<iii> edgeid(2e5 + 5);
map<int, ll> idval;
ll s;
ll dfs(int u, int p){
    ll sub = (g[u].size() == 1);
    for(auto pp : g[u]){
        if(pp.ff != p){
            ll sub1 = dfs(pp.ff,u);
            ll x = u;
            ll y = pp.ff;
            if(x > y){
                swap(x,y);
            }
            pq.push({ sub1 * pp.ss,invedgeid[{{x,y},pp.ss}]});
            s += sub1 * pp.ss;
            sub += sub1;
        }
    }
    return subnodes[u] = sub;
}
int main(){
    Shazam;
    test(){
        int n; cin >> n;
        ll lim; cin >> lim;
        while(!pq.empty()){
            pq.pop();
        }
        subnodes.clear();
        edgeid.clear();
        idval.clear();
        invedgeid.clear();
        for(int i = 0; i < n + 2; i++) {
            g[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            if(a > b) swap(a,b);  
            g[a].push_back({b,c});
            g[b].push_back({a,c});
            edgeid[i] = {{a,b},c};
            idval[i] = c;
            invedgeid[{{a,b}, c}] = i;
        }
        s = 0;
        dfs(1,0);
        int ans = 0;
        while(s > lim){
            auto tp = pq.top();
            int idx = tp.ss;
            ll netcost = tp.ff;
            pq.pop();
            ll edgecost = idval[idx];
            ll counter = netcost / edgecost;
            ll benifit = ( edgecost + 1 ) / 2  * counter;
            s -= benifit;
            idval[idx] /= 2;
            if(idval[idx])
                pq.push({counter * idval[idx], idx});
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}