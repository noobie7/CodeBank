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
    string S; cin>>S;
    ll b = 0;
    ll c = 0;
    ll s = 0;
    for(char x : S){
        b += (x=='B');
        c += (x=='C');
        s += (x=='S');
    }
    ll nb, ns, nc; cin>>nb>>ns>>nc;
    ll pb, ps, pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;

    auto ok = [&](long long x){
        ll cost = 0;
        //x burgers => x*b breads required
        //x*b-nb breads to be purchased
        cost += max(0LL,(x*b - nb))*pb;
        cost += max(0LL,(x*c - nc))*pc;
        cost += max(0LL,(x*s - ns))*ps;
        return cost  <= r; 

    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long double mid = (lo + hi)/2.0;
            if(ok(mid))
                lo = mid;
               
            else 
                hi = mid;
                
        }
        return lo;
        
    };
    ll already = 2e9 ;
    if(b)
        already = min(already, nb/b);
    if(c)
        already = min(already, nc/c);
    if(s)
        already = min(already, ns/s);
    cout<<bs(0 , r+already + 1)<<endl;
    return 0;
}