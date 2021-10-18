
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int m, int n) {
	return Matrica(m,std::vector<double>(n));
}
Matrica UnesiMatricu(int m,int n) {
	Matrica A(KreirajMatricu(m,n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>A.at(i).at(j);
		}
	}
return A;
}

void IspisiMatricu(Matrica A)  {
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A.at(i).size(); j++) {
			std::cout<<std::right<<std::setw(4)<<A.at(i).at(j);
		}
		std::cout<<std::endl;
	}
}
Matrica Horizontalna(Matrica A) {
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<(A.at(i).size()/2); j++) {
			double pomocna;
			int z(A.at(i).size()-1-j);
			pomocna=A.at(i).at(z);
			A.at(i).at(z)=A.at(i).at(j);
			A.at(i).at(j)=pomocna;
		}
	}
	return A;
}
Matrica Vertikalna(Matrica A) {
	for(int i=0; i<A.size()/2; i++) {
		for(int j=0;j<A.at(i).size(); j++) {
			double pomocna;
			pomocna=A.at(i).at(j);
			int z(A.size()-1-i);
			A.at(i).at(j)=A.at(z).at(j);
			A.at(z).at(j)=pomocna;
		}
	}
	return A;
}
Matrica Kombinovana(Matrica A) {
	Matrica D=Horizontalna(A);
	Matrica C=Vertikalna(D);
	return C;
}
Matrica OgledaloMatrica(Matrica A){
	Matrica V=Vertikalna(A);
	Matrica H=Horizontalna(A);
	Matrica K=Kombinovana(A);
	int i(0);
	bool jeste_grbava(false);
	for(int j=i+1;j<A.size();j++) {
		if(A.at(i).size()!=A.at(j).size()) {
			jeste_grbava=true;
			break;
		}
	}
	if(jeste_grbava) throw std::domain_error("Matrica nije korektna.");
	if(A.size()==0 || A[0].size()==0) {
		Matrica Nula;
		Nula.resize(3*A.size());
		return Nula;
	}
	else {
		int a=A.size();
		int b=A[0].size();
		Matrica Nova(KreirajMatricu(3*a,3*b));
		for(int i=0;i<a;i++) {
			for(int j=0;j<b;j++) {
				Nova.at(i).at(j)=K.at(i).at(j);
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=0;j<b;j++) {
				Nova.at(i).at(j)=H.at(i-a).at(j);
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=0;j<b;j++) {
				Nova.at(i).at(j)=K.at(i-2*a).at(j);
			}
		}
		for(int i=0;i<a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova.at(i).at(j)=V.at(i).at(j-b);
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova.at(i).at(j)=A.at(i-a).at(j-b);
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=b;j<2*b;j++) {
				Nova.at(i).at(j)=V.at(i-2*a).at(j-b);
			}
		}
		for(int i=0;i<a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova.at(i).at(j)=K.at(i).at(j-2*b);
			}
		}
		for(int i=a;i<2*a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova.at(i).at(j)=H.at(i-a).at(j-2*b);
			}
		}
		for(int i=2*a;i<3*a;i++) {
			for(int j=2*b;j<3*b;j++) {
				Nova.at(i).at(j)=K.at(i-2*a).at(j-2*b);
			}
		}
		return Nova;
	}
}
int main ()
{
	try {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) throw std::range_error("Dimenzije matrice moraju biti nenegativne!");
	std::cout<<"Unesite elemente matrice:\n";
	auto A(UnesiMatricu(m,n));
	std::cout<<"Rezultantna matrica: \n";
	IspisiMatricu(OgledaloMatrica(A));
	}
	catch (std::range_error poruka) {
		std::cout<<poruka.what();
	}
	catch (std::domain_error poruka) {
		std::cout<<poruka.what();
	}
	return 0;
}