#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    vector<ll> L;
    cin>>n;
    for(int i=1;i<n;i++){
        ll a;
        cin>> a;
        L.push_back(a);
    }
    vector<ll> Pl;
    Pl.push_back(0);
    for(int i=0;i<L.size();i++){
        Pl.push_back(Pl[i]+L[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<Pl.size();j++){
            cout<<Pl[j]-Pl[i]<<" ";
        }
        cout<<"\n"; 
    }
}