#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> V;
    V.push_back(a);
    V.push_back(b);
    V.push_back(c);
    sort(V.begin(),V.end());
    if(V[2]-V[0]>=10){
        cout<<"check again";
    }else{
        cout<<"final "<<V[1];
    }
}