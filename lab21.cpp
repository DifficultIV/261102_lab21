#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double num1,num2,num3,num4;
	num1 = real*c.real;
	num2 = real*c.imag;
	num3 = imag*c.real;
	num4 = imag*c.imag;
	return ComplexNumber(num1-num4,num2+num3);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double num1,num2,num3,num4,num5;
	num1 = real*c.real;
	num2 = real*c.imag;
	num3 = imag*c.real;
	num4 = imag*c.imag;
	num5 = pow(c.real,2.0) + pow(c.imag,2.0);
	return ComplexNumber((num1+num4)/num5,(num3-num2)/num5);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag) return true;
	else return false;
}

double ComplexNumber::angle(){
	return atan2(imag,real)*180/ M_PI;
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2.0)+pow(imag,2.0));
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	double num;
	num = pow(c.real,2.0) + pow(c.imag,2.0);
	return ComplexNumber((s*c.real)/num,(s*(-c.imag))/num);
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.imag == 0) return os << c.real;
	else if(c.imag < 0){
	if(c.real == 0) return os << c.imag << "i";	
	else return os << c.real << c.imag << "i";
	} 
	else if(c.real == 0) return os <<c.imag << "i";
	else return os <<c.real << "+" << c.imag << "i";
}

ComplexNumber operator==(double s,const ComplexNumber &c){
	if(s == c.real && s == c.imag) return true;
	else return false;
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





