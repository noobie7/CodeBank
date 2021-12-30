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
const ll INF = 1e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<vector<int>> a(2, vector<int> (n));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i < n; i++){
            a[1][i] += a[1][i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            a[0][i] += a[0][i + 1];
        }
        ll ans = INF;
        for(int i = 0; i < n; i++){
            ll curr =  max( (i) ? a[1][i - 1] : -INF , (i + 1 < n) ? a[0][i + 1] : -INF );
            if(curr != -1e18 )
                ans = min(ans, curr);
        }
        cout << (ans != INF ? ans : 0 ) << endl;
    }
    return 0;
}