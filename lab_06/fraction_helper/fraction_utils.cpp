#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fraction_utils.h"

using namespace std;

// TODO

bool is_equal(const Fraction& first_fraction,
              const Fraction& second_fraction){
    return first_fraction.denominator*second_fraction.numerator == first_fraction.numerator*second_fraction.denominator;
}

bool is_greater(const Fraction& first_fraction,
                const Fraction& second_fraction){
    return first_fraction.numerator*second_fraction.denominator>second_fraction.numerator*first_fraction.denominator;
}   
                
bool is_less(const Fraction& first_fraction,
             const Fraction& second_fraction){
    return first_fraction.numerator*second_fraction.denominator<second_fraction.numerator*first_fraction.denominator;   
}
             
void auto_test_fraction(string input_file_name,string output_file_name){
    int err=0;
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
        return;    
    }
    char op;
    fin>>op; fin.ignore();
    ofstream fout(output_file_name);
    for (int i=0;i<t;i++){
        int count =0;
        Fraction fracs[6];
        getline(fin,line);
        if (line ==" \t\r\n") continue;
        stringstream ss(line);
        if (op == '+' or op=='-' or op=='*' or op=='/'){
            string fraci;
            while (getline(ss,fraci,',')){
                if (fraci==" \t\r\n") break;
                stringstream fraci_ss(fraci);
                string de, num="";
                getline(fraci_ss,num,'/');
                getline(fraci_ss,de);
                if (num=="") break;
                cout<<"op "<<err++<<endl;
                fracs[count].numerator=stoi(num);
                fracs[count].denominator=stoi(de);
                count++;
            }
            for (int j=1;j<count;j++){
                if (op=='+'){
                    fracs[0]=sum_fraction(fracs[0], fracs[j]);
                } else if (op =='-') {
                    fracs[0]=minus_fraction(fracs[0], fracs[j]);
                } else if (op=='*'){
                    fracs[0]=multiply_fraction(fracs[0], fracs[j]);
                } else {
                    fracs[0]=divide_fraction(fracs[0], fracs[j]);
                }
            }
            fout<<fracs[0].numerator<<"/"<<fracs[0].denominator<<endl;
        } else {
            Fraction f1,f2;
            string frac1, frac2;
            string frac1de,frac1num, frac2de,frac2num;
            getline(fin,frac1,',');
            fin>>frac2;
            fin.ignore();
            stringstream frac1_ss(frac1),frac2_ss(frac2);
            getline(frac1_ss,frac1num, '/');
            frac1_ss>>frac1de;
            frac1_ss.ignore();
            getline(frac2_ss, frac2num, '/');
            frac2_ss>>frac2de;
            frac2_ss.ignore();
            cout<<err++<<endl;
            f1.denominator = stoi(frac1de);
            f1.numerator = stoi(frac1num);
            f2.denominator = stoi(frac2de);
            f2.numerator = stoi(frac2num);
            if (op == '>'){
                fout<<is_greater(f1, f2)<<endl;
            } else if (op == '='){
                fout<<is_equal(f1,f2)<<endl;
            } else {
                fout<<is_less(f1,f2)<<endl;
            }
        }
    }
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