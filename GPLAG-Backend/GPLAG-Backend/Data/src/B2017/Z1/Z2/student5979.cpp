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
typedef std::vector<std::vector<double>> Matrica ;

Matrica NajvecaPlaninaMatrice(Matrica m){
		bool neispravna (true);
		for (int j = 0; j < m.size(); j++) {
			if(m.at(j).size()>0)
				neispravna=false;
		}
		Matrica praznaaaa;
		if(neispravna){
			return praznaaaa;
		}
		for (int i = 0; i < m.size(); i++) {
			if(m.at(i).size()!=m.at(0).size())
			throw  std::domain_error("Matrica nije korektna");
		}
		int max_pl_red=0,max_pl_kol=0,max_pl_form=0;
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m.at(0).size(); j++) {
					
					int pl_form (0);
				    long double suma1(m.at(i).at(j)),suma2(0);
					int	kolona1 (j-1),kolona2 (j+1),red1 (i-1),red2 (i+1);
					while (1) {
						if(red1<0 || red2>=m.size() || kolona1<0 || kolona2>=m.at(0).size())
							break;
						for (int k = red1; k <= red2; k++) {
							suma2+=m.at(k).at(kolona1) +m.at(k).at(kolona2);
						}
						for (int k = kolona1+1; k < kolona2; k++) {
							suma2+=m.at(red1).at(k)+m.at(red2).at(k);
						}
						if(suma2<suma1){
							pl_form++;
							red1--;
							red2++;
							kolona1--;
							kolona2++;
							suma1=suma2;
							suma2=0;
						}else 
						break;
					}
					if(pl_form>max_pl_form){
						max_pl_form=pl_form;
						max_pl_kol=j;
						max_pl_red=i;
					}else if(pl_form==max_pl_form){
						if(m.at(max_pl_red).at(max_pl_kol)<m.at(i).at(j))
							{
							max_pl_kol=j;
							max_pl_red=i;
						}
				}
			}
		}
		Matrica b;
		for (int i = max_pl_red-max_pl_form; i <= max_pl_red+max_pl_form; i++) {
			std::vector<double> v ;
			for (int j = max_pl_kol-max_pl_form; j <= max_pl_kol+max_pl_form; j++) {
				v.push_back(m.at(i).at(j));
			}
			b.push_back(v);
		}
		return b;	
	}
	
	

int main ()
{
	std::cout << "Unesite dimenzije matrice (m i n): " ;
	int a,b,d;
	std::cin >> a>>b;
	if(a<0 || b<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 0;
	}
	Matrica c;
	std::cout << "Unesite elemente matrice: " << std::endl;
	for (int i = 0; i < a; i++) {
		std::vector<double> v ;
		for (int j = 0; j < b; j++) {
			std::cin >> d;
			v.push_back(d);
		}
		c.push_back(v);
	}
	Matrica m(NajvecaPlaninaMatrice(c));
	std::cout << "Najveca planina unesene matrice je: " << std::endl;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.at(0).size(); j++) {
			std::cout << std::setw(6) << m.at(i).at(j);
		}
		std::cout << std::endl;
	}
	
	
	
	
	
	return 0;
}