#include <iostream>
#include <vector>

#include "../../include/cpplot.hpp"
using namespace std;

int main() {
  Cpplot cplt("--persist");

  vector<vector<int>> vvi (100, vector<int>(100));
  for (int i=0; i<vvi.size(); ++i) {
    for (int j=0; j<vvi[i].size(); ++j) {
      vvi[i][j] = i + j;
    }
  }
  cplt.splot(vvi);
}
