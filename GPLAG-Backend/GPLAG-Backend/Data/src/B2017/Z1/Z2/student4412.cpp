#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona)
{
	return Matrica(broj_redova, std::vector<double> (broj_kolona));
}

Matrica UnosMatrice (int broj_redova, int broj_kolona)
{
	auto m(KreirajMatricu(broj_redova, broj_kolona));
	for(int i=0; i<broj_redova; i++) {
		for(int j=0; j<broj_kolona; j++)
			std::cin>>m.at(i).at(j);
	}
	return m;
}

void IspisMatrice (Matrica m)
{
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.at(i).size(); j++)
			std::cout<<std::setw(6)<<m.at(i).at(j);
		std::cout<<std::endl;
	}
}

bool GrbavaMatrica (Matrica m)  												//sluzit ce za provjeru da li je unesena matrica grbava
{

	for(int i=1; i<m.size(); i++) {
		if(m.at(i).size()!=m.at(0).size()) return true;
	}
	return false;
}

Matrica NajvecaPlaninaMatrice(Matrica m)
{
	auto trazena_planina(KreirajMatricu(0,0));

	if(m.size()==1 && m.at(0).size()==1) return m; 								//slucaj kada se poslana matrica sastoji od 1 elementa

	if(m.size()==0 && m.at(0).size()==0) 										//ako je jedna od dimenzija matrice 0, vraca se prazna
		return trazena_planina;

	if(GrbavaMatrica(m))														//bacanje izuzetka
		throw std::domain_error("Matrica nije korektna");

	int max(0);
	if((m.size()==2 && m.at(0).size()==2) || (m.size()==1 && m.at(0).size()!=0)	//slucajevi kada je poslana matrica formata 2x2 ili ima samo 1 red, odnosno kolonu
	        || (m.size()!=0 && m.at(0).size()==1)) {
		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m.at(i).size(); j++)
				if(m.at(i).at(j)>max) max=m.at(i).at(j);
		}
		trazena_planina.resize(1);
		trazena_planina.at(0).resize(1);

		trazena_planina.at(0).at(0)=max;
		return trazena_planina;
	}																			//svi slucajevi navedeni iznad se tretiraju kao specijalni

	int i(1), j(1), k(1), l, novadim_gore(0), novadim_dole(0), novadim_lijevo(0),
	    novadim_desno(0), x(0), y(0), brojac1(0), brojac2(0),
	    prethodni_punikvadrat(0), novi_punikvadrat(0), prosli_format(0),
	    prosli_i(1), prosli_j(1), novi_format(0);
	double suma_1(0), prethodna(0);

	for(i=1; i<m.size()-1; i++) { 												//petlja koja uzima element po element, ne ukljucuje rubove
		for(j=1; j<m.at(i).size()-1; j++) {
			suma_1=0;
			for(k=i-1; k<=i+1; k++)
				for(l=j-1; l<=j+1; l++)  										//suma prvog kvadrata oko vrha
					suma_1+=m.at(k).at(l);

			suma_1-=m.at(i).at(j);

			if(suma_1<m.at(i).at(j)) { 											//pokusavamo prosiriti ovaj format
				novadim_gore=i-2;
				novadim_dole=i+2;
				novadim_lijevo=j-2;
				novadim_desno=j+2;
				prethodna=suma_1;
				prethodni_punikvadrat=prethodna+m.at(i).at(j);

				for(;;) {														//beskonacna petlja bez prirodnog izlaza
					if(novadim_gore<0 || novadim_lijevo<0 ||
					        novadim_dole>m.size()-1 ||
					        novadim_desno>m.at(i).size()-1) {
						novadim_gore++;
						novadim_dole--;
						novadim_lijevo++;
						novadim_desno--;
						break;
					}

					novi_punikvadrat=0;
					for(x=novadim_gore; x<=novadim_dole; x++)
						for(y=novadim_lijevo; y<=novadim_desno; y++)  			//racuna se suma novog kvadrata
							novi_punikvadrat+=m.at(x).at(y);

					if(novi_punikvadrat-prethodni_punikvadrat>prethodna)
						break;
					prethodna=novi_punikvadrat-prethodni_punikvadrat;
					prethodni_punikvadrat=novi_punikvadrat;

					novadim_gore--;
					novadim_dole++;
					novadim_lijevo--;
					novadim_desno++;
				}

				novi_format=novadim_desno-novadim_lijevo+1;
				if((prosli_format==0) || (prosli_format<novi_format) ||
				        (prosli_format==novi_format && m.at(i).at(j)>m.at(prosli_i).at(prosli_j)) 
				        || (prosli_format==novi_format && m.at(i).at(j)==m.at(prosli_i).at(prosli_j) && i<prosli_i) 
				        || (prosli_format==novi_format && m.at(i).at(j)==m.at(prosli_i).at(prosli_j) && i==prosli_i && j<prosli_j)) 
				        {														//ukoliko su ispunjeni uvjeti gore, pronadjena je nova planina
					brojac1=0, brojac2=0;
					trazena_planina.resize(novadim_dole-novadim_gore+1);
					for(int g=0; g<trazena_planina.size(); g++)
						trazena_planina.at(g).resize(novadim_desno-novadim_lijevo+1);

					for(x=novadim_gore; x<=novadim_dole; x++) {
						brojac2=0;
						for(y=novadim_lijevo; y<=novadim_desno; y++) {
							trazena_planina.at(brojac1).at(brojac2)=m.at(x).at(y);
							brojac2++;
						}
						brojac1++;
					}
					prosli_i=i;
					prosli_j=j;
				}
			}
			prosli_format=novi_format;
		}
	}
	return trazena_planina;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(n<0 || m<0) {															//provjera ispravnosti unesenih dimenzija
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice:";
	auto unesena_matrica(UnosMatrice(m,n));										//koristi se pomocna funkcija za unos
	try {
		std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
		IspisMatrice(NajvecaPlaninaMatrice(unesena_matrica));
	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}

	return 0;
}