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
        int n,m,k; cin>>n>>m>>k;
        vector<string> g(n);
        get(g);
        int cnt = 0;
        for(string s : g){
            for(char c : s){
                cnt+=(c=='R');
            }
        }    
        auto getchar = [&](int c){
            if(c<26){
                return (char)((int)('a')+c);
            }
            if(c<52){
                return (char)((int)('A')+(c-26));
            }
            else{
                return (char)((int)('0')+(c-52));
            }
        };
        int dist = cnt/k;
        vector<int> counter(k,dist);
        for(int i = 0; i < cnt%k; i++)
            counter[i]++;
        int id = 0;
        for(int i = 0; i < n; i++){
            if(i&1^1){
                for(int j = 0 ; j < m; j++){
                    if(g[i][j]=='R'){
                        g[i][j] = getchar(id);
                        counter[id]--;
                        if(id+1<k&&!counter[id]) id++;
                    }
                    else{
                        g[i][j] = getchar(id);
                    }
                }
            }
            else{
                for(int j = m-1; j>=0; j--){
                    if(g[i][j]=='R'){
                        g[i][j] = getchar(id);
                        counter[id]--;
                        if(id+1<k&&!counter[id]) id++;
                    }
                    else{
                        g[i][j] = getchar(id);
                    }
                }
            }
        }
        for(string s : g){
            cout<<s<<endl;
        }
    }
    return 0;
}