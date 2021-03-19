#include <iostream>
#include <tuple>
#include <vector>

#include "../../include/cpplot.hpp"
using namespace std;

int main() {
  Cpplot cplt("--persist");

  // z = sin(x) + sin(y)
  vector<tuple<int,int, int>> data (100);
  for (int x=0; x<data.size(); ++x) {
    auto& target = data[x];
    std::get<0>(target) = float(x);
    std::get<1>(target) = float(x);
    std::get<2>(target) = float(x*x);
  }
  cplt.splot(data);
}
