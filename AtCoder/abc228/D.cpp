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
    map<ll,ll> f;
    map<ll, ll> interval;
    const ll mx = (1LL << 20);
    const ll mask = mx - 1;
    interval[mx] = 0; // initial range [0, mx)
    for(int i = 0 ; i < n; i++){
        ll t, x; cin >> t >> x;
        if(t == 1){
            ll i = x & mask; // nice way to take the modulo
            auto itr = interval.upper_bound(i);
            if(itr == end(interval)){
                i = 0;
                itr = begin(interval);
            }
            if(itr -> second <= i){
                f[i] = x;
                ll l1 = itr -> second;
                ll r1 = i;
                ll l2 = i + 1;
                ll r2 = itr -> first;
                interval.erase(itr);
                if(l1 != r1){
                    interval[r1] = l1;
                }
                if(l2 != r2){
                    interval[r2] = l2;
                }
            }
            else{
                f[itr -> second] = x;
                itr -> second += 1;
                if(itr -> first == itr -> second){
                    interval.erase(itr);
                }
            }
        }
        else{
            auto itr = f.find(x & mask);
            cout << (itr == end(f) ? -1 : itr -> second) << endl;
        }
    }
    return 0;
}