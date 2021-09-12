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

    int n; cin>>n;
    ll k; cin>>k;
    vector<ll> a(n);
    for(ll &i : a) cin>>i;
    sort(all(a));
    ll hi = 2e18+1;
    ll lo = -2e18;
    while(hi - lo > 1){
        ll m = lo + (hi-lo)/2;
        ll sum = 0;
        for(int i = 0 ; i < n; i++){
            if(a.at(i)>0) sum += lower_bound(a.begin(),a.end(), (long double)(m)/a.at(i)) - a.begin();
            if(a.at(i)<0) sum += n - (upper_bound(a.begin(),a.end(),(long double)(m)/a.at(i)) - a.begin());
            if(a.at(i)==0) sum += ((m>0)?n:0);
            if(a.at(i)*a.at(i) < m) sum--; 
        }
        if(sum/2 < k)
            lo = m;
        else
            hi = m;
    }
    cout<<lo<<endl;

    return 0;
}