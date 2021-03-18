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
      init();
    }
    void init () {
      fprintf(gp_, "unset key\n");
      fprintf(gp_, "set terminal qt font 'Helvetica'\n");
    }
    void setXLabel (std::string label) {
      fprintf(gp_, "set xlabel '%s'\n", label.c_str());
    }
    void setYLabel (std::string label) {
      fprintf(gp_, "set ylabel '%s'\n", label.c_str());
    }

    void setLabels (std::string xlabel, std::string ylabel) {
      this->setXLabel(xlabel);
      this->setYLabel(ylabel);
    }

    void setXRange (int start, int end) {
      fprintf(gp_, "set xrange[%d:%d]\n", start, end);
    }

    void setYRange (int start, int end) {
      fprintf(gp_, "set yrange[%d:%d]\n", start, end);
    }

    void plot (vector<int> v) {
      setXRange(0, v.size());
      setYRange(0, v.size());
      //fprintf(gp_, "set zrange[-2:2]\n");
      //fprintf(gp_, "set zlabel \"Amplitude\"\n");
      fprintf(gp_, "plot '-' with points\n");
      for (int i=0; i<v.size(); ++i) {
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
