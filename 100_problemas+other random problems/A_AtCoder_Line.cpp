#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    if(a>b){
        swap(a,b);
    }
    if(c>=a && c<=b){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    
}