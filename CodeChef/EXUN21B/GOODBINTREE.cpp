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
const int mod = 1e9 + 7;



int main(){
    Shazam;
    test(){
        ll m, n;
        cin >> n >> m;
        // int h = (int)log2(m - 1) + 1;
        int h = 0;
        while(n){
            h++;
            n /= 2;
        }
        vector<vector<ll>> dp(h, vector<ll> (m));
        for(int i = 0; i < m; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < h; i++){
            ll sum = 0;
            for(int j = 0; j < m && (i & 1 ^ 1); j++){
                dp[i][j] += sum * sum;
                sum += dp[i - 1][j];
                sum %= mod;
                dp[i][j] %= mod;
            }
            for(int j = m - 1; j >= 0 && (i & 1); j--){
                dp[i][j] += sum * sum;
                sum += dp[i - 1][j];
                sum %= mod;
                dp[i][j] %= mod;
            }
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            ans = (ans + dp[h - 1][i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}