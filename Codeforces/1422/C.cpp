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
const ll mod = 1e9 + 7;


vector<ll> fac;
vector<ll> ifac;

int main(){
    Shazam;
    string s; cin>>s;
    int n = s.size();
    vector<ll> a;
    vector<vector<ll>> dig(10, vector<ll> (n));

    for(int i = 0; i <  10; i++){
        ll pw = 10;
        dig[i][0] = i;
        for(int j = 1; j < n; j++){
            dig[i][j] = dig[i][j-1]*pw%mod;
        }
    } 
    for(char c : s){
        a.push_back(c-'0');
    }


    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };

    ll ans = 0;
    vector<ll> backward(n,1);
    ll pw = 10;
    for(int i = n-2 ; i >= 0; i--){
        backward[i] = (n-i)*pw%mod;
        if(i < n-1){
            add(backward[i],backward[i+1]);
        }
        pw = pw*10%mod;
    }
    for(ll i = 0 ; i < n; i++){
        add(ans, dig[a[i]][n-1-i]*((i*(i+1))/2 %mod)%mod);
        
        if(i<n-1){
            add(ans, a[i]*backward[i+1]%mod);
            
        }
       
    }
    cout<<ans<<endl;
    return 0;
}