#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica ;
typedef std::vector<double> Vektor ;

Matrica KreirajMatricu(int broj_redova,int broj_kolona)
{
	return Matrica(broj_redova,Vektor(broj_kolona));
}
Matrica UnesiMatricu(int broj_redova,int broj_kolona)
{
	auto matrica(KreirajMatricu(broj_redova,broj_kolona));
	for(int i=0; i<broj_redova; i++) {
		for(int j=0; j<broj_kolona; j++) {
			std::cin>>matrica.at(i).at(j);
		}
	}
	return matrica;

}



Matrica NajvecaPlaninaMatrice(Matrica glavna_matrica)
{
	Matrica planina_matrice;
	Matrica planina_matrice2;
	int zbri_osmorke;
	if(glavna_matrica.size()==0 || glavna_matrica.at(0).size()==0) {
		auto vrati(KreirajMatricu(0,0));
		return vrati;
	}
	int broj_kolona(glavna_matrica.at(0).size());
	for(int i=0; i<glavna_matrica.size(); i++) {
		if(glavna_matrica.at(i).size()!=broj_kolona)
			throw std::domain_error("Matrica nije korektna");

	}

	if(glavna_matrica.size()==2 && glavna_matrica.at(0).size()==2) {
		auto	planina_matrice(KreirajMatricu(1,1));
		int max=0;
		for(int i=0; i<glavna_matrica.size(); i++) {
			for(int j=0; j<glavna_matrica.at(0).size(); j++) {
				if(glavna_matrica.at(i).at(j)>max) {
					max=glavna_matrica.at(i).at(j);
				}
			}
		}
		planina_matrice.at(0).at(0)=max;
		return planina_matrice;
	}

	for(int i=0; i<glavna_matrica.size(); i++) {
		if(planina_matrice.size()>0) break;
		for(int j=0; j<glavna_matrica.at(0).size(); j++) {
			if(i!=0 && j!=0 && i!=glavna_matrica.size()-1 && j!=glavna_matrica.at(0).size()-1) {
				zbri_osmorke=glavna_matrica.at(i-1).at(j-1)+glavna_matrica.at(i-1).at(j)+glavna_matrica.at(i-1).at(j+1)+glavna_matrica.at(i).at(j-1)+glavna_matrica.at(i).at(j+1)+glavna_matrica.at(i+1).at(j-1)+glavna_matrica.at(i+1).at(j)+glavna_matrica.at(i+1).at(j+1);

				if(zbri_osmorke<glavna_matrica.at(i).at(j) && (i-2<0 || j-2<0 || j+2>glavna_matrica.size()-1 || j+2>glavna_matrica.size()-1)) {
					planina_matrice=KreirajMatricu(3,3);
					planina_matrice.at(0).at(0)=glavna_matrica.at(i-1).at(j-1);//prvi red
					planina_matrice.at(0).at(1)=glavna_matrica.at(i-1).at(j);
					planina_matrice.at(0).at(2)=glavna_matrica.at(i-1).at(j+1);
					planina_matrice.at(1).at(0)=glavna_matrica.at(i).at(j-1); //drug red
					planina_matrice.at(1).at(1)=glavna_matrica.at(i).at(j);
					planina_matrice.at(1).at(2)=glavna_matrica.at(i).at(j+1);
					planina_matrice.at(2).at(0)=glavna_matrica.at(i+1).at(j-1);//treci red
					planina_matrice.at(2).at(1)=glavna_matrica.at(i+1).at(j);//treci red
					planina_matrice.at(2).at(2)=glavna_matrica.at(i+1).at(j+1);//treci red
					break;
				}
			}


		}
	}
	for(int i=0; i<glavna_matrica.size(); i++) {
		if(planina_matrice2.size()>0) break;
		for(int j=0; j<glavna_matrica.at(0).size(); j++) {
			zbri_osmorke=0;
			if(i!=0 && j!=0 && i!=glavna_matrica.size()-1 && j!=glavna_matrica.at(0).size()-1) {
				zbri_osmorke=glavna_matrica.at(i-1).at(j-1)+glavna_matrica.at(i-1).at(j)+glavna_matrica.at(i-1).at(j+1)+glavna_matrica.at(i).at(j-1)+glavna_matrica.at(i).at(j+1)+glavna_matrica.at(i+1).at(j-1)+glavna_matrica.at(i+1).at(j)+glavna_matrica.at(i+1).at(j+1);
				if(i>=2 && j>=2 && j+2<=glavna_matrica.size()-1 && j+2<=glavna_matrica.size()-1) {
					int zbir_sesnest=glavna_matrica.at(i-2).at(j-2)+glavna_matrica.at(i-2).at(j-1)+glavna_matrica.at(i-2).at(j)+glavna_matrica.at(i-2).at(j+1)+glavna_matrica.at(i-2).at(j+2)+glavna_matrica.at(i-1).at(j-2)+glavna_matrica.at(i-1).at(j+2)+glavna_matrica.at(i).at(j-2)+glavna_matrica.at(i).at(j+2)+  glavna_matrica.at(i+1).at(j-2)+glavna_matrica.at(i+1).at(j+2)+  glavna_matrica.at(i+2).at(j-2)+   glavna_matrica.at(i+2).at(j-1)+  glavna_matrica.at(i+2).at(j)+ glavna_matrica.at(i+2).at(j+1)+    glavna_matrica.at(i+2).at(j+2);


					if(zbri_osmorke<glavna_matrica.at(i).at(j)  && zbir_sesnest<glavna_matrica.at(i).at(j)) {
						auto	planina_matrice2(KreirajMatricu(5,5));
						//prvi red
						planina_matrice2.at(0).at(0)=glavna_matrica.at(i-2).at(j-2);
						planina_matrice2.at(0).at(1)=glavna_matrica.at(i-2).at(j-1);
						planina_matrice2.at(0).at(2)=glavna_matrica.at(i-2).at(j);
						planina_matrice2.at(0).at(3)=glavna_matrica.at(i-2).at(j+1);
						planina_matrice2.at(0).at(4)=glavna_matrica.at(i-2).at(j+2);
						//drugi red
						planina_matrice2.at(1).at(0)=glavna_matrica.at(i-1).at(j-2);
						planina_matrice2.at(1).at(1)=glavna_matrica.at(i-1).at(j-1);
						planina_matrice2.at(1).at(2)=glavna_matrica.at(i-1).at(j);
						planina_matrice2.at(1).at(3)=glavna_matrica.at(i-1).at(j+1);
						planina_matrice2.at(1).at(4)=glavna_matrica.at(i-1).at(j+2);
						//treci red
						planina_matrice2.at(2).at(0)=glavna_matrica.at(i).at(j-2);
						planina_matrice2.at(2).at(1)=glavna_matrica.at(i).at(j-1);
						planina_matrice2.at(2).at(2)=glavna_matrica.at(i).at(j);
						planina_matrice2.at(2).at(3)=glavna_matrica.at(i).at(j+1);
						planina_matrice2.at(2).at(4)=glavna_matrica.at(i).at(j+2);
						//cetvrti red
						planina_matrice2.at(3).at(0)=glavna_matrica.at(i+1).at(j-2);
						planina_matrice2.at(3).at(1)=glavna_matrica.at(i+1).at(j-1);
						planina_matrice2.at(3).at(2)=glavna_matrica.at(i+1).at(j);
						planina_matrice2.at(3).at(3)=glavna_matrica.at(i+1).at(j+1);
						planina_matrice2.at(3).at(4)=glavna_matrica.at(i+1).at(j+2);
						//peti red
						planina_matrice2.at(4).at(0)=glavna_matrica.at(i+2).at(j-2);
						planina_matrice2.at(4).at(1)=glavna_matrica.at(i+2).at(j-1);
						planina_matrice2.at(4).at(2)=glavna_matrica.at(i+2).at(j);
						planina_matrice2.at(4).at(3)=glavna_matrica.at(i+2).at(j+1);
						planina_matrice2.at(4).at(4)=glavna_matrica.at(i+2).at(j+2);
						return planina_matrice2;
					}

				}
			}
		}

	}
	return planina_matrice;

}






int main ()
{
	try {
		std::cout <<"Unesite dimenzije matrice (m i n): " ;
		int m,n;
		std::cin >> m>>n;
		if(m<0 || n<0) {
			std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
			return 0;
		}

		std::cout <<"Unesite elemente matrice:"<<std::endl ;
		auto A(UnesiMatricu(m,n));

		std::cout <<"Najveca planina unesene matrice je:"<<std::endl ;
		if(m==1 && n==1) {
			for(int i=0; i<A.size(); i++) {
				for(int j=0; j<A.at(i).size(); j++) {
					std::cout<<std::setw(6)<<A.at(i).at(j);
				}
				std::cout<<std::endl;
			}
			return 0;
		}
		auto planina(NajvecaPlaninaMatrice(A));
		for(int i=0; i<planina.size(); i++) {
			for(int j=0; j<planina.at(i).size(); j++) {
				std::cout<<std::setw(6)<<planina.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}