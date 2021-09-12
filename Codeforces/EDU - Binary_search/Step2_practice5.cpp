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
const double eps = 1e-6;


int main(){
    Shazam;
    long double c; cin>>c;
    auto oksqrt = [&](long double x, long double m  ){
       return x*x<=m;
    };
    
    auto bsqrt = [&](long double lo, long double hi){
        long double xx = hi;
        while(hi-lo > eps){
            long double mid = (lo + hi)/2.0;
            if(oksqrt(mid,xx))
                lo = mid;
            else 
                hi = mid;
        }
        return lo;
    };
    
    auto ok = [&](long double x){
        return x*x + bsqrt(0,x) <= c;
    };
    
    auto bs = [&](long double lo, long double hi){
        while(hi-lo > eps){
            long double mid = (lo + hi)/2.0;
            if(ok(mid))
                lo = mid;
            else 
                hi = mid;

        }
        return lo;
    };
    
    cout<<fixed<<setprecision(6)<<bs(0, c+1)<<endl;
    return 0;
}