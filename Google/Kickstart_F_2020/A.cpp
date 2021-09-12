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
    int c = 1;
    test(){
        ll n,x; cin>>n>>x;
        map<ll,vector<ll>> f;
        for(int i = 1; i < n + 1; i++){
            ll k; cin>>k;
            f[(k + x-1)/x].push_back(i);
        }
        cout<<"Case #"<<c<<": ";
        for(auto iv : f){
            for(int i : iv.ss){
                cout<<i<<" ";
            }
        }
        cout<<endl;




        c++;
    }
    return 0;
}