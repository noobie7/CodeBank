/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
 */
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
        vector<int> a(n);
        get(a);
        map<int,vector<int>> f;
        for(int i = 0; i < n; i++){
            f[a[i]].push_back(i);
        }
        for(auto &iv : f){
            reverse(all(iv.ss));
            iv.ss.push_back(-1);
            reverse(all(iv.ss));
            iv.ss.push_back(n);
        }
        vector<int> ans(n+1, 1e9);

        auto calc = [&](vector<int>& a){
            int ans = -1;
            int n = a.size();
            for(int i = 0; i < n-1; i++){
                ans = max(ans, a[i+1]-a[i]);
            }
            return ans;
        };

        for(auto iv : f){
            int res = calc(iv.ss);
            if(res!=-1)
               ans[res] = min(ans[res], iv.ff);
        }
        for(int i = 1; i <=n; i++){
            ans[i] = min(ans[i-1],ans[i]);
        }
        for(int &i : ans){
            if(i==1e9)
                i = -1;
        }
        for(int i = 1; i < n+1; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}