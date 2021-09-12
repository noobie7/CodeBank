/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
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
    vector<int> isprime(1e5 + 5,1);
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i*i <= 1e5 + 5; i++){
        for(int j = 2*i; isprime[i] && j < 1e5 + 5; j+= i){
            isprime[j] = false;
        }
    }
    test(){
        int n; cin>>n;
        vector<int> ans;
        for(int i = (n-1); i < 1e5 + 1; i += (n-1)){
            if(isprime.at(i + 1) == 1){
                ans.assign(n,i/(n-1));
            }
        }
        ans[0] = 1;
        pra(ans);
        for(int i = 1; i <=n-1; i++){
            swap(ans[i],ans[i-1]);
            pra(ans);
        }
    }
    return 0;
}