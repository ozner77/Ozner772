#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> freq;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            freq[x]++;
        }
        if(freq[100]>0){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}