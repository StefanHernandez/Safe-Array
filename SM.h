#ifndef SM_V1
#define SM_V1

#include<iostream>
#include "SA.h"

template<class T2> class SM{
	
	SA<T2>** matrix;
	int rows, rlow;
	int cols, clow;
	
	public:
	//default constructor
	SM(){
		rows = 1;
		cols = 1;
		clow=0;
		rlow=0;
		
		matrix = new SA<T2>*[1];
		for(int i = 0; i<1; i++){
			matrix[i] = new SA<T2>(1);
			}
		
	}
	
	//constructor with 2 parameters for rows/cols
	SM(int r, int c, int rl, int cl){
		rows = r;
		cols = c;
		rlow = rl;
		clow = cl;
		
		matrix = new SA<T2>*[r];
		for(int i = 0; i<r; i++){
			matrix[i] = new SA<T2>(c);
			}
		
	}
	
/**	void copySM(const SM<T> &m) {
    for(int i=row_low; i<=row_high; i++)
        for(int j=col_low; j<=col_high; j++)
            matrix[i][j] = m.matrix()[i][j];
	}
*/
	SA<T2>&   operator[](int index){
		return *matrix[index];
		
	}
	
	SM<T2>& operator=( SM<T2> s){
		if(this==&s)return *this;
		delete [] matrix;
		 rows = s.rows;
		 cols = s.cols;
		 rlow = s.rlow;
		 clow=s.clow;
		matrix =new SA<T2>*[rows];
		
		for(int i=0; i<rows; i++){
			matrix[i] = new SA<T2>(cols);
		}
		
		for(int i=rlow; i<rows; i++){
			for(int j = clow; j<cols; j++){
				(*this)[i][j]=s[i][j];
			}
			
		}
		
		
		
		return *this;
	}
	
	SM<T2> operator*(SM<T2> B) {
		
		if(rows != B.cols || cols != B.rows){ cout<<"Matrix multiplication not allowed between these two Matrices!"<<endl; SM<T2> multiSM; return multiSM;}
		
		SM<T2> multiSM(rows,rows,rlow, rlow);
			
			int sum=0;
			
			for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++){
					
					int sum=0;
					
					for(int k=0; k<cols; k++){
						int lhs = (*this)[i][k];
						
						//cout<<"this is LHS: "<<lhs<<endl;
						
						sum+=lhs*(B[k][j]);
						
						//cout<<"this is SUM: "<<sum<<endl;
					}
					
					multiSM[i][j]=sum;
					
				}
		
			}
			
	return multiSM;
	}
	
	void printMatrix(){
		
		for(int i=rlow; i<rows; i++){
			for(int j=clow; j<cols; j++){
				cout<<"|"<<(*this)[i][j];
		}
		cout<<endl;
	}
		
	}
	
	
};

#endif