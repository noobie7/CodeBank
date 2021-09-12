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
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    string a,b;
    cin>>a>>b;
    int n = a.size();
    int cnt1 = count(all(a),'1');
    int cnt2 = count(all(b),'1');
    int i = 0;
    for( ; i < min(cnt1,n-cnt2)+min(cnt2,n-cnt1); i++){
        cout<<"1";
    }
    for( ; i < n; i++){
        cout<<"0";
    }
    cout<<endl;
    

    return 0;
}