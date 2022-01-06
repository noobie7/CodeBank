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
        ll n; cin >> n;
        vector<ll> a(n);
        get(a);
        sort(all(a));
        ll sum = 0;
        for(int i : a){
            sum += i;
        }
        auto ok_ = [&](ll x){
            ll cost_mean = n * x - sum;
            if(cost_mean < 0){
                return -1LL;
            }
            ll cost_median = 0;
            for(int i = (n - 1) / 2 ; i < n; i++){
                cost_median += max(0LL, x - a[i]);
            }
            if(cost_median > cost_mean){
                return -1LL;
            }
            return cost_mean;
        };



        ll lo = a[(n - 1) / 2] - 1;
        ll hi = 1e9 + 1;
        ll ans = -1;
        while(hi - lo > 1){
            ll mid = (hi + lo) / 2;
            if(ok_(mid) == -1)
                lo = mid;
            else{    
                hi = mid;
                ans = ok_(mid);
            }
        }
        cout << ans << endl;        
    }
    return 0;
}