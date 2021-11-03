/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
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
    double a, b, c; cin >>  a >> b >> c;
    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101)));


    function<double(int, int, int)> recursive = [&](int a, int b, int c){
      if(dp[a][b][c]) return dp[a][b][c];
      if(a == 100 || b == 100 || c == 100) return 0.0;
      double ans = 0;
      ans += (recursive(a + 1, b, c) + 1 ) * a / (a + b + c);
      ans += (recursive(a, b + 1, c) + 1 ) * b / (a + b + c);
      ans += (recursive(a, b, c + 1) + 1 ) * c / (a + b + c); 
      return dp[a][b][c] = ans;
    };
    cout << fixed << setprecision(10) << recursive(a, b, c) << endl;
    return 0;
}