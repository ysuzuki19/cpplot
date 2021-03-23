#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "../../include/cpplot.hpp"
using namespace std;

void generateWave(vector<pair<float,float>> & vpair, float delay) {
  for (int i=0; i<vpair.size(); ++i) {
    vpair[i].first = 0.01 * i;
    vpair[i].second = sin(0.01 * i + delay);
  }
}

int main() {
  Cpplot cplt;
  cplt.setLabels("x", "sin(x+t)");
  cplt.setYRange(-2.0, 2.0);
  cplt.setStyle("lines");

  vector<pair<float,float>> vpair (1000);

  for(float delay=0.0; delay<5.0; delay+=0.1) {
    generateWave(vpair, delay);
    cplt.plot(vpair);
    this_thread::sleep_for(chrono::milliseconds(100));
  }
}
