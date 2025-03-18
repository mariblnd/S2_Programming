#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

//Display
std::ostream& operator<<(std::ostream& os, Fraction const& f1) {
    return os << f1.numerator << "/" << f1.denominator;
}

float to_float(Fraction f1){
    float numerator = static_cast<float>(f1.numerator);
    float denominator = static_cast<float>(f1.denominator);
    return numerator / denominator;
}

Fraction::operator float() const {
    
    return to_float(*this);
}



Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}


// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

// Add
// Fraction operator+(Fraction const& f1, Fraction const& f2){
//     Fraction temp {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     };
//     temp = simplify(temp);
//     return temp;
// }


// +=
Fraction operator+=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f1.denominator = f1.denominator * f2.denominator;

    simplify(f1);

    return f1;
}

Fraction operator+(Fraction& f1, Fraction const& f2){
    Fraction temp { f1+=f2 };
    temp = simplify(temp);
    return temp;
}


Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction operator-(Fraction const& f1, Fraction const& f2){
//     Fraction temp {
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     };
//     temp = simplify(temp);
//     return temp;
// }

Fraction operator-=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f1.denominator = f1.denominator * f2.denominator;

    simplify(f1);

    return f1;
}

Fraction operator-(Fraction& f1, Fraction const& f2){
        Fraction temp {
            f1 -= f2
        };
        temp = simplify(temp);
        return temp;
    }

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

// Mul
// Fraction operator*(Fraction const& f1, Fraction const& f2){
//     Fraction temp {
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     };
//     temp = simplify(temp);
//     return temp;
// }

Fraction operator*=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.numerator;
    f1.denominator = f1.denominator * f2.denominator;

    simplify(f1);

    return f1;
}

Fraction operator*(Fraction& f1, Fraction const& f2){
    Fraction temp {
        f1 *= f2
    };
    temp = simplify(temp);
    return temp;
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

// Div
// Fraction operator/(Fraction const& f1, Fraction const& f2){
//     Fraction temp {
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     };
//     temp = simplify(temp);
//     return temp;
// }

Fraction operator/=(Fraction& f1, Fraction const& f2) {
    f1.numerator = f1.numerator * f2.denominator;
    f1.denominator = f1.denominator * f2.numerator;

    simplify(f1);

    return f1;
}

Fraction operator/(Fraction& f1, Fraction const& f2){
    Fraction temp {
        f1 /= f2
    };
    temp = simplify(temp);
    return temp;
}

//Egalité
bool operator==(Fraction const& f1, Fraction const& f2) {
    return f1.numerator*f2.denominator == f1.denominator*f2.numerator;
}

//Différence
bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

// f1 est strictement plus petit que f2
bool operator<(Fraction& f1, Fraction& f2) {

    if(f1.denominator == f2.denominator){
        return f1.numerator < f2.numerator;
    } 
    
    else{
        f1.denominator = f1.denominator*f2.denominator;
        f1.numerator = f1.numerator*f2.denominator;

        f2.denominator = f1.denominator*f2.denominator;
        f2.numerator = f2.numerator*f1.denominator;

        return f1.numerator < f2.numerator;
         
    }

}

// f1 est plus petit ou égal à f2
bool operator<=(Fraction& f1, Fraction& f2) {
    return (f1 < f2 || f1 == f2);
}

// f1 est strictement plus grand que f2
bool operator>(Fraction& f1, Fraction& f2) {
    return !(f1 < f2);
}

// f1 est plus grand ou égal à f2
bool operator>=(Fraction& f1, Fraction& f2) {
    return (!(f1 < f2) || f1 == f2);
}



