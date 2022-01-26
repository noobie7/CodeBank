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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<ll> a(n);
        get(a);
        auto ok = [&](ll mid){
            vector<ll> c = a;
            for(int i = n - 1; i >= 2; i--){
                if(c[i] < mid) return false;
                ll need = min(c[i] - mid, a[i]) / 3;
                c[i - 1] += need;
                c[i - 2] += 2 * need;
            }
            return (*min_element(all(c)) >= mid);     
        };
        ll hi = *max_element(all(a)) + 1;
        ll lo = 0;
        while(hi - lo > 1){
            ll mid = (lo + hi) / 2;
            if(ok(mid)){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        cout << lo << endl;
    }
    return 0;
}