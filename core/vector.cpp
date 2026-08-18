#include "vector.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

Vector::Vector(double x, double y):x(x),y(y){}

Vector Vector::operator+(const Vector& other) const
{
    double new_x =  x + other.x ;
    double new_y =  y + other.y ;
    return Vector(new_x,new_y);
}


Vector Vector::operator-(const Vector& other) const
{
    double new_x =  x - other.x ;
    double new_y =  y - other.y ;
    return Vector(new_x,new_y);
}
Vector Vector::operator*(const double scalar ) const
{
    double new_x =  x * scalar ;
    double new_y =  y * scalar ;
    return Vector(new_x,new_y);
}
Vector Vector::operator/(const double scalar ) const
{
    if (scalar == 0)
    {
        throw std::invalid_argument("Error : divison by zero ");
    }
    
    double new_x =  x / scalar ;
    double new_y =  y / scalar ;
    return Vector(new_x,new_y);
}
double Vector::mag() const{
    return sqrt(pow(x,2) + pow(y,2));
}

Vector operator*(double scalar , const Vector& vec){
    return vec * scalar;
}

Vector Vector::normalize()const{
    double m = mag();
    double new_x = x / m;
    double new_y = y / m;
    return Vector(new_x,new_y);
}

Vector Vector::rotate(const double angle)const{
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        return Vector(new_x,new_y);

}

double Vector::dot(const Vector& other)const
{
    return x * other.x + y * other.y;
}
void Vector::setmag(const double& magnitude){
    Vector n = normalize();
    x = n.x * magnitude;
    y = n.y * magnitude;
}

double Vector::dist(const Vector& other) const
{
    return Vector(x - other.x , y - other.y).mag();
}

Vector Vector::zero()const
{
    return Vector(0,0);
}