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

int dp[71][71][40][71];

int main(){
    Shazam;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int a = 0; a <= m/2; a++){
                for(int r = 0; r <= k; r++){
                    dp[i][j][a][r] = -inf;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    auto max_self = [&](int &a, int b){
        a = max(a, b);
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int cnt = 0; cnt  <= m/2; cnt++){
                for(int rem = 0; rem < k; rem++){
                    if(dp[i][j][cnt][rem] == -inf) continue;
                    int ni = (j == m - 1 ? i + 1 : i); // finding the location we want to update using the data at (i,j);
                    int nj = (j == m - 1 ? 0 : j + 1); // if the element is at the last in a row then we would to update the location which is the first element of the next row.
                    if(i != ni){
                        max_self(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
                    }
                    else{
                        max_self(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
                    }
                    if(cnt + 1 <= m/2){
                        int nrem = (rem + a[i][j]) % k;
                        if(i != ni){
                            max_self(dp[ni][nj][0][nrem] ,(int) (dp[i][j][cnt][rem] + a[i][j])); // choose or not choose the last element in a row
                        }
                        else{
                            max_self(dp[ni][nj][cnt + 1][nrem], (int) (dp[i][j][cnt][rem] + a[i][j]));
                        }
                    }
                }
            }
        }
    }
    cout << max(0, dp[n][0][0][0]) << endl;
    return 0;
}