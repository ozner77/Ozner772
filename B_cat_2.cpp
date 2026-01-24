#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    set<string> S;
    ll n;
    vector<string> V;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        V.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string both=V[i]+V[j];
            string reboth=V[j]+V[i];
            S.insert(both);
            S.insert(reboth);
        }
    }
    cout<<S.size()<<"\n";
}