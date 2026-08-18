#pragma once

class Vector
{   
public:
    double x,y;
    Vector(double x , double y);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const ;
    Vector operator*(const double scalar) const;
    Vector operator/(const double scalar) const;
    double mag() const;
    Vector normalize() const;
    Vector rotate(const double angle)const;
    double dot(const Vector& other)const;
    void setmag(const double& magnitude);
    double dist(const Vector& other) const;
    Vector zero()const;


};

Vector operator*(double scalar ,const Vector& vec);