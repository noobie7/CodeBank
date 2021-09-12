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
        vector<int> ans(n+1);
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({n,{-1,-n}});
        int c = 1;
        while(pq.size() && c < n+1){
            auto pp = pq.top();
            pq.pop();
            int l = abs(pp.ss.ff);
            int r = abs(pp.ss.ss);
            int len = pp.ff;
            int m = ((len&1)?((l+r)/2):((l+r-1)/2));
            ans[m] = c++;
            if(r==l) continue;
            int lsize = m - l;
            int rsize = r - m;
            pq.push({lsize,{-l, -m+1}});
            pq.push({rsize,{-m-1, -r}});
        }
        for(int i = 1; i < n+1; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}