#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll con=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            if(con%2!=0){
                cout<<i+1<<",";
            }else{
                cout<<i+1<<"\n";
            }
            con++;
        }

    }
}