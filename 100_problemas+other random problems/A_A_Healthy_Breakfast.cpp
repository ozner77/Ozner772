#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    if(s[1]=='M' && s[0]=='R'){
        cout<<"Yes";
    }else if(s[2]=='M' && s[0]=='R'){
        cout<<"Yes";
    }else if(s[2]=='M' && s[1]=='R'){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}