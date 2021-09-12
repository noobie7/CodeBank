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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    string t; t = s;
    cout<<n<<endl;
    for(int i = 0; i < n; i++){
        t[i] = s[i%k];
    }
    if(t>=s){
        cout<<t<<endl;
        return 0;
    }
    int p = k-1;
    while( p>=0 && s[p] == '9' ){
        s[p] = '0';
        p--;
    }
    s[p]++;
    for(int i = 0 ; i < n; i++){
        cout<<s[i%k];
    }
    cout<<endl;
    return 0;
}