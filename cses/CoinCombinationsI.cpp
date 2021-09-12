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
const int mod = 1e9 + 7;

int n; 
ll x; 
ll dp[2000005];
ll coins[2000005];

void add(ll &a, ll b){
    a = (a % mod + b % mod) % mod;
}

ll solve(ll val){
    if(val < 0) return 0;
    if(dp[val] != -1) return dp[val];
    ll res = 0;
    for(int i = 0; i < n; i++){
        add( res, solve(val - coins[i]) % mod);
    }
    return dp[val] = res;
}

int main(){
    Shazam;
    cin >> n;
    cin >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];
    for(int i = 0; i < x + 1; i++) dp[i] = -1;
    dp[0] = 1;
    cout << solve(x) << endl;    
    return 0;
}