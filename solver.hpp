#pragma once
#include <iostream>
#include <complex>

using namespace std;

namespace solver{
    class RealVariable{
        double a;
        double b;
        double c;
        int a_power;
        int b_power;
    public:

        RealVariable(){
            a=c=0;
            a_power=2;
            b=b_power=1;
        }
        friend RealVariable& operator * (double n,RealVariable& r);
        friend RealVariable& operator * (RealVariable r, double n);
        friend RealVariable& operator * (RealVariable& r1, RealVariable& r2);
        friend RealVariable& operator ^ (RealVariable& r, double n);
        friend RealVariable& operator - (double n, RealVariable& r);
        friend RealVariable& operator - (RealVariable& r, double n);
        friend RealVariable& operator - (RealVariable& r1, RealVariable& r2);
        friend RealVariable& operator + (RealVariable& r,double n);
        friend RealVariable& operator + (double n,RealVariable& r);
        friend RealVariable& operator + (RealVariable& r1,RealVariable& r2);
        friend RealVariable& operator / (RealVariable& r,double n);
//        friend RealVariable& operator / (double n,RealVariable& r);
//        friend RealVariable& operator / (RealVariable& r1,RealVariable& r2);
        friend RealVariable& operator == (RealVariable& r, double n);
        friend RealVariable& operator == (RealVariable& r1,RealVariable& r2 );
        friend RealVariable& operator == (double n,RealVariable& r);
        friend double solve (RealVariable& r);
        ~RealVariable(){

        }
    };
    class ComplexVariable{
        double real;
        double image;
        double coeff;
        double power;
    public:
        ComplexVariable(){
            real=image=coeff=power=0;
        }
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
//        friend ComplexVariable& operator / (double n,ComplexVariable& r);
//        friend ComplexVariable& operator / (ComplexVariable& r1,ComplexVariable& r2);
        friend ComplexVariable& operator == (ComplexVariable& r, double n);
        friend ComplexVariable& operator == (ComplexVariable& r1,ComplexVariable& r2 );
        friend ComplexVariable& operator == (ComplexVariable& r1,std::complex<double> r2);
        friend complex<double> solve (ComplexVariable& c);

        // add << function.

    };





}


