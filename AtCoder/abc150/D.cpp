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
    ll n,m; cin>>n>>m;
    ll l1 = 1, l2 = 1;
    int p = -1;
    for(int i = 0; i < n; i++){
        ll k; cin>>k;
        k>>=1;
        l1 = l1*k/__gcd(l1,k);
        int cnt = 0;
        while(k%2==0){
            k/=2;
            cnt++;
        }
        if(!i){
            p = cnt;
        }
        if(p!=cnt){
            cout<<0<<endl;
            return 0;
        }
        
    }

    cout<<m/l1 - m/(2*l1)<<endl; 
    return 0;
}