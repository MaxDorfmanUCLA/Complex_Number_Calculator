//
//  Header.h
//  HW5_PIC10B
//
//  Created by Max Dorfman on 2/21/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
// I Max Dorfman declare that this work is my own and i did not work with anyone else on this code

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

// Complex class with function defenitions declared in class for ease of reference




class Complex{
private:
    double r; // member variable (real part)
    double i; // member variable (imaginary part)
public:
    Complex(double r = 0, double i = 0): r(r), i(i){} // constructor that can take agruments or set default init to 0
    /**
     operator for addition assignment
     
     @param c reference to const complex object being used to assign implicit
     */
    Complex& operator+=(const Complex& c){
        r += c.r;
        i += c.i;
        return *this;
    }
    /**
     operator for unary plus just returns reference to object because and x, such that +x, is still x
          */
    Complex& operator+(){
        return *this;
    }
    /** 
     prefix increment operator returns incremented object
     */
    Complex& operator++(){
        ++r; // only real part is incremented
        return *this;
    }
    /**
     postfix increment operator returns copy, then increments object
     */
    Complex operator++(int unused){ //int unsd so that postfix ++ has different func signature
        Complex tempc(*this);
        ++r;// only real part is incremented
        return tempc;
    }
    /**
     operator for subtraction assignment
     
     @param c reference to const complex object being used to assign implicit
     */
    Complex& operator-=(const Complex& c){
        r -= c.r;
        i -= c.i;
        return *this;
    }
    /**
     operator for unary minus operator returns sets both real and imaginary part to neg and returns object*/
    Complex& operator-(){
        r = -r;
        i = -i;
        return *this;
    }
    /**
     prefix increment operator returns incremented object
     */
    Complex& operator--(){
        --r;
        return *this;
    }
    /**
     postfix increment operator returns copy, then increments object
     */
    Complex operator--(int unused){ //int unsd so that postfix ++ has different func signature
        Complex tempc(*this);
        --r;
        return tempc;
    }
    /** multiplication assignment operator
     
     @param c other Complex object used to multiply by implicit*/
    Complex& operator*=(const Complex& c){
        r = ((r*c.r)-(i*c.i));
        i = ((i*c.r)+(r*c.i));
        return *this;
    }
    /** division assignment operator
     
     @param c other Complex object used to divie implicit by*/
    Complex& operator/=(const Complex& c){
        r = ((r*c.r)+(i*c.i))/(((c.r)*(c.r))+((c.i)*(c.i)));
        i = ((i*c.r)-(r*c.i))/(((c.r)*(c.r))+((c.i)*(c.i)));
        return *this;
    }
    /**call operator initializing real and imaginary part to 0
     */
    Complex& operator()(){
        r = 0;
        i = 0;
        return *this;
    }
    /** helper function indexCheck returns a unique int for literal real or fake that can be used in switch
     
     @param ind string to compare to literal we want*/
    int indexCheck(const std::string& ind){
        if (ind == "real")
            return 1;
        else if (ind == "imag")
            return 2;
        else
            return 0;
    }
    /** index operator uses switch statement to catch a case, and throws an error as default
     
     @param ind string that in compared to literals real or imaginary*/
    double& operator[](const std::string& ind){
        switch (indexCheck(ind)){
                case 1: return r; break;
                case 2: return i; break;
                default: throw std::out_of_range("Index Out of Bounds"); break;
            }
    }
    /**
     input operator reads in real and imaginary parts and assigns from input stream
     
     @param in the input stream chosen
     @param c the complex object that is being taken in
     */
    friend std::istream& operator>>(std::istream& in, Complex& c){
        in>>c.r>>c.i;
        return in;
    }
    /**
     input operator reads in real and imaginary parts and assigns from input stream
     
     @param out the output stream chosen
     @param c the complex object that is being output
     */
    friend std::ostream& operator<<(std::ostream& out, Complex c){
        if(c.i>=0){
            out<<c.r<<'+'<<c.i<< 'i'<<"/n";
            return out;
        }
        else {
            out<<c.r<<c.i<<'i'<<"/n";
            return out;
        }
    }
    /**
     function less than defined according to rules for complex numbers
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator<(const Complex& c1, const Complex& c2){
     if (c1.r<c2.r)
         return true;
     else {
         if ((c1.r==c2.r) && (c1.i<c2.i))
             return true;
         else if ((c1.r==c2.r) && (c1.i>c2.i))
             return false;
         else
             return false;
        }
    }
    /**
     function greater than defined according to rules for complex numbers
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator>(const Complex& c1, const Complex& c2){
        if (c1.r>c2.r)
            return true;
        else {
            if ((c1.r==c2.r) && (c1.i>c2.i))
                return true;
            else if ((c1.r==c2.r) && (c1.i<c2.i))
                return false;
            else
                return false;
        }
    }
    /**
     function equals defined from defenitions of <,>
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator==(const Complex& c1, const Complex& c2){
        return !((c1<c2) || (c1>c2));
    }
    /**
     function not equal defined from defenitions of <,>
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator!=(const Complex& c1, const Complex& c2){
        return ((c1<c2) || (c1>c2));
    }
    /**
     function less than or equal to defined from defenitions of <,>
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator<=(const Complex& c1, const Complex& c2){
        return !(c1>c2);
    }
    /**
     function greater than or equal to defined from defenitions of <,>
     
     @param c1 complex object one
     @param c2 complex object 2 being compared with 1
     */
    friend bool operator>=(const Complex& c1, const Complex& c2){
        return !(c1<c2);
    }
    operator std::string(){
        std::string str;
        str += r;
        if(i>0){
            str += '+';
        }
        else if (i<0){
            str+='-';
        }
        str += i;
        return str;
    }
};

//Outside the class

/** binary addition operator
 
 @param c1 complex number being added
 @param c2 complex number being added
 */
Complex operator+(Complex c1, const Complex& c2){
    c1 += c2;
    return c1;
}
/** binary subtraction operator
 
 @param c1 complex number
 @param c2 complex number being subtracted
 */
Complex operator-(Complex c1, const Complex& c2){
    c1 -= c2;
    return c1;
}
/** binary multiplication operator
 
 @param c1 complex number being multiplied
 @param c2 complex number being multiplied
 */
Complex operator*(Complex c1, const Complex& c2){
    c1 *= c2;
    return c1;
}
/** binary division operator
 
 @param c1 complex number being divided
 @param c2 complex number being divided
 */
Complex operator/(Complex c1, const Complex& c2){
    c1 /= c2;
    return c1;
}
/**
 user defined literal for complex class
 
 @param ptr pointer to const char used to read literal statement
 */
Complex operator""_i(const char* ptr){
    Complex c;
    std::string real;
    std::string imag;
    std::string temp;
    while (ptr!=nullptr){ //increment ptr through all input chars
        ++ptr;
        temp.push_back(*ptr);
        if (*ptr+1=='-'){ // if we hit a minus, we know there is an imaginary part as well
            real=temp; // we know that if we encounter a plus or minus that our first string must be the real
            while (ptr!=nullptr){
                if (*ptr+1=='0')
                    imag = '0';
                else
                    imag.push_back(*ptr+1); // fill imaginary part
            }
        }
        if (*ptr+1=='+'){
            real=temp; // we know that if we encounter a plus or minus that our first string must be the real
            while (ptr!=nullptr){
                if (*ptr+1=='0')
                    imag = '0';
                else
                    imag.push_back(*ptr+2); // fill imaginary part
            }
        }
        else {
            imag=temp;
            real = '0';
        }
    }
c[real]=stod(real);
c[imag]=stod(imag);
return c;
}

#endif /* Header_h */
