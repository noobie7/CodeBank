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
#define pra(a) fl(i,0,a.size()) cout<<a[i]+1<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> diffs;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
        vector<int> b = a[i];
        sort(all(b));
        if(b.back() != b.front()) diffs.push_back(i);
    }
    int curr = 0;
    for(int i = 0; i < n ; i++){
        curr ^= a[i][0];
    }
    vector<int> ans(n);
    if(!curr){
        for(auto idx : diffs){
            int c = 0;
            for(int i = 0; i < m-1 && !curr; i++){
                //cout<<a[idx][i+1]<<" ";
                curr ^= a[idx][i];
                curr ^= a[idx][i+1];
                ans[idx] = i+1;
            }
            //cout<<endl;
            if(curr) break; 
        }
    }
    if(curr){
        cout<<"TAK"<<endl;
        pra(ans);
    }
    else{
        cout<<"NIE"<<endl;
    }

    return 0;
}