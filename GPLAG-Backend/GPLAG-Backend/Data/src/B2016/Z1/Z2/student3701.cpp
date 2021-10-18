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

typedef std::vector<std::vector<double>> Matrica;

Matrica Kreiraj_matricu (int redovi, int kolone) {			//KREIRAJ MATRICU
	return Matrica(redovi, std::vector<double> (kolone));
}

Matrica Unesi_matricu ( int redovi, int kolone) {			//UNESI MATRICU
	Matrica matrica(Kreiraj_matricu(redovi,kolone));
	for (int i=0; i<redovi; i++)
		for (int j=0; j<kolone; j++)
			std::cin>>matrica[i][j];
//	for (int i=0,j=i+1; j<redovi; j++)					//provjera da li je matrica grbava, ako jeste bacam izuzetak
//		if (matrica[i].size()!=matrica[j].size()) 
//			throw std::domain_error("Matrica nije korektna");
	return matrica;
}

Matrica Horizontalno_ogledalo (Matrica original) {							//HORIZONTALNA MATRICA mijenjam redoslijed kolona
	Matrica horizontalna_mat(Kreiraj_matricu(original.size(),original[0].size()));
	for (int i=0; i<original.size(); i++)
		for (int j=original[0].size()-1,k=0; j>=0; j--,k++) 	//mijenjam kolone, moraju obe petlje
			horizontalna_mat[i][k]=original[i][j];
	return horizontalna_mat;
}

Matrica Vertikalno_ogledalo (Matrica original) {							//VERTIKALNA MATRICA mijenjam redoslijed redova
	Matrica vertikalna_mat(Kreiraj_matricu(original.size(),original[0].size()));
	for (int i=original.size()-1,j=0; i>=0; i--,j++) 
		vertikalna_mat[j]=original[i];				//samo redove, jer su vektori, elementi se sami kopiraju
	return vertikalna_mat;
}

Matrica Kombinovano_ogledalo (Matrica original) {							//KOMBINOVANA MATRICA mijenjam i redove i kolone 
	Matrica kombinovana_mat(Kreiraj_matricu(original.size(),original[0].size()));
	kombinovana_mat=Vertikalno_ogledalo(original);
	kombinovana_mat=Horizontalno_ogledalo(kombinovana_mat);		
	return kombinovana_mat;
}

void Ispisi_matricu (Matrica m) {					//FUNKCIJA ZA ISPIS MATRICA
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m[0].size(); j++)
			std::cout<<std::right<<std::setw(4)<<m[i][j];	//ispisuje elemente, pomjerene desno,i na 4 mjesta sirine 
		std::cout<<std::endl;
	}
}

Matrica OgledaloMatrica (Matrica polazna_matrica) {				//NAJVAZNIJA FUNKCIJA, OGLEDAMO FUNKCIJA
	for (int i=0, j=i+1; j<polazna_matrica.size(); j++) 		//provjera da li je matrica grbava, ako jeste bacam izuzetak
		if (polazna_matrica[i].size()!=polazna_matrica[j].size())
			throw std::domain_error ("Matrica nije korektna");
	if (polazna_matrica.size()==0) {return polazna_matrica;}			//pravi veliku matricu od h,v,hv i polazne matrice
	Matrica h(Horizontalno_ogledalo(polazna_matrica)), v(Vertikalno_ogledalo(polazna_matrica)), hv(Kombinovano_ogledalo(polazna_matrica));
	Matrica finalna(Kreiraj_matricu(polazna_matrica.size()*3,polazna_matrica[0].size()*3));
	for (int i=0; i<finalna.size(); i++){
		int p1=0;
		for (int j=0,k=0; j<finalna[0].size(); j++,k++) {
			if (i<polazna_matrica.size()){									//uslov za upis prvog okvirnog reda, (hv,v,hv)
				if (p1==0){
					finalna[i][j]=hv[i][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=1;}		// k je broj kolona malih matrica ga moram stalno
				}															// vracati na 0, tj na -1 jer ce prvo proci kroz 
				else if (p1==1){											// petlju, k++, pa onda opet doci do elementa male matrice
					finalna[i][j]=v[i][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=2;}
				}
				else  {
					finalna[i][j]=hv[i][k];
					if (k==polazna_matrica[0].size()-1) {k=-1;}
				}
			}
			else if (i>=polazna_matrica.size() && i<polazna_matrica.size()*2){	//uslov za upis drugog okvirnog reda (h,polazna,h)
				if (p1==0){
					finalna[i][j]=h[i-polazna_matrica.size()][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=1;}
				}
				else if (p1==1){
					finalna[i][j]=polazna_matrica[i-polazna_matrica.size()][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=2;}
				}
				else if (p1==2){
					finalna[i][j]=h[i-polazna_matrica.size()][k];
					if (k==polazna_matrica[0].size()-1) {k=-1;}
				}
			}
			else if (i>=polazna_matrica.size()*2){						//uslov za upis treceg okvirnog reda (hv,v,hv)
				if (p1==0){
					finalna[i][j]=hv[i-polazna_matrica.size()*2][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=1;}
				}
				else if (p1==1){
					finalna[i][j]=v[i-polazna_matrica.size()*2][k];
					if (k==polazna_matrica[0].size()-1) {k=-1; p1=2;}
				}
				else {
					finalna[i][j]=hv[i-polazna_matrica.size()*2][k];
					if (k==polazna_matrica[0].size()-1) {k=-1;}
				}
			}
		}
	}
	return finalna;							//konacna matrica
}

int main ()
{
	int broj_redova,broj_kolona;
	try {
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>broj_redova>>broj_kolona;
		if (broj_redova<0 || broj_redova<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		Matrica pocetna(Unesi_matricu(broj_redova,broj_kolona));
		std::cout<<"Rezultantna matrica: "<<std::endl;
		Ispisi_matricu(OgledaloMatrica(pocetna));
	}
	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}