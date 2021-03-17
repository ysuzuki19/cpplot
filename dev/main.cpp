#include <iostream>
#include <vector>
using namespace std;

class Cpplot {
  private:
    FILE *gp_;
  public:
    Cpplot () {
      gp_ = ::popen("gnuplot -persist", "w");
    }
    ~Cpplot () {
      ::pclose(gp_);
    }
    void init () {
    }
    void setLabels (std::string xlabel, std::string ylabel) {
      fprintf(gp_, "set xlabel '%s'\n", xlabel.c_str());
      fprintf(gp_, "set ylabel '%s'\n", ylabel.c_str());
    }
    void plot (vector<int> v) {
      fprintf(gp_, "unset key\n");
      fprintf(gp_, "set xrange[0:%d]\n", int(v.size()));
      fprintf(gp_, "set yrange[0:%d]\n", int(v.size()));
      fprintf(gp_, "set zrange[-2:2]\n");
      fprintf(gp_, "set zlabel \"Amplitude\"\n");
      fprintf(gp_, "plot '-' with points\n");
      for (int i=0; i<v.size(); ++i) {
        printf("%d, %d\n", i, v[i]);
        fprintf(gp_, "%d, %d\n", i, v[i]);
      }
      fprintf(gp_, "e\n");
      fflush(gp_);
    }
};

int main() {
  cout << "PROG" << endl;
  vector<int> v (100);
  for (int i=0; i<v.size(); ++i) {
    v[i] = i;
  }
  Cpplot cplt;
  cplt.setLabels("x", "y");
  cplt.plot(v);
}
