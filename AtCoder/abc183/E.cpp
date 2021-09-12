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



int main(){
    Shazam;
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for(auto &s : grid){
        cin >> s;
    }
    vector<vector<ll>> dp(h, vector<ll>(w));
    dp[0][0] = 1;
    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };
    for(int i = 0; i < h; i++){
       
        for(int j = 0; j < w; j++){

            if(i && grid[i-1][j] == '.' ){
                add(dp[i][j], (dp[i-1][j] > 0) + dp[i-1][j]);
            }
            if(j && grid[i][j-1] == '.'){
                add(dp[i][j], (dp[i][j-1] > 0) + dp[i][j-1]);
            }
            if(i && j && grid[i-1][j-1] == '.'){
                add(dp[i][j], (dp[i-1][j-1] > 0) + dp[i-1][j-1]);
            }
            
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}