#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    string prev="";
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        if(a=="sweet" && a==prev && i!=n-1){
            cout<<"No";
            return 0;
        }
        prev=a;
    }
    cout<<"Yes";
}