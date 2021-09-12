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
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    get(a);

    auto ok = [&](int pos, ll q){
        return a[pos]<=q;
    };
    for(int i = 0 ; i < k; i++){
        ll q;
        cin>>q;
        int hi = n;
        int lo = 0;
        while(hi - lo  > 1){
            int mid = (hi + lo)/2;
            if(ok(mid,q))
                lo = mid;
            else
                hi = mid;
        }
        if(a[lo]==q){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}