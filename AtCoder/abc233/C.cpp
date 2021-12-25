/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
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
    map<ll, ll> f;
    int n; cin >> n;
    ll x; cin >> x;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        vector<ll> a(k);
        get(a);
        if(!i){
            for(ll j : a){
                f[j]++;
            }
            continue;
        }
        
        map<ll, ll> curr;
        for(ll j : a){
            for(auto pp : f){
                if(j * pp.ff > x) continue;
                curr[j * pp.ff] += pp.ss;
            }
        }
        f = curr;
    }
    cout << f[x] << endl;
    return 0;
}