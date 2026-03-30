#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(b>c){
        if(b<a && c>=a){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    }else{
        if(a>=c || a<b){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }

}