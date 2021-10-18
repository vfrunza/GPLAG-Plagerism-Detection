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

typedef std::vector<std::vector<double>> Matrica;

int BrojRedova(Matrica m) {
	return m.size();
}

int BrojKolona(Matrica m, int i) {
	return m[i].size();
}

Matrica OgledaloMatrica(Matrica mat) {
	Matrica v(BrojRedova(mat),std::vector<double> (BrojKolona(mat,0)));
	Matrica ogledalo(3*BrojRedova(mat),std::vector<double> (3*BrojKolona(mat,0)));
	for(int i(0);i<BrojRedova(mat);i++) {
		for(int j(i+1);j<BrojRedova(mat)-1;j++) {
		if(BrojKolona(mat,i)!=BrojKolona(mat,j)) throw std::domain_error ("Matrica nije korektna");
		}
	}
	
	if(BrojRedova(mat)!=0) {
		int k;
		//vertikalna matrica
		k=BrojRedova(mat)-1;
		for(int i(0);i<(BrojRedova(mat)/2)+1;i++) {
			v[i]=mat[k];
			v[k]=mat[i];
			k--;
		}
		//hv dio			
		for(int i(0);i<BrojRedova(mat);i++) {
			k=BrojKolona(mat,0)-1;
			for(int j(0);j<=BrojKolona(mat,0)/2;j++) {
				ogledalo[i][j]=v[i][k];
				ogledalo[i][k]=v[i][j];
				k--;
			}
		}
		//h dio				
		int p(0);
		for(int i(BrojRedova(mat));i<BrojRedova(mat)*2;i++) {
			k=BrojKolona(mat,0)-1;
			for(int j(0);j<=BrojKolona(mat,0)/2;j++) {
				ogledalo[i][j]=mat[p][k];
				ogledalo[i][k]=mat[p][j];       
				k--;
			}
			p++;
		}
		//hv dio			
		p=0;
		for(int i(BrojRedova(mat)*2);i<BrojRedova(mat)*3;i++) {
			k=BrojKolona(mat,0)-1;
			for(int j(0);j<=BrojKolona(mat,0)/2;j++) {
				ogledalo[i][j]=v[p][k];
				ogledalo[i][k]=v[p][j];
				k--;
			}
			p++;
		}
		//v dio				
		for(int i(0);i<BrojRedova(mat);i++) {
			k=0;
			for(int j(BrojKolona(mat,0));j<BrojKolona(mat,0)*2;j++) {
				ogledalo[i][j]=v[i][k];
				k++;
			}
		}
		//m dio				
		p=0;
		for(int i(BrojRedova(mat));i<BrojRedova(mat)*2;i++) {
			k=0;
			for(int j(BrojKolona(mat,0));j<BrojKolona(mat,0)*2;j++) {
				ogledalo[i][j]=mat[p][k];
				k++;
			}
			p++;
		}
		//v dio			
		p=0;
		for(int i(BrojRedova(mat)*2);i<BrojRedova(mat)*3;i++) {
			k=0;
			for(int j(BrojKolona(mat,0));j<BrojKolona(mat,0)*2;j++) {
				ogledalo[i][j]=v[p][k];
				k++;
			}
			p++;
		}
		//hv dio			
		int m,n;
		for(int i(0);i<BrojRedova(mat);i++) {
			k=BrojKolona(mat,0)-1;
			n=BrojKolona(mat,0)*3-1;
			m=0;
			for(int j(BrojKolona(mat,0)*2);j<=(BrojKolona(mat,0)*3)-((BrojKolona(mat,0)/2)+1);j++) {
				ogledalo[i][j]=v[i][k];
				ogledalo[i][n]=v[i][m];
				m++;
				k--;
				n--;
			}
		}
		//h dio				
		p=0;
		for(int i(BrojRedova(mat));i<BrojRedova(mat)*2;i++) {
			k=BrojKolona(mat,0)-1;
			n=BrojKolona(mat,0)*3-1;
			m=0;
			for(int j(BrojKolona(mat,0)*2);j<=(BrojKolona(mat,0)*3)-((BrojKolona(mat,0)/2)+1);j++) {
				ogledalo[i][j]=mat[p][k];
				ogledalo[i][n]=mat[p][m];       
				k--;
				n--;
				m++;
			}
			p++;
		}
		//hv dio			
		p=0;
		for(int i(BrojRedova(mat)*2);i<BrojRedova(mat)*3;i++) {
			k=BrojKolona(mat,0)-1;
			n=BrojKolona(mat,0)*3-1;
			m=0;
			for(int j(BrojKolona(mat,0)*2);j<=(BrojKolona(mat,0)*3)-((BrojKolona(mat,0)/2)+1);j++) {
				ogledalo[i][j]=v[p][k];
				ogledalo[i][n]=v[p][m];
				k--;
				n--;
				m++;
			}
			p++;
		}
	}
		return ogledalo;
}


int main ()
{
	try {
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		do {
			std::cin>>m>>n;
			if(m<0 || n<0) {
				std::cout<<"Dimenzije matrice moraju biti nenegativne!";
				break;
			}
			std::cout<<"Unesite elemente matrice: ";
			Matrica mat(m,std::vector<double> (n));
			for(int i(0);i<m;i++) {
				for(int j(0);j<n;j++) {
					std::cin>>mat[i][j];
				}
			}
			std::cout<<"\nRezultantna matrica:\n";
			Matrica ogledalo(OgledaloMatrica(mat));
			for(int i(0);i<BrojRedova(ogledalo);i++) {
				for(int j(0);j<BrojKolona(ogledalo,0);j++) {
					std::cout<<std::setw(4)<<std::setfill(' ')<<ogledalo[i][j];
				}
				std::cout<<std::endl;
			}
		} while(m<0 || n<0);
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}