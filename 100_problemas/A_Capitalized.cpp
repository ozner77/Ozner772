#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string S;
    cin>>S;
    if(S[0]>='A' && S[0]<='Z'){
        for(int i=1;i<S.size();i++){
            if(S[i]>='A' && S[i]<='Z'){
                cout<<"No";
                return 0;
            }
        }
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}