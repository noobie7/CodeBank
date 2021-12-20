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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    int cnt = 0; 
    cnt += count(all(a[0]), '#');
    cnt += count(all(a[1]), '#');
    if(cnt >= 3){
        cout << "Yes" << endl;
    }
    else{
        map<int,int> r, c;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(a[i][j] == '#'){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ok = 0;
        for(auto pp : r){
            ok |= (pp.ss == 2);
        }
        for(auto pp : c){
            ok |= (pp.ss == 2);
        }
        cout << ( ok ? "Yes" : "No") << endl;
    }
    return 0;
}