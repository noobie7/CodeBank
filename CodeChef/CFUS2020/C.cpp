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
    test(){
        int n,k; cin>>n>>k;
        vector<int> portals(k);
        get(portals);
        int fr = 1,bk = n;
        if(!portals.size()){
            k = (n-1)/2 + (n-1)%2;
            cout<<1<<" "<<k<<endl;
            continue;
        }
        fr = portals.front();
        bk = portals.back();
        if(portals.back()!=n){
            portals.push_back(n);
        }
        reverse(all(portals));
        if(portals.back()!=1){
            portals.push_back(1);
        }
        reverse(all(portals));
        ll x = 1,y = 1;
        if((fr-1)&1){
            x = (fr-1)/2 + 1;
        }
        if((n - bk)&1){
            y = (n-bk)/2 + 1;
        }
        int p1 = (fr-1)/2 + ((fr-1)%2);
        int p2 = (n-bk)/2 + (n-bk)%2;
        cout<<x*y<<" "<<p1+k-1+p2<<endl;
    }
    return 0;
}