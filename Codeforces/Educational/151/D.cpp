#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> V;
        ll maxi,ans,mini,cur;
        mini=0;
        maxi=0;
        cur=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            V.push_back(a);
        }
        for(int i=0;i<n;i++){
            cur+=V[i];
            maxi=max(maxi,cur);
            if(cur-maxi<mini){
                mini=cur-maxi;
                ans=maxi;
            }
        }
        cout<<ans<<"\n";
    }
}