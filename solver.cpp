#define EPSILON 0.0001
#include "solver.hpp"
using namespace solver;

 RealVariable& solver::operator * (RealVariable& r,double n){
     return r;
 }

 RealVariable& solver::operator * (double n,RealVariable& r){
     return r;
 }
 
 RealVariable& solver::operator * (RealVariable& r1, RealVariable& r2){
     return r1;

 }
 RealVariable& solver::operator ^ (RealVariable& r, double n){
     return r;

 }
 RealVariable& solver::operator - (double n, RealVariable& r){
     return r;

 }
 RealVariable& solver::operator - (RealVariable& r, double n){
     return r;

 }
 RealVariable& solver::operator - (RealVariable& r1, RealVariable& r2){
     return r1;
 }
 RealVariable& solver::operator + (RealVariable& r,double n){
     return r;
 }
 RealVariable& solver::operator + (double n,RealVariable& r){
     return r;
 }
 RealVariable& solver::operator + (RealVariable& r1,RealVariable& r2){
     return r1;
 }
 RealVariable& solver::operator / (RealVariable& r,double n){
     return r;
 }
 RealVariable& solver::operator / (double n,RealVariable& r){
     return r;
 }
 RealVariable& solver::operator / (RealVariable& r1,RealVariable& r2){
     return r1;
 }
 RealVariable& solver::operator == (RealVariable& r, double n){
     return r;
 }
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



