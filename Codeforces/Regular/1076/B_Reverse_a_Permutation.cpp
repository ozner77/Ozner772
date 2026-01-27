#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> L;
        vector<pair<ll,ll>> V;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back({a,i});
            L.push_back(a);
        }
        sort(V.rbegin(),V.rend());
        ll xd=-1;
        ll ind;
        ll ind2;
        vector<ll> ans;
        for(int i=0;i<n;i++){
            if(V[i].first!=L[i]){
                xd=V[i].first;
                ind=V[i].second;
                ind2=i;
                break;
            }else{
                ans.push_back(L[i]);
            }
        }
        if(xd==-1){
            for(auto x:L){
                cout<<x<<" ";
            }
        }else{
            for(int i=ind;i>=ind2;i--){
                ans.push_back(L[i]);
            }
            for(int i=ind+1;i<n;i++){
                ans.push_back(L[i]);
            }
            for(auto x:ans){
                cout<<x<<" ";
            }

        }
        cout<<"\n";
    }
}