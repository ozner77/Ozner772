#include "robot.h"
#include <bits/stdc++.h>
using namespace std;
#define ll int
// cur west south eas north
void solve(ll ac,ll oe,ll su,ll es,ll no){
    vector<ll> L;
    L.push_back(ac);
    L.push_back(oe);
    L.push_back(su);
    L.push_back(es);
    L.push_back(no);
    map<ll,char> M;
    M[1]='W';
    M[2]='S';
    M[3]='E';
    M[4]='N';
    
}
void program_pulibot()
{
    for(int i=-2;i<=6;i++){
        for(int j=-2;j<=6;j++){
            for(int k=-2;k<=6;k++){
                for(int f=-2;f<=6;f++){
                    for(int h=-2;h<=6;h++){
                        solve(i,j,k,f,h);
                    }
                }
            }
        }
    }
}
