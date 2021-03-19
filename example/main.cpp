#include <iostream>
#include <vector>

#include "../include/cpplot.hpp"
using namespace std;

int main() {
  cout << "PROG" << endl;
  Cpplot cplt;
  cplt.setLabels("x", "y");

  vector<float> v (100);
  for (int i=0; i<v.size(); ++i) {
    v[i] = i;
  }
  cplt.plot(v);

  vector<pair<int,int>> vii (100);
  for (int i=0; i<v.size(); ++i) {
    vii[i].first = i;
    vii[i].second = v.size() - i;
  }
  cplt.plot(vii);

  vector<pair<int,float>> vif (100);
  for (int i=0; i<v.size(); ++i) {
    vif[i].first = i;
    vif[i].second = v.size() - i;
  }
  cplt.plot(vif);
}
