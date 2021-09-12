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

int n; 
string s;
vector<int> r,g,b;

int calc(int i, int j){
    i++;
    j++;
    set<char> to_find;
    to_find.insert('R');
    to_find.insert('G');
    to_find.insert('B');
    to_find.erase(s[i-1]);
    to_find.erase(s[j-1]);
    char of = *to_find.begin();
    int ans = ((of=='R')?(r[j]-r[i]): ((of=='G')?(g[j]-g[i]):(b[j]-b[i])));
    if(((j-i)&1^1)&&(s[i + (j-i)/2 - 1]==of))
        ans--;
    return ans;
}

int main(){
    Shazam;
    cin>>n;
    cin>>s;
    ll ans = 0;
    r = g = b =  vector<int>(n+1);
    for(int i = 0; i < n; i++){
        if(s[i]=='R')
            r[i+1] = 1;
        else if(s[i]=='G')
            g[i+1] = 1;
        else
            b[i+1] = 1;
    }
    for(int i = 1; i < n+1; i++){
        r[i] += r[i-1];
        g[i] += g[i-1];
        b[i] += b[i-1];
    }
    for(int i = 0 ; i < n; i++){
        for(int j = i + 2; j < n; j++){
            if(s[i]==s[j]) continue;
            ans += calc(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}