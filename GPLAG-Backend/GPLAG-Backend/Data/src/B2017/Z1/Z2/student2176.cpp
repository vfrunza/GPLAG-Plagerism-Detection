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
#include <cmath>

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){
	std::vector<std::vector<double>> povratna;
	constexpr double EPS=0.000000001;
	//grbava matrica
	
	//if(matrica.size()==0 || matrica.at(0).size()==0) return povratna;
	for(int i=0;i<matrica.size();i++)
		if(matrica.at(0).size()!=matrica.at(i).size()) throw std::domain_error("Matrica nije korektna");
	if(matrica.size()==0 || matrica.at(0).size()==0) return povratna;
	// slucaj da nema planine, vec treba vratiti najveci element matrice 
	
	int visina(matrica.size());
	int sirinaMatrice(matrica.at(0).size());
	if(visina<3 || sirinaMatrice<3){
		double maks(matrica.at(0).at(0));
		for(int i=0;i<visina;i++){
			for(int j=0;j<sirinaMatrice;j++){
				if(matrica.at(i).at(j)>maks) maks=matrica.at(i).at(j);
			}
		}
		std::vector<double> pomocna;
		pomocna.push_back(maks);
		povratna.push_back(pomocna);
		return povratna;
	}
	//
	double suma(0);
	int red(0), kolona(0), sirina(0);
	int k(1);
	double vrh(0);
	int sirinaKonacna(0);
	int prvaKoordinata(0);
	int drugaKoordinata(0);
	double vrhKonacni(0);
	
	for (int i=1; i<matrica.size()-1; i++){
		for(int j=1; j<matrica.at(0).size()-1; j++){
			double poredim(matrica.at(i).at(j));
			k=1;
			sirina=0;
			suma=0;
			while (1){
				for(int l=i-k; l<=i+k; l++){
					for (int t=j-k; t<=j+k; t++){
						if((l==i-k || l==i+k) || (l>i-k && l<i+k && (t==j-k || t==j+k))) suma+=matrica.at(l).at(t);
					}
				}
				if(suma<poredim){
					poredim=suma;
					red=i;
					kolona=j;
					sirina=k;
					vrh=matrica.at(i).at(j);
				}
				else break;
				suma=0;
				if(i-k-1==-1 || i+k+1==matrica.size() || j-k-1==-1 || j+k+1==matrica.at(0).size()) break;
				k++;
			}
			if(sirina>sirinaKonacna) {
				sirinaKonacna=sirina;
				prvaKoordinata=red;
				drugaKoordinata=kolona;
				vrhKonacni=vrh;
			}
			else if(sirina==sirinaKonacna && sirinaKonacna!=0 && vrh>vrhKonacni){
				vrhKonacni=vrh;
				sirinaKonacna=sirina;
				prvaKoordinata=red;
				drugaKoordinata=kolona;
			}
			else if(sirina==sirinaKonacna && sirinaKonacna!=0 && std::fabs(vrh-vrhKonacni)<=EPS*(std::fabs(vrh)+std::fabs(vrhKonacni)) && red<prvaKoordinata){
				vrhKonacni=vrh;
				prvaKoordinata=red;
				drugaKoordinata=kolona;
				sirinaKonacna=sirina;

			}
			else if(sirina==sirinaKonacna && sirinaKonacna!=0 && std::fabs(vrh-vrhKonacni)<=EPS*(std::fabs(vrh)+std::fabs(vrhKonacni)) && red==prvaKoordinata && kolona<drugaKoordinata){
				vrhKonacni=vrh;
				drugaKoordinata=kolona;
				prvaKoordinata=red;
				sirinaKonacna=sirina;
			}
		}
	}
	//	std::cout<<"red: "<<prvaKoordinata<<" kolona: "<<drugaKoordinata<<" vrh: "<<vrhKonacni<<" sirina: "<<sirinaKonacna<<std::endl;
		std::vector<double> pomocniVektor;
		if(sirinaKonacna!=0){
			
			for(int i=prvaKoordinata-sirinaKonacna; i<=prvaKoordinata+sirinaKonacna;i++){
				for(int j=drugaKoordinata-sirinaKonacna; j<=drugaKoordinata+sirinaKonacna; j++) {
				
					pomocniVektor.push_back(matrica.at(i).at(j));
				}	
			povratna.push_back(pomocniVektor);
			pomocniVektor.resize(0);
			}
		}
		else {
			double maksimum(matrica.at(0).at(0));
			for (int i=0; i<matrica.size();i++){
				for(int j=0;j<matrica.at(0).size(); j++){
					if (matrica.at(i).at(j)>maksimum) maksimum=matrica.at(i).at(j);
				}
			}
			std::vector<double> nemaPlanina;
			nemaPlanina.push_back(maksimum);
			povratna.push_back(nemaPlanina);
		}
	
	
	
	return povratna;
}

int main ()
{
	int m(0), n(0);
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> matrica(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++) std::cin>>matrica.at(i).at(j);
	
		
	try{
		std::vector<std::vector<double>> najvecaPlanina(NajvecaPlaninaMatrice(matrica));
		
		std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i=0;i<najvecaPlanina.size();i++){
			for(int j=0;j<najvecaPlanina.at(0).size();j++) std::cout<<std::setw(6)<<najvecaPlanina.at(i).at(j);
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error greska){
		std::cout<<greska.what();
		return 0;
	}
	
	  //AT28(neaktivni)
        //Neispravno rjesenje:
        //  if (matrica.empty() || !matrica.at(0).size()) 
        //      return std::vector<std::vector<double>>();
        
        //Ispravno rjesenje:
        //
        //  if (matrica.empty()) 
        //      return std::vector<std::vector<double>>();
        //  for (std::vector<double> vektor : matrica)
        //      if (vektor.size() != matrica.at(0).size())
        //          throw std::domain_error("Matrica nije korektna");
        //  if (!matrica.at(0).size()) 
        //      return std::vector<std::vector<double>>();
        //
    
     //AT28(neaktivni)
        //Neispravno rjesenje:
        //  if (matrica.empty() || !matrica.at(0).size()) 
        //      return std::vector<std::vector<double>>();
        
        //Ispravno rjesenje:
        //
        //  if (matrica.empty()) 
        //      return std::vector<std::vector<double>>();
        //  for (std::vector<double> vektor : matrica)
        //      if (vektor.size() != matrica.at(0).size())
        //          throw std::domain_error("Matrica nije korektna");
        //  if (!matrica.at(0).size()) 
        //      return std::vector<std::vector<double>>();
        //
    /*
    std::vector<std::vector<double>> matrica {{}, {}, {2}};
    try
    {
        matrica = NajvecaPlaninaMatrice(matrica);
    }
    catch (std::domain_error& e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
*/

	return 0;
}