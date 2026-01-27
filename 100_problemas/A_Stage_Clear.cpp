#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll a=s[0]-'0';
    ll b=s[2]-'0';
    b++;
    if(b>8){
        b=1;
        a++;
    }
    cout<<a<<"-"<<b;
}