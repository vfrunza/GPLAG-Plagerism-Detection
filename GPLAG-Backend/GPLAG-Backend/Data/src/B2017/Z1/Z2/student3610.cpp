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

double minimumKoordinata (double a, double b, double c, double d){
	return std::min(a, std::min(b, std::min(c,d)));
}

Matrica vrhoviPlanine (Matrica m){
	double zbirOkolnih=0;
	Matrica vrhovi;
	
	for (int i=1; i<m.size()-1; i++){
		for (int j=1; j<m.at(i).size()-1; j++){
			zbirOkolnih=m.at(i-1).at(j-1)+m.at(i-1).at(j)+m.at(i-1).at(j+1)+m.at(i).at(j-1)+m.at(i).at(j+1)+m.at(i+1).at(j-1)+m.at(i+1).at(j)+m.at(i+1).at(j+1);
			
			if (m.at(i).at(j)>zbirOkolnih) vrhovi.push_back({m.at(i).at(j), i, j});
		}
	}
	return vrhovi;
}

void ispisiMatricu (Matrica m){
	for (int i=0; i<m.size(); i++){
		for (int j=0; j<m.at(i).size(); j++){
			std::cout<<std::setw(6)<<m.at(i).at(j);
		}
		std::cout<<std::endl;
	}
}


Matrica napraviVrhPlanine (Matrica matricaPlanine, std::vector<double> vrhIKoordinate){
	int prostorIznad = vrhIKoordinate.at(1);
	int prostorLijevo = vrhIKoordinate.at(2);
	int prostorDesno = matricaPlanine.at(0).size() - vrhIKoordinate.at(2)-1;
	int prostorIspod = matricaPlanine.size() - vrhIKoordinate.at(1)-1;
	int dimenzija = (int)minimumKoordinata(prostorIznad, prostorIspod, prostorDesno, prostorLijevo);
	
	Matrica vrhPlanine;
	
	
	for (int i= (int)vrhIKoordinate.at(1)-dimenzija; i<(int)vrhIKoordinate.at(1)+dimenzija+1; i++){
		std::vector<double> pom;
		for (int j=(int)vrhIKoordinate.at(2)-dimenzija; j<(int)vrhIKoordinate.at(2)+dimenzija+1; j++){
			
			pom.push_back(matricaPlanine.at(i).at(j));
			
		}
		vrhPlanine.push_back(pom);
	}
	return vrhPlanine;
}

bool jelGrbavaMatrica (Matrica m){
	for (int i=1; i<m.size(); i++){
		if (m.at(i).size() != m.at(i-1).size()) return true;
	}
	return false;
}

std::vector<int> indeksMinimalnihKoordinata (std::vector<double> koordinate){
	std::vector<int> indeksi;
	double minKoordinata = koordinate.at(0);
	for (int i=1; i<koordinate.size(); i++){
		if (koordinate.at(i)< minKoordinata) minKoordinata=koordinate.at(i);
	}
	for (int i=0; i<koordinate.size(); i++){
		if (minKoordinata == koordinate.at(i)) indeksi.push_back(i);
	}
	return indeksi;
}


std::vector<int> indeksiMaksimalnihDimenzija (std::vector<double> dimenzije){
	std::vector<int> indeksi;
	double maxDimenzija  = dimenzije.at(0);
	
	for (int i=1; i<dimenzije.size(); i++){
		if (dimenzije.at(i)> maxDimenzija)maxDimenzija=dimenzije.at(i);
	}
	
	for (int i=0; i<dimenzije.size(); i++){
		if (maxDimenzija == dimenzije.at(i)) indeksi.push_back(i);
	}
	return indeksi;
}

double najveciElementPlanine (Matrica planina){
	double max = planina.at(0).at(0);
	
	for (int i=0; i<planina.size(); i++){
		for (int j=0; j<planina.size(); j++){
			if (planina.at(i).at(j)>max)  max=planina.at(i).at(j);
		}
	}
	return max;
}

Matrica NajvecaPlaninaMatrice(Matrica planinaMatrice){
	Matrica praznaMatrica;
	
	if (jelGrbavaMatrica(planinaMatrice)) throw std::domain_error ("Matrica nije korektna");
	
	if (planinaMatrice.size()==0) return praznaMatrica;
	
	if (planinaMatrice.size() < 3 || planinaMatrice.at(0).size() < 3){
		praznaMatrica.push_back ({najveciElementPlanine(planinaMatrice)});
		return praznaMatrica;
	}
	
	
	Matrica vrhovi = vrhoviPlanine(planinaMatrice);
	if (vrhovi.size() == 0){
		praznaMatrica.push_back({najveciElementPlanine(planinaMatrice)});
		return praznaMatrica;
	}
	
	std::vector<std::vector<std::vector<double>>> sviVrhovi;
	Matrica dimenzijaIKoordinate;
	
	for (int i=0; i<vrhovi.size(); i++){
		sviVrhovi.push_back(napraviVrhPlanine(planinaMatrice, vrhovi.at(i)));
	}
	
	std::vector<double> dimenzije;
	std::vector<double> prveKoordinate;
	std::vector<double> drugeKoordinate;
	
	for (int i=0; i<sviVrhovi.size(); i++){
		double velicina= (double)sviVrhovi.at(i).size();
		double x = vrhovi.at(i).at(1);
		double y = vrhovi.at(i).at(2);
		dimenzije.push_back(velicina);
		prveKoordinate.push_back(x);
		drugeKoordinate.push_back(y);
	}
	std::vector<int> indeksiMaksDimenzija =  indeksiMaksimalnihDimenzija(dimenzije);
	if (indeksiMaksDimenzija.size() == 1) return sviVrhovi.at(indeksiMaksDimenzija.at(0));
	else {
		
		std::vector<std::vector<std::vector<double>>> vrhoviPoKoordinatama;
		std::vector<double> prveKoordinate1;
		std::vector<double> drugeKoordinate1;
		
		for (int i=0; i<indeksiMaksDimenzija.size(); i++){
			vrhoviPoKoordinatama.push_back(sviVrhovi.at(indeksiMaksDimenzija.at(i)));
			
			prveKoordinate1.push_back(prveKoordinate.at(indeksiMaksDimenzija.at(i)));
			
			drugeKoordinate1.push_back(drugeKoordinate.at(indeksiMaksDimenzija.at(i)));
		}
		
		std::vector<int> indeksiMinPrvihKoordinata =indeksMinimalnihKoordinata(prveKoordinate1);
		
		if (indeksiMinPrvihKoordinata.size() == 1) return vrhoviPoKoordinatama.at(0);
		
		else    {
			std::vector<std::vector<std::vector<double>>> vrhoviPoDrugojKoordinati;
			std::vector<double> drugeKoordinate2;
			for (int i=0; i<indeksiMinPrvihKoordinata.size(); i++){
				vrhoviPoDrugojKoordinati.push_back(vrhoviPoKoordinatama.at(indeksiMinPrvihKoordinata.at(i)));
				drugeKoordinate2.push_back(drugeKoordinate1.at(indeksiMinPrvihKoordinata.at(i)));
			}
			std::vector<int>indeksiMinDrugihKoordinata = indeksMinimalnihKoordinata (drugeKoordinate2);
			return vrhoviPoDrugojKoordinati.at(indeksiMinDrugihKoordinata.at(0));
			
		}
	}
}






int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if (m<=0 || n<=0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	Matrica planinica;
	double broj;
	for (int i=0 ; i<m; i++){
		std::vector<double>pom;
		for (int j=0; j<n; j++){
			std::cin>>broj;
			pom.push_back(broj);
		}
		planinica.push_back(pom);
	}
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	try{
		ispisiMatricu(NajvecaPlaninaMatrice(planinica));
	}
	
	
	catch (std::exception& e){
		std::cout<<e.what();
	}
	
	
	return 0;
}