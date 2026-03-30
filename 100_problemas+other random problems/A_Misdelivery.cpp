#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<string> V(n);
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        V[i]=name;
    }
    ll x;
    string y;
    cin>>x>>y;
    if(V[x-1]==y){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}