#ifndef YSL_CPPLOT

#pragma once
#include <vector>

class Cpplot {
  private:
    FILE *gp_;

    template <typename T>
    const char* c_str(T num) {
      return std::to_string(num).c_str();
    }

  public:
    Cpplot () {
      gp_ = ::popen("gnuplot -persist", "w");
      init();
    }
    ~Cpplot () {
      ::pclose(gp_);
    }
    void init () {
      ::fprintf(gp_, "unset key\n");
      ::fprintf(gp_, "set terminal qt font 'Helvetica'\n");
    }
    void setXLabel (std::string label) {
      ::fprintf(gp_, "set xlabel '%s'\n", label.c_str());
    }
    void setYLabel (std::string label) {
      ::fprintf(gp_, "set ylabel '%s'\n", label.c_str());
    }
    void setZLabel (std::string label) {
      ::fprintf(gp_, "set zlabel '%s'\n", label.c_str());
    }

    void setLabels (std::string xlabel, std::string ylabel) {
      this->setXLabel(xlabel);
      this->setYLabel(ylabel);
    }

    void setLabels (std::string xlabel, std::string ylabel, std::string zlabel) {
      this->setXLabel(xlabel);
      this->setYLabel(ylabel);
      this->setZLabel(zlabel);
    }

    template <typename T>
    void setXRange (T start, T finish) {
      ::fprintf(gp_, "set xrange[%s:%s]\n", c_str(start), finish);
    }
    template <typename T>
    void setYRange (T start, T finish) {
      ::fprintf(gp_, "set yrange[%s:%s]\n", c_str(start), finish);
    }
    template <typename T>
    void setZRange (T start, T finish) {
      ::fprintf(gp_, "set zrange[%s:%s]\n", c_str(start), finish);
    }

    template <typename T>
    void plot (std::vector<T> v) {
      ::fprintf(gp_, "plot '-' with points\n");
      for (int i=0; i<v.size(); ++i) {
        ::fprintf(gp_, "%s, %s\n", c_str(i), c_str(v[i]));
      }
      ::fprintf(gp_, "e\n");
      ::fflush(gp_);
    }

    template <typename T>
    void plot (std::vector<std::pair<T,T>> vpair) {
      ::fprintf(gp_, "plot '-' with points\n");
      for (const auto& elm: vpair) {
        ::fprintf(gp_, "%s, %s\n", c_str(elm.first), c_str(elm.second));
      }
      ::fprintf(gp_, "e\n");
      ::fflush(gp_);
    }
};
#endif
