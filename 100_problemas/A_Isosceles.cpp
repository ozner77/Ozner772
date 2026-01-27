#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> V;
    ll a,b,c;
    cin>>a>>b>>c;
    V.push_back(a);
    V.push_back(b);
    V.push_back(c);
    sort(V.begin(),V.end());
    if(V[0]==V[1] || V[1]==V[2]){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}