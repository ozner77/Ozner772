#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> V(n);
    for(int i=0;i<n;i++){
        cin>>V[i].first;
        V[i].second=i;
    }
    ll ans1=-1;
    ll ans2=-1;
    ll l=0;
    ll r=n-1;
    sort(V.begin(),V.end());
    while(l<r){
        if((V[l].first+V[r].first)==k){
            ans1=V[l].second;
            ans2=V[r].second;
            break;
        }else if((V[l].first+V[r].first)<k){
            l++;
        }else{
            r--;
        }
    }
    if(ans1==-1){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<ans1+1<<" "<<ans2+1;
    }
}