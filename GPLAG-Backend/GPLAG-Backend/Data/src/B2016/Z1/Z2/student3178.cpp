/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
//DNEVNIK RADA: 22.03. potpuni ocaj..ne radi nista.program se krahira a ne znam zasto...
//tmurni oblaci se nadvili ...23:00 ima nade!

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n){
	return Matrica(m,std::vector<double>(n));
}

int BrojRedova(Matrica A){
	return A.size();
}

int BrojKolona(Matrica A){
	if (A.size() == 0)
	return 0;
	return A[0].size();
}

Matrica UnesiMatricu(int m, int n){
	
	auto A(KreirajMatricu(m, n));
	for(int i=0; i<m; i++){
	   for(int j=0; j<n; j++){
		   std::cin >> A[i][j];
	    } 
	}
	return A;	
}

void IspisiMatricu(Matrica A){
	for(int i=0; i<BrojRedova(A); i++){
    	for(int j=0; j<BrojKolona(A); j++)
        	std::cout << std::setw(4) << A[i][j];
	std::cout << std::endl;
	}
}

Matrica H(Matrica A){
	auto H(KreirajMatricu(BrojRedova(A),BrojKolona(A)));
	int n{0};
	n=BrojKolona(A);
	for(int i=0; i<BrojRedova(A); i++){
	  	 for(int j=0; j<BrojKolona(A); j++){ 
	        H[i][j]=A[i][n-1-j];
	     }
	}
	return H;
}


Matrica V(Matrica A){
	auto V(KreirajMatricu(BrojRedova(A),BrojKolona(A)));
	int m{0};
	m=BrojRedova(A);
		for(int i=0; i<BrojRedova(A); i++)
	  {
	  	 for(int j=0; j<BrojKolona(A); j++)
	  	 { 

    V[i][j] = A[m-1-i][j];
    
	  	 }}
	  	 	return V;
}
 
 
Matrica HV(Matrica A){
	auto HV(KreirajMatricu(BrojRedova(A),BrojKolona(A)));
	int i2{0};
	int j2{0};
	for(int i=0; i<BrojRedova(A); i++)
	  {
	  	 for(int j=0; j<BrojKolona(A); j++)
	  	 { 
	  	 i2 = 	BrojRedova(A) - 1 - i;
	  	 j2 =   BrojKolona(A) - 1 - j;
	  	 HV[i][j]=A[i2][j2];
	  	 }
	  }
	  return HV;
}
	
	
Matrica OgledaloMatrica( Matrica A ){
	if(BrojRedova(A) == 0 && BrojKolona(A)== 0){
	auto C(KreirajMatricu(0,0));
	return C;}
	for(int i=0; i<BrojRedova(A); i++){
		int r;
		r=A[0].size();
		if (A[i].size() != r)  throw std::domain_error("Matrica nije korektna");
		
	}
	
	
	int m;
	int n;
	m= BrojRedova(A);
	n= BrojKolona(A);
	auto B(KreirajMatricu(3*m,3*n));
    
   
	for(int i=0; i<m; i++)
    	for(int j=0; j<n; j++){
    
	B[i][j]=HV(A)[i][j];
    B[i][j+2*n]=HV(A)[i][j];
    B[i+2*m][j]=HV(A)[i][j];
    B[i+2*m][j+2*n]=HV(A)[i][j];
    B[m+i][j]=H(A)[i][j];
    B[m+i][j+2*n]=H(A)[i][j];
    	}
    	
    for(int i=0; i<m; i++)
    	for(int j=0; j<n; j++){
    
	B[i][j+n]=V(A)[i][j];
   // B[i][j+2*n]=(HV(A))[i][j];
   B[m+i][n+j]=A[i][j];
    B[i+2*m][j+n]=V(A)[i][j];
    	}	
    	
    	
	return B;
	
	
}



int main ()
{	
try{
	int m,n;
	
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
    if(m<0 || n<0){
    std::cout << "Dimenzije matrice moraju biti nenegativne!";
    return 0;	}
    std::cout << "Unesite elemente matrice: \n";
    auto A(UnesiMatricu(m,n));
   /* std::cout << "Matrica A: \n";
	IspisiMatricu(A); */
//}
//catch(const char poruka[]){
//	std::cout << poruka << std::endl;
//}
	
//	try{
	std::cout << "Rezultantna matrica: \n";
	IspisiMatricu(OgledaloMatrica(A));
}
catch(std::domain_error izuzetak){
	std::cout << izuzetak.what() << std::endl;
}
	

	return 0;
}