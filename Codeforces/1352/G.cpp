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
    test(){
        int n; cin>>n;
        if(n < 4){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n);
        int c = 0;
        int val = n - ((n&1)?0:1);
        while(val > 0){
            ans[c] = val;
            c++;
            val-=2;
        }
        ans[c++] = 4;
        ans[c++] = 2;
        for(int i = c ; i < n; i++){
            ans[i] = 4 + 2*(i-c+1);
        }
        pra(ans);
    }
    return 0;
}