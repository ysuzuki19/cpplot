#include <iostream>
#include <vector>

#include "../include/cpplot.hpp"
//#include "pstream.hpp"
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

  vector<pair<int,int>> vpair (100);
  for (int i=0; i<v.size(); ++i) {
    vpair[i].first = i;
    vpair[i].second = v.size() - i;
  }
  cplt.plot(vpair);
}
