#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

float polyfunction(float *poly, int degree, float x){
	float sum = poly[degree];
	while(degree){
		sum*=x;
		degree--;
		sum+=poly[degree];
	}
	return sum;
}


int main(){
	int degree;
	float l,r;
	cout<<"Enter the degree of polynomial"<<endl;
	cin>>degree;
	float poly[degree+1];
	for(int i =degree;i>=0;i--){
		cout<<"Enter the "<<i<<"th degree coeff.";
		cin>>poly[i];
	}
	cout<<"Enter the lower and upper limits"<<endl;
	cin>>l>>r;
	int n;
	cout<<"Enter the value n"<<endl;
	cin>>n;
	float I ;
	float dx = float(r-l)/float(n);
	float x0 = polyfunction(poly, degree, l);
	float xn = polyfunction(poly, degree, l+n*dx);
	float z=0.0,y=0.0;
	for(int i =1;i<n;i++){
		float xi = l+i*dx;
		if(i%2==0){
			y+=polyfunction(poly,degree,xi);
		}
		else if(i%2!=0){
			z+=polyfunction(poly,degree,xi);
		}
		
	}
	
	I = dx/3*(x0 + 2*y + 4*z + xn);
	cout<<I;
	return 0;
}