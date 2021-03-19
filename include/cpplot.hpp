#ifndef YSL_CPPLOT

#pragma once
#include <iostream>
#include <vector>
#include "pipestream.hpp"

class Cpplot {
  private:
    pipestream pipe_;

  public:
    Cpplot () : pipe_("gnuplot -persist") {
      init();
    }
    ~Cpplot () {
    }

    void init ();

    void setXLabel (const char* label);
    void setXLabel (std::string label);
    void setYLabel (const char* label);
    void setYLabel (std::string label);
    void setZLabel (const char* label);
    void setZLabel (std::string label);

    void setLabels (const char* const& xlabel,
                    const char* const& ylabel);
    void setLabels (std::string const& xlabel,
                    std::string const& ylabel);
    void setLabels (const char* const& xlabel,
                    const char* const& ylabel,
                    const char* const& zlabel);
    void setLabels (std::string const& xlabel,
                    std::string const& ylabel,
                    std::string const& zlabel);

    template <typename T> void setXRange (T start, T finish);
    template <typename T> void setYRange (T start, T finish);
    template <typename T> void setZRange (T start, T finish);

    template <typename T> void plot (std::vector<T> v);
    template <typename Tx, typename Ty>
      void plot (std::vector<std::pair<Tx,Ty>> vpair);
};

void Cpplot::init () {
  pipe_ << "unset key\n";
  pipe_ << "set terminal qt font 'Helvetica'\n";
}
void Cpplot::setXLabel (const char* label) {
  pipe_ << "set xlabel '" << label << "'\n";
}
void Cpplot::setXLabel (std::string label) {
  pipe_ << "set xlabel '" << label << "'\n";
}
void Cpplot::setYLabel (const char* label) {
  pipe_ << "set ylabel '" << label << "'\n";
}
void Cpplot::setYLabel (std::string label) {
  pipe_ << "set ylabel '" << label << "'\n";
}
void Cpplot::setZLabel (const char* label) {
  pipe_ << "set zlabel '" << label << "'\n";
}
void Cpplot::setZLabel (std::string label) {
  pipe_ << "set zlabel '" << label << "'\n";
}

void Cpplot::setLabels (const char* const& xlabel, const char* const& ylabel) {
  this->setXLabel(xlabel);
  this->setYLabel(ylabel);
}
void Cpplot::setLabels (std::string const& xlabel, std::string const& ylabel) {
  this->setXLabel(xlabel);
  this->setYLabel(ylabel);
}

void Cpplot::setLabels (const char* const& xlabel, const char* const& ylabel, const char* const& zlabel) {
  this->setXLabel(xlabel);
  this->setYLabel(ylabel);
  this->setZLabel(zlabel);
}
void Cpplot::setLabels (std::string const& xlabel, std::string const& ylabel, std::string const& zlabel) {
  this->setXLabel(xlabel);
  this->setYLabel(ylabel);
  this->setZLabel(zlabel);
}

template <typename T>
void Cpplot::setXRange (T start, T finish) {
  pipe_ << "set xrange[" << start << ":"<< finish << "]\n";
}
template <typename T>
void Cpplot::setYRange (T start, T finish) {
  pipe_ << "set yrange[" << start << ":"<< finish << "]\n";
}
template <typename T>
void Cpplot::setZRange (T start, T finish) {
  pipe_ << "set zrange[" << start << ":"<< finish << "]\n";
}

template <typename T>
void Cpplot::plot (std::vector<T> v) {
  pipe_ << "plot '-' with points\n";
  for (int i=0; i<v.size(); ++i) {
    pipe_ << i << ", " << v[i] << "\n";
  }
  pipe_ << "e\n";
  pipe_.flush();
}

template <typename Tx, typename Ty>
void Cpplot::plot (std::vector<std::pair<Tx,Ty>> vpair) {
  pipe_ << "plot '-' with points\n";
  for (const auto& e: vpair) {
    pipe_ << e.first << ", " << e.second << "\n";
  }
  pipe_ << "e\n";
  pipe_.flush();
}
#endif
