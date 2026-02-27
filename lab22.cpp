#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;

		ComplexNumber(double x = 0,double y = 0);

		ComplexNumber operator+(const ComplexNumber &) const;
		ComplexNumber operator-(const ComplexNumber &) const;
		ComplexNumber operator*(const ComplexNumber &) const;
		ComplexNumber operator/(const ComplexNumber &) const;

		bool operator==(const ComplexNumber &) const;

		double abs() const;
		double angle() const;
};


ComplexNumber::ComplexNumber(double x,double y){
	real = x;
	imag = y;
}


ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const{
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const{
	return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const{
	return ComplexNumber(
		real*c.real - imag*c.imag,
		real*c.imag + imag*c.real
	);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const{
	double denom = c.real*c.real + c.imag*c.imag;
	return ComplexNumber(
		(real*c.real + imag*c.imag)/denom,
		(imag*c.real - real*c.imag)/denom
	);
}

bool ComplexNumber::operator==(const ComplexNumber &c) const{
	return real == c.real && imag == c.imag;
}

double ComplexNumber::abs() const{
	return sqrt(real*real + imag*imag);
}

double ComplexNumber::angle() const{
	return atan2(imag,real) * 180.0 / M_PI;
}

ComplexNumber operator+(double d,const ComplexNumber &c){
	return ComplexNumber(d) + c;
}

ComplexNumber operator-(double d,const ComplexNumber &c){
	return ComplexNumber(d) - c;
}

ComplexNumber operator*(double d,const ComplexNumber &c){
	return ComplexNumber(d) * c;
}

ComplexNumber operator/(double d,const ComplexNumber &c){
	return ComplexNumber(d) / c;
}

bool operator==(double d,const ComplexNumber &c){
	return ComplexNumber(d) == c;
}

ostream& operator<<(ostream &out,const ComplexNumber &c){
	if(c.real == 0 && c.imag == 0){
		out << 0;
	}
	else if(c.real == 0){
		out << c.imag << "i";
	}
	else if(c.imag == 0){
		out << c.real;
	}
	else{
		out << c.real;
		if(c.imag > 0) out << "+" << c.imag << "i";
		else out << c.imag << "i";
	}
	return out;
}