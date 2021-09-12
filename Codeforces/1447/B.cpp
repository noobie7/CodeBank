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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        for(auto &v : a) get(v);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m  + 1, vector<int>(2, -2e9)));
    
        for(int i = 0; i < m; i++){
            dp[0][i][0] = dp[0][i][1] = 0;
        }
        for(int i = 0; i < n; i++){
            dp[i][0][0] = dp[i][0][1] = 0;
        }
        dp[1][1][0] = dp[1][1][1] = a[0][0];
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(i){
                    dp[i][j][0] = max(dp[i][j][0] , max(dp[i - 1][j][0] , dp[i - 1][j][1]) + a[i-1][j-1]);
                    dp[i][j][0] = max(dp[i][j][0] , max(dp[i][j-1][0], dp[i][j - 1][1]) + a[i-1][j-1]);
                }
                if(i > 1){ 
                    dp[i][j][1] = max(dp[i][j][1] , (dp[i - 2][j][0] - a[i-1][j-1] - a[i-2][j-1]) + dp[i-1]);
                }
                if(j > 1){
                    
                    dp[i][j][1] = max(dp[i][j][1] , (dp[i][j-2][0] - a[i-1][j-1] - a[i-1][j-2]));
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                cout << dp[i][j][0] << " " << dp[i][j][1] << " | ";
            }
            cout << endl;
        }
        cout << max(dp[n-1][m-1][0], dp[n-1][m-1][1]) << endl;
    }
    return 0;
}