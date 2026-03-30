#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll r,g,b;
    cin>>r>>g>>b;
    string s;
    cin>>s;
    if(s=="Blue"){
        cout<<min(r,g);
    }else if(s=="Red"){
        cout<<min(b,g);
    }else{
        cout<<min(r,b);
    }
}