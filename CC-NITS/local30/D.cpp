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
    int n; cin>>n;
    vector<pair<int,int>> p(n),q(n),r(n);
    for(int i = 0 ; i < n; i++){
        int a,b,c; cin>>a>>b>>c;
        p[i] = {a,i};
        q[i] = {b,i};
        r[i] = {c,i};
    }
    sort(all(p));
    sort(all(q));
    sort(all(r));
    int p1 = p.front().ss;
    set<int> to_be_present;
    for(int i = 0 ; i < n; i++){
        if(q[i].ss==p1){
            break;
        }
        to_be_present.insert(q[i].ss);
    }
    int from_here;
    for(int i = 0; i < n; i++){
        if(r[i].ss==p1)
        break;
        from_here = i;
    }
    for(int i = from_here+1; i < n; i++){
        if(to_be_present.count(r[i].ss)){
            to_be_present.erase(r[i].ss);
        }
    }
    if(to_be_present.size()==0){
        cout<<p1+1<<endl;
        return 0;
    }

    int q1 = q.front().ss;
    to_be_present.clear();
    for(int i = 0 ; i < n; i++){
        if(p[i].ss==q1){
            break;
        }
        to_be_present.insert(p[i].ss);
    }
   
    for(int i = 0; i < n; i++){
        if(r[i].ss==q1)
        break;
        from_here = i;
    }
    for(int i = from_here+1; i < n; i++){
        if(to_be_present.count(r[i].ss)){
            to_be_present.erase(r[i].ss);
        }
    }
    if(to_be_present.size()==0){
        cout<<q1+1<<endl;
        return 0;
    }
    int r1 = r.front().ss;
    to_be_present.clear();
    for(int i = 0 ; i < n; i++){
        if(q[i].ss==r1){
            break;
        }
        to_be_present.insert(q[i].ss);
    }
   
    for(int i = 0; i < n; i++){
        if(p[i].ss==r1)
        break;
        from_here = i;
    }
    for(int i = from_here+1; i < n; i++){
        if(to_be_present.count(p[i].ss)){
            to_be_present.erase(p[i].ss);
        }
    }
    if(to_be_present.size()==0){
        cout<<r1+1<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}