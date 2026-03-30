#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<string> S;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        string xd="";
        for(int j=i;j<a.size();j++){
            xd+=a[j];
            S.insert(xd);
        }
    }
    cout<<S.size();
}