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
    int n; cin >> n;
    ll k; cin >> k;
    map<ll, ll> f;
    for(int i = 0; i < n; i++){
      ll x; cin >> x;
      f[x]++;
    }
    vector<pair<ll, ll>> a(1, {0,1});
    for(auto pp : f){
      a.push_back({pp.ff, pp.ss});
    }
    ll ans = 0;
    while(a.size() > 1 && k > 0){
      int s = a.size();
      ll dif = a[s - 1].ff - a[s - 2].ff;
      ll max_moves = dif * a[s - 1].ss;
      if(k >= max_moves){
        ans += a[s - 1].ff * (a[s - 1].ff + 1) / 2  * a.back().ss;
        ans -= a[s - 2].ff * (a[s - 2].ff + 1) / 2  * a.back().ss;
        k -= max_moves;
        a[s - 2].ss += a[s - 1].ss;
        a.pop_back();
        continue;
      }

      ll feasible_moves = k / a[s - 1].ss;
      k %= a[s - 1].ss;
      ans += a[s - 1].ff * (a[s - 1].ff + 1) / 2 * a.back().ss;
      ans -= (a[s - 1].ff - feasible_moves) * (a[s - 1].ff - feasible_moves + 1) / 2 * a.back().ss;
      a[s - 1].ff -= feasible_moves;
      ans += k * a[s - 1].ff;
      break;
    }
    cout << ans << endl;
    return 0;
}