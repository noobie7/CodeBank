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
    vector<pair<ll,int>> a(n*2);
    for(int i = 0 ; i < n; i++){
        cin>>a[i*2].ff>>a[i*2+1].ff; 
        a[i*2].ss = 0;
        a[i*2+1].ss = 1;
    }
    sort(all(a));
    int cnt = 0;
    int mx = -1;
    int mxy = -1;
    stack<ll> st;
    for(int i = 0 ; i < 2*n; i++){
        while(i+1<2*n && a[i]==a[i+1]){
            if(st.)
        }
        
    }
    cout<<mx<<" "<<mxy<<endl;
    return 0;
}