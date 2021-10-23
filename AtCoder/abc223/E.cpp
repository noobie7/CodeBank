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
    ll x, y, a, b, c; 
    cin >> x >> y >> a >> b >> c;
    
    auto solve2 = [&](ll x, ll y, ll a, ll b){
        for(int i = 0; i < 2; i++){
            ll len = (a + x - 1) / x;
            if(len < y && x * (y - len) >= b){
                return true;
            }
            swap(x, y);
        }
        return false;
    };

    auto solve3 = [&](ll x, ll y, ll a, ll b, ll c){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                ll len = (a + x - 1) / x;
                if(len < y && solve2(x, y - len, b, c)){
                    return true;
                }
                swap(a, b);
                swap(b, c);

            }
            swap(x, y);
        }
        return false;
    };

    cout << (solve3(x, y, a, b, c) ? "Yes" : "No") << endl;
    return 0;
}