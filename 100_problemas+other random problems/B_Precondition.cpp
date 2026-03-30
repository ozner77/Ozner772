#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    unordered_map<char,ll> M;
    string S;
    string T;
    cin>>S>>T;
    for(int i=0;i<T.size();i++){
        M[T[i]]++;
    }
    bool ok=true;
    for(int i=1;i<S.size();i++){
        if('A'<=S[i] && S[i]<='Z'){
            if(M[S[i-1]]==0){
                ok=false;
                break;
            }
        }
    }
    if(ok){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}