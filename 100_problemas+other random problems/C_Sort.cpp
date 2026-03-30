#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> V;
    vector<pair<ll,ll>> ans;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<n;i++){
        while(V[i]!=i+1){
            ans.push_back({i+1,V[i]});
             swap(V[i],V[V[i]-1]);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}