/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

ll solve(){
    string s; cin>>s; 
    vector<ll> a;
    int n = s.size();
    string st = "KICK";
    string en = "START";
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i]=='K'){
            bool ok = true;
            int j;
            for(j =0 ; j < 4 && i+j < n; j++){
                ok &= (int)(st[j]==s[i+j]);
            }
            if(j==4&&ok) a.push_back(0);
        }
        if(s[i]=='S'){
            bool ok = true;
            int j;
            for(j = 0; j <5 && i+j < n; j++){
                ok &= (int)(en[j]==s[i+j]);
            }
            if(ok&&j==5) a.push_back(1);
        }
    }
    ll ans = 0;
    ll curr= 0;
    for(int i = a.size()-1; i>=0; i--){
        if(a[i]==0){
            ans += curr;
        }
        else{
            curr++;
        }
    }
    return ans;
}

int main(){
    Shazam;
    int c = 1;

    test(){
        cout<<"Case #"<<c<<": "<<solve()<<endl;
        c++;
    }
    return 0;
}