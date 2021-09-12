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
    ll x; cin >> x;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff;
        a[i].ss = i;
    }
    sort(all(a));
    string ans = "IMPOSSIBLE";
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll f = x - a[i].ff - a[j].ff;
            if(f <= 0) break;
            int p1 = lower_bound(all(a), make_pair(f, 0LL)) - a.begin();
            int p2 = lower_bound(all(a), make_pair(f + 1, 0LL)) - a.begin();
            set<int> ps;
            for(int k = 0; k < min(p2 - p1 , 4); k++){
                ps.insert(p1 + k);
            } 

            if(ps.count(i))
                ps.erase(ps.find(i));
            if(ps.count(j))
                ps.erase(ps.find(j));
            if(ps.size() == 0) continue;
            cout << a[i].ss + 1 << " " << a[j].ss + 1 << " " << a[*ps.begin()].ss + 1 << endl;
            return 0;

        }
    }
    cout << ans << endl;
    return 0;
}