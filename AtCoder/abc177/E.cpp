/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
    ll g = 0;
    map<int,int> f;
    for(int i = 0 ; i < n; i++){
        ll k; cin>>k;
        g = __gcd(g,k);
        for(int i = 2; i*i <= k; i++){
            if(k%i==0){
                f[i]++;
                while(k%i==0){
                    k/=i;
                }
            }
        }
        if(k>=2)
            f[k]++;
    }
    if(g!=1){
        cout<<"not coprime"<<endl;
    }
    else{
        bool single = true;
        for(auto pp : f){
            if(pp.ss>1)
                single = false;
        }
        if(!single){
            cout<<"setwise coprime"<<endl;
        }
        else{
            cout<<"pairwise coprime"<<endl;
        }
    }
    return 0;
}