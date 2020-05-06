#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver{
    class RealVariable{


    public:
        double a;
        double b;
        double c;
        RealVariable(){
            a=c=0;
            b=1;
        }
        friend RealVariable operator * (double n,const RealVariable& r);
        friend RealVariable operator * (const RealVariable& r, double n);
        friend RealVariable operator * (const RealVariable& r1,const RealVariable& r2);
        friend RealVariable operator ^ (const RealVariable& r, double n);
        friend RealVariable operator - (double n,const RealVariable& r);
        friend RealVariable operator - (const RealVariable& r, double n);
        friend RealVariable operator - (const RealVariable& r1,const RealVariable& r2);
        friend RealVariable operator + (const RealVariable& r,double n);
        friend RealVariable operator + (double n,const RealVariable& r);
        friend RealVariable operator + (const RealVariable& r1,const RealVariable& r2);
        friend RealVariable operator / (const RealVariable& r,double n);
        friend RealVariable operator == (const RealVariable& r, double n);
        friend RealVariable operator == (const RealVariable& r1,const RealVariable& r2 );
        friend RealVariable operator == (double n,const RealVariable& r);
    };
    class ComplexVariable{
    public:
        double real;
        double image;
        double coeff;
        double power;
        ComplexVariable(){
            real=image=0;
            coeff=power=1;
        }
        friend ComplexVariable operator * (double n,const ComplexVariable& r);
        friend ComplexVariable operator * (const ComplexVariable& r, double n);
        friend ComplexVariable operator * (const ComplexVariable& r1,const ComplexVariable& r2);
        friend ComplexVariable operator ^ (const ComplexVariable& r, double n);
        friend ComplexVariable operator - (double n,const ComplexVariable& r);
        friend ComplexVariable operator - (const ComplexVariable& r, double n);
        friend ComplexVariable operator - (const ComplexVariable& r1,const ComplexVariable& r2);
        friend ComplexVariable operator + (const ComplexVariable& r,double n);
        friend ComplexVariable operator + (double n,const ComplexVariable& r);
        friend ComplexVariable operator + (const ComplexVariable& r1,const ComplexVariable& r2);
        friend ComplexVariable operator + (const ComplexVariable& r1,complex<double> r2);
        friend ComplexVariable operator / (const ComplexVariable& r,double n);
        friend ComplexVariable operator == (const ComplexVariable& r, double n);
        friend ComplexVariable operator == (const ComplexVariable& r1,const ComplexVariable& r2 );
        friend ComplexVariable operator == (const ComplexVariable& r1,std::complex<double> r2);

    };

    complex<double> solve (const ComplexVariable& c);
    double solve (const RealVariable& r);
}


