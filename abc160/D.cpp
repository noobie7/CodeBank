/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin>>n;
    int x,y; cin>>x>>y;
    vector<int> cnt(n-1);
    for(int i = 1  ; i <=n; i++){
        for(int j = i+1; j <= n; j++){
            cnt[min(j-i,min(abs(i-x) + abs(j-y), abs(j-x)+ abs(i-y))+1)-1]++;
        }
    }
    pra(cnt);
    //cout<<0<<endl;
    return 0;
}