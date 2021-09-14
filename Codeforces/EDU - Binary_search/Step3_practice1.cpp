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
    int n; cin>>n;
    vector<ll> x(n) , v(n);
    for(int i = 0; i < n; i++){
        cin>>x[i]>>v[i];
    }




    auto ok = [&](long double t){
        long double mini = -1e18;
        long double maxi =  1e18;
        for(int i = 0; i < n; i++){
            mini = max(mini, x[i]-t*v[i]);
            maxi = min(maxi, x[i]+t*v[i]);
        }
        return mini<=maxi;
    };
    
    auto bs = [&](long double lo, long double hi){
        while(hi-lo > eps){
            long double mid = (lo + hi)/2.0;
            if(ok(mid))
            //    lo = mid;
                hi = mid;
            else 
          //      hi = mid;
                lo = mid;
        }
        //return lo;
        return hi;
    };
    
    cout<<fixed<<setprecision(6)<<bs(-1 , 1e9 )<<endl;
    return 0;
}