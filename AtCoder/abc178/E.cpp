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



int main(){
    Shazam;
    int n; cin>>n;
    set<ll> xplusy;
    set<ll> xminusy;
    for(int i = 0 ; i < n; i++){
        ll x,y; cin>>x>>y;
        xplusy.insert(x+y);
        xminusy.insert(x-y);
    }
    cout<<max(abs(*xplusy.rbegin()-*xplusy.begin()),  abs(*xminusy.rbegin()-*xminusy.begin()))<<endl;
    return 0;
}