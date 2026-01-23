#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c<a){
        cout<<"Yes";
    }else if(a==c && d<=b){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}