#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

typedef std::vector<Matrica> TriDeVektor;   // Vektor Matrica

Matrica NapraviMatricu (int redovi, int kolone)
{
	return Matrica(redovi, std::vector<double> (kolone));
}

int BrojRedova(Matrica m)
{
	return m.size();
}

int BrojKolona(Matrica m)
{
	return m.at(0).size();
}

int Manji (int m, int n) // Ispisuje manji od dva broja
{
	if (m>n) return n;
	return m;
}

Matrica NajvisaPlanina (TriDeVektor VektorPlanina)   // Trazi najvecu planinu od podmatrica koje su vec planine // Uslov da se vrati ona sa manjim koordinatam je ispunjen jer su podmatrice u vektoru matrica poredane po redu
{
	int max_format(0);
	double vrh(0);
	for (int i = 0; i<VektorPlanina.size(); i++)
		if (VektorPlanina.at(i).size()>max_format)
			max_format=VektorPlanina.at(i).size();
		

	for (int i = 0; i<VektorPlanina.size(); i++)
		if (VektorPlanina.at(i).size()<max_format) {
			VektorPlanina.erase(VektorPlanina.begin()+i);
			i--;
		}

	for (int i = 0; i<VektorPlanina.size(); i++)
		for (int j = 0; j<VektorPlanina.at(i).size(); j++)
			for (int k = 0; k<VektorPlanina.at(i).at(j).size(); k++)
				if (k==(VektorPlanina.at(i).at(j).size()/2) && j == (VektorPlanina.at(i).size()/2) && VektorPlanina.at(i).at(j).at(k)>vrh)
					vrh=VektorPlanina.at(i).at(j).at(k);

	for (int i = 0; i<VektorPlanina.size(); i++)
		for (int j = 0; j<VektorPlanina.at(i).size(); j++)
			for (int k = 0; k<VektorPlanina.at(i).at(j).size(); k++)
				if (k==(VektorPlanina.at(i).at(j).size()/2) && j == (VektorPlanina.at(i).size()/2) && abs(VektorPlanina.at(i).at(j).at(k)-vrh)<0.0001) {
					return VektorPlanina.at(i);
				}
	Matrica nula(NapraviMatricu(0,0));
	return nula;
}

bool Grbavost (Matrica grbava)
{
	int prva_kolona (grbava.at(0).size());
	for (int i = 0; i<grbava.size(); i++)
		if (prva_kolona!=grbava.at(i).size())
			return true;
	return false;
} // Ispituje da li je matrica grbava

bool Brdo (int i, int j, Matrica const m)
{
	for (int k = 0; k<2; k++)
		for (int r = 0; r<m.at(0).size(); r++)
			if (m.at(0).at(r)==i && m.at(1).at(r)==j)
				return true;
	return false;
}   // Funkcija koja smjesta koordinate podmatrica koje su zadovoljile uslove da budu planina

Matrica NajvecaPlaninaMatrice (Matrica const m)
{
	if (m.size()==0){
		Matrica nula(NapraviMatricu(0,0));
		return nula;
	}
	
	if (Grbavost(m)) throw std::domain_error("Matrica nije korektna");
	TriDeVektor VektorPlanina;
	Matrica Zadovoljava(NapraviMatricu(2,1));// Matrica u koju se pisu oni koji su zadovoljili uslove
	for (int k = 0; k < Manji(BrojRedova(m),BrojKolona(m))/2+1; k++) {  // Koliko da odsječe ruba matrice
	int brojac(0);
		for (int i = 0; i < BrojRedova(m); i++){
			for (int j = 0; j < BrojKolona(m); j++) {
		
				Matrica podmatrica(NapraviMatricu(2*k+1,2*k+1));    // Kreiranje podmatrice koja ima dimenzije 2k+1,2k+1

				double vanjski_omotac(0),unutrasnji_omotac(0);    // Kreiranje vanjskog omotaca i unutrasnjeg omotaca

				if (i<k || j<k || j>=(BrojKolona(m)-k) || i>=(BrojRedova(m)-k))   // Ako se element nalazi u k-tom rubu matrice preskoci ga jer izlazi van granica matrice 
				continue;

				if ((k>1 && !Brdo(i,j,Zadovoljava))) continue;    // Ovo ispitiva da li su date koordinate vec nekad u proslosti bile planina (tj. brdo hehe)

				int red(0),kolona(0);   // pocetni uslov podmatrice koju pravim
				for (int r=(i-k) ; r < (i-k+(2*k+1)) ; r++) {
					for (int s=(j-k) ; s < (j-k+(2*k+1)) ; s++) {
						//Suma vanjskog omotaca
						if (r == (i-k) || s==(j-k) || s== (j+k) || r==(i+k))
							vanjski_omotac+=m.at(r).at(s);
						//Suma unutrašnjeg omotaca
						else if (r==(i-k+1) || r==(i+k-1) || s==(j+k-1) || s==(j-k+1))
							unutrasnji_omotac+=m.at(r).at(s);
							
						podmatrica.at(red).at(kolona)=m.at(r).at(s);     // Podmatrica sacinjena od elementa
						kolona++;
					}
					red++;      // povecava se red podmatrice u sljedecoj iretaciji
					kolona=0;     // resetiranje kolona na nulu
				}
				
				if (vanjski_omotac<unutrasnji_omotac) { // Ukoliko je zadovoljen uslov smjestam podmatricu u vektor matrica tj. 3D vektor
				brojac++;
					VektorPlanina.push_back(podmatrica);
					Zadovoljava.at(0).push_back(i);  // koordinate vrha planine ako je zadovoljila uslove, da bi se u slucaju da je veca moglo testirati da li
					Zadovoljava.at(1).push_back(j);   // je prije toga bila planina
				}
				// Ovo ubaci sve elemente matricu u podmatricu formata 1x1
				if (k==0)
					VektorPlanina.push_back(podmatrica);
			}
		}
		if (brojac==0 && k!=0) break;
	}
	return (NajvisaPlanina(VektorPlanina));
}

int main ()
{
	try {
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		if (m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 1;
		}
		Matrica mat(NapraviMatricu(m,n));
		std::cout<<"Unesite elemente matrice: ";
		//Unos matrice:
		for (int i = 0; i < BrojRedova(mat); i++)
			for (int j = 0; j < BrojKolona(mat); j++)
				std::cin>>mat.at(i).at(j);

		Matrica rezulat(NajvecaPlaninaMatrice(mat));
		std::cout<<"\nNajveca planina unesene matrice je: "<<std::endl;
		for (int i = 0; i < BrojRedova(rezulat); i++) {
			for (int j = 0; j < BrojKolona(rezulat); j++) 
				std::cout<<std::right<<std::setw(6)<<rezulat.at(i).at(j);
			std::cout<<std::endl;
		}
	}
	catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}