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
    int f = 0;
    deque<int> order;
    for(int i = 0; i < s.size(); i++)
        order.push_back(i);
    int q; cin>>q;
    int move = s.size();
    while(q--){
        int type; cin>>type;
        if(type==1) f = !f;
        else{
            int op; cin>>op;
            string k; cin>>k;
            s+=k;
            op--;
            if(f^op){
                order.push_back(move);
            }
            else{
                order.push_front(move);
            }
            move++;
        }
       
    }
    if(f)
        reverse(all(order));
    for(int i : order){
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}