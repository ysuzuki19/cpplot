#ifndef YSL_PIPESTREAM

class pipestream {
  private:
    FILE *fp_;
  public:
    pipestream () {}
    pipestream (const char* pname) {
      this->open(pname);
    }
    ~pipestream () {
      this->close();
    }

    void open(const char* pname);
    void close();
    void flush();

    pipestream& operator<<(const int &val);
    pipestream& operator<<(const float &val);
    pipestream& operator<<(const double &val);
    pipestream& operator<<(const char* str);
    pipestream& operator<<(const std::string &str);
};

void pipestream::open(const char* pname) {
  fp_ = ::popen(pname, "w");
}

void pipestream::close() {
  ::pclose(fp_);
}

void pipestream::flush() {
  ::fflush(fp_);
}

pipestream& pipestream::operator<<(const int &val){
  ::fprintf(fp_, "%d", val);
  return *this;
}

pipestream& pipestream::operator<<(const float &val){
  ::fprintf(fp_, "%f", val);
  return *this;
}

pipestream& pipestream::operator<<(const double &val){
  ::fprintf(fp_, "%f", val);
  return *this;
}

pipestream& pipestream::operator<<(const char* str){
  ::fprintf(fp_, "%s", str);
  return *this;
}

pipestream& pipestream::operator<<(const std::string &str){
  ::fprintf(fp_, "%s", str.c_str());
  return *this;
}
#endif
