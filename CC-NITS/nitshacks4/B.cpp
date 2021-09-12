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
//#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> a(n , vector<ll> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    map<ll, int> rcnt, ccnt;
    for(int i = 0; i < n; i++){
        ll curr = 0;
        for(int j = 0; j < m; j++){
            curr += a[i][j];
        }
        rcnt[curr]++;
    }
    for(int j = 0; j < m; j++){
        ll curr = 0;
        for(int i = 0; i < n; i++){
            curr += a[i][j];
        }
        ccnt[curr]++;
    }
    
    vector<ll> row, col;
    vector<int> rcounter, ccounter; 
    row.push_back(-2e9 - 7);
    rcounter.push_back(0);
    col.push_back(-2e9 - 7);
    ccounter.push_back(0);
    for(auto pp : rcnt){
        row.push_back(pp.ff);
        rcounter.push_back(pp.ss);
    }
    for(auto pp : ccnt){
        col.push_back(pp.ff);
        ccounter.push_back(pp.ss);
    }
    row.push_back(2e9 + 7);
    rcounter.push_back(0);
    col.push_back(2e9 + 7);
    ccounter.push_back(0);
    for(int i = 1; i < rcounter.size(); i++){
        rcounter[i] += rcounter[i - 1];
    }
    for(int i = 1; i < ccounter.size(); i++){
        ccounter[i] += ccounter[i - 1];
    }

    auto doit = [&](vector<ll> uniq, vector<int> pref, ll lo, ll hi ){
        ll ans;
        int ptr = lower_bound(all(uniq), hi) - uniq.begin();
        if( uniq.at(ptr) > hi) ptr--;
        assert(ptr >= 0);
        ans = pref[ptr];
        ptr = lower_bound(all(uniq), lo) - uniq.begin();
        assert(ptr - 1 >= 0);
        ans -= pref[ptr - 1];
        return ans;
    };


    while(q--){
        ll l, r; cin >> l >> r;
        ll ansrow = doit(row, rcounter, l, r);
        ll anscol = doit(col, ccounter, l, r);
        cout << ansrow << " " << anscol << endl;
    }
    return 0;
}
