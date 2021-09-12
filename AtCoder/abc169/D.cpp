
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
    ll n; cin>>n;
    ll ans = 0;
    vector<int> faclist;
    for(ll i = 2; i*i <=n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0){
                c++;
                n/=i;
            }
            faclist.push_back(c);
        }  
    }
    if(n>=2) ans++;
    
    
    for(int i : faclist){
        int c = 0;
        int s = 0;
        while(s<i){
            c++;
            s+=c;
            if(s<=i)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}