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
    int n, m, k; 
    cin >> n >> m >> k;
    vector<string> a(n);
    for(auto &s : a) cin >> s;
    int ans = 0;
    for(int r_mask = 0; r_mask < (1 << n); r_mask++){
        for(int c_mask = 0; c_mask < (1 << m); c_mask++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(r_mask & (1 << i)) continue;
                for(int j = 0; j < m; j++){
                    if(c_mask & (1 << j)) continue;
                    count += (a[i][j] == '#');
                }   
            }
            ans += (count == k);
        }
    }
    cout << ans << endl;
    return 0;
}