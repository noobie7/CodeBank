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
const double eps = 1e-2;

typedef long double ld;
int main(){
    Shazam;
    int n; cin >> n;
    vector<pair<ld, ld>> a(n);
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        ld l, r; cin >> l >> r;
        if(t == 2) r-=eps;
        if(t == 3) l+=eps;
        if(t == 4) r-=eps, l+=eps;
        a[i] = {l, r};
    }
    long long ans = 0;
    auto engulf = [&](int i, int j){
        return (a[i].ff <= a[j].ff && a[j].ss <= a[i].ss);
    };
    auto ok = [&](int i, int j){
       // if(engulf(i, j) || engulf(j, i)) return false;
      //  return ( (a[j].ff <= a[i].ff && a[i].ff <= a[j].ss) || (a[j].ff <= a[i].ss && a[i].ss <= a[j].ss));
    };
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += max(a[i].ff, a[j].ff) <= min(a[i].ss, a[j].ss);
           
        }
    }
    cout << ans << endl;
    return 0;
}