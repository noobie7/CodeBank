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
    string alpha; cin >> alpha;
    map<int, int> f;
    for(int i = 0; i < 26; i++){
        f[alpha[i] - 'a'] = i;
    }
    int n; cin >> n;
    vector<string> a(n);
    for(string &s : a){
        cin >> s;
    }
    auto transform = [&](string& s){
        for(int i = 0; i < s.size(); i++){
            s[i] = f[s[i] - 'a'];
        }
    };
    auto sorter = [&](string& s, string& t){
        string scopy = s;
        string tcopy = t;
        transform(scopy);
        transform(tcopy);
        return scopy < tcopy;
    };
    sort(all(a), sorter);
    for(string s : a){
        cout << s << endl;
    }
    return 0;
}