/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
        vector<string> a(n);
        get(a);
        vector<pair<int,int>> wht, blt, whb, blb;
        if(a[0][1]=='1') wht.push_back({1,2});
        else             blt.push_back({1,2});
        if(a[1][0]=='1') wht.push_back({2,1});
        else             blt.push_back({2,1});
        if(a[n-1][n-2]=='1') whb.push_back({n,n-1});
        else                 blb.push_back({n,n-1});
        if(a[n-2][n-1]=='1') whb.push_back({n-1,n});
        else                 blb.push_back({n-1,n});
        if((int)(wht.size()) == 1 ){
            if(blb.size()==1){
                cout<<2<<endl;
                cout<<blt.back().ff<<" "<<blt.back().ss<<endl;
                cout<<whb.back().ff<<" "<<whb.back().ss<<endl;
            }
            else if(blb.size()==2){
                cout<<1<<endl;
                cout<<blt.back().ff<<" "<<blt.back().ss<<endl;
            }
            else{
                cout<<1<<endl;
                cout<<wht.back().ff<<" "<<wht.back().ss<<endl;
            }
        }
        else if((int)wht.size()==2){
            cout<<whb.size()<<endl;
            for(auto pp : whb){
                cout<<pp.ff<<" "<<pp.ss<<endl;
            }
        }
        else{
            cout<<blb.size()<<endl;
            for(auto pp : blb){
                cout<<pp.ff<<" "<<pp.ss<<endl;
            }
        }
    
    }
    return 0;
}