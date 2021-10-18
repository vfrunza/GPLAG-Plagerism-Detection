#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica NajvecaPlaninaMatrice(Matrica mat) {
	for(int i(0); i<mat.size(); i++) {
		if(mat.at(0).size()!=mat.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}
	Matrica maxplanina;
	bool vecaod3(true);
	if(mat.size()<3) vecaod3=false;
	for(int i(0); i<mat.size(); i++) {
		if(mat.at(i).size()<3) {
			vecaod3=false;
			break;
		}
	}
	if(vecaod3) {
		int n(3);
		double vrh(mat.at(1).at(1));
		int vrhi(1), vrhj(1);
		int redovi(mat.size());
		double prethodniprsten(0);
		for(int i(1); i<redovi-1; i++) {
			int kolone(mat.at(i).size());
			for(int j(1); j<kolone-1; j++) {
				double suma(mat.at(i-1).at(j-1)+mat.at(i-1).at(j)+mat.at(i-1).at(j+1)+mat.at(i).at(j-1)+mat.at(i).at(j+1)+mat.at(i+1).at(j-1)+mat.at(i+1).at(j)+mat.at(i+1).at(j+1));
				if(suma<mat.at(i).at(j) && mat.at(i).at(j)>=vrh) {
					prethodniprsten=suma;
					vrh=mat.at(i).at(j);
					vrhi=i;
					vrhj=j;
				}
			}
		}
		int pomjeri(1);
		for(;;) {
			if((vrhi-(n/2)-pomjeri)<0 || (vrhi+(n/2)+pomjeri)>=mat.size() || (vrhj-(n/2)-pomjeri)<0 || (vrhj+(n/2)+pomjeri)>=mat.at(0).size()) break;
			double s(0);
			for(int i(vrhi-(n/2)-pomjeri); i<=(vrhi+(n/2)+pomjeri); i++) {
				for(int j(vrhj-(n/2)-pomjeri); j<=(vrhj+(n/2)+pomjeri); j++) {
					if(i==(vrhi-(n/2)-pomjeri) || i==(vrhi+(n/2)+pomjeri) || j==(vrhj-(n/2)-pomjeri) || j==(vrhj+(n/2)+pomjeri)) s+=mat.at(i).at(j);
					if(j==(vrhj+(n/2)+pomjeri)) break;
				}
				if(i==(vrhi+(n/2)+pomjeri)) break;
			}
			if(s>prethodniprsten) break;
			else if(s<prethodniprsten) {
				prethodniprsten=s;
				n+=2;
				pomjeri++;
			}
		}
		maxplanina.resize(n);
		for(int i(0); i<maxplanina.size(); i++) maxplanina.at(i).resize(n);
		int i(0);
		for(int k(vrhi-(n/2)); k<=(vrhi+(n/2)); k++) {
			int j(0);
			for(int h(vrhj-(n/2)); h<=(vrhj+(n/2)); h++) {
				maxplanina.at(i).at(j)=mat.at(k).at(h);
				j++;
			
			}
	
			i++;
		}
	}
	else {
		double maxi(mat.at(0).at(0));
		for(int i(0); i<mat.size(); i++) {
			for(int j(0); j<mat.at(i).size(); j++) {
				if(mat.at(i).at(j)>maxi) maxi=mat.at(i).at(j);
			}
		}
		maxplanina.resize(1);
		for(int i(0); i<1; i++) maxplanina.at(i).resize(1);
		maxplanina.at(0).at(0)=maxi;
	}
	return maxplanina;
}
int main () {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat;
	mat.resize(m);
	for(int i(0); i<mat.size(); i++) mat.at(i).resize(n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0); i<mat.size(); i++) {
		for(int j(0); j<mat.at(i).size(); j++) std::cin>>mat.at(i).at(j);
	}
	Matrica najvecapl(NajvecaPlaninaMatrice(mat));
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i(0); i<najvecapl.size(); i++) {
		for(int j(0); j<najvecapl.at(i).size(); j++) std::cout<<std::setw(6)<<najvecapl.at(i).at(j);
		std::cout<<std::endl;
	}
	return 0;
}