#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    vector<ll> V;
    V.push_back(0);
    for(int i=0;i<a;i++){
        ll c;
        cin>>c;
        V.push_back(c);
    }
    for(int i=1;i<=a;i++){
        if(V[i]-V[i-1]>b){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}