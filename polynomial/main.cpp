#include <iostream>
#include "polynomialclass.h"
using namespace std;

int main() {
    
    Polynomial A;
    cout << "Specify the first polynomial (A) with the degree follwed by coeffecients:" << endl;
    cin >> A;
    cout << "Let A = " << A << endl;
    
    Polynomial B;
    cout << "Specify the first polynomial (B) with the degree follwed by coeffecients:" << endl;
    cin >> B;
    cout << "Let B = " << B << endl;
    
    Polynomial C = A * B;
    cout << "Let C = A * B = " << C << endl;
    
    Polynomial D;
    cout << "Specify a new polynomial (D): " << endl;
    cin >> D;
    cout << "Let D = " << D << endl;
    
    cout << "Give a value for x: ";
    double lx;
    cin >> lx;
    
    cout << "D(" << lx << ") = " << D.calculate(lx) << endl;
    cout << "Let E = dx/dy (D) = " << D.buildIndefiniteIntegral() << endl;
    cout << "Let E(12.0, 0.0) = " << D.buildDefiniteIntegral(0.0, 12.0) << endl;
    
    return 0;
}