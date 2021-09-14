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
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin>>n;
        vector<int> a(n);
        for(int &i : a){
            cin >> i;
            --i;
        }
        sort(all(a));
        vector<vector<int>> dp(n + 1, vector<int> (2 * n + 1, 2e9));
        dp[0][0] = 0;
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < 2 * n - 1; j++){
                if(dp[i][j] < 2e9){
                    if(i < n){
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - j));
                    }
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                }
            }
        }
        cout << dp[n][2*n-1] << endl;
    }
    return 0;
}