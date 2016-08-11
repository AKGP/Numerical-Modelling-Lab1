#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void matrix_multiply( double M[][10],double N[][10],double A[][10], int n, int m){
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			A[i][j] = 0;
			for(int k =0;k<n;k++){
				A[i][j] +=M[i][k]*N[k][j];
			}
		}	
	}
}

void matrix_transpose(double M[][10],int n,int m){
	double T[10][10];
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			T[i][j] = M[i][j];
		}	
	}
	for(int i = 0;i<m;i++ ){
		for(int j =0;j<n;j++){
			M[i][j] = T[j][i];
		
		}
	}
}
void print_matrix(int n,int m, double A[][10]){
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n;
	cout<<"Enter the dimension of the matrix"<<endl;
	cin>>n;
	double A[10][10];
	double M[10][10],N[10][10];
	double x0[n][10], x[n][10];
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++){
			cin>>M[i][j];
			N[i][j] = M[i][j];
			
		}
	}
	
	cout<<"Enter the x0 matrix of order n x 1"<<endl;
	for(int i =0;i<n;i++){
		cin>>x0[i][0];
	}
	double limit = 0.00001; 			//limiting criteria to stop.
	double R = 1, x_max= -100;
	double xi[10][10],xj[10][10],xz[10][10], xa[10][10];

	// Run the while loop until the limiting criteria is achieved.
	while(R-x_max>=limit){

		matrix_multiply(M,x0,x,n,1); 	//xi is calculated and stored in x
		for(int i =0;i<n;i++){
			xz[0][i] = x[i][0];  		// transposed of x value to be used in finding denominator of R
			x_max = max(x_max,x[i][0]);
			x0[i][0] = x[i][0];

		}

		// Calculation of R
		matrix_multiply(M,x,xi,n,1);
		matrix_transpose(xi,n,1);
		matrix_multiply(xi,x,xj,n,1);
		R = xj[0][0];					//numerator calculated and saved in R
		matrix_multiply(xz,x,xa,n,1);
		R/=xa[0][0];

	}
	cout<<"The approximate eigen value is"<<R;
	return 0;
}