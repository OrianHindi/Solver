#include "solver.hpp"
#include "doctest.h"
#include <complex>
using namespace solver;
using namespace std;
RealVariable x;
ComplexVariable c;

TEST_CASE("Checking the correctness of the exercise"){
            CHECK(solve(2*x == 10)==5);
            CHECK(solve(x*2 == 10)==5);
            CHECK(solve(5+x == 20)==15);
            CHECK(solve(x+5 == 20)==15);
            CHECK(solve(20-1*x == 20)==0);
            CHECK(solve(x-20 == 20)==40);
            CHECK(solve(-1*x==20)==-20);
            CHECK(solve(5/x == 1)==5);
            CHECK(solve(x/5 == 1)==5);
            CHECK((solve((x^2) == 25)==5 || solve((x^2) == 25)==-5));
}//10

TEST_CASE("Testing Commutative equations"){
            CHECK(solve(x*2 == 10)==solve(2*x == 10));
            CHECK(solve(x+5 == 20)==solve(5+x == 20));
            CHECK(solve(5/x == 1)==solve(x/5 == 1));                           //The '/' operator is not commutative, but sometimes give the same result
            CHECK_FALSE(solve(6/x == 2)==solve(x/6 == 2));                     //The left side need return 3, but the right side need return 12
            CHECK_FALSE(solve(20-x == 20)==solve(x-20 == 20));                 //The left side need return 0, but the right side need return 40
            CHECK_FALSE(solve(20*x==20)==solve(20*x==-20));
            CHECK(solve(x-2*x==-40)==40);
            CHECK(solve(2*x==4)==1.99999);
            CHECK(solve(2*x==-4)==-1.9999);
            CHECK((solve((x^2)==1)==1 || solve((x^2)==1)==-1));
            CHECK(solve(x+x==4)==solve(2*x==4));
            CHECK((solve((x^2)+2*x==-3)==1 || solve((x^2)+2*x==-3)==-3));
            CHECK((solve((x^2)+2*x+3==0)==1 || solve((x^2)+2*x+3==0)==-3));
}


TEST_CASE("Tests without organ assembly"){
            CHECK(solve(2*x==2+2+2+2+2)==5);
            CHECK(solve(x+x == 10)==5);
            CHECK(solve(x+x == 5)==2.5);
            CHECK(solve(5+5+x == 20)==10);
            CHECK(solve(x+x+5 == 20)==7.5);
            CHECK(solve(10+10-x == 20)==0);
            CHECK(solve(x+x-20 == 20)==20);
            CHECK(solve(4*x-4*x+x/2==4)==8);
            CHECK(solve(3*x==3)==1);
            CHECK(solve((3+2)/x == 1)==5);
            CHECK(solve((x+x)/5 == 1)==2.5);
            CHECK((solve(((x+x)^2) == 25)==2.5 || solve(((x+x)^2) == 25)==-2.5));
}//9

TEST_CASE("exceptions"){
            CHECK_THROWS(solve(x*x*x==9));
            CHECK_THROWS(solve((x^2)==-16));
            CHECK_THROWS(solve(x*x==-16));
            CHECK_THROWS(solve((x^2)+30==15));
            CHECK_THROWS(solve((x^2)==4));
            CHECK_THROWS(solve(x/0));
            CHECK_THROWS(solve((x*x)/0));
            CHECK_THROWS(solve((x^7)+40==10));
            CHECK_THROWS(solve((x^2)*x==4*x-4));
            CHECK_THROWS(solve(4/x==(x^3)));
}

TEST_CASE("ComplexVariables"){
            CHECK(solve(c+3i==2i) == complex<double> (0.0,-1.0));
            CHECK(solve(2*c+5==4*c-3)==complex<double> (4.0,0.0));
            CHECK((solve((c^2)==16)==complex<double> (4.0,0.0) || solve((c^2)==16)==complex<double> (4.0,0.0)));
            CHECK((solve((c^2)==-16)==complex<double> (0.0,4.0) || solve((c^2)==-16)==complex<double> (0.0,-4.0)));
            CHECK((solve(c*c+4i==5i)==complex<double> (0.0,1.0) || solve(c*c+4i==5i)==complex<double> (0.0,-1.0)));
            CHECK(solve(2*c+4==3*c+2i)==complex<double> (4.0,-2.0));
            CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
            CHECK(solve(4*c-c+c==0)==complex<double> (0.0,0.0));
            CHECK(solve(c+2i==2*c-5)==complex<double> (5.0,2.0));
            CHECK(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,1.0));

}

TEST_CASE("FALSE ComplexVariable"){
            CHECK_FALSE(solve(c+3i==2i) == complex<double> (3.0,-1.0));
            CHECK_FALSE(solve(2*c+5==4*c-3)==complex<double> (2.0,0.0));
            CHECK_FALSE((solve((c^2)==16)==complex<double> (4.0,1.0) || solve((c^2)==16)==complex<double> (4.0,1.0)));
            CHECK_FALSE((solve((c^2)==-16)==complex<double> (4.0,4.0) || solve((c^2)==-16)==complex<double> (4.0,-4.0)));
            CHECK_FALSE((solve(c*c+4i==5i)==complex<double> (1.0,1.0) || solve(c*c+4i==5i)==complex<double> (1.0,-1.0)));
            CHECK_FALSE(solve(2*c+4==3*c+2i)==complex<double> (4.0,2.0));
            CHECK_FALSE((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,1.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,1.0)));
            CHECK_FALSE(solve(4*c-c+c==0)==complex<double> (1.0,0.0));
            CHECK_FALSE(solve(c+2i==2*c-5)==complex<double> (-5.0,2.0));
            CHECK_FALSE(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,-1.0));
}
TEST_CASE("ComplexVariable 2"){
            CHECK(solve(4+c+3i==2i) == complex<double> (-4.0,-1.0));
            CHECK(solve(2*c+2i==4*c-8)==complex<double> (4.0,1.0));
            CHECK((solve((c^2)==4)==complex<double> (2.0,0.0) || solve((c^2)==16)==complex<double> (-2.0,0.0)));
            CHECK((solve((c^2)==-25)==complex<double> (0.0,5.0) || solve((c^2)==-16)==complex<double> (0.0,-5.0)));
            CHECK((solve(c*c+4i==8i)==complex<double> (0.0,2.0) || solve(c*c+4i==5i)==complex<double> (0.0,-2.0)));
            CHECK(solve(2*c+4i==3*c+2i)==complex<double> (0.0,2.0));
            CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
            CHECK(solve(4*c-c+c==4)==complex<double> (1.0,0.0));
            CHECK(solve(c+2i==2*c+5i)==complex<double> (0.0,-3.0));
            CHECK(solve(2*c-c+4==-1*c+2i)==complex<double> (-2.0,1.0));
            CHECK(solve(3+c+3i==2i) == complex<double> (-3.0,-1.0));
            CHECK(solve(2*c+2i==4*c-6)==complex<double> (3.0,1.0));
            CHECK(solve(2*c+4==3*c+2)==complex<double> (2.0,0.0));
            CHECK((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (4.0,0.0) || solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c)==complex<double> (-4.0,0.0)));
            CHECK(solve(4*c-c-4*c==4)==complex<double> (-4.0,0.0));
            CHECK(solve(5+c+2i==2*c+5i)==complex<double> (5.0,-3.0));
            CHECK(solve(2*c-c+4==2i)==complex<double> (-4.0,2.0));
            CHECK((solve((c^2)==100)==complex<double> (10.0,0.0) || solve((c^2)==100)==complex<double> (-10.0,0.0)));
            CHECK((solve((c^2)==-64)==complex<double> (0.0,8.0) || solve((c^2)==64)==complex<double> (0.0,-8.0)));
            CHECK((solve(c*c+4i==20i)==complex<double> (0.0,4.0) || solve(c*c+4i==5i)==complex<double> (0.0,-4.0)));
}

TEST_CASE("Another cases"){
            CHECK_THROWS(solve(2*x==2^4));
            CHECK(solve(x*25 == 25)==1);
            CHECK(solve(5*x+x*5 == 20)==2);
            CHECK(solve(3*4*x+1 == 25)==2);
            CHECK(solve((x^2)*4== 100)==5);
            CHECK(solve(x/x == 1)==1);
            CHECK(solve(x/2+5*x == 55)==10);
            CHECK(solve(x/0.5 == 4)==solve(x*2 == 4));
            CHECK(solve(x == 1)==1);
            CHECK(solve(2*x==0)==0);
            CHECK(solve(x+x+2*x == 20)==5);
            CHECK(solve(50*x == 100)==2);
            CHECK(solve(x*x+1+1 == 27)==5);
            CHECK(solve(2.5*x+2.5*x== 100)==20);
            CHECK((solve(((2+x)^2) == 25)==3 || solve(((2+x)^2) == 25)==-7));
}