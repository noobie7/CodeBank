/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
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
    int n,m; cin>>m>>n;
    vector<ll> t(n),z(n), y(n);
    for(int i = 0 ; i < n; i++)
        cin>>t[i]>>z[i]>>y[i];
    

    auto ok = [&](long long T){
        int count = 0;
        for(int i = 0 ; i < n; i++){
            count+= (T/(z[i]*t[i]+y[i]))*z[i] + min(z[i], (T%(z[i]*t[i]+y[i]))/(t[i])); 
        }
        
        return count>=m;
    };

    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = (lo + hi)/2.0;
            if(ok(mid))
                hi = mid;
            else 
                lo = mid;
        }
        return hi;
    };
    
    ll T = bs(-1, 3e6 + 1);
    ll make = m;
    cout<<T<<endl;
    for(int i = 0 ; i < n; i++){
        ll cycles = (T/(z[i]*t[i] + y[i]))*z[i];
        ll extra  = min(z[i], (T%(z[i]*t[i]+y[i]))/(t[i]));
        cout<<min(make, cycles + extra)<<" ";
        make-=min(make, cycles + extra);
    }
    cout<<endl;
    return 0;
}