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
        int n; cin >> n;
        vector<ll> x(n), y(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }

        ll res = INF;
        map<ll,ll> rd, ld;
        for(int i = 0; i < n; i++){
            rd[y[i] - x[i]]++;
            ld[y[i] + x[i]]++;
        }

         // assemble on the right diagonals then on the left diagonals
        ll ans = -1;
        ll mx_ld = -1;
        ll mx_rd = -1;
        for(auto pp : ld){
            mx_ld = max(pp.ss, mx_ld);
        }
        for(auto pp : rd){
            mx_rd = max(pp.ss, mx_rd);
        }
        ans = n - mx_ld;
        ans += n - mx_rd; 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ll res = 0;
                for(int p = 0; p < n; p++){
                    ll a = abs(x[i] - x[p]);
                    ll b = abs(y[j] - y[p]);
                    res += (a > 0) + (b > 0) - (a && b && (a == b));
                }
                ans = min(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}