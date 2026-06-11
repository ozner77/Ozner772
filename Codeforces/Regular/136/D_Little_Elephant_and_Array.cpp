#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> V;
vector<ll> frequency;
ll ans;
ll n,m;
ll block_size;
struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        int block_this = l / block_size;
        int block_other = other.l / block_size;
        
        if (block_this != block_other) {
            return block_this < block_other;
        }
        return r < other.r; 
    }
};
void add(ll ind){
    if(V[ind]>n){return; }
    ll val=V[ind];
    if(frequency[val]==val){
        ans--;
    }
    frequency[val]++;
    if(frequency[val]==val){
        ans++;
    }
}
void remove(ll ind){
    if(V[ind]>n){return; }
    ll val=V[ind];
    if(frequency[val]==val){
        ans--;
    }
    frequency[val]--;
    if(frequency[val]==val){
        ans++;
    }
}
int main(){
    cin>>n>>m;
    vector<ll> ansi(m,0);
    vector<Query> queries(m);
    frequency.assign(n+1,0);
    block_size=sqrt(n)+1;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].id=i;
        queries[i].l--;queries[i].r--;
    }
    sort(queries.begin(),queries.end());
    ll curl=0;
    ll curr=-1;
    ans=0;
    for(int i=0;i<m;i++){
        ll L=queries[i].l;
        ll R=queries[i].r;
        while(curl>L){
            curl--;
            add(curl);
        }
        while(curl<L){
            remove(curl);
            curl++;
        }
        while(curr<R){
            curr++;
            add(curr);
        }
        while(curr>R){
            remove(curr);
            curr--;
        }
        ansi[queries[i].id]=ans;
    }
    for(auto x:ansi){
        cout<<x<<"\n";
    }
}