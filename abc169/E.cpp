/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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

bool sorter(pair<ll,ll> a, pair<ll,ll> b){
    return a.ss<b.ss;
}


int main(){
    Shazam;
    int n; cin>>n;
    vector<pair<ll,ll>> ranges(n);
    for(pair<ll,ll> &pp : ranges){
        cin>>pp.ff>>pp.ss;
    }
    sort(all(ranges));
    vector<ll> lower, upper;
    for(auto pp : ranges){
        lower.push_back(pp.ff);
    }
    long double lower_limit = ((n&1)?lower[(n+1)/2-1]:(lower[n/2 - 1]+lower[n/2]));
    sort(all(ranges), sorter);
    for(auto pp : ranges){
        upper.push_back(pp.ss);
    }
    
    long double upper_limit = ((n&1)?upper[(n+1)/2-1]:(upper[n/2 - 1]+upper[n/2]));
    // cout<<upper_limit<<" "<<lower_limit<<endl;
   
        cout<<(ll)(upper_limit-lower_limit+1)<<endl;
    
    return 0;
}