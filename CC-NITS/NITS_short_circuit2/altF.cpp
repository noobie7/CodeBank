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
    int n, m;
    cin>>n>>m;
    vector<ll> a(n);
    get(a);
    multiset<ll> elements;
    for(ll i : a){
        elements.insert(i);
    }
    for(int i = 0 ; i < m; i++){
        int type; cin>>type;
        if(type==1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            auto it = elements.find(a[pos]);
            elements.erase(it);
            a[pos] = val;
            elements.insert(val);
        }
        else{
            int k; cin>>k;
            ll ans = 0;
            int cnt = 0;
            for(ll i : elements){
                if(cnt==k){
                    break;
                }
                cnt++;
                ans+=i;
            }

            cout<<ans<<endl;
        }
    }
    return 0;
}