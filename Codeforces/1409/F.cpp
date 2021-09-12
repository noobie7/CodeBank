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

ll dp[205][205][3]; // dp[i][j][k] = total occurences till i'th position making j changes so far of 
                   // k == 0 - > 't[0]'
                   // k == 1 - > t
int main(){
    Shazam;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t; cin >> t;
    s = "^" + s;
    n = s.size();
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int cnt = 0; cnt <=k; cnt++ ){
            if(1){
                for(int j = 0; j < 3; j++){
                    add(dp[i][cnt][j], dp[i-1][cnt][j]);
                }
                if(s[i] == t.front())
                    add(dp[i][cnt + 1][1], dp[i-1][cnt][0]);
            }
            if(1){
                for(int j = 0; j < 3; j++){
                    add(dp[i][cnt][j], dp[i-1][cnt][j]);
                }
                if(s[i] == t.back())
                    add(dp[i][cnt + 1][2], dp[i-1][cnt][1]);
            }
        }
    }
    
    ll ans = 0;
    
    cout << dp[n][0][2] << endl;

    for(int cnt = 0; cnt <= k; cnt++){
        ans = max(ans, dp[n][cnt][2]);
    }
    cout << ans << endl;
    return 0;
}