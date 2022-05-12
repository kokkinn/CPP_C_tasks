#include <iostream>
#include <cmath>

using namespace std;
int NOD(int num1, int num2) {
    for (int i = num1>=num2 ? num1 : num2; i >= 2; i--){
            if (num1%i == 0 && num2%i == 0)
                return i;
    }
    return 1;
}

int NOK(int num1, int num2) {
    for (int j = num1>=num2 ? num1 : num2; j <= num1*num2; j++){
        if (not j%num1 && not j%num1)
            return j;         
    }
    return num2*num1;
}

class Fraction {
    private:
    int numerator, denominator;
    int numer_sqrt_val;

    public:
    Fraction(int numer, int denom) {
        if (denom == 0) throw std::invalid_argument("incorrect denominator");
        int nod = NOD(numer, denom); 
        if (nod != 1) {this->numerator = numer/nod; this->denominator = denom/nod;}
        else {this->numerator=numer; this->denominator=denom;} this->numer_sqrt_val=1;
    };
   
    int get_numer() {return numerator;}
    int get_denom() {return denominator;}

    void set_numer_sqrt_val(int a){
        numer_sqrt_val = a;}

    friend ostream& operator<<(ostream& os, const Fraction& fr)
    { 
        bool numer_eql_1 = fr.numerator == 1 ? true : false;
        bool denom_eql_1 = fr.denominator == 1 ? true : false;
        bool numer_sqrt_val_eql_1 = fr.numer_sqrt_val == 1 ? true : false;

        if (numer_sqrt_val_eql_1 && denom_eql_1){
            cout << fr.numerator;
            return os;
            }
        else if(not numer_eql_1 && not denom_eql_1 && not numer_sqrt_val_eql_1){
            cout << fr.numerator << "sqrt(" << fr.numer_sqrt_val << ")" << "/" << fr.denominator;
            return os;
        }
        else if(numer_sqrt_val_eql_1 && not denom_eql_1){
            cout << fr.numerator << "/" << fr.denominator;
            return os;
        }
        else if(not numer_sqrt_val_eql_1 && denom_eql_1 && numer_eql_1){
            cout << "sqrt(" << fr.numer_sqrt_val << ")";
            return os;
            }
        
        else{
            return os;
        }
    }

    
    friend Fraction operator+(Fraction const &fr1, Fraction const &fr2){
        if (fr1.denominator == fr2.denominator)
            return Fraction(fr1.numerator + fr2.numerator, fr1.denominator);
        else {
            int nok = NOK(fr1.denominator, fr2.denominator);
            return Fraction(fr1.numerator*nok/fr1.denominator + fr2.numerator*nok/fr2.denominator, nok);
        }
    }

    friend Fraction operator-(Fraction const &fr1, Fraction const &fr2){
        if (fr1.denominator == fr2.denominator)
            return Fraction(fr1.numerator - fr2.numerator, fr1.denominator);
        else {
            int nok = NOK(fr1.denominator, fr2.denominator);
            return Fraction(fr1.numerator*nok/fr1.denominator - fr2.numerator*nok/fr2.denominator, nok);
        }
    }

    friend Fraction operator*(Fraction const &fr1, Fraction const &fr2){
            return Fraction(fr1.numerator*fr2.numerator, fr1.denominator*fr2.denominator);
    }
    
    friend Fraction operator/(Fraction const &fr1, Fraction const &fr2){
            return Fraction(fr1.numerator*fr2.denominator, fr1.denominator*fr2.numerator);
    }
};

bool isPerfectSquare(long double x) 
{   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 


Fraction sqrtt(Fraction n){
        
    int num = n.get_numer();
    int den = n.get_denom();

    if (isPerfectSquare(num) && isPerfectSquare(den))
        return Fraction(sqrt(num), sqrt(den));
    else if (isPerfectSquare(num) && not isPerfectSquare(den)){
        Fraction a(sqrt(num), den);
        a.set_numer_sqrt_val(den);
        return a;
    }
    else if (not isPerfectSquare(num) && isPerfectSquare(den)){
        Fraction a(1, sqrt(den));
        a.set_numer_sqrt_val(num);
        return a;
    }
    else {
        return Fraction (sqrt(num), sqrt(den));
    }
};
 

class Complex {
    private:
    Fraction modulus;
    Fraction real;
    Fraction imag;

    public:

    Complex(Fraction re, Fraction im) : real(re), imag(im), modulus(sqrtt((re*re) + (im*im))){
    };

    Complex(int re, int im) : real(Fraction(re, 1)), imag(Fraction(im, 1)), modulus(sqrtt((Fraction(re, 1)*Fraction(re, 1)) + (Fraction(im, 1)*Fraction(im, 1)))) {};
    
    Fraction get_modulus(){ 
        return modulus;
    }

    Fraction get_real(){
        return real;  
    }

    Fraction get_imag(){
        return imag;
    }

    void conjugate(){
        this->imag = this->imag - this->imag * Fraction(2, 1); 
    }

    friend ostream& operator<<(ostream& os, const Complex& complex) {
    os << complex.real << "+" << "(" << complex.imag << ")" << "i";
    return os;
    }

    friend Complex operator+(const Complex& num1, const Complex& num2){
        return Complex(num1.real+num2.real, num1.imag+num2.imag);
    }

    friend Complex operator-(const Complex& num1, const Complex& num2){
        return Complex(num1.real-num2.real, num1.imag-num2.imag);
    }

    friend Complex operator*(const Complex& num1, const Complex& num2){
        return Complex((num1.real*num2.real) - (num1.imag*num2.imag), (num1.real*num2.imag) + (num1.imag*num2.real));
    }

    friend Complex operator/(const Complex &num1, const Complex &num2);
    
};


Complex operator/(const Complex &num1, const Complex &num2)
    { 
        Fraction reall(((num1.real*num2.real) + (num1.imag*num2.imag))/((num2.real*num2.real) + (num2.imag*num2.imag)));
        Fraction imagg(((num2.real*num1.imag) - (num1.real*num2.imag))/( (num2.real*num2.real) + (num2.imag*num2.imag)));
        return Complex(reall, imagg);
    };


int main(){

    Fraction fr1(2, 4);
    cout << endl << "Fraction 1: " << fr1 << endl;
    Fraction fr2(6, 8);
    cout <<  "Fraction 2: " << fr2 << endl << endl;

    cout << "Sum of Fraction 1, Fraction 2: " << fr1+fr2 << endl;
    cout << "Subtraction of Fraction 1, Fraction 2: " << fr1-fr2 << endl;
    cout << "Multiplication of Fraction 1, Fraction 2: " << fr1*fr2 << endl;
    cout << "Division of Fraction 1, Fraction 2: " << fr1/fr2 << endl << endl;

    Complex comp1(4, 3); 
    cout << "Complex number 1: " << comp1 << endl;
    Complex comp2(1, -4);
    cout << "Complex number 2: " << comp2 << endl;
    comp1.conjugate();
    comp2.conjugate();
    cout << "Conjugated Complex number 1: " << comp1 << endl;
    cout << "Conjugated Complex number 2: " << comp2 << endl;
    cout << "Modulus of Complex number 1: " << comp1.get_modulus() << endl;
    cout << "Modulus of Complex number 2: " << comp2.get_modulus() << endl << endl;


    cout << "Sum of Complex number 1, Complex number 2: " << comp1+comp2 << endl;
    cout << "Subtraction of Complex number 1, Complex number 2: " << comp1-comp2 << endl;
    cout << "Multiplication of Complex number 1, Complex number 2: " << comp1*comp2 << endl;
    cout << "Division of Complex number 1, Complex number 2: " << comp1/comp2 << endl;


    return 0;
};
   
    
    
