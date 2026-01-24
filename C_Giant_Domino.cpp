#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        vector<pair<ll,ll>> V;
        cin>>n;
        ll start;
        ll end;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(i==0){
                start=a;
            }
            V.push_back({a,i});
        }
        sort(V.begin(),V.end());
        ll ans=2;
        ll ind;
        for(int i=0;i<n;i++){
            if(V[i].first==start){
                ind=i;
                break;
            }
        }
        ll cur=start;
        for(int i=ind+1;i<n;i--){
            
        }
    }
}