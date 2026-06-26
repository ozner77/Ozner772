#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    k--;
    vector<ll> V;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        V.push_back(a);
    }
    ll l=0;
    ll r=1e18;
    while(l<r){
        ll mid=l+(r-l)/2;
        ll sumi=0;
        ll left=k;
        for(int i=0;i<n;i++){
            sumi+=V[i];
            if(sumi>mid){
                sumi=V[i];
                left--;
            }
            if(sumi>mid){
                left=-1;
            }
        }
        if(left>=0){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r;
}