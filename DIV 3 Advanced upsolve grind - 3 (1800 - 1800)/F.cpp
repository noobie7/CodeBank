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
    int n, q; cin >> n >> q;
    vector<array<int, 3>> ed(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> ed[i][1] >> ed[i][2] >> ed[i][0];
        ed[i][1]--;
        ed[i][2]--;
    }
    sort(all(ed));
    vector<pair<int,int>> query(q);
    for(int i = 0; i < q; i++){
        cin >> query[i].ff;
        query[i].ss = i;
    }
    sort(all(query));
    reverse(all(ed));
    vector<ll> ans(q);
    ll res = 0;
    vector<int> leader(n);
    vector<list<int>> idx(n);
    for(int i = 0; i < n; i++){
        idx[i].push_back(i);
        leader[i] = i;
    }
    auto calc  = [&](ll x){
        return ( x * (x - 1) )/ 2;
    };
    auto unite = [&](int a, int b){
        a = leader[a];
        b = leader[b];
        ll sx = idx[a].size();
        ll sy = idx[b].size();
        res += (calc(sx + sy) - calc(sx) - calc(sy));
        if(idx[a].size() > idx[b].size()) swap(a,b); // transfering a to b;
        for(int i : idx[a]){
            idx[b].push_back(i);
            leader[i] = b;
        }
    };
    for(auto pp : query){
        while(ed.size() && ed.back()[0] <= pp.ff){
            auto tp = ed.back();
            int a = tp[1];
            int b = tp[2];
            unite(a,b);
            ed.pop_back();
        }
        ans[pp.ss] = res;
    }
    pra(ans);
    return 0;
}