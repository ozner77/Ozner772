#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    vector<ll> V;
    cin>>n;
    ll maxi=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        maxi=max(maxi,a);
        V.push_back(a);
    }
    sort(V.begin(),V.end());
    ll l=0;
    ll r=maxi+1;
    while(l<r){
        ll m=(l+r+1)/2;
        auto it=lower_bound(V.begin(),V.end(),m);
        if(it==V.end()){
            r=m-1;
            continue;
        }
        ll cnt=it-V.begin();
        cnt=n-cnt;
        if(cnt>=m){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    cout<<l;
}