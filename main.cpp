#include<iostream>
#include <cstdlib>
#include<cassert>
#include "SA.h"
#include "SM.h"
using namespace std;

int main(){
	
	/**
	Hard coded the input for Matrix A and B as a sample to display that the matrices work.
	Input can be made, and that input can be displayed.
	Results for matrix multiplication creating a dynamic result are also displayed. Feel free to enter/change the matrices around to create your own results.
	*/
	
	SM<int> A(3,3,0,0);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			A[i][j]=2;
		}
	}
	
	SM<int> B(3,3,0,0);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			B[i][j]=2;
		}	
	}
	
	cout<<"Printing Matrix A: "<<endl;
	A.printMatrix();
	
	
	
	
	cout<<"\nPrinting Matrix B: "<<endl;
	B.printMatrix();
	
	
	SM<int> C;
    C =	A*B;
	
	cout<<"\nPrinting Matrix C (The Product of A*B): "<<endl;
	C.printMatrix();
	
	
	
	cout<<"\nTwo 3x3 Matrices were created, filled with 2's and then multiplied, creating a dynamic result/matrix";
	
	
	
	return 0;
}