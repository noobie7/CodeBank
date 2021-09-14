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
        vector<int> a(n);
        get(a);
        map<int,vector<int>> f;
        for(int i = 0; i < n; i++){
            f[a[i]].push_back(i+1);
        }
        if((int)f.size()==1){cout<<"NO"<<endl; continue;}
        else{
            cout<<"YES"<<endl;
            int later = -1;
            int stp = f.begin()->ss.back();
            f.begin()->ss.pop_back();
            int stg = f.begin()->ff;
            for(auto pp : f){
                if(pp.ff == stg) continue;
                for(auto i : pp.ss){
                    cout<<stp<<" "<<i<<endl;
                    if(later==-1){
                        later = i;
                    }
                }
            }
            for(auto i : f.begin()->ss)
                cout<<later<<" "<<i<<endl;
            
        }
    }   
    return 0;
}