#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
/*HORIZONTALNA*/
vector<vector<double>> Vertikalna(vector<vector<double>> A){
	vector<vector<double>> B(A.size(), vector<double>(A[0].size()));
	
	for ( int i = A[0].size()-1; i >= 0; i--){
		for ( int j = 0; j < A.size(); j++){
			B[j][i]=A[j][A[0].size()-1-i];
	}
}
	return B;
}
/*VERTIKALNA*/
vector<vector<double>> Horizontalna(vector<vector<double>> A){
	vector<vector<double>> B(A.size(), vector<double>(A[0].size()));
	int j(0);
	
	for ( int i = A.size()-1; i >= 0; i--){
			B.at(j)=A.at(i);
		j++;
	}
	return B;
}
/*FUNKCIJA ZA PRAVLJENJE REZULTANTNE MATRICE*/
vector<vector<double>> OgledaloMatrica(vector<vector<double>> A){
	/*if(A.size()==0 && A[0].size()== 0) throw A;*/
	
	vector<vector<double>> B(A.size()*3, vector<double>(A[0].size()*3));
	
	vector<vector<double>> V(Vertikalna(A));
	
	vector<vector<double>> H(Horizontalna(A));
	
	vector<vector<double>> O(Vertikalna(H));
	
	
	/*oba ogledala 1(blok 1)*/
	for ( int i = 0; i < A.size(); i++){
		for ( int j = 0; j < A[0].size(); j++){
			B[i][j]=O[i][j];
		}
	}

	/*vertikalno 1(blok 2)*/
	for ( int i = A.size(); i < (A.size()*2); i++){
		for ( int j = 0; j < A[0].size(); j++){
			B[i][j]=V[i-A.size()][j];
		}
	}

	/*oba ogledala 2(blok 3)*/
	for ( int i = (A.size()*2); i < (A.size()*3); i++){
		for(int j = 0; j < A[0].size(); j++){
			B[i][j]=O[i-(2*A.size())][j];
		}
	}

	/*horizontalno 1(blok 4)*/
	for ( int i = 0; i < A.size(); i++){
		for ( int j = A[0].size(); j < (2*A[0].size()); j++){
			B[i][j]=H[i][j-(A[0].size())];
		}
	}

	/*A(blok 5)*/
	for ( int i = A.size(); i < (A.size()*2); i++){
		for ( int j = A[0].size(); j < (2*A[0].size()); j++){
			B[i][j]=A[i-(A.size())][j-(A[0].size())];
		}
	}

	/*horizontalno 2(blok 6)*/
	for ( int i = (A.size()*2); i < (A.size()*3); i++){
		for ( int j = A[0].size(); j < (2*A[0].size()); j++){
			B[i][j]=H[i-(A.size()*2)][j-(A[0].size())];
		}
	}

	/*oba ogledala 3(blok 7)*/
	for ( int i = 0; i < A.size(); i++){
		for ( int j = (2*A[0].size()); j < (3*A[0].size()); j++){
			B[i][j]=O[i][j-(2*A[0].size())];
		}
	}

	/*vertikalno 2(blok 8)*/
	for ( int i = A.size(); i < (A.size()*2); i++){
		for ( int j = (2*A[0].size()); j < (3*A[0].size()); j++){
			B[i][j]=V[i-(A.size())][j-(2*A[0].size())];
		}
	}

	/*oba ogledala 4(blok 9) */
	for ( int i = (A.size()*2); i < (A.size()*3); i++){
		for ( int j = (2*A[0].size()); j < (3*A[0].size()); j++){
			B[i][j]=O[i-(2*A.size())][j-(2*A[0].size())];
		}
	}
return B;}


int main ()
{
	using std::cout;
	using std::cin;
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0 || (m<0 && n<0)){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	vector<vector<double>> A(m, vector<double> (n));
	
	cout<<"Unesite elemente matrice: ";
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			std::cin>>A[i][j];
		}
	}

	vector<vector<double>> B=OgledaloMatrica(A);
/*	try{
		
	}*/
cout<<"\nRezultantna matrica: \n";
if(m!=0 && n!=0){
	for(int i = 0; i < B.size(); i++){
		for(int j = 0; j < B[0].size(); j++){
			cout << std::setw(4)<< B[i][j];}
			  cout << std::endl;
		}}
	return 0;
}