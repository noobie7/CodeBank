/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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
const int mod = 1e9 + 7;



int main(){
    Shazam;
    int n,m,k; 
    cin>>n>>m>>k;
    ll ans = 0;

    auto add = [&](ll &a, ll b){
        a = (a%mod + b%mod)%mod;
    };

    for(int place = 0; place < k; place++){
        int d = (place%m + 1);
            
    }
    swap(n,m);
    for(int place = 0; place < k; place++){
        int row = n - place/m -1;
        int col = m - place%m;
        add(ans, (place%m + 1)*  col %mod * row %mod * (row+1) %mod /2);
    }
    cout<<ans*(k-2)%mod<<endl;
    return 0;
}