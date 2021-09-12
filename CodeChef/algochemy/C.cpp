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
        ll x, y; cin >> x >> y;
        vector<ll> a(n);
        get(a);
        vector<ll> dp(3);
        // dp[0] = total score if last element was unchanged
        // dp[1] = total score if last element was multiplied by x
        // dp[2] = total score if last element was multiplied by y
        for(int i = 1; i < n; i++){
            vector<ll> last = dp;
            dp[0] = max({abs(a[i] - a[i - 1]) + last[0], abs(a[i] - x * a[i - 1]) + last[1], abs(a[i] - y * a[i - 1]) + last[2]});
            dp[1] = max({abs(x * a[i] - a[i - 1]) + last[0], abs(x * a[i] - x * a[i - 1]) + last[1], abs(x * a[i] - y * a[i - 1]) + last[2]});
            dp[2] = max({abs(y * a[i] - a[i - 1]) + last[0], abs(y * a[i] - x * a[i - 1]) + last[1], abs(y * a[i] - y * a[i - 1]) + last[2]});
        }
        cout << *max_element(all(dp)) << endl;
    }
    return 0;
}