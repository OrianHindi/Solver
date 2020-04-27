#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver{
    class RealVariable{
        double real;
    public:
        friend RealVariable& operator * (double n,RealVariable& r);
        friend RealVariable& operator * (RealVariable& r, double n);
        friend RealVariable& operator * (RealVariable& r1, RealVariable& r2);
        friend RealVariable& operator ^ (RealVariable& r, double n);
        friend RealVariable& operator - (double n, RealVariable& r);
        friend RealVariable& operator - (RealVariable& r, double n);
        friend RealVariable& operator - (RealVariable& r1, RealVariable& r2);
        friend RealVariable& operator + (RealVariable& r,double n);
        friend RealVariable& operator + (double n,RealVariable& r);
        friend RealVariable& operator + (RealVariable& r1,RealVariable& r2);
        friend RealVariable& operator / (RealVariable& r,double n);
        friend RealVariable& operator / (double n,RealVariable& r);
        friend RealVariable& operator / (RealVariable& r1,RealVariable& r2);
        friend RealVariable& operator == (RealVariable& r, double n);
        friend RealVariable& operator == (RealVariable& r1,RealVariable& r2 );
    };
    class ComplexVariable{
        double real;
        double image;

    public:
        friend ComplexVariable& operator * (double n,ComplexVariable& r);
        friend ComplexVariable& operator * (ComplexVariable& r, double n);
        friend ComplexVariable& operator * (ComplexVariable& r1, ComplexVariable& r2);
        friend ComplexVariable& operator ^ (ComplexVariable& r, double n);
        friend ComplexVariable& operator - (double n, ComplexVariable& r);
        friend ComplexVariable& operator - (ComplexVariable& r, double n);
        friend ComplexVariable& operator - (ComplexVariable& r1,ComplexVariable& r2);
        friend ComplexVariable& operator + (ComplexVariable& r,double n);
        friend ComplexVariable& operator + (double n,ComplexVariable& r);
        friend ComplexVariable& operator + (ComplexVariable& r1,ComplexVariable& r2);
        friend ComplexVariable& operator + (ComplexVariable& r1,complex<double> r2);
        friend ComplexVariable& operator / (ComplexVariable& r,double n);
        friend ComplexVariable& operator / (double n,ComplexVariable& r);
        friend ComplexVariable& operator / (ComplexVariable& r1,ComplexVariable& r2);
        friend ComplexVariable& operator == (ComplexVariable& r, double n);
        friend ComplexVariable& operator == (ComplexVariable& r1,ComplexVariable& r2 );
        friend ComplexVariable& operator == (ComplexVariable& r1,std::complex<double> r2);

        // add << function.

    };

    complex<double> solve (ComplexVariable c);

    double solve (RealVariable r);

}

