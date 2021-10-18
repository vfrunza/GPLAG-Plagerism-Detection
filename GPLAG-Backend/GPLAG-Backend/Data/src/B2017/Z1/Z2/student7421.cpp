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

double VrhPlanine(std::vector<std::vector<double>> planina){
	if(planina.size()==0)return 0; // u slucaju da se prazna matrica posalje... dok u najveca planina jos nsita nema...
	int koordinata(planina.size()/2);
	return planina.at(koordinata).at(koordinata);
}


bool DaLiJePLanina (std::vector<std::vector<double>> moguca_planina){ // mozda stavit da ako jeste planina vrati njen vrh.... 
	int pomocni_format(moguca_planina.size()), zapamti_sumu(0), br(0);
	bool indikator(true);
	while(pomocni_format>=1){ //racunanje suma od vanjskog prema unutrasnjem krugu, tj provjera dal je planina;
		
		int suma(0);
		for(int i=0; i<moguca_planina.size(); i++){
			for(int j=0; j<moguca_planina.at(i).size(); j++){
				if( ((i==0+br || i==moguca_planina.size()-br-1) && j>=0+br && j<=moguca_planina.size()-br-1) || ((j==0+br || j==moguca_planina.size()-br-1) && i>=0+br && i<=moguca_planina.size()-br-1) )suma+=moguca_planina.at(i).at(j);
			}
		}
		//std::cout << "\n ___ " << suma << " ___ " << zapamti_sumu << "   \n";
		if(pomocni_format==moguca_planina.size())zapamti_sumu=suma;
		else if(suma<=zapamti_sumu){
			//std::cout << "bio sam ovde";
			indikator=false;
			break;
		}
		else zapamti_sumu=suma;
		
		br++;
		pomocni_format-=2;
	}
	return indikator;
}


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){ 
	std::vector<std::vector<double>> najveca_planina;
	int x_vrha_naj_planine(matrica.size()), y_vrha_naj_planine(matrica.size());
	for(int i=0; i<matrica.size(); i++){
		if(matrica.at(i).size()!=matrica.at(0).size())throw std::domain_error("Matrica nije korektna"); 
	}
	if(matrica.size()==0 || (matrica.size()!=0 && matrica.at(0).size()==0)) return najveca_planina; // vraca praznu matricu;
	
	int format_planine;
	if(matrica.size()%2==0)format_planine=matrica.size()-1;
	else format_planine=matrica.size();
	
	while(format_planine>=1){
		for(int i=0; i<matrica.size(); i++){
			for(int j=0; j<matrica.at(i).size(); j++){
				 
				std::vector<std::vector<double>>planina;
				if(i+format_planine-1<matrica.size() && j+format_planine-1<matrica.at(i).size()){ // moze biti planina; // -1 jer se i ovo i ili j racuna kao dio formata...
					std::vector<std::vector<double>>moguca_planina(format_planine);
					int x_vrha(matrica.size()), y_vrha(matrica.size());
				
					//ovde izdvajam mogucu planinu i saljem gore na provjeru dal je i pamtim ovde indekse i vrijednost vrha planine...
					for(int z=i, br=0; z<i+format_planine; z++, br++){
						for(int k=j; k<j+format_planine; k++){
							moguca_planina.at(br).push_back(matrica.at(z).at(k));
							if(z==z+format_planine/2)x_vrha=z;
							if(k==j+format_planine/2)y_vrha=k;
						}
					}
					if(DaLiJePLanina(moguca_planina)){
						planina=moguca_planina;
						
						
					/*	std::cout << "\nplanina.... \n";
						for(int h=0; h<planina.size(); h++){
							for(int l=0; l<planina.at(h).size(); l++){
								std::cout << std::setw(6) << planina.at(h).at(l);
							}
							std::cout << std::endl;
						}
						std::cout << "\n\n";
					*/	
						
						
						if(planina.size()>najveca_planina.size()){
							najveca_planina=planina; // oni imaju ovde iste sigurno formate ovo je samo da bi se prvi onaj krug nesto unijelo u najveca planina
							x_vrha_naj_planine=x_vrha;
							y_vrha_naj_planine=y_vrha;
						}
						else if(VrhPlanine(planina)>VrhPlanine(najveca_planina)){
							najveca_planina=planina;
							x_vrha_naj_planine=x_vrha;
							y_vrha_naj_planine=y_vrha;
						}
						else if(VrhPlanine(planina)==VrhPlanine(najveca_planina) && x_vrha<x_vrha_naj_planine){
						//	std::cout << "\nPOredenje 1 x vrha   " << x_vrha << "  k vrha naj planine "  << x_vrha_naj_planine << "\n";
							x_vrha_naj_planine=x_vrha;
							y_vrha_naj_planine=y_vrha;
							najveca_planina=planina;
						}
						else if(VrhPlanine(planina)==VrhPlanine(najveca_planina) && x_vrha==x_vrha_naj_planine && y_vrha<y_vrha_naj_planine){
						//	std::cout << "\nPoredenje 2 y vrha " << y_vrha << "  y vrha naj planine " << y_vrha_naj_planine << "\n";
							y_vrha_naj_planine=y_vrha;
							najveca_planina=planina;
						}
						
						/*
						std::cout << "\nNajveca planina... \n";
						for(int h=0; h<najveca_planina.size(); h++){
							for(int l=0; l<najveca_planina.at(h).size(); l++){
								std::cout << std::setw(6) << najveca_planina.at(h).at(l);
							}
							std::cout << std::endl;
						}
						std::cout << "\n\n";
						*/
						
					}
				
				} 
				
				
				
			}
		}
		
		if(najveca_planina.size()!=0)break;
		format_planine-=2;
	}
	
	
	return najveca_planina;
}

int main ()
{
	try{
		int m,n;
		std::cout << "Unesite dimenzije matrice (m i n): ";
		std::cin >> m >> n;
		if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		std::vector<std::vector<double>> matrica(m, std::vector<double>(n));
		std::cout << "Unesite elemente matrice:";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				std::cin >> matrica.at(i).at(j);
			}
		}
		 /*
		std::cout << "Unijeli ste matricu: \n";
		for(int i=0; i<matrica.size(); i++){
			for(int j=0; j<matrica.at(i).size(); j++){
				std::cout << std::setw(6) << matrica.at(i).at(j);
			}
			std::cout << std::endl;
		}
		std::cout << "\n\nDa li je planina: " << DaLiJePLanina(matrica);
		std::cout << "\n vrh " << VrhPlanine(matrica) << "\n\n"; 
		*/
		
		 
		std::vector<std::vector<double>> naj_planina(NajvecaPlaninaMatrice(matrica));
		std::cout << "\nNajveca planina unesene matrice je:\n";
		for(int i=0; i<naj_planina.size(); i++){
			for(int j=0; j<naj_planina.at(i).size(); j++){
				std::cout << std::setw(6) << std::right << naj_planina.at(i).at(j);
			}
			std::cout << std::endl;
		}
	}catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}