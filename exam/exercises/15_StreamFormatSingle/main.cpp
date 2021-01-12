#include <iostream>
#include "future"

using namespace std;

struct Form {
	int prc, wdt;
        ios_base::fmtflags fmt;
        double value;

	Form(int p=6)  {
          prc = p;
          fmt=ios_base::scientific;
          wdt=0;
	}
	Form& scientific() {
		fmt=ios_base::scientific;
		return *this;
	}
	Form& precision(int p) { prc=p; return *this; }

	Form& operator()( double d){
          value = d;
          return *this;
	}
};

class formSetter {
  ios_base::fmtflags ff;
  int prc, wdt;

protected:
  ostream &os;

public:
  formSetter(ostream& os, Form f): os(os){
    ff = os.flags();
    prc = os.precision();
    wdt = os.width();
    os.setf(f.fmt,ios_base::floatfield);
    os.width(f.wdt);
    os.precision(f.prc);
  }

  ~formSetter(){
    os.precision(prc);
    os.flags(ff);
    os.width(wdt);
  }
};

//output operator
ostream& operator<<(ostream& os, Form &f ) {
    formSetter s(os, f);
    // ...change other output settings...
    return os << f.value;
}

Form gen4(3);

void f(double d){
    Form sci8=gen4;
    cout << gen4(d) <<" back to old " << d << std::endl;
}

int main() {
    f(5.25888845);
    return 0;
}
