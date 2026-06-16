#ifndef AGENTES_H
#define AGENTES_H

#include <string>
#include <vector>

using namespace std;

vector<int> encode(vector<string> agents);
string decode(vector<string> agents, int id);

#endif