#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    string xd="";
    for(int i=3;i<s.size();i++){
        xd+=s[i];
    }
    ll uwu=stoll(xd);
    if(uwu<350 && uwu!=316 && uwu>0){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}