#include <iostream>
#include <vector>

#include "../../include/cpplot.hpp"
using namespace std;

int main() {
  Cpplot cplt("--persist");
  cplt.setLabels("x", "y");

  vector<float> v (100);
  for (int i=0; i<v.size(); ++i) {
    v[i] = i;
  }
  cplt.plot(v);
}
