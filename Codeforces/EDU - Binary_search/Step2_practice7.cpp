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
    ll k; cin>>k;
    int n; cin>>n;
    vector<ll> a(n);
    get(a);
    ll tot = 0;
    for(ll i : a)
        tot+=i;

    auto ok = [&](long long x){
        long long count = 0;
        for(long long  i : a)
            count += min(i,x);
        return count>=x*k;
    };
    
    auto bs = [&](long long lo, long long hi){
        while(hi-lo > 1){
            long long mid = lo + (hi - lo)/2;
            if(ok(mid))
                lo = mid;
                
            else 
                hi = mid;
             
        }
        return lo;
    };
    
    cout<<bs(0 , (tot+k-1)/k+1)<<endl;
    return 0;
}