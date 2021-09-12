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
    ll x, y; 
    cin >> x >> y;
    if(x >= y){
        cout << (x - y) << endl;
        return 0;
    }
    ll ans = (y - x);
    queue<pair<ll,ll>> q;
    set<ll> vis;
    q.push({y, 0LL});
    vis.insert(y);
    while(!q.empty()){
        ll curr_val = q.front().ff;
        ll curr_dis = q.front().ss;
        q.pop();
        if(curr_dis >= ans) break;
        ans = min(ans, curr_dis + abs(curr_val - x));
        if(curr_val <= x) continue;
        if(curr_val % 2 == 0){
            if(vis.find(curr_val / 2) == vis.end()){
                q.push({curr_val / 2, curr_dis + 1});
                vis.insert(curr_val / 2);
            }
        }
        else{
            if(vis.find(curr_val + 1) == vis.end()){
                q.push({curr_val + 1, curr_dis + 1});
                vis.insert(curr_val + 1);
            }
            if(vis.find(curr_val - 1) == vis.end()){
                q.push({curr_val - 1, curr_dis + 1});
                vis.insert(curr_val - 1);
            }
        }
    }
    cout << vis.size() << endl;
    cout << ans << endl;
    return 0;
}