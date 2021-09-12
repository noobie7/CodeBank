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
        vector<pair<ll,ll>> range(n);
        for(int i = 0; i < n ; i++){
            cin>>range[i].ff>>range[i].ss;
        }
        sort(all(range));
        int ans = 0;
        int start = range.front().ff;
        while(start < range.back().ss){
            ans++;
            //cout<<start<<endl;
            int p = lower_bound(range.begin(), range.end(), make_pair(start + x,0LL)) - range.begin();
            if(p){
                p--;
                if(range[p].ss > start + x){
                    start = start+x;
                }
                else{
                    if(p+1 < n)
                        start = range[p+1].ff;
                    else{
                        break;
                    }   
                }
            }
            
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
        c++;
    }
    return 0;
}