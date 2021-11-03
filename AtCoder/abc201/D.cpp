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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    get(a);
    vector<vector<int>> dp(n, vector<int> (m));
    dp[n - 1][m - 1] = 0;
    auto score = [&](int i, int j){
      int p = ((i + j) & 1 ) ? 1 : -1;
      int v = (a[i][j] == '+' ? 1 : -1);
      return p * v;
    };

    for(int i = n - 1; i >= 0; i--){
      for(int j = m - 1; j >= 0; j--){
        if(i == n - 1 && j == m - 1) continue;
        int p = (i + j) & 1 ;
        int b = (i + 1 < n) ? (dp[i + 1][j] + score(i + 1, j)) : (p ? inf : -inf);
        int r = (j + 1 < m) ? (dp[i][j + 1] + score(i, j + 1)) : (p ? inf : -inf);
        if(p){
          dp[i][j] = min(b, r);
        } 
        else{
          dp[i][j] = max(b, r);
        }
      }
    }
    if(dp[0][0] == 0){
      cout << "Draw" << endl;
      return 0;
    }
    cout << (dp[0][0] > 0 ? "Takahashi" : "Aoki") << endl;
    return 0;
}