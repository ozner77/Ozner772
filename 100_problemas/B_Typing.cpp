#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string a,b;
    cin>>a>>b;
    ll cur=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==a[cur]){
            cout<<i+1<<" ";
            cur++;
        }
    }
}