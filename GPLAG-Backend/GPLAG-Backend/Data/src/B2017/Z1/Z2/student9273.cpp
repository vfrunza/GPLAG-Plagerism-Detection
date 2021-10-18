/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/

#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int redovi,int kolone){
	return Matrica(redovi, std::vector<double>(kolone));
}

Matrica UnesiMatricu(int redovi,int kolone){
	auto mat(KreirajMatricu(redovi,kolone));
	for (int i = 0; i<redovi; i++) {
		for(int j=0;j<kolone;j++){
			std::cin >> mat.at(i).at(j);
		}
	}
	return mat;	
}

int Redovi(Matrica mat){
	return mat.size();
}

int Kolone(Matrica mat){
	return mat.at(0).size();
}

void IspisiMatricu(Matrica mat){
	for(int i=0;i<Redovi(mat);i++){
		for(int j=0;j<Kolone(mat);j++){
			std::cout << std::setw(6)<<mat.at(i).at(j);
		}
		std::cout  << std::endl;
	}
}

std::vector<int> PozicijaMax(Matrica mat){
	std::vector<int>pozicija;
	
	int max=mat.at(0).at(0);
	pozicija.push_back(0);
	pozicija.push_back(0);
	for(int i=0;i<Redovi(mat);i++){
		for(int j=0;j<Kolone(mat);j++){
			if(mat.at(i).at(j)>max){
				max = mat.at(i).at(j);
				pozicija.at(0)=i;
				pozicija.at(1)=j;
			}
		}
	}
	return pozicija;
}


Matrica Koncentricni_kvadrati(Matrica mat,std::vector<int> pozicija,int format){
	int koordinata_i=pozicija.at(0);
	int koordinata_j=pozicija.at(1);
	auto nova_matrica(KreirajMatricu(format,format));
	int k(0),l(0);
	
	for(int i=koordinata_i-(format/2);i<=koordinata_i+(format/2);i++){
		for(int j=koordinata_j-(format/2);j<=koordinata_j+(format/2);j++){
			nova_matrica.at(k).at(l)=mat.at(i).at(j);
			l++;
		}
		k++;
		l=0;
	}
	return nova_matrica;
}

int BrojMogucih(Matrica mat, std::vector<int> pozicija ){
	int brojac1(1);
	int brojac2(1);
	int koordinata_i=pozicija.at(0);
	int koordinata_j=pozicija.at(1);
	
	while ((koordinata_i>=1 && koordinata_j>=1)){
		brojac1+=2;
		koordinata_i--;
		koordinata_j--;
	}	
	
	koordinata_i=pozicija.at(0);
	koordinata_j=pozicija.at(1);
		
	while(koordinata_i<=(Redovi(mat)-2) && koordinata_j<=(Kolone(mat)-2)) {
		brojac2+=2;
		koordinata_i++;
		koordinata_j++;
		
	}
	
	if(brojac1<brojac2) return brojac1;
	
	return brojac2;
}

Matrica NajvecaPlaninaMatrice(Matrica mat){
	
	Matrica prazna;
	prazna=KreirajMatricu(0,0);
	
	if(Redovi(mat)==0 || mat.at(0).size()==0){
		return prazna;
	}
	
	
	int sirina=mat.at(0).size();
	
	for(int i=0;i<Redovi(mat);i++){
		if(mat.at(i).size()!=sirina) throw std::domain_error("Matrica nije korektna");
	}
	
	
	std::vector<int>pozicija=PozicijaMax(mat);
	int maks_format = BrojMogucih(mat, pozicija);
	std::vector<Matrica> vektor_rezultata;
	auto prva(KreirajMatricu(1,1));
	prva.at(0).at(0) = mat.at(pozicija.at(0)).at(pozicija.at(1));
	vektor_rezultata.push_back(prva);
	for(int i = 3; i <= maks_format;i+=2 ){
		auto rezultantna=Koncentricni_kvadrati(mat,pozicija,i);
		vektor_rezultata.push_back(rezultantna);
	}
	return vektor_rezultata.at(vektor_rezultata.size()-1);
}

int main (){

	Matrica prazna;
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if(m!=0 && n!=0){	
		std::cout << "Unesite elemente matrice: " << std::endl;
		
		auto unesena_matrica(UnesiMatricu(m,n));

		std::cout << "Najveca planina unesene matrice je:" << std::endl;
		
		try{
			IspisiMatricu(NajvecaPlaninaMatrice(unesena_matrica));
		}
		catch(std::domain_error &izuzetak){
			std::cout << izuzetak.what();
		}
	}

	return 0;
}