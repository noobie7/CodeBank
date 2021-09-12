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
    int n,m; cin>>n>>m;
    vector<string> a(n);
    get(a);
    vector<vector<ll>> dp(m, vector<ll>(6,1e9));
    map<char,int> ref[2][m];
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            ref[i%2][j][a[i][j]]++;
        }
    }
    vector<string> pairing = {"AC","AG","AT","CG","CT","GT"};
    for(int pid = 0; pid < 6; pid++){
        ll score1 = 0, score2 = 0;
        for(int dir = 0 ; dir < 2; dir++){
            if(!dir){
                score1+=  (n+1)/2 - ref[0][0][pairing[pid][0]];
                score1+=   n/2 - ref[1][0][pairing[pid][1]];
            }
            else{
                score2 += (n+1)/2 - ref[0][0][pairing[pid][1]];
                score2 +=  n/2 - ref[1][0][pairing[pid][0]];
            }
        }
        dp[0][pid] = min(score1,score2);
    }
    map<int,int> mapping;
    mapping[0] = 5;
    mapping[1] = 4;
    mapping[2] = 3;
    mapping[3] = 2;
    mapping[4] = 1;
    mapping[5] = 0;
    for(int i = 1 ; i < m; i++){
        for(int pid = 0; pid < 6; pid++){
            dp[i][pid] = dp[i-1][mapping[pid]];
            for(int prevd = 0; prevd < 2; prevd++){
                
                ll score1 = 0;
                ll score2 = 0; 
                for(int dir = 0; dir < 2; dir++){
                    if(!dir){
                    score1 += ref[0][i][pairing[pid][0]];
                    score1 += ref[1][i][pairing[pid][1]];
                    }
                    else{
                       score2 +=  ref[0][i][pairing[pid][1]];
                       score2 +=  ref[1][i][pairing[pid][0]];
                    }
                }
                dp[i][pid]+= min(score1,score2);
            }
        }
    }
    ll ans = INT_MAX;
    for(int col = 0; col < m; col++){
        for(int i = 0 ; i < 6; i++){
            cout<<dp[col][i]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}