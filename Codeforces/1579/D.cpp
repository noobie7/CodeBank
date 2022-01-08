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
        int n; cin >> n;
        int tot = 0;
        vector<pair<int, int>> a(n);
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            cin >> a[i].ff;
            tot += a[i].ff;
            a[i].ss = i + 1;
            if(a[i].ff)
            pq.push({a[i].ff, a[i].ss});
        }
        vector<pair<int,int>> ans;
        while(pq.size() > 1){
            auto mx = pq.top();
            pq.pop();
            auto smx = pq.top();
            pq.pop();
            ans.push_back({mx.ss, smx.ss});
            mx.ff--;
            smx.ff--;
            if(mx.ff)
                pq.push(mx);
            if(smx.ff)
                pq.push(smx);
            
        }
        cout << ans.size() << endl;
        for(auto pp : ans){
            cout << pp.ff << " " << pp.ss << endl;
        }

    }
    return 0;
}