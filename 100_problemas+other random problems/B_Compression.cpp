#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<ll> S;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        S.insert(a);
    }
    cout<<S.size()<<"\n";
    for(auto x:S){
        cout<<x<<" ";
    }
}