/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod = 998244353;



int main(){
    Shazam;
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<vector<ll>>> dp(1024, vector<vector<ll>> (1024, vector<ll>(10)));
    for(int i = 1; i <= n; i++){
        int x = s[i - 1] - 'A';
        for(int j = 0; j < 1024; j++){
            for(int k = 0; k < 10; k++){
                dp[i][j][k] += dp[i - 1][j][k];
                if(k == x){
                    dp[i][j][k] += dp[i - 1][j][k];
                    dp[i][j][k] %= mod;
                }
            }
        }
        for(int mask = 0; mask < (1LL << 10); mask++){
            if((mask & (1 << x))) continue;
            for(int j = 0; j < 10; j++){
                dp[i][mask| (1 << x)][x] += dp[i - 1][mask][j]; 
                dp[i][mask| (1 << x)][x] %= mod;
            }
            
        }
        dp[i][(1 << x)][x]++;
        dp[i][(1 << x)][x] %= mod;
    }
    
    ll ans = 0;
    for(int mask = 0; mask < 1024; mask++){
        for(int j = 0; j < 10; j++){
            ans = (ans + dp[n][mask][j]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}