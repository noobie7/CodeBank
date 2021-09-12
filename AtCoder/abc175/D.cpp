/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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
    vector<ll> p(n), c(n);
    for( ll &i : p){
        cin>>i;
    } 
    for(ll &i : p){
        i--;
    }
    for(ll &i : c){
        cin>>i;
    }
    ll ans = -LLONG_MAX;
    for(int i = 0 ; i < n; i++){
        int curr = i;
        ll cycle_score = 0;
        int cnt = 0;
        while(true){
            cycle_score+= c[curr];
            curr = p[curr];
            cnt++;
            if(curr==i) break;
            
        }
        ll single = 0;
        int cnt2 = 0;
        while(true){
            cnt2++;
            single += c[curr];
            if(cnt2 > k){
                break;
            }
            int num = (k-cnt2)/cnt;
            ans = max(ans, single + max(0LL,cycle_score)*num);
            curr = p[curr];
            if(curr==i) break;
        }
       
    }
    cout<<ans<<endl;

    return 0;
}