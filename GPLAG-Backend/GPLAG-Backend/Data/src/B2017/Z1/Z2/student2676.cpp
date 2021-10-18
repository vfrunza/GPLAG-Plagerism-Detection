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

using namespace std;

vector<vector<double>>NajvecaPlaninaMatrice(vector<vector<double>>mat){
	vector<vector<double>> rezultat;
	if(mat.size()==0){
		return rezultat;
	}
	for(int i(1);i<(int)mat.size();i++){
		if(mat.at(i).size()!=mat.at(0).size()){
			throw std::domain_error("Matrica nije korektna");
		
			
		}	
		}
		int redIndeks(0),kolonaIndeks(0),radijusKoncKvadrata(0);
		bool postojiPlanina=false;
		double vrh(0);
		for(int i(1);i<(int)mat.size()-1;i++){
			for(int j(1);j<(int)mat.at(0).size()-1;j++){
				double sumaKoncKvadrata(0);
				//ova petlja racuna sumu prvog konc kvadrata
				for(int k(i-1);k<=i+1;k++){
					for(int m(j-1);m<=j+1;m++){
						if(k==i && m==j){
							continue;
						}
						sumaKoncKvadrata += mat.at(k).at(m);
					}
				}
				if(mat.at(i).at(j)>sumaKoncKvadrata){
					//madjena je planina
					//brojac broji koliko koncentricnih krugova ukupno postoji
					//trenutno postoji samo jedan koncentricni krug oko vrha
					int brojac(1);
					while(true){
						double sumaOkolnogKoncKvadrata(0);
						for(int k(i-1-brojac);k<=i+1+brojac&& i-1-brojac>=0 && i+1+brojac<(int)mat.size();k++){
							for(int m(j-1-brojac);m<=j+1+brojac && j-1-brojac>=0 && j+1+brojac<(int)mat.at(j).size();m++){
							//svi brojevi koji su u unutrasnjosti okolnog  koncentricnog kvadrata se ne smiju racunati u sumu okolonog konc.kvadrata
							if(k>i-1-brojac && k<i+1+brojac && m>j-1-brojac && m<j+1+brojac){
								continue;
								
							}
							sumaOkolnogKoncKvadrata +=mat.at(k).at(m);
							
						}
					}
					if(sumaOkolnogKoncKvadrata>=sumaKoncKvadrata || i-1-brojac<0 || i+1+brojac>=(int)mat.size() || j-1-brojac<0 || j+1+brojac>=(int)mat.at(j).size()){
						break;
					}
					// ako se utvrdi da je ovo zaista pravi koncentricni kvadrat vrha onda se on uracuna u ukupan broj koncentricnih kvadrata
					brojac++;
					sumaKoncKvadrata=sumaOkolnogKoncKvadrata;
				}
				if(!postojiPlanina){
					redIndeks=i;
					kolonaIndeks=j;
					radijusKoncKvadrata=brojac;
					postojiPlanina=true;
					vrh=mat.at(i).at(j);
					
				}
				else if(postojiPlanina && brojac>radijusKoncKvadrata){
					redIndeks=i;
					kolonaIndeks=j;
					radijusKoncKvadrata=brojac;
					vrh=mat.at(i).at(j);
					
				}
				else if(postojiPlanina && brojac==radijusKoncKvadrata&&mat.at(i).at(j)>vrh){
					redIndeks=i;
					kolonaIndeks=j;
					vrh=mat.at(i).at(j);
				}
				else if(postojiPlanina && brojac==radijusKoncKvadrata && mat.at(i).at(j)==vrh){
					if(i<redIndeks){
						redIndeks=i;
						kolonaIndeks=j;
						
					}
					else if(i==redIndeks && j<=kolonaIndeks){
						redIndeks=i;
						kolonaIndeks=j;
					}
				}
			}
		}
	}
	rezultat.resize(radijusKoncKvadrata * 2 +1);
	for(int i(0);i<radijusKoncKvadrata * 2 + 1;i++){
		rezultat.at(i).resize(radijusKoncKvadrata * 2 + 1);
	}
	for(int i(redIndeks-radijusKoncKvadrata);i<=radijusKoncKvadrata+redIndeks;i++){
		for(int j(kolonaIndeks-radijusKoncKvadrata);j<=kolonaIndeks+radijusKoncKvadrata;j++){
			rezultat.at(i-redIndeks+radijusKoncKvadrata).at(j-kolonaIndeks+radijusKoncKvadrata)=mat.at(i).at(j);
		}
	}
	return rezultat;
}


int main ()
{
	vector<vector<double>>rez;
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	
if(m>0 && n>0){	std::cout<<"Unesite elemente matrice: "<<std::endl;
rez.resize(m);
	for(int i=0;i<m;i++){
		rez.at(i).resize(n);
		for(int j=0;j<n;j++){
			std::cin>>rez.at(i).at(j);
		}
	}
	
	rez=NajvecaPlaninaMatrice(rez);
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i(0);i<rez.size();i++){
		for(int j(0);j<rez[i].size();j++)
		cout<<setw(6)<<rez[i][j];
	cout<<endl;
	}}
	else std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
}