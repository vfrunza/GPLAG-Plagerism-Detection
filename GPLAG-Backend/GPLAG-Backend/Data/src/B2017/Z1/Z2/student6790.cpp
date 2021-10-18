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
#include <stdexcept>
#include <iomanip>



typedef std::vector<std::vector<double>> Matrica;

Matrica KreiranjeMatrice(int red, int kolona) {
	return Matrica(red,std::vector<double>(kolona));
}
Matrica UnosMatrice (int red, int kolona) {
	auto m(KreiranjeMatrice(red,kolona));
	for(int i(0);i<red;i++) {
		for(int j(0);j<kolona;j++) {
			std::cin>>m.at(i).at(j);
		}
	}
	return m;
}

bool DaLiJeGrbava (Matrica m) {
	
	int broj_elemenata_u_redu(m.at(0).size());
	
	for(int i(0);i<m.size();i++) {
		for(int j(0);j<m.at(i).size();j++) {
			if(broj_elemenata_u_redu!=m.at(i).size()) return true;
		}
	}
	
	return false;
}

 
Matrica NajvecaPlaninaMatrice(Matrica m) {
	
	//Rubni slucaj: jedna od dimenzija nula-> vrati nula matricu:
	if(m.size()==0 || m.at(0).size()==0) {
		Matrica nula_matrica(0, std::vector<double>(0));
		return nula_matrica;
	}
	
	//Ako je matrica grbava; baci izuzetak:
	if(DaLiJeGrbava(m)) 
		throw std::domain_error("Matrica nije korektna");
	
	//Ako matrica ima dva reda ili dvije kolone samo; ne moze da vrati matricu
	//vecu od 1x1. Tada je najveca planina zapravo najveci elemenat u matrici:
	if(m.size()<=2 || m.at(0).size()<=2) {
		const double epsilon(0.000000001);
		double max;
		for(int i(0);i<m.size();i++) {
			for(int j(0);j<m.at(i).size();j++) {
				if(i==0 && j==0) 
					max=m.at(i).at(j);
				if(m.at(i).at(j)-max>epsilon) 
					max=m.at(i).at(j);
			}
		}
		Matrica planina(1, std::vector<double>(1,max));
		return planina;
	}
	
	int AktuelniVrh(m.at(1).at(1)),DimenzijaPlanine(1);
	int DimPotPlanine(1);
	int koordi(1),koordj(1);
	
	for(int i(0);i<m.size();i++) {
		for(int j(0);j<m.at(i).size();j++) {
			if(i!=0 && j!=0 && i!=m.size() && j!=m.at(i).size()) {
				
				int PotencijalniVrh(m.at(i).at(j));
				
				int suma(m.at(i).at(j));
				int pomjeriza(1);
				int iVrh(1),jVrh(1);
				
				for(;;) {
					int suma1(0);
					if((iVrh-pomjeriza)<0||(iVrh+pomjeriza)>=m.size() ||
						(jVrh-pomjeriza)<0 || (jVrh+pomjeriza)>=m.at(0).size()){
							DimPotPlanine-=2;
							break;
						}
				
					
					for(int k(iVrh-pomjeriza);k<=(iVrh+pomjeriza);k++) {
						for(int l(jVrh-pomjeriza);l<=(jVrh+pomjeriza);l++) {
							if(k==(iVrh-pomjeriza) || k==(iVrh+pomjeriza) ||
							  (l==(jVrh-pomjeriza) && k>(iVrh-pomjeriza) && k<(iVrh+pomjeriza)) ||
							  (l==(jVrh+pomjeriza) && k>(iVrh-pomjeriza) && k<(iVrh+pomjeriza)))
							  			suma1+=m.at(k).at(l);
						}
					}
					if(suma1<=suma) break;
					pomjeriza++;
					if(DimPotPlanine==1) suma=suma1+m.at(i).at(j);
					else suma=suma1;
					DimPotPlanine+=2;
					
				}
				
				if(DimPotPlanine>DimenzijaPlanine) {
					AktuelniVrh=PotencijalniVrh;
					koordi=iVrh;
					koordj=jVrh;
					DimenzijaPlanine=DimPotPlanine;
					
				}
				if(DimenzijaPlanine==DimPotPlanine) {
					if(PotencijalniVrh>AktuelniVrh) {
						AktuelniVrh=PotencijalniVrh;
						koordi=iVrh;
						koordj=jVrh;
						DimenzijaPlanine=DimPotPlanine;
					}
					if(PotencijalniVrh==AktuelniVrh) {
						if(koordi<iVrh) {
							AktuelniVrh=PotencijalniVrh;
							koordi=iVrh;
							koordj=jVrh;
							DimenzijaPlanine=DimPotPlanine;
						}
						if(koordi==iVrh) {
							if(koordj<jVrh) {
								AktuelniVrh=PotencijalniVrh;
								koordi=iVrh;
								koordj=jVrh;
								DimenzijaPlanine=DimPotPlanine;
							}
						}
					}
				}
				
			}
		}
	}
	
	Matrica Planina;int br=0;
	for(int i(koordi-DimenzijaPlanine);i<=koordi+DimenzijaPlanine;i++)
	{   
		Planina.resize(Planina.size()+1);
		for(int j(koordj-DimenzijaPlanine);j<=koordj+DimenzijaPlanine;j++)
				Planina.at(br).push_back(m.at(i).at(j));
		br++;
	}
	
	
	return Planina;
}




int main () {
	
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
	
		if(m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
	
		std::cout<<"Unesite elemente matrice: ";
		auto A(UnosMatrice(m,n));
	
		std::cout<<std::endl;
		Matrica B=NajvecaPlaninaMatrice(A);
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i(0);i<B.size();i++) {
			for(int j(0);j<B.at(i).size();j++) {
				std::cout<<std::right<<std::setw(6)<<B.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error poruka) {
		std::cout<<poruka.what()<<std::endl;
	}
	

	return 0;
}