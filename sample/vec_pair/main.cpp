#include <iostream>
#include <vector>

#include "../../include/cpplot.hpp"
using namespace std;

int main() {
  Cpplot cplt("--persist");

  vector<pair<int,int>> vii (100);
  for (int i=0; i<vii.size(); ++i) {
    vii[i].first = i;
    vii[i].second = vii.size() - i;
  }
  cplt.plot(vii);

  vector<pair<int,float>> vif (100);
  for (int i=0; i<vii.size(); ++i) {
    vif[i].first = i;
    vif[i].second = vii.size() - i;
  }
  cplt.plot(vif);
}
