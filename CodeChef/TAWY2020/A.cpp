/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
 */
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    vector<ll> a(1e6);
    iota(all(a),0);
    for(ll &i : a){
        ll x = i;
        ll y = i;
        ll init = i;
        ll ynew = i;
        ll rev = 0;
        int numsize = 0;
        while(x){
            rev *=10LL;
            rev += x%10;
            x/=10;
            i*=10LL;
        }
        i += rev;
        ll yrev = 0;
        
        while(y >=10){
            yrev *=10;
            yrev +=y%10;
            ynew*=10;
            y/=10;
        }
        if(ynew+yrev != init)
            a.push_back(ynew+yrev);

    }
    sort(all(a));
    ll x; cin>>x;
    if(*lower_bound(all(a),x)==x){
        cout<<x<<" "<<0<<endl;
        return 0;
    }
    else{
        cout<<a[lower_bound(all(a),x)-a.begin()-1]<<" "<<x-a[lower_bound(all(a),x)-a.begin()-1]<<endl;
    }

    return 0;
}