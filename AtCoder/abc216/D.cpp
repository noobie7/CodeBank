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
    int n, m; cin >> n >> m;
    vector<vector<int>> located_at(n);
    vector<queue<int>> a;
    queue<int> q;
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        queue<int> curr;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            x--;
            curr.push(x);
        }
        a.push_back(curr);
        located_at[curr.front()].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(located_at[i].size() == 2){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : located_at[now]){
            a[i].pop();
            if(a[i].size()){
                located_at[a[i].front()].push_back(i);
                if(located_at[a[i].front()].size() == 2){
                    q.push(a[i].front());
                }
            }
        }  
    }
    for(int i = 0; i < m; i++){
        if(a[i].size()){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}