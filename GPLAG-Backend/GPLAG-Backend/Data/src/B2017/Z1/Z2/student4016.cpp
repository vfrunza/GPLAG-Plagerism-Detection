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

double suma(int a, int b, int br_puta, std::vector<std::vector<double>> & mat){
	double s(0);
	for(int i=a-br_puta; i<=a+br_puta; i++){
		for(int j=b-br_puta; j<=b+br_puta; j++){
			if((i==a || i==a+br_puta-1 || i==a-br_puta-1) && (j==b || j==b+br_puta-1 || j==b-br_puta-1)) continue;
			s+=mat.at(i).at(j);
		}
	}
	return s;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice( std::vector<std::vector<double>> m ){

/*	for(auto a:m){
		if(a.size()!=m.at(0).size) throw std::domain_error("Matrica nije korektna");
	}
	*/
	
	int vbroj = m.at(0).size();
	int mbroj=m.size();
	int max(0), a(0), b(0);
	for(int i=0; i<mbroj; i++){
		for(int j=0; j<vbroj; j++){
			int puta(1);
			double s=m.at(i).at(j);
			
			while(suma(i,j,puta,m)<s && puta<=i && puta<=j){
				s=suma(i,j,puta,m);
				puta++;
			}
			puta--;
			
			if(puta>max) {
				max=puta;
				a=i;
				b=j;
			}
		}
	}
	
	std::vector<std::vector<double>> planina(max*2 + 1, std::vector<double>(max*2 + 1));
	int i1=0;
	for(int i=a-max; i<=a+max; i++){
		int j1=0;
		for(int j=b-max; j<=b+max; j++){
			planina.at(i1).at(j1)=m.at(i).at(j);
			i1++;
			j1++;
		}
	}
	
	return planina;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite m i n: ";
	std::cin>>m>>n;
	
	std::cout<<"Unesite elemente matrice: ";
	std::vector<std::vector<double>> matrica(m, std::vector<double>(n));
	
   for(int i = 0; i < m; i++){
   for(int j = 0; j < n; j++) {
       std::cin >> matrica.at(i).at(j);
   }
   }
 
    std::vector<std::vector<double>> plan(NajvecaPlaninaMatrice(matrica));
    int red(plan.size());
    int kol(plan.at(0).size());
    
    for(int i=0; i<red; i++){
    	for(int j=0; j<kol; j++){
    		std::cout<<plan.at(i).at(j)<<" ";
    	}
    	std::cout<<std::endl;
    }
	return 0;
}