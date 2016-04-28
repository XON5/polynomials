#include "polynomialclass.h"
#include <math.h>
using namespace std;

Polynomial::Polynomial() {
    fDegree = 0;
    for(int i = 0; i < MAX_DEGREE; i++) {
        fCoefficient[i] = 0;
    }
}

Polynomial Polynomial::operator* (const Polynomial& aRightPoly) const {
    Polynomial resultPoly;
    resultPoly.fDegree = fDegree + aRightPoly.fDegree;
    
    //For all values of Left Side Polynomial
    for(int i = 0; i <= fDegree; i++) {
        //For all values of Right Side Polynomial
        for(int j = 0; j <= aRightPoly.fDegree; j++) {
            resultPoly.fCoefficient[i + j] += fCoefficient[i] * aRightPoly.fCoefficient[j];
        }
    }
    
    return resultPoly;
}

std::istream& operator>>(std::istream& aIStream, Polynomial& aPolynommial) {
    aIStream >> aPolynommial.fDegree;
    
    //For all degrees include ^0 to specified degree.
    for(int i = 0; i <= aPolynommial.fDegree; i++) {
        //Input from lowest degree (^0) to max specified
        aIStream >> aPolynommial.fCoefficient[i];
    }
    
    return aIStream;
}

std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aPolynomial) {
    
    //For all the coeffecients in the polynomial
    for(int i = 0; i <= aPolynomial.fDegree; i++) {
        aOStream << aPolynomial.fCoefficient[i] << "x^" << i;
        
        //If not the highest coeffecient include the addition sign (Concatenation)
        if(i != aPolynomial.fDegree) {
            aOStream << " + ";
        }
        
    }
    return aOStream;
}

double Polynomial::calculate(double aX) const {
    double resultDouble;
    
    for(int i = 0; i <= fDegree; i++) {
        resultDouble += fCoefficient[i] * pow(aX, i);
    }
    
    return resultDouble;
}

Polynomial Polynomial::buildIndefiniteIntegral() const {
    Polynomial resultPoly;
    resultPoly.fDegree = fDegree + 1;
    
    for(int i = 0; i <= fDegree; i++) {
        //next degree coeffecient = (current coeffecient/(current degree + 1))
        resultPoly.fCoefficient[i + 1] = (fCoefficient[i] / (i + 1));
    }
    
    return resultPoly;
}

double Polynomial::buildDefiniteIntegral(double aLowX, double aHighX) const {
    double resultDouble;
    resultDouble = buildIndefiniteIntegral().calculate(aHighX) - buildIndefiniteIntegral().calculate(aLowX);
    return resultDouble;
}