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

std::vector<std::vector<double>> NajvecaPlaninaMatrice (std::vector<std::vector<double>> m) {
	std::vector<std::vector<double>> najveca(0);
	if(m.size()==0 || m.at(0).size()==0) return najveca;
	for(int i=0; i<m.size()-1;i++)
		if(m.at(i).size()!=m.at(i+1).size()) throw std::domain_error("Matrica nije korektna");
	
	double sum(0),sum2(0);
	int n(3),max(3),mi(0),mj(0);
	for(int i=0;i<m.size(); i++) {
		for(int j=0; j<m.at(0).size();j++) {
		//	if(i!=0 && i!=m.size()-1 && j!=0 && j!=m.at(0).size()-1) {		
				if(n%2!=0 && i-n/2>=0 && i+n/2<m.size()) {
					for(int k=i-n/2; k<=i+n/2; k+=n/2) {
						for(int s=i-n/2; s<=i+n/2; s+=n/2) {
								sum+=m.at(k).at(s);
								sum-=m.at(i).at(j);
							if(n==3 && m.at(i).at(j)>sum) n+=2;
							sum2+=m.at(k).at(s);
							sum2-=sum-m.at(i).at(j);
							if(n>3 && n%2!=0 && sum2<sum) n+=2;
						}	
					}	
				}
				if (n>max) {
					max=n;
					mi=i;
					mj=j;
				}
				else if (n==max) {
					if(m.at(i).at(j)>m.at(mi).at(mj)) {
						mi=i;
						mj=j;
					}
					else if (m.at(i).at(j)==m.at(mi).at(mj)){
						if(i<mi) {
							mi=i;
							mj=j;
						}
						else if(i==mi) {
							if(j<mi) {
								mi=i;
								mj=j;
							}
						}
					}
			//	}
				
			}
			
		}
	}
	for(int i=0; i<max;i++,mi+=max/2) {
		for(int j=0;j<max;j++,mj+=max/2) {
			najveca.at(i).at(j)==m.at(mi-max/2).at(mj-max/2);
		}
	}
	return najveca;
}


int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m(0),n(0);
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> mat(0);
	std::cout<<"Unesite elemente matrice:";
	for(int i=0; i<m;i++)
		for(int j=0;j<n;j++)
			std::cin>>mat.at(i).at(j);
	try {
		std::vector<std::vector<double>> nova(NajvecaPlaninaMatrice(mat));
		std::cout<<"Najveca planina unesene matrice je:";
		for(int i=0; i<nova.size();i++) {
			for(int j=0; j<nova.at(i).at(j);j++) {
				std::cout<<std::setw(6)<<nova.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	catch(...) {
		std::cout<<"Matrica nije korektna";
	}
	
	return 0;
}