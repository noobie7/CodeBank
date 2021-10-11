/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    map<int, map<int, int>> g;
    priority_queue<pair<ll, pair<ll,ll>>> q;
    for(ll i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a][b] = c;
        g[b][a] = c;
        q.push({-c,{a,b}});
    }
    vector<list<ll>> idx(n);
    for(ll i = 0; i < n; i++){
        idx[i].push_back(i);
    }
    ll ans = 0;
    vector<ll> leader(n);
    iota(all(leader), 0);
    while(!q.empty()){
        auto u = q.top();
        q.pop();
        ll w = u.ff;
        ll a = u.ss.ff;
        ll b = u.ss.ss;
        a = leader[a];
        b = leader[b];
        if(w >= 0){
            if(a != b){
                if(idx[a].size() > idx[b].size()){
                    swap(a, b);
                }
                for(ll i : idx[a]){
                    idx[b].push_back(i);
                    leader[i] = b;
                }
            }
            continue;
        }
        if(a != b){
            if(idx[a].size() > idx[b].size()){
                swap(a, b);
            }
            for(ll i : idx[a]){
                idx[b].push_back(i);
                leader[i] = b;
            }
        }
        else{
            ans -= (w);
        }
    }
    cout << ans << endl;
    return 0;
}