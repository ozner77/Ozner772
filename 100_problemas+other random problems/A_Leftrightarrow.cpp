#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll iz=0;
    ll de=0;
    string s;
    cin>>s;
    if(s[0]=='<' && s[s.size()-1]=='>'){
        for(int i=1;i<s.size()-1;i++){
            if(s[i]!='='){
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}