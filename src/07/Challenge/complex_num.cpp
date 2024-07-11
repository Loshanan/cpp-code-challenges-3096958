#include "complex_num.h"

complex_num::complex_num(double r, double i){
    // Write your code here
    this->r = r;
    this->i = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here
    z.r = this->r + w.r;
    z.i = this->i + w.i;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z.r = this->r - w.r;
    z.i = this->i - w.i;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here
    //(ac-bd) + i(ad+bc)
    z.r = this->r * w.r - this->i * w.i;
    z.i = this->r * w.i + this->i * w.r;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    // real : (ac+bd)/(c^2+d^2)
    z.r = (this->r * w.r + this->i * w.i) / (w.r *w.r + w.i * w.i);
    // imaginary : (bc-ad)/(c^2+d^2)
    z.i = (this->i * w.r - this->r * w.i) / (w.r *w.r + w.i * w.i);
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    if (this->r != 0) std::cout << this->r;
    if (this->i > 0) std::cout << " + i" << this->i;
    else if (this->i < 0) std::cout << " - i" << -this->i;
    // std::cout << std::endl;
}