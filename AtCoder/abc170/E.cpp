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
    int n; cin>>n;
    int q; cin>>q;
    map<int,int> belongs_to;
    map<int,int> values;
    for(int i = 1 ; i < n+1; i++){
        int a,b; cin>>a>>b;
        belongs_to[i] = b;
        values[i] = a;
    }
    map<int,multiset<ll,greater<ll>>> kindergarten;
    for(int i = 1 ; i < n+1; i++){
        kindergarten[belongs_to[i]].insert(values[i]);
    }
    multiset<ll,greater<ll>> highest_in_the_room; //she saw my eyes, she know I'm gone
    for(auto pp : kindergarten){
        highest_in_the_room.insert(*pp.ss.begin());
    }

    for(int i = 0; i < q; i++){
        int c,d; cin>>c>>d;
        //removing the highest of the kidergarten where c belongs initially.
        {
            highest_in_the_room.erase(highest_in_the_room.find(*kindergarten[belongs_to[c]].begin()));
        }
        //removing the value of cth student from the kindergarten it belongs to initially.
            kindergarten[belongs_to[c]].erase(values[c]);
        if(kindergarten[belongs_to[c]].size()==0)
            kindergarten.erase(kindergarten.find(belongs_to[c]));
        //updating the new highest value of the kindergarten where c belongs initially.
        {
            if(kindergarten.count(belongs_to[c])){
                highest_in_the_room.insert(*kindergarten[belongs_to[c]].begin());
            }
        }

        {
            //removing the highest of the kindergarten c is getting transfered to. (if it already had some students) 
            if(kindergarten.count(d)){
                highest_in_the_room.erase(highest_in_the_room.find(*kindergarten[d].begin()));
            }
        }
        //inserting the student to destination kindergarten
        kindergarten[d].insert(values[c]);
        
        highest_in_the_room.insert(*kindergarten[d].begin());

        cout<<*highest_in_the_room.rbegin()<<endl;
    

        //Updating the new kindergarten of cth student


        belongs_to[c] = d;
    }

    return 0;
}