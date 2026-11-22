#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fraction_utils.h"

using namespace std;

// TODO

bool is_equal(const Fraction& first_fraction,
              const Fraction& second_fraction){
    if (first_fraction.denominator*second_fraction.numerator == first_fraction.numerator*second_fraction.denominator){
        return 1;
    } else {
        return 0;    
    }
}

bool is_greater(const Fraction& first_fraction,
                const Fraction& second_fraction){
    if (first_fraction.numerator*second_fraction.denominator>second_fraction.numerator*first_fraction.denominator){
        return 1;
    } else {
        return 0;
    }
}   
                
bool is_less(const Fraction& first_fraction,
             const Fraction& second_fraction){
    if (first_fraction.numerator*second_fraction.denominator<second_fraction.numerator*first_fraction.denominator){
        return 1;
    } else {
        return 0;
    }             
}
             
void auto_test_fraction(
    std::string input_file_name,
    std::string output_file_name){
    ifstream fin(input_file_name);
    string line;
    int t;
    if (fin.is_open() and getline(fin, line)){
        stringstream ss(line);
        if (ss>>t){
        } else {
            cout<<"Khong hop le."<<endl;
        }

    } else {
        cerr<<"Khong the mo tep "<<input_file_name<<endl;
        return 1;    
    }
    
    for (int i=0;i<t;i++){
        char c;
        getline(fin,ss);        
        ss>>c;
        Fraction res;
        switch (c)
        {
        case '+':
            int i=0;
            string op;
            getline(fin, op);
            while (!op.empty() && (op.back() == '\r' || op.back() == ' ' || op.back() == '\n')) {
                op.pop_back();
            }
            Fraction old={0,1};
            Fraction fs[6];
            string fraction;
            while (getline(fin, fraction, ',')){
                fs[i]=parse_fraction_from_string(fraction);
                old = sum_fraction(old, fs[i]);
                i++;
            }
            res=old;
        break;
        
        case '-':
            int i=0;
            string op;
            getline(fin, op);
            while (!op.empty() && (op.back() == '\r' || op.back() == ' ' || op.back() == '\n')) {
                op.pop_back();
            }
            Fraction old;
            Fraction fs[6];
            string fraction;
            getline(fin,fraction,',');
            fs[0]=parse_fraction_from_string(fraction);
            i++;
            old =fs[0];
            while (getline(fin, fraction, ',')){
                fs[i]=parse_fraction_from_string(fraction);
                old = minus_fraction(old, fs[i++]);
            }
            res=old;
        break;
        
        
        default:
            break;
        }
    }
}

Fraction parse_fraction_from_string(string s) {
    string clean_s = "";
    for (char c : s) {
        if (c != ' ' && c != '\r') clean_s += c;
    }
    stringstream ss(clean_s);
    long long num = 0, den = 1;
    char slash;
    ss >> num >> slash >> den;
    return {(int)num, (int)den};
}

Fraction reduce_fraction(const Fraction& fraction){
    Fraction f=fraction;
    if (fraction.numerator==0){
        f.numerator=0;
        f.denominator=1;
        return f;
    }
    bool isNegative = (fraction.denominator*fraction.numerator<0);
    
    int a=f.numerator,b=f.denominator;
    while (b!=0){
        int r= a%b;
        a=b;
        b=r;
    }
    if (isNegative) a=-a;
    f.numerator=f.numerator/a;
    f.denominator=f.denominator/a;
    
    if (f.denominator<0){
        f.denominator=-f.denominator;
        f.numerator=-f.numerator;
    }
    return f;
}

Fraction sum_fraction(const Fraction& first_fraction,
                      const Fraction& second_fraction){
    Fraction f;
    f.numerator = first_fraction.numerator*second_fraction.denominator + first_fraction.denominator*second_fraction.numerator;
    f.denominator = first_fraction.denominator*second_fraction.denominator;
    f = reduce_fraction(f);
    return f;
}
                      
Fraction minus_fraction(const Fraction& first_fraction,
                        const Fraction& second_fraction){
    Fraction f;
    f.numerator = first_fraction.numerator*second_fraction.denominator - first_fraction.denominator*second_fraction.numerator;
    f.denominator = first_fraction.denominator*second_fraction.denominator;
    f = reduce_fraction(f);
    return f;
}

Fraction multiply_fraction(const Fraction& first_fraction,
                           const Fraction& second_fraction){
    Fraction f;
    f.numerator = first_fraction.numerator*second_fraction.numerator;
    f.denominator = first_fraction.denominator*second_fraction.denominator;
    f = reduce_fraction(f);
    return f;
}

Fraction divide_fraction(const Fraction& first_fraction,
                         const Fraction& second_fraction){
    Fraction f,f2;
    f2.denominator=second_fraction.numerator;
    f2.numerator = second_fraction.denominator;
    f = multiply_fraction(first_fraction,f2);
    f = reduce_fraction(f);
    return f;
}


// END TODO