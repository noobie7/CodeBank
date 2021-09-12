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
const double eps = 1e-14;


int main(){
    Shazam;
    int n,d; cin>>n>>d;
    vector<long double> a(n);
    get(a);
    vector<long double> p(n+1);
    for(int i = 0 ; i < n ; i++){
        p[i+1] = p[i] + a[i];
    }
    int left, right;

    auto ok = [&](long double x){
        long double red = 0;
        for(long double &i : p){ i-=red; red+=x;}

        bool can = false;
        long double mini = 2e18;
        int minat = -1;
        for(int i = 0 ; i <=n-d; i++){
            if(mini > p[i]){
                mini = p[i];
                minat = i;
            }
            
            if(p[i+d]>=mini){
                can = true;
                left  = minat+1;
                right = i+d;
            }
        }
        red = x;
        for(long double &i : p){ i+=red; red+=x;}
        return can;
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
    
    long double ans = bs(0 , p[n-1]+1);
    //cout<<ans<<endl;
    ok(ans);
    //cout<<ok(54.8)<<endl;
    cout<<left<<" "<<right<<endl;
    return 0;
}