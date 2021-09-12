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
        int n,m; cin>>n>>m;
        int a[n][2][2];
        bool x = false;
        bool l = false;
        bool r = false;
        bool allsame = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    cin>>a[i][j][k];
                }
            }
            if(a[i][0][0]==a[i][1][1] && a[i][0][1]==a[i][1][0] && a[i][0][0] == a[i][1][0]) allsame = true;
            // if(a[i][0][0]==a[i][1][1] && a[i][0][1]==a[i][1][0]) x = true;
            // if(a[i][0][0]==a[i][1][1]) l = true;
            if(a[i][1][0]==a[i][0][1]) r = true;
        }
        if(m&1){cout<<"NO"<<endl; continue;}
        if(allsame){
            cout<<"YES"<<endl;
            continue;
        }
        if(r){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}