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

int BliziKraj (int a, int b)
{
	if(a>=b) return b;
	else return a;
}
int Suma_Okolnih (std::vector<std::vector<double>> matrica, int i, int j, int k)
{
	double PocetnaSuma(0);
	for(int a(i-k); a<=i+k; a++) {
		for(int b(j-k); b<=j+k; b++) {
			if((a==i-k || a==i+k) || (b==j-k || b==i+k)) PocetnaSuma+=matrica.at(a).at(b);
		}
	}
	return PocetnaSuma;
}
std::vector<std::vector<double>> NovaMatrica(std::vector<std::vector<double>> matrica, int i, int j, int k, int pomak)
{
	std::vector<std::vector<double>> finalna_matrica(pomak);
	int t(0);
	for(int a(i-k); a<=i+k; a++) {
		for(int b(j-k); b<=j+k; b++) {
			finalna_matrica.at(t).push_back(matrica.at(a).at(b));
		}
		t++;
	}
	return finalna_matrica;
}
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica)
{
	std::vector<std::vector<double>> finalna_matrica;
	std::vector<std::vector<double>> najveca_planina;
	int vrh_najvece_planine(0);
	if(matrica.size()==0 || matrica[0].size()==0) return finalna_matrica;
	int poklapanje(0);
	for(int j(0); j<matrica.size(); j++)
		if(matrica.at(j).size()!=matrica.at(0).size()) poklapanje++;
	if(poklapanje>=1) throw std::domain_error("Matrica nije korektna");

	for(int i(0); i<matrica.size(); i++) {
		for(int j(0); j<matrica.at(0).size(); j++) {
			double Suma(0), PomocnaSuma, vrh;
			int k(0);
			std::vector<std::vector<double>> PomocnaMatrica=matrica;
			std::vector<std::vector<double>> finalna_matrica2;
			int max1(BliziKraj(matrica.size()-i-1,i)), max2(BliziKraj(matrica.at(0).size()-j-1,j)), MAX(BliziKraj(max1,max2)), pomak(1);
			while(k<=MAX) {
				if(k==0 && matrica.at(i).at(j)>=Suma) {
					finalna_matrica2.resize(1);
					finalna_matrica2.at(0).push_back(matrica.at(i).at(j));
					vrh=matrica.at(i).at(j);
					k++;
					PomocnaSuma=matrica.at(i).at(j);
				} else {
					Suma=Suma_Okolnih(PomocnaMatrica,i,j,k);
					if(Suma<PomocnaSuma) {
						PomocnaSuma=Suma;
						pomak=pomak+2;
						finalna_matrica2.resize(0);
						finalna_matrica2=NovaMatrica(PomocnaMatrica,i,j,k,pomak);
						k++;
					} else break;
				}
			}
			if((finalna_matrica2.size()>najveca_planina.size()) || (vrh>vrh_najvece_planine)) {
				najveca_planina=finalna_matrica2;
				vrh_najvece_planine=vrh;
			}
		}
	}
	return najveca_planina;
}
int main ()
{
	try {
		int m,n;
		std::vector<std::vector<double>> Matrica;
		std::vector<std::vector<double>> FinalnaMatrica;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne! ";
		else {
			Matrica.resize(m);
			std::cout<<"Unesite elemente matrice:";
			for(int i(0); i<Matrica.size(); i++) Matrica.at(i).resize(n);
			for(int i(0); i<m; i++) {
				for(int j(0); j<n; j++) {
					double k;
					std::cin>>k;
					Matrica.at(i).at(j)=k;
				}
			}
			std::cout<<"\nNajveca planina unesene matrice je:\n";
			FinalnaMatrica=NajvecaPlaninaMatrice(Matrica);
			for(int i(0); i<FinalnaMatrica.size(); i++) {
				for(int j(0); j<FinalnaMatrica.at(0).size(); j++) {
					std::cout<<std::setw(6)<<FinalnaMatrica.at(i).at(j);
				}
				std::cout<<"\n";
			}
		}
	} catch(const std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}