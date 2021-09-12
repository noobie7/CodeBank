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
    string s; cin>>s;
    s += "$";
    int n = s.size();
    
        //k = 0
    vector<int> p(n), c(n);
    vector<pair<char,int>> a(n);
    for(int i = 0; i < n; i++){
        a[i] = {s[i],i};
    }
    sort(all(a));
    for(int i = 0 ; i < n; i++){
        p[i] = a[i].ss; 
    }   
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(a[i].ff==a[i-1].ff){
            c[p[i]] = c[p[i-1]];
        } else{
            c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    
    while((1 << k) < n){ 
        vector<pair<pair<int,int>,int>> combine(n);
        for(int i = 0 ; i < n; i++){
            combine[i] = {{c[i],c[(i + (1<<k))%n]}, i};
        }
        sort(all(combine));
        for(int i = 0 ; i < n ; i++){
            p[i] = combine[i].ss;
        }
        c[p[0]] = 0;
        for(int i = 1; i <  n; i++){
            if(combine[i].ff==combine[i-1].ff)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }
    for(int i = 0; i < n; i++){
        cout<<combine[i].ss<<" "<<s.substr(p[i],n-p[i])<<endl;
    }
    return 0;
}       