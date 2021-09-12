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
        vector<int> a(n); 
        get(a);
        vector<int> ans(n);
        vector<int> vis(n+1);
        ans[0] = a[0];
        vis[a[0]] = 1;
        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                ans[i] = a[i];
                vis[a[i]] = 1;
            }
        }
        bool cant = false;
        if(count(all(ans),0)){
            int c = 1;
            for(int i = 0; i < n; i++){
                while(vis[c]) c++;
                if(ans[i] == 0){
                    if(c > a[i]){
                        cant = true;
                    }
                    else{
                        ans[i] = c;
                        c++;                   
                    }
                }
            }
        }
        if(cant){
            cout << -1 << endl;
            continue;
        }
        pra(ans);
    }
    return 0;
}