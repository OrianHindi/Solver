//
//  Demo.cpp
//  operatorOverload
//
//  First version by Adam Lev-Ari on 29/12/2019.
//  Second version by Erel Segal-Halevi on 22/04/2020.
//

#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

int main() {
    RealVariable x;
    ComplexVariable y;
    std::complex<double> p = solve(2*y+5i+3==3*y+4);
    //a=c=a_power=0; b=2,b_power=1; c=-4;
    cout<<"real : " <<p.real() <<endl;
    cout<< "image : "<<p.imag();
//    cout << solve(-1*x-4 ==10 ) << endl;  // 7
//    cout << solve((x^2) == 16) << endl;   // 4 or -4
//    cout << solve((x^2) == -16) << endl;  // exception: no real solution
//    cout << solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) << endl;   // 4 or -4
//    double xvalue = solve(2*x-4.0 == 10.0);   // xvalue == 7
//
//    ComplexVariable y;
//    std::complex<double> yvalue = solve(2*y-4 == 10);
//    cout << yvalue << endl;  // 7+0i  (can be in any other format)
//
//    cout << solve((y^2) == 16+4i) << endl;   // 4+0i or -4+0i
//    cout << solve((y^2) == -16) << endl;  // 0+4i or 0-4i
//    cout << solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) << endl;   // 4+0i or -4+0i
//    cout << solve(2*(y+5i) == 2*y+3i) << endl;   // 0+2i





    return 0;
}
