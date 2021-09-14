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

ll n;
ll dp[1000005];
 
void add(ll &a, ll b){
    a = (a % mod + b % mod) % mod;
}

ll solve(int x){
    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];
    ll res = 0;
    for(int i = 1; i < 7; i++){
        add(res, solve(x - i));
    }
    return dp[x] = res;
}

int main(){
    Shazam;
    cin >> n;
    memset(dp, -1, sizeof dp);
    dp[0] = 1LL;
    cout << solve(n) << endl;
    return 0;
}