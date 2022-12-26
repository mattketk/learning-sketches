#include <vector>
#include <iostream>
#include <fstream>

// constants
namespace Const {
    const double QE = 1.602176565e-19;      // [C]; elementary charge
    const double EPS0 = 8.85418782e-12;     // [C/V/m]; vacuum permittivity
    const double ME = 9.10938215e-31;       // [kg]; electron mass
};

using namespace std;
using namespace Const;
using dvector = vector<double>;

bool outputCSV(double x0, double dx, const dvector &phi, const dvector &rho, const dvector &ef);

int main() {
    const int ni = 21;
    const double x0 = 0;
    const double xm = 0.1;
    double dx = (xm - x0) / (ni - 1);
    
    dvector phi(ni);
    dvector rho(ni, QE*1e+12);
    dvector ef(ni);

    outputCSV(x0, dx, phi, rho, ef);

    return 0;
}

bool outputCSV(double x0, double dx, const dvector &phi, const dvector &rho, const dvector &ef) {
    ofstream out("results.csv");
    if (!out) {
        cerr<<"Could not open output file!"<<endl;
        return false;
    }

    out<<"x,phi,rho,ef\n";
    for (int i = 0; i < phi.size(); i++) {
        out<<x0+i*dx;
        out<<","<<phi[i]<<","<<rho[i]<<","<<ef[i];
        out<<"\n";
    }

    return true;
}