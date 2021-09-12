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
    int n,k; cin>>n>>k;
    vector<int> a(n);
    get(a);
    vector<int> ans(n);
    map<int,int> f;
    int c = 0;
    for(int i : a){
        if(f.lower_bound(i)!=f.end()){
            auto pp = *f.lower_bound(i);
            if(pp.ss > i){
                auto qq = *f.lower_bound(i-k+1);
                if(qq==pp){
                    ans[c] = max(0,i-k+1);
                    f[i] = max(0,i-k+1);
                }
                else{
                    ans[c] = qq.ss+1;
                    f[min(i+k-1,pp.ss-1)] = ans[c];
                }
            }
            else{
                ans[c] = pp.ss;
            }
        }
        else{
            if(f.lower_bound(i-k+1)==f.end()){
                ans[c] = max(0,i-k+1);
                f[1] = ans[c];
            }
            else{
                auto pp = *f.lower_bound(i-k+1);
                ans[c] = pp.ff+1;
                f[i] = pp.ff+1;
            }
            
        }
        c++;
    }
    pra(ans);
    return 0;
}