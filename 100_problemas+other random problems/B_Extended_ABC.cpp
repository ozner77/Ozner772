#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string S;
    cin>>S;
    for(int i=1;i<S.size();i++){
        if(S[i]<S[i-1]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
}