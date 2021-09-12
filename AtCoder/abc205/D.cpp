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
    int q; cin >> q;
    vector<ll> a(n);
    get(a);
    a.push_back(2e18);
    sort(all(a));
    vector<pair<ll, ll>> slab;
    if(a[0] - 1 > 0){
        slab.push_back({1, a[0] - 1});
    }
    for(int i = 1; i <= n; i++){
        if(a[i] - a[i - 1] > 1){
            slab.push_back({a[i - 1] + 1, a[i] - 1});
        }
    }
    int m = slab.size();
    vector<ll> pref(m + 1);
    for(int i = 1; i <= m; i++){
        pref[i] = pref[i - 1] + slab[i - 1].ss - slab[i - 1].ff + 1;
    }
    
    
    for(int i = 0; i < q; i++){
        ll id; cin >> id;
        int pos = lower_bound(all(pref), id) - pref.begin();

        pos -= (lower_bound(all(pref), id) != pref.end());

        if(pos == -1){
            cout << slab.back().ff + id - 1 << endl;
            continue;
        }
        cout << slab[pos].ff + id - pref[pos] - 1<< endl;
    }

    return 0;
}