/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include <stdexcept>
using namespace std;
typedef vector<vector<double>>Matrica;


Matrica h (Matrica mat){
 double temp;
 if(mat[0].size()>1){
	for(int i(0);i<mat.size();i++){
		for(int j=(mat[i].size()-1)/2;j>=0;j--){
			for(int k=mat[i].size()-1-j;k>=0;k--){
			temp=mat[i][j];
			mat[i][j]=mat[i][k];
			mat[i][k]=temp;
		break;
		}}}
 
return mat;
}

return mat;
}



Matrica v(Matrica mat){
double temp;
//if(mat.size()>1){
if(mat.size()<3){
	for(int i(0);i<mat.size()/2;i++){
		for(int j(0);j<mat[i].size();j++){
			
		temp=mat[i][j];	
		mat[i][j]=mat[mat[i].size()/2-i][j];
		mat[mat[i].size()/2-i][j]=temp;
	}
}
}
else{
for(int i(0);i<mat.size()/2;i++){
		for(int j(0);j<mat[i].size();j++){
			
		temp=mat[i][j];	
		mat[i][j]=mat[mat[i].size()-i][j];
		mat[mat[i].size()-i][j]=temp;
	}}}
	return mat;
}
//return mat;
//}



Matrica hv(Matrica mat){
if((mat.size()<2 && mat.size()>2) || (mat[0].size()<2 && mat[0].size()>0))return mat;
		mat=v(mat);
	mat=h(mat);
	return mat;
	
}
Matrica SortirajKolone (Matrica mat, int mv,int nm){
	

double temp;
			for(int i(0);i<mv;i++){
			for(int j=nm;j<(2*nm-1);j++){
			temp=mat[i][j];
			mat[i][j]=mat[i][2*j-1];
			mat[i][2*j-1]=temp;
			}}
		return mat;

}
Matrica SortirajRedove (Matrica mat, int nv, int mm){
	double temp;
	//mm=3 nv=9

	for(int i=mm;i<(2*mm-1);i++){
		for(int j(0);j<nv;j++){
			temp=mat[i][j];
			mat[i][j]=mat[2*i-1][j];
			mat[2*i-1][j]=temp;
			}}
	
	
/*	else{
		//mm=3 nv=6
		for(int i=mm;i<=2*mm-1;i++){
		for(int j(0);j<nv;j++){
			temp=mat[i][j];	
		mat[i][j]=mat[nv-i][j];
		mat[nv-i][j]=temp;
		}
		}
		
	}
*/
	return mat;
}
bool NijeGrbava(Matrica A){
    int a=A.size();
    int b=A[0].size();
    for(int i(1);i<a;i++){
       
            if(b!=A[i].size())return false;
        }
        return true;
        
    }
    Matrica KreirajMatricu(int m,int n){
    	return Matrica(m,vector<double>(n));
    }
/// koliki je broj kolona toliko puta ispisi hv kolonu 
Matrica OgledaloMatrica (Matrica mat){
	if(mat.size()==0) return mat;
	if(!NijeGrbava(mat)) throw domain_error ("Matrica nije korektna.");

			mat=hv(mat);
	Matrica mat1;
	int m=mat.size();
	int n=mat[0].size();
	mat1.resize(3*m);
	int m1=mat1.size();
	int n1=3*n;
	
	
	for(int i(0);i<m1;i++){
		mat1[i].resize(3*n);
	}
	int k=-1;
	int l=0;
	
	for(int i(0);i<m1;i++){
		k++;
		if(k>(m-1))k=0;
		for(int j(0);j<n1;j++){
		
			mat1[i][j]=mat[k][l];
			l++;
			if(l>(n-1))l=0;
			
		}
	}
	if((mat1[0].size()<2 && mat[0].size()>0)){
		mat1=SortirajRedove(mat1,n1,m);
		return mat1;
	}
	
	if(mat1.size()<2 && mat.size()>0 ){
		mat1=SortirajKolone(mat1,m1,n);
		return mat1;
	}
	if(!(mat1[0].size()<2 && mat[0].size()>0) || !(mat1.size()<2 && mat.size()>0 ))
	{mat1=SortirajKolone(mat1,m1,n);
	mat1=SortirajRedove(mat1,n1,m);
}

return mat1;
}

int main ()
{	
	
	
	//Provjera h(m) v(m) hv(m)
	/*vector<vector<double>>mat{{1,2,3},{4,5,6}};
	vector<vector<double>>mat1{{1,2,3},{4,5,6},};

	mat=h(mat);
	
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			cout<<mat[i][j]<<" ";
			
		}
	
		cout<<endl;
	}
	/////////
		mat1=v(mat1);
	cout<<endl;
	for(int i(0);i<mat1.size();i++){
		for(int j(0);j<mat1[i].size();j++){
			cout<<mat1[i][j]<<" ";
			
		}
		cout<<endl;
		
	}
	vector<vector<double>>mat3{{1,2,3},{4,5,6}};
	////////
	mat3=hv(mat3);
	cout<<endl;
	for(int i(0);i<mat3.size();i++){
		for(int j(0);j<mat3[i].size();j++){
			cout<<mat3[i][j]<<" ";
			
		}
		cout<<endl;
		
	}*/
	/*vector<vector<double>>mat3{{1,2,3},{4,5,6}};
	mat3=OgledaloMatrica(mat3);
	
	for(int i(0);i<mat3.size();i++){
		for(int j(0);j<mat3[i].size();j++){
			cout<<mat3[i][j]<<" ";
			}
		cout<<endl;
	}*/
	int m,n;
       cout<<"Unesite dimenzije matrice (m n): ";
       cin>>m>>n;
       
       if (m<0 || n<0){
               cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl;
               cin.clear();
               cin.ignore(1000,'\n');
               return 0;
       }
       auto A(KreirajMatricu(m,n));
        cout<<"Unesite elemente matrice:"<<endl;
        for(int i(0);i<m;i++){
            for(int j(0);j<n;j++){
                cin>>A[i][j];
            }
        }
        try{
        	A=OgledaloMatrica(A);
        	cout<<"Rezultantna matrica:"<<endl;
        	for(int i(0);i<A.size();i++){
		for(int j(0);j<A[i].size();j++){
			cout<<setw(4)<<A[i][j];
		}
        	cout<<endl;
        	}
        }
        catch (domain_error n){
           cout<<n.what()<<endl;
       }
	return 0;
}