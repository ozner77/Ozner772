#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> V;
    ll ans;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    V.push_back(t);
    ans=V[0];
    ll xd=V[0];
    while(xd<t){
        xd+=100;
        auto it=lower_bound(V.begin(),V.end(),xd);
        if(it==V.end()){
            break;
        }
        ans+=abs(*it-xd);
        xd=*it;
    }
    cout<<ans;
}