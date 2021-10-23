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
        map<int, vector<int>> g;
        vector<pair<int,int>> seg(n);
        set<int> bag;
        priority_queue<int> q;
        for(int i = 0; i < n; i++){
            cin >> seg[i].ff >> seg[i].ss;
            g[seg[i].ff].push_back(seg[i].ss);
            bag.insert(seg[i].ff);
        }
        bag.insert(INT_MAX);
        int i = (*bag.begin()); 
        int ok = 1;
        while(i <= (int)1e9){
            for(int r : g[i]){
                q.push(-r);
            }
            int now = abs(q.top());
            q.pop();
            if(q.empty()) i = *bag.lower_bound(i + 1);
            else{
                if(abs(q.top()) <= i){ 
                    ok = 0; break;
                }
                i++;
            }
        }
        if(!q.empty()) 
            ok = 0;
        cout << (ok ? "Yes" : "No") << endl;
    }  
    return 0;
}