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
    string s; cin>>s;
    map<int,pair<char,int>> f;
    int p = 0;
    int canleavemax = 0;
    int infinite = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i]=='?'){
            f[p-1] = {f[p-1].ff,1};
            canleavemax++;
            continue;
        }
        else if(s[i]=='*'){
            f[p-1] = {f[p-1].ff,2};
            canleavemax++;
            infinite++;
            continue;
        }
        else
            f[p++] = {s[i],0};
    }
    int k; cin>>k;
    if(k<(int)f.size()-canleavemax){
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(infinite){
        int normal = (int)f.size() - canleavemax;
        int use = k-normal;
        bool got = false;
        for(auto ii : f){
            if(ii.ss.ss == 0){
                cout<<ii.ss.ff;
            }
            else if(ii.ss.ss == 1){
                continue;
            }
            else if(!got){
                got = true;
                for(int i = 0 ; i < use; i++){
                    cout<<ii.ss.ff;
                }
            }
        }
        cout<<endl;
    }
    else{
    
        int normal = (int)f.size();
        
        int del = (normal - k);
        //cout<<del<<endl;
        if(del < 0){
            cout<<"Impossible"<<endl;
            return 0;
        }
        for(auto ii : f){
            if(ii.ss.ss==0){
                cout<<ii.ss.ff;
                
            }
            else if(del>0 && ii.ss.ss==1){
                del--;
            }
            else if(ii.ss.ss==1){
                cout<<ii.ss.ff;
            }
        }
        cout<<endl;
    }
    return 0;
}