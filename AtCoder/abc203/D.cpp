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
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int lim = k * k / 2 + 1;
    vector<vector<int>> s(n + 1, vector<int> (n + 1));
    int lo = -1;
    int hi = 1e9;
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + (a[i][j] > mid);
            }
        }
        int ok = false;
        for(int i = 0; i < n - k + 1; i++){
            for(int j = 0; j < n - k + 1; j++){
                if(s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] < lim )
                    ok = true;
            }
        }
        if(ok)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << endl;
    return 0;
}