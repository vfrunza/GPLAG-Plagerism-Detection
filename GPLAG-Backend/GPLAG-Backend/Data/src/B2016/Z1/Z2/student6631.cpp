/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

/*bool jeGrbava(std::vector<std::vector<double>>m ){
	int velicina(m[0].size());
	for(int i=1;i<m.size();i++){
		if(m[i].size()!=ve)
	}
	return true;
}*/

bool jeGrbava(std::vector<std::vector<double>> matrica){
	for(int i=0;i<matrica.size();i++){
		int velicina(matrica[0].size());
		if(velicina != matrica[i].size()) return true;
	}
	return false;
}

int BrojRedova(std::vector<std::vector<double>> m) {
 return m.size();
}

int BrojKolona(std::vector<std::vector<double>> m) {
 return m[0].size();
}

void IspisiMatricu(std::vector<std::vector<double>> m) {
 			for(int i=0; i<BrojRedova(m); i++) {
 			for(int j = 0; j < BrojKolona(m); j++)
 			std::cout << std::setw(4) << m[i][j];
 			std::cout << std::endl;
 }
}
std::vector<std::vector<double>> KreirajMatricu(int broj_redova, int broj_kolona){
   return std::vector<std::vector<double>>(broj_redova, std::vector<double>(broj_kolona));
}

std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> matrica){
	std::vector<std::vector<double>> horizont(matrica.size());
	
	for(int i=0;i<matrica.size();i++){
		for(int j=matrica[i].size()-1; j>=0;j--){
			horizont[i].push_back(matrica[i][j]);
		}
	}
	return horizont;	
}

    std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> matrica){
	std::vector<std::vector<double>> vertikala(matrica.size());
	
	for(int i=matrica.size()-1;i>=0;i--){
		for(int j=0; j<matrica[i].size();j++){
			vertikala[i].push_back(matrica[i][j]);
		}
	}
	return vertikala;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> matrica){
	
	if(jeGrbava(matrica)) throw std::domain_error("Matrica nije korektna");
	
	std::vector<std::vector<double>> horizont, vertikala, hv;
	
	
	
	vertikala=VertikalnoOgledalo(matrica);
	horizont=HorizontalnoOgledalo(matrica);
	hv=HorizontalnoOgledalo(VertikalnoOgledalo(matrica));
	
	int sirina, visina;
	visina=matrica.size();
	if(matrica.size()==0){
		sirina=0;
	}
	else{
	sirina=BrojKolona(matrica);
	}
	int inicijalna;
	inicijalna=3*visina;
	std::vector<std::vector<double>>ogledalo(inicijalna);

	
	//prva trecina
					int kontrolna(visina-1);
					for(int i=0;i<visina;i++){
						for(int j(0);j<=3*sirina;j++){
			
							if(j<sirina){
								ogledalo[i].push_back(hv[kontrolna][j]);
							}
							else if(j>=sirina && j<(2*sirina)){
								for(int a(0);a<sirina;a++){
									ogledalo[i].push_back(vertikala[kontrolna][a]);
								}
								j+=sirina;
							}
							else if(j>=(2*sirina)){
								for(int a(0);a<sirina;a++){
									ogledalo[i].push_back(hv[kontrolna][a]);
								}
								j+=sirina;
							}}
						kontrolna--;
					}
			//druga trecina
					kontrolna=0;
					int vrijednost=2*visina;
					for(int x=visina; x<=vrijednost-1 ;x++){
						for(int y(0); y<=3*sirina ;y++){
							
							if(y<(sirina)){
								ogledalo[x].push_back(horizont[kontrolna][y]);
							}
							else if(y>=(sirina) && y<2*sirina){
								for(int a(0);a<sirina;a++){
									ogledalo[x].push_back(matrica[kontrolna][a]);
								}
								y+=sirina;
							}
							else if(y>=(2*sirina)){
								for(int a(0);a<sirina;a++){
									ogledalo[x].push_back(horizont[kontrolna][a]);
								}
							y+=sirina;
							}
					}
					kontrolna++;
				}
			//treca trecina
					int kontrola(0);
					
					for(int c=3*visina-1; c>=vrijednost;c--){
						for(int b=0; b<=3*sirina; b++){	
			
			
							if(b<sirina){
								ogledalo[c].push_back(hv[kontrola][b]);
							}
							else if(b>=(sirina) && b<(2*sirina)){
								for(int a(0);a<sirina;a++){
									ogledalo[c].push_back(vertikala[kontrola][a]);
								}
							b+=sirina;
							}
							else if(b>=(2*sirina)){
								for(int a(0);a<sirina;a++){
									ogledalo[c].push_back(hv[kontrola][a]);
								}
							b+=sirina;
							}
						} 
						kontrola++;
				}
		return ogledalo;
}			
				

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	if(std::cin>>m>>n,m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
		
	}
	
	std::vector<std::vector<double>> matrica(m);
	std::vector<std::vector<double>> rez;
	double element;
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0); i<m; i++){
		for(int j(0);j<n;j++){
			std::cin>>element;
			matrica[i].push_back(element);
		}
	}
	try{
	rez=OgledaloMatrica(matrica);
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	IspisiMatricu(rez);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	

	return 0;
}
