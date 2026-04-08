#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> V(n);
    vector<ll> L;
    vector<ll> ans(n,-1);
    for(int i=0;i<m;i++){
        ll a;
        cin>>a;
        a--;
        L.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    ll q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        while(a!=b){
            V[L[a]]-=c;
            if(ans[L[a]]==-1 && V[L[a]]<=0){
                ans[L[a]]=i+1;
            }
            a++;
            if(a==m){
                a=0;
            }
        }
        V[L[a]]-=c;
        if(ans[L[a]]==-1 && V[L[a]]<=0){
            ans[L[a]]=i+1;
        }
    }
    for(auto x:ans){
        if(x==-1){
            cout<<"NIE\n";
        }else{
            cout<<x<<"\n";
        }
    }
