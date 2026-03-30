#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(auto &i:v)
        cin>>i;
    set<ll> s;
    for(int i=0;i<k;i++){
        s.insert(v[i]);
    }
    ll con=0;
    auto it=s.begin();
    ll ans=*it;
    for(int i=k;i<n;i++){
        cout<<ans<<"\n";
        ll vali=v[i];
        
        if(vali>ans){
            s.insert(vali);
            it=s.find(ans);
            it++;
            ans=*it;
        }
    }
    cout<<ans<<"\n";
}