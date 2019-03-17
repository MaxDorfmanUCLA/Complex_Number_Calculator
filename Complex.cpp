//
//  main.cpp
//  HW5_PIC10B
//
//  Created by Max Dorfman on 2/21/17.
//  Copyright © 2017 Max Dorfman. All rights reserved.
//

#include "Complex.h"
#include <vector>
#include <algorithm>
#include<iostream>

int main(){
    // Create Complex numbers through constructors
    Complex z1, z2(4), z3(3, 4), z4(-1, -3.7);
    z2 *= 2; // multiply by 2 (which will be converted to Complex(2,0)
    // Create with user-defined literal
    Complex z5 = 3.14 - 14.3_i;
    std::cout << "Numbers: " << z1 << " " << z2 << " " << z3 << " " << z4 << " " << z5 << std::endl;
    
    // Do some arithmetic to them and check values
    z4 += z3;	z2 /= z3;	z3();
    z2 = z1 + z2 + z3 - z4;
    std::cout << "New numbers: " << z1 << " " << z2 << " " << z3 << " " << z4 << std::endl;
    
    // And read in with std::cin
    std::cout << "Enter two doubles to set real and imaginary parts: ";
    std::cin >> z4;
    std::cout << "-z4 and +z5: " << -z4 << " " << std::endl;
    
    // Access real and imaginary parts
    z4["real"] = 100;
    std::cout << "real(z4) and imag(z4): " << z4["real"] << " " << z4["imag"] << std::endl;
    
    // increment and decrement operators
    ++++z4, z5------;
    std::cout << "z4 with two pre++ and z5 with 3 post--: " << z4 << +z5 << " " << z5 << std::endl;
    
    // store items in a vector, sort them
    std::vector<Complex> vec{ z1, z2, z3, z4, z5 }; // vector of complex
    std::vector<std::string> vec2{ z1, z2, z3, z4, z5 }; // vector of strings because of conversion operator
    std::cout << "The elements: ";
    for (const std::string& complexString : vec2)
        std::cout << complexString << " ";
    std::sort(std::begin(vec), std::end(vec));
    std::cout << "\nsorted vector: ";
    for (const Complex& number : vec)
        std::cout << number << " ";
    std::cout << std::endl;
    
    try{ // try accessing invalid index
        z2["french fries"];
    }
    catch (std::out_of_range& ORR){
        std::cerr << ORR.what();
    }
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
