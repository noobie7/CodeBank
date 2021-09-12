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
const double eps = 1e-7;


int main(){
    Shazam;
    int n,k; cin>>n>>k;
    vector<long double> a(n);
    for(long double &i :  a ) cin>>i;

    auto ok = [&](long double x){
        int count = 0;
        for(long double  i : a)
            count += i/x;
        return count>=k;
    };

    auto bs = [&](long double lo, long double hi){
        while(hi-lo > eps){
           // cout<<lo<<" "<<hi<<endl;
            long double mid = (lo + hi)/2.0;
            if(ok(mid))
                lo = mid;
            else 
                hi = mid;    
        }
        return lo;
    };

    cout<<fixed<<setprecision(7)<<bs(0,*max_element(all(a))+1)<<endl;
    return 0;
}