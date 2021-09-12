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
    ll n; cin>>n;
    vector<ll> p(n-1);
    for(ll &i : p){
        cin>>i;
        --i;
    }
    vector<vector<ll>> g(n);
    for(ll i = 0 ;i < n-1; i++){
        g[p[i]].push_back(i + 1);
    }
    vector<ll> cnt(n);
    get(cnt);

    int s = 0;
    ll dis = cnt.front();
    ll ans = 0;
    while(true){
        vector<pair<ll,ll>> child;
        for(ll i : g[s]){
            child.push_back({cnt[i],i});
        }
        if(child.size()==0){
            ans = dis;
            break;
        }
        ll nc = (ll)child.size();
        vector<ll> can(nc);
        sort(all(child));
        ll mx = child.back().ff;
        for(int i = 0; i < nc-1; i++) dis -= min(dis, mx-child[i].ff);
        s = child.back().ss;
        dis = child.back().ff + (dis + nc -1)/nc;       
    }
    cout<<ans<<endl;
    return 0;
}