#pragma once
#include <iostream>
#define MAX_DEGREE 20+1+1 //+1 for Multiplication, another +1 for integral

class Polynomial {
private:
    int fDegree;
    double fCoefficient[MAX_DEGREE];
    
public:
    Polynomial();
    Polynomial operator* (const Polynomial& aRightPoly) const;
    friend std::istream& operator>>(std::istream& aIStream, Polynomial& aPolynommial);
    friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aPolynomial);
    
    double calculate(double aX) const;
    Polynomial buildIndefiniteIntegral() const;
    double buildDefiniteIntegral(double aLowX, double aHighX) const;
    
};