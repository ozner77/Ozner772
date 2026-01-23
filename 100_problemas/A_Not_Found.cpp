#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    unordered_map<char,ll> M;
    for(auto x:s){
        M[x]++;
    }
    char act='a';
    while(M[act]>0){
        act++;
    }
    cout<<act;
}