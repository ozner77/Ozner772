#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    ll ans2=0;
    vector<pair<ll,ll>> V;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        ll x;
        cin>>x;
        cin>>s;
        if(s=="USB"){
            V.push_back({x,0});
        }else{
            V.push_back({x,1});
        }
    }
    sort(V.begin(),V.end());
    for(int i=0;i<n;i++){
        if(V[i].second==0 && a>0){
            ans+=V[i].first;
            a--;
            ans2++;
        }else if(V[i].second==1 && b>0){
            ans+=V[i].first;
            b--;
            ans2++;
        }else if(c>0){
            c--;
            ans2++;
            ans+=V[i].first;
        }
    }
    cout<<ans2<<" "<<ans;
}