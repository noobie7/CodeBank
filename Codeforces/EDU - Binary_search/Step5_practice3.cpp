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
    ll n; cin>>n;
    ll k; cin>>k;
    vector<ll> a(n);
    vector<ll> b(n);
    get(a);
    get(b);
    sort(all(b));
    int cnt = 0;
    auto ok = [&](long long sum){
      ll count = 0;
      for(ll i : a){
        ll ptr = lower_bound(all(b), sum - i) - b.begin();
        count += ptr;
      }
      cnt = count;
      return count < k;
    };
    
    auto bs = [&](long long lo, long long hi){
      while(hi-lo > 1){
        long long mid = (lo + hi)/2.0;
        if(ok(mid))
          lo = mid;
          //hi = mid;
        else 
          hi = mid;
          //lo = mid;
      }
      return lo;
      //return hi;
    };
    ll mx = *max_element(all(a));
    ll mn = *min_element(all(a));
    ll oki =  bs(mn + b.front() , mx + b.back() + 1);
    ok(oki+1);

    if(cnt >=k){
      cout<< oki<<endl;
    }
    else
      cout<< oki + 1  <<endl;
    return 0;
}