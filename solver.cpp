
#include "solver.hpp"
#include <complex>
#include <vector>
using namespace solver;

RealVariable solver::operator * (const RealVariable& r,double n){  //good
    RealVariable new_var;
    new_var.a=r.a*n;
    new_var.b=r.b*n;
    new_var.c=r.c*n;
    return new_var;
}

RealVariable solver::operator * (double n,const RealVariable& r){ //good
    return r*n;
}

RealVariable solver::operator * (const RealVariable& r1, const RealVariable& r2){ //good
    RealVariable new_var;
    if(r1.a!=0 && r2.a!=0) throw runtime_error("The power higher then 2");
    if((r1.a!=0 && r2.b!=0) || (r2.a!=0 && r1.b!=0)) throw runtime_error("The power higher then 2");
    new_var.a = r1.b * r2.b + r1.a * r2.c + r2.a * r1.c;
    new_var.b = r1.b * r2.c + r1.c * r2.b;
    new_var.c = r1.c * r2.c;
    return new_var;
}

RealVariable solver::operator ^ (const RealVariable& r, double n){
    RealVariable new_var;
    if(n>2) throw runtime_error("Power is higher then 2.");
    if(r.a!=0 && n>1) throw runtime_error("Power is higher then 2.");
    if(n==1) {
        new_var.a=r.a,new_var.b=r.b,new_var.c=r.c;
        return new_var;}
    if(n==0){
        new_var.c=1;
        new_var.a=new_var.b=0;
        return new_var;
    }
    if(r.b!=0 && r.c!=0){  //kefel mekozar.
        new_var.a=pow(r.b,n);
        new_var.b=n*r.b*r.c;
        new_var.c=pow(r.c,n);
        return new_var;
    }
    if(r.b==0){
        new_var.c=pow(r.c,n);
        return new_var;
    }
    new_var.a=pow(r.b,n);
    new_var.b=0;
    return new_var;
}

RealVariable solver::operator - (double n,const RealVariable& r){ //good
    RealVariable new_var;
    new_var.a=r.a;
    new_var.b=r.b;
    new_var.c=r.c-n;
    return new_var;
}
RealVariable solver::operator - (const RealVariable& r, double n){ //good
    return n-r;
}
RealVariable solver::operator - (const RealVariable& r1,const RealVariable& r2) { //good
    RealVariable new_var;
    new_var.a = r1.a - r2.a;
    new_var.b = r1.b - r2.b;
    new_var.c = r1.c - r2.c;
    return new_var;
}

RealVariable solver::operator + (const RealVariable& r,double n){  //good
    RealVariable new_var;
    new_var.a=r.a;
    new_var.b=r.b;
    new_var.c=r.c+n;
    return new_var;
}
RealVariable solver::operator + (double n,const RealVariable& r){ //good
    return r+n;
}
RealVariable solver::operator + (const RealVariable& r1,const RealVariable& r2){ //good
    RealVariable new_var;
    new_var.a=r1.a+r2.a;
    new_var.b=r1.b+r2.b;
    new_var.c=r1.c+r2.c;
    return new_var;
}
RealVariable solver::operator / (const RealVariable& r,double n){ //good
    if(n==0) throw runtime_error("The cant divide by 0");
    RealVariable new_var;
    new_var.a=r.a/n;
    new_var.b=r.b/n;
    new_var.c=r.c/n;
    return new_var;
}

RealVariable solver::operator == (const RealVariable& r, double n){ //last op .
    RealVariable new_var;
    new_var.a = r.a;
    new_var.b = r.b;
    new_var.c = r.c-n;
    return new_var;
}
RealVariable solver::operator == (double n,const RealVariable& r){
    return r==n;
}
RealVariable solver::operator == (const RealVariable& r1,const RealVariable& r2){
    return r1-r2;
}


///////////////////////ComplexVariable//////////////////////////

ComplexVariable solver::operator * (const ComplexVariable& r, double n){
    ComplexVariable new_var;
    new_var.real=r.real;
    new_var.image=r.image;
    new_var.power=r.power;
    new_var.coeff=n*r.coeff;
    return new_var;

}
ComplexVariable solver::operator * (const ComplexVariable& r1, const ComplexVariable& r2){
    ComplexVariable new_var;
    new_var.coeff=r1.coeff*r2.coeff;
    new_var.power=2;
    return new_var;
}
ComplexVariable solver::operator * (double n,const ComplexVariable& r){
    return r*n;
}
ComplexVariable solver::operator ^ (const ComplexVariable& r, double n){
    ComplexVariable new_var;
    if(n>2)throw runtime_error("Power is higher then 2");
    if(n==1){
        new_var.real=r.real;
        new_var.image=r.image;
        new_var.coeff=r.coeff;
        new_var.power=r.power;
        return new_var;
    }
    if(n==0){
        new_var.real=1;
        new_var.image=0;
        new_var.coeff=0;
        new_var.power=0;
        return new_var;
    }
    return r*r;
}

ComplexVariable solver::operator - (double n, const ComplexVariable& r){
    ComplexVariable new_var;
    new_var.real = n-r.real;
    new_var.image = -r.image;
    new_var.coeff=-r.coeff;
    new_var.power=r.power;
    return new_var;
}
ComplexVariable solver::operator - (const ComplexVariable& r, double n){
    ComplexVariable new_var;
    new_var.real = r.real-n;
    new_var.image = r.image;
    new_var.coeff=r.coeff;
    new_var.power=r.power;
    return new_var;
}
ComplexVariable solver::operator - (const ComplexVariable& r1, const ComplexVariable& r2){;
    ComplexVariable new_var;
    new_var.real=r1.real-r2.real;
    new_var.image=r1.image-r2.image;
    new_var.coeff=r1.coeff-r2.coeff;
    new_var.power=r1.power;
    return new_var;
}
ComplexVariable solver::operator + (const ComplexVariable& r,double n){
    ComplexVariable new_var;
    new_var.real = r.real+n;
    new_var.image = r.image;
    new_var.power=r.power;
    new_var.coeff=r.coeff;
    return new_var;
}
ComplexVariable solver::operator + ( double n,const ComplexVariable& r){
    return r+n;
}
ComplexVariable solver::operator + (const ComplexVariable& r1,const ComplexVariable& r2){
    ComplexVariable new_var;
    new_var.real=r1.real+r2.real;
    new_var.image=r1.image+r2.image;
    new_var.coeff=r1.coeff+r2.coeff;
    new_var.power=r1.power;
    return new_var;
}

ComplexVariable solver::operator + (const ComplexVariable& r1,complex<double> r2){
    ComplexVariable new_var;
    new_var.real=r1.real+r2.real();
    new_var.image=r1.image+r2.imag();
    new_var.coeff=r1.coeff;
    new_var.power=r1.power;
    return new_var;
}
ComplexVariable solver::operator / (const ComplexVariable& r,double n){
    ComplexVariable new_var;
    new_var.real=r.real;
    new_var.image=r.image;
    new_var.coeff=r.coeff/n;
    new_var.power=r.power;
    return new_var;
}

ComplexVariable solver::operator == (const ComplexVariable& r, double n){
    return r-n;
}

complex<double> solver::solve (const ComplexVariable& c){
    double i,r;
    if(c.power==2){
        if(c.real>0){
            i=sqrt(c.real/c.coeff);
            r=0;
        }
        else{
            r=sqrt(-c.real/c.coeff);
            i=0;
        }
    }
    else if(c.power==1 && c.coeff!=0){
        r=-c.real/c.coeff;
        i=-c.image/c.coeff;
    }
    else if(c.coeff==0) throw runtime_error("Cant solve this question");
    return std::complex<double>(r,i);
}

double solver::solve (const RealVariable& r){
    double ans;
    if(r.a!=0 && r.b==0 && r.c==0) ans= 0;                                                         //a
    if(r.a==0 && r.b!=0 && r.c==0) ans= 0;                                                         //b
    if(r.a==0 && r.b==0 && r.c!=0) throw runtime_error("There is no solution to this equation");     //c
    if(r.a!=0 && r.b!=0 && r.c==0) ans= 0;                                                         //a,b
    if(r.a!=0 && r.b==0 && r.c!=0){                                                                  //a,c
        if((-r.c<0 && r.a>0) || (-r.c>0 && r.a<0)) throw runtime_error("There is no solution to this equation ");
        else ans= sqrt((-r.c)/r.a);
    }
    if(r.a==0 && r.b!=0 && r.c!=0) ans= (-r.c)/r.b;                                                //b,c
    if(r.a!=0 && r.b!=0 && r.c!=0)ans= (-r.b + sqrt(pow(r.b,2)-4*r.a*r.c))/2*r.a;             //a,b,c                                                                                      //a,b,c
    return ans;
}

ComplexVariable solver::operator == (const ComplexVariable& r1,const ComplexVariable& r2 ){
    return r1-r2;

}
ComplexVariable solver::operator == (const ComplexVariable& r1,std::complex<double> r2){
    ComplexVariable new_var;
    new_var.real=r1.real;
    new_var.image=r1.image-r2.imag();
    new_var.coeff=r1.coeff;
    new_var.power=r1.power;
    return new_var;


}

