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

std::vector<std::vector<double>> KreirajMatricu(int br_redova, int br_kolona){
	return std::vector<std::vector<double>>(br_redova,std::vector<double> (br_kolona));
}

int BrojRedova(std::vector<std::vector<double>> m){
	return m.size();
}

int BrojKolona(std::vector<std::vector<double>> m) {
	return m[0].size();
}

std::vector<std::vector<double>> UnesiMatricu(int br_redova,int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++)
	for(int j=0; j<br_kolona; j++){
		std::cin>>m[i][j];
	}
	return m;
}

void IspisiMatricu(std::vector<std::vector<double>> m){
	for(int i=0; i<BrojRedova(m); i++){
	for(int j=0; j<BrojKolona(m); j++){
		std::cout<<std::setw(4)<<m[i][j];
	}
		std::cout<<std::endl;
}}

std::vector<std::vector<double>> HM (std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> nova(0);
	
	for(int i=0; i<BrojRedova(a); i++){
		std::vector<double> red(0);
		   for(int j=BrojKolona(a)-1; j>=0; j--)
		   red.push_back(a[i][j]);
		   
		   nova.push_back(red);
		}
		return nova;
	}
	
std::vector<std::vector<double>> VM (std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> nova(0);
	
	for(int i=BrojRedova(a)-1; i>=0; i--){
		std::vector<double> red(0);
		   for(int j=0; j<BrojKolona(a); j++)
		   		red.push_back(a[i][j]);
		   
		   nova.push_back(red);
		}
		return nova;
	}
	
std::vector<std::vector<double>> HVM (std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> nova(0);
	
	for(int i=BrojRedova(a)-1; i>=0; i--){
		std::vector<double> red(0);
		   for(int j=BrojKolona(a)-1; j>=0; j--)
		   red.push_back(a[i][j]);
		   
		   nova.push_back(red);
		}
		return nova;
	}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> s){
	if(s.size()<1)
	return s;
	
	for(int i=0; i<BrojRedova(s);i++){
		if(s[i].size() != s[0].size())
			throw std::domain_error("Matrica nije korektna");
	}


	std::vector<std::vector<double>> m(KreirajMatricu(3*BrojRedova(s),3*BrojKolona(s)));
	std::vector<std::vector<double>> hm(HM(s));
	std::vector<std::vector<double>> vm(VM(s));
	std::vector<std::vector<double>> hvm(HVM(s));
	
	
	for(int i=0; i<BrojRedova(s); i++)
		for(int j=0; j<BrojKolona(s); j++){
			m[i][j]=hvm[i][j];
			m[i][2*BrojKolona(s)+j]=hvm[i][j];
			m[2*BrojRedova(s)+i][j]=hvm[i][j];
			m[2*BrojRedova(s)+i][2*BrojKolona(s)+j]=hvm[i][j];
		}

	for(int i=0; i<BrojRedova(s); i++)
		for(int j=0; j<BrojKolona(s); j++){
			m[i][BrojKolona(s)+j]=vm[i][j];
			m[2*BrojRedova(s)+i][BrojKolona(s)+j]=vm[i][j];
		}

	for(int i=0; i<BrojRedova(s); i++)
		for(int j=0; j<BrojKolona(s); j++){
			m[BrojRedova(s)+i][j]=hm[i][j];
			m[BrojRedova(s)+i][2*BrojKolona(s)+j]=hm[i][j];
		}
		
	// upisivanje originalne matrice u sredinu
	for(int i=0; i<BrojRedova(s); i++)
		for(int j=0; j<BrojKolona(s); j++){
			m[BrojRedova(s)+i][BrojKolona(s)+j]=s[i][j];
		}
		
	return m;
}

int main ()
{
	int k,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>k>>n;
	if(k<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::vector<std::vector<double>> m=KreirajMatricu(k,n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			std::cin>>m[i][j];
		}
	}
	
	std::cout<<"\nRezultantna matrica:\n";
	
	//if(m.size()==0) return 0;
	
	std::vector<std::vector<double>> nova(OgledaloMatrica(m));
	IspisiMatricu(nova);
	return 0;
}