/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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
        int n,k; cin>>n>>k;
        string s; cin>>s;
        //cout<<s<<endl;
        int st = 0;
        while(st < n && s[st]=='L')st++;
        map<int, vector<vector<int>>> f;
        for(int i = st; i < n; i++){
            if(s[i]=='L'){
                int cnt = 0;
                vector<int> ids;
                while(i < n && s[i]=='L'){cnt++; ids.push_back(i); i++;}
                f[cnt].push_back(ids);
            }
        }
        for(auto pp : f){
            for(auto v : pp.ss){
                if(k <= 0) break;
                for(int i : v){
                    assert(s[i]=='L');
                    s[i] = 'W';
                    k--;
                    if(k<=0) break;
                }
            }
        }

        int pos = 0;
        st--;
        while(st >=0 && k > 0) {s[st--] = 'W'; k--;}
        for(int i = 0; i < n  && k>0; i++){
            if(s[i]=='L') {s[i]='W'; k--;}
        }

        ll score = 0;
        for(int i = 0; i < n; i++){
            if(i){
                if(s[i-1]=='W' && s[i]=='W') score+=2;
                else if(s[i]=='W') score++;
            }
            else{
                score+=(s[i]=='W');
            }
        }

        cout<<score<<endl;
    }
    return 0;
}