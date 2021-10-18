/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

vector<vector<double>> VertikalnoOgledalo(vector<vector<double>>mat)
{	
	vector<vector<double>>mat1;
	if(mat.size()==0 || mat[0].size()==0){mat1=mat; return mat1;} 
	int n=mat.size()-1;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
					double temp=mat[i][j];
					mat[i][j]=mat[n][j]; 
					mat[n][j]=temp;
					
		}
				if(n>(mat.size())/2)	n--;
				else break;
			
		}
		mat1=mat;
		return mat1;
}
vector<vector<double>> HorizontalnoOgledalo(vector<vector<double>>mat)
{	
	vector<vector<double>>mat1{};
		if(mat.size()==0 || mat[0].size()==0){mat1=mat; return mat1;} 
	int n=mat[0].size()-1; 
	for(int i=0;i<mat[0].size();i++){
		for(int j=0;j<mat.size();j++){
					double temp=mat[j][i];
					mat[j][i]=mat[j][n]; 
					mat[j][n]=temp;
					
		}
				if(n>(mat[0].size())/2)	n--;
				else break;
			
		}
		mat1=mat;
		return mat1;
}
vector<vector<double>> KombinovanoOgledalo(vector<vector<double>>mat)
{
	vector<vector<double>> mat1{};
	mat1=VertikalnoOgledalo(mat);
	mat1=HorizontalnoOgledalo(mat1);
	return mat1;
}




vector<vector<double>> OgledaloMatrica(vector<vector<double>>mat)
{
    	for(int i=0;i<mat.size();i++)
		if(mat[0].size()!=mat[i].size())throw domain_error("Matrica nije korektna");

	vector<vector<double>>mat1{},mat2{},mat3{},mat4{};
	mat4=mat;	
	mat4.resize(mat.size()*3);
	for(int i=0;i<mat4.size();i++)
	mat4[i].resize(mat[0].size()*3);
	if(mat.size()==0 || mat[0].size()==0){ return mat4;} 
	int n=mat.size(),n1=mat[0].size();
	int vel1=mat.size()*3;
	int vel2=mat[0].size()*3;

	
	mat1=HorizontalnoOgledalo(mat);
	mat2=VertikalnoOgledalo(mat);
	mat3=KombinovanoOgledalo(mat);
	for(int i=0;i<vel1;i++){
	for(int j=0;j<vel2;j++){
		if((i<n  || (i>=(n*2) && i<vel1)) && (j<n1 || ( j>=(n1*2) && j<vel2)))mat4[i][j]=mat3[i%n][j%n1];
		else if((j>=n1 && j<n1*2)&&(i<n || (i>=n*2 && i<vel1))) mat4[i][j]=mat2[i%n][j%n1];
		else  if((j>=n1 && j<n1*2)&&(i>=n &&  i<n*2))mat4[i][j]=mat[i%n][j%n1];
	
		else 
		mat4[i][j]=mat1[i%n][j%n1];
		}
	}
		
	return mat4;
}


int main ()
{
	try{
	int m,n;
	vector<vector<double>> mat{},mat1{};
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	mat.resize(m);
	for(int i=0;i<mat.size();i++){
	mat[i].resize(n);
	
	}
	cout<<"Unesite elemente matrice: "<<endl;
	
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	cin>>mat[i][j];
	
	mat1=OgledaloMatrica(mat);
	
	cout<<"Rezultantna matrica: "<<endl;
	for(int i=0;i<mat1.size();i++){
	for(int j=0;j<mat1[i].size();j++)
		cout<<setw(4)<<mat1[i][j];
		cout<<endl;
		}
	}
     catch(domain_error izuzetak) {
	  cout << izuzetak.what(); return 0;
	}

	
	return 0;
}