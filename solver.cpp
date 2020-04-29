#define EPSILON 0.0001
#include "solver.hpp"
using namespace solver;

RealVariable& solver::operator * (RealVariable& r,double n){
    r.a=r.a*n;
    r.b=r.b*n;
    r.c=r.c*n;
    return r;
}

RealVariable& solver::operator * (double n,RealVariable& r){
    return r*n;
}

RealVariable& solver::operator * (RealVariable& r1, RealVariable& r2){
    double newb=0,newc=0;
    if(r1.a==0 && r2.a==0){
        //code;
    }

    RealVariable* ans =  new RealVariable();
    RealVariable& temp = *ans;
    if()

        return r1;

}

RealVariable& solver::operator ^ (RealVariable& r, double n){
    if(n>2) throw runtime_error("Power is higher then 2.");
    if(r.a!=0 && n>1) throw runtime_error("Power is higher then 2.");
    if(n==1) return r;
    if(n==0){
        r.c=1;
        r.a=r.b=r.a_power=r.b_power=0;
        return r;
    }
    if(r.b!=0 && r.c!=0){  //kefel mekozar.
        r.a=pow(r.b,n);
        r.a_power=n;
        r.b=n*r.b*r.c;
        r.c=pow(r.c,n);
        return r;
    }
    if(r.b==0){
        r.c=pow(r.c,n);
        return r;
    }
    r.a=pow(r.b,n);
    r.a_power=n;
    r.b=0;
    r.b_power=0;
    return r;
}

RealVariable& solver::operator - (double n, RealVariable& r){
    r=r*(-1);
    r=r+n;
    return r;
}
RealVariable& solver::operator - (RealVariable& r, double n){
    r.c=r.c-n;
    return r;
}
RealVariable& solver::operator - (RealVariable& r1, RealVariable& r2) {
    r1.a = r1.a - r2.a;
    r1.b = r1.b - r2.b;
    r1.c = r1.c - r2.c;
    return r1;
}

RealVariable& solver::operator + (RealVariable& r,double n){
    r.c=r.c+n;
    return r;
}
RealVariable& solver::operator + (double n,RealVariable& r){
    return r+n;
}
RealVariable& solver::operator + (RealVariable& r1,RealVariable& r2){
    r1.a=r1.a+r2.a;
    r1.b=r1.b+r2.b;
    r1.c=r1.c+r2.c;
    return r1;
}
RealVariable& solver::operator / (RealVariable& r,double n){
    if(n==0) throw runtime_error("The cant divide by 0");
    r.a=r.a/n;
    r.b=r.b/n;
    r.c=r.c/n;
    return r;
}
RealVariable& solver::operator / (double n,RealVariable& r){ //check if needed.

    return r;
}
RealVariable& solver::operator / (RealVariable& r1,RealVariable& r2){    //check if needed.
    return r1;
}
RealVariable& solver::operator == (RealVariable& r, double n){

    return r;
}

///////////////////////ComplexVariable//////////////////////////

ComplexVariable& solver::operator * (ComplexVariable& r, double n){
    return r;
}
ComplexVariable& solver::operator * (ComplexVariable& r1, ComplexVariable& r2){
    return r1;
}
ComplexVariable& solver::operator * (double n,ComplexVariable& r){
    return r;
}
ComplexVariable& solver::operator ^ (ComplexVariable& r, double n){
    return r;
}
ComplexVariable& solver::operator - (double n, ComplexVariable& r){
    return r;
}
ComplexVariable& solver::operator - (ComplexVariable& r, double n){
    return r;
}
ComplexVariable& solver::operator - (ComplexVariable& r1, ComplexVariable& r2){
    return r1;
}
ComplexVariable& solver::operator + (ComplexVariable& r,double n){
    return r;
}
ComplexVariable& solver::operator + ( double n,ComplexVariable& r){
    return r;
}
ComplexVariable& solver::operator + (ComplexVariable& r1,ComplexVariable& r2){
    return r1;
}

ComplexVariable& solver::operator + (ComplexVariable& r1,complex<double> r2){
    return r1;
}
ComplexVariable& solver::operator / (ComplexVariable& r,double n){
    return r;
}
ComplexVariable& solver::operator / (double n,ComplexVariable& r){
    return r;
}
ComplexVariable& solver::operator / (ComplexVariable& r1,ComplexVariable& r2){
    return r1;
}
ComplexVariable& solver::operator == (ComplexVariable& r, double n){
    return r;
}

complex<double> solver::solve (ComplexVariable c){
    return std::complex<double>(1,2);
}

double solver::solve (RealVariable r){
    return 1;
}

ComplexVariable& solver::operator == (ComplexVariable& r1,ComplexVariable& r2 ){
    return r1;
}
ComplexVariable& solver::operator == (ComplexVariable& r1,std::complex<double> r2){
    return r1;
}

RealVariable& solver::operator == (RealVariable& r1,RealVariable& r2 ){
    return r1;
}



// --------------------YIRAT PELEG CODE RIP--------------------------
//if(r2.a!=0) {
//r1.a = r1.a * r2.a;
//r1.b = r1.b * r2.a;
//r1.c = r1.c * r2.a;
//r1.a_power = r1.a_power + r2.a_power;
//r1.b_power = r1.b_power + r2.a_power;
//}
//
//if(r2.b!=0) {
//r1.a = r1.a * r2.b;
//r1.b = r1.b * r2.b;
//r1.c = r1.c * r2.b;
//r1.a_power = r1.a_power + r2.b_power;
//r1.b_power = r1.b_power + r2.b_power;
//}
//
//if(r2.c!=0) {
//r1.a = r1.a * r2.c;
//r1.b = r1.b * r2.c;
//r1.c = r1.c * r2.c;
//}


