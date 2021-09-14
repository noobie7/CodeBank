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

ll dp[100005][105];

int main(){
    Shazam;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };
    for(int &i : a) cin >> i, --i;
    for(int i = 0; i < n; i++){
        if(i){
            for(int j = 0; j < m; j++){
                add(dp[i][j], dp[i-1][j]);
                if(j)   
                    add(dp[i][j], dp[i-1][j-1]);
                if(j + 1 < m)
                    add(dp[i][j], dp[i-1][j+1]);
            }
        }
        else{
            for(int j = 0; j < m; j++)
                dp[i][j] = 1;
        }
        if(~a[i]){
            for(int j = 0; j < m; j++)
                if(a[i] ^ j)
                    dp[i][j] = 0;
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        add(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}