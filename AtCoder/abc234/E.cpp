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
    set<ll> bag;
    for(ll i = 1; i <= 9; i++){
        ll curr = i;
        ll last = i;
        bag.insert(curr);
        for(ll d = -9; d < 10; d++){
            curr = i;
            last = i;
            if(last + d < 0 || last + d > 9) continue;
            while(curr < 1e18){
                if(last + d < 0 || last + d > 9) break;
                curr *= 10;
                curr += (last + d);
                last  = (last + d);
                bag.insert(curr);
            }
        }   
    }
    ll k; cin >> k;
    cout << *bag.lower_bound(k) << endl;
    return 0;
}