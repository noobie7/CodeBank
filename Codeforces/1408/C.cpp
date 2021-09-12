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
    test(){
        int n; cin>>n;
        ll l; cin>>l;
        vector<ll> a(n);
        get(a);

        long double ans;
        long double d;
        long double taa = -1;
        long double tbb = -1;
        auto ok = [&](long double x){
            ll aca = 0;
            long double ta = 0;
            long double tb = 0;
            long double last  = 0;
            long double u = 1;
            for(int i = 0 ; i < n && a[i] <=x; i++){
                long double v = sqrtl( 2.0*aca*(a[i]-last) + u*u);
                ta += ((aca)?( ( (v-u)  ) /aca):(a[i]-last));
                last = a[i]; 
                aca++;
                u = v;          
            }
           // assert(false);
            long double v = sqrtl(2.0*aca*(x-last) + u*u);
            ta += ((aca)?( ( (v-u)  ) /aca):(x-last));
            aca = 0;
            u = 1.0;
            last = l;
            for(int i = n-1 ; i >=0 && a[i] >= x; i--){
                v = sqrtl( 2.0*aca*-1*(a[i]-last) + u*u);
                tb += ((aca)?( ( (v-u)  ) /aca):(-1*(a[i]-last)));
                last = a[i]; 
                aca++;
                u = v;
                        
            }
            
            v = sqrtl(2.0*aca*-1*(x-last) + u*u);
            tb += ((aca)?( ( (v-u)  ) /aca):(-1*(x-last)));
            ans = ta;
            taa = ta;
            tbb = tb;
            return ta>=tb;
        };
        
        auto bs = [&](long double lo, long double hi){
            while(hi-lo > eps){
                long double mid = (lo + hi)/2.0;
                if(ok(mid))
                   // lo = mid;
                    hi = mid;
                else 
                    //hi = mid;
                   lo = mid;
            }
            //return lo;
            return hi;
        };
        long double loc = bs(0 , l+eps);
        ok(loc);
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}