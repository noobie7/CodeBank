/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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



int main(){
    Shazam;
    test(){
        int n; cin>>n;
        vector<int> pos, neg;
        ll sum = 0;
        int cntz = 0;
        vector<ll> a(n);
        for(int i = 0 ; i < n; i++){
            ll k; cin>>k;
            sum+=k;
            a[i] = k;
            if(k==0){
                cntz++;
            }
            else if(k>0){
                pos.push_back(k);
            }
            else{
                neg.push_back(k);
            }
        }
        if(sum==0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        sort(all(pos));
        sort(all(neg));
        if(sum>0){
            for(int i : pos) cout<<i<<" ";
            for(int i : neg) cout<<i<<" ";
            for(int i = 0; i < cntz; i++) cout<<0<<" ";
        }
        else{
            for(int i : neg) cout<<i<<" ";
            for(int i : pos) cout<<i<<" ";
            for(int i = 0; i < cntz; i++) cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}