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
    ll c; cin >> c;
    vector<pair<int,int>> range(n);
    vector<int> cost(n);
    ll tot = 0;
    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++){
        cin >> range[i].ff >> range[i].ss >> cost[i];
        tot += cost[i];
        a.push_back({range[i].ff, cost[i]});
        a.push_back({range[i].ss + 1, -cost[i]});
    }
    sort(all(a));
    ll curr = 0;
    ll ans = 0;
    ll prev = -1;
    for(int i = 0; i < a.size(); i++){
        if(prev == -1){
            curr += a[i].ss;
            prev = a[i].ff;
            continue;
        }
        ans += min(curr, c) * (a[i].ff - prev);
        curr += a[i].ss;
        prev = a[i].ff;
    }
    cout << ans << endl;
    

    return 0;
}