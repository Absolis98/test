#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double a, double b)
{
    x = a;
    y = b;
    //cout << "Constructor Runs" << endl;
}

ComplexNumber::~ComplexNumber()
{
    //cout << "Destructor Runs" << endl;
}

 double ComplexNumber::getX()
 {
     return x;
 }

double ComplexNumber::getY()
{
    return y;
}

ComplexNumber& ComplexNumber::setX(double a)
{
    x = a;
    return *this;
}
ComplexNumber& ComplexNumber::setY(double b)
{
    y = b;
    return *this;
}

ComplexNumber& ComplexNumber::printCN()
{
    cout << "(" << x << " , " << y << ")" << endl;
    return *this;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber gio)//Gio just opted to name the variable after his own name
 {
     double x3 = x + gio.getX();
     double y3 = y + gio.getY();
     ComplexNumber sum(x3 , y3);
     return sum;
 }

 ComplexNumber ComplexNumber::operator - (ComplexNumber b)
 {
     double x3 = x - b.getX();
     double y3 = y - b.getY();
     ComplexNumber s(x3 , y3);
     return s;
 }

 ComplexNumber& ComplexNumber::operator += (ComplexNumber b)
 {
     x += b.getX();
     y += b.getY();
     return *this;
 }


 ComplexNumber ComplexNumber::sumComplexNumber(ComplexNumber gio)//Gio just opted to name the variable after his own name
 {
     double x3 = x + gio.getX();
     double y3 = y + gio.getY();
     ComplexNumber sum(x3 , y3);
     return sum;
 }


 ComplexNumber ComplexNumber::subComplexNumber(ComplexNumber b)
 {
     double x3 = x - b.getX();
     double y3 = y - b.getY();
     ComplexNumber s(x3 , y3);
     return s;
 }

ComplexNumber ComplexNumber::mulComplexNumber(ComplexNumber b)
{
     double x3 = x*b.getX() - y*b.getY();
     double y3 = x*b.getY() + y*b.getX();
     ComplexNumber m(x3 , y3);
     return m;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber b)
{
     double x3 = x*b.getX() - y*b.getY();
     double y3 = x*b.getY() + y*b.getX();
     ComplexNumber m(x3 , y3);
     return m;
}

 ComplexNumber& ComplexNumber::operator *= (ComplexNumber b)
{
    if(x == 0 && y == 0){
        throw "Division by zero is not allowed";
    }else{
    double k1 = x;
    x *= (b.getX() - (y*b.getY()/x));
    y *= ((k1*b.getY()/y) + b.getX());
    return *this;
    }
}

//(x1 + i y1)/(x2 + iy2) = (x1x2 + y1y2)/(x2^2 + y2^2)  + i (x2y1 -x1y2)/(x2^2 + y2^2)
ComplexNumber ComplexNumber::divComplexNumber(ComplexNumber b)
{
    if(b.getX() == 0 && b.getY() == 0){
        throw "Division by zero is not allowed";
    }else{
        double x3 = (x*b.getX() + y*b.getY())/(pow(b.getX(), 2)+pow(b.getY(),2));
        double y3 = (-x*b.getY() + y*b.getX())/(pow(b.getX(), 2)+pow(b.getY(),2));
        ComplexNumber div(x3, y3);
        return div;
    }
}

ComplexNumber ComplexNumber::operator / (ComplexNumber b)
{
    if(b.getX() == 0 && b.getY() == 0){
        throw "Division by zero is not allowed";
    }else{
        double x3 = (x*b.getX() + y*b.getY())/(pow(b.getX(), 2)+pow(b.getY(),2));
        double y3 = (-x*b.getY() + y*b.getX())/(pow(b.getX(), 2)+pow(b.getY(),2));
        ComplexNumber div(x3, y3);
        return div;
    }
}

ComplexNumber& ComplexNumber::operator/=(ComplexNumber b)
{
    if(b.getX() == 0 && b.getY() == 0){
        throw "Division by zero is not allowed";
    }else{
        double k1 = x;

        x *= (b.getX() + (y*b.getY()/x))/(pow(b.getX(), 2)+pow(b.getY(),2));
        y *= ((-k1*b.getY())/y + b.getX())/(pow(b.getX(), 2)+pow(b.getY(),2));

        return *this;
    }
}

bool ComplexNumber::operator == (ComplexNumber b)
{
    if(x == b.getX() && y == b.getY()) return true;
    else return false;
}

bool ComplexNumber::operator != (ComplexNumber b)
{
    return !(*this == b);
}

