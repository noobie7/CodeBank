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
    ll x,s; cin>>x>>s;
    if(x > s || (s-x)&1){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> ans(3);
    ans[0] = x;
    ll diff = s-x;
    while(diff){
        int bit = 62;
        for(; bit ; bit--){
            if((1LL<<bit) <= diff){
                bit--;
                break;
            }
        }
        assert(bit!=-1);
        {  
            if((x)&(1LL<<bit)){
                ans[1] += (1LL<<bit);
                ans[2] += (1LL<<bit);
            }
            else{
                ans[0] += (1LL<<bit);
                ans[1] += (1LL<<bit);
            }
            diff-=2LL*(1LL<<bit);
        }
    }
    while( ans.back() == 0){
        ans.pop_back();
    }
    cout<<ans.size()<<endl;
    for(ll i : ans) cout<<i <<" ";
    cout<<endl;

    return 0;
}