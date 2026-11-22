#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fraction_helper/fraction_utils.h"
#include "student_helper/student_utils.h"

using namespace std;

// TODO

// END TODO


int main () {
    // TODO
    ifstream fin("fraction_helper/test_result/input_fraction.txt");
    if (!fin){
        cerr<<"Error opening file."<<endl;
        return 1;
    }
    Fraction f1={2,4};
    Fraction f2={17,4};
    f1=minus_fraction(f1,f2);
    cout<<f1.numerator<<"/"<<f1.denominator;
    
    // END TODO
    fin.close();
    return 0;
}