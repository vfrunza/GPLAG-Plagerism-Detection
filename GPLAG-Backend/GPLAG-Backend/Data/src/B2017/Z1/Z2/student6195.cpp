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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona) {
	return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

Matrica UnesiMatricu (int broj_redova, int broj_kolona) {
	auto a(KreirajMatricu(broj_redova, broj_kolona));
	for(int i(0); i < broj_redova; i++) {
		for(int j(0); j < broj_kolona; j++)
		std::cin>>a.at(i).at(j);
	}
	return a;
}
std::vector<int> dajPlaninu(Matrica m,int r,int k){
	double suma=0,sumalast=0; int sirina=1;
	bool planina=false;bool prva=false;
	int brojac=0;
	while(1){
		if(r-sirina>=0&&r+sirina<m.size()&&k-sirina>=0&&k+sirina<m.at(0).size()){
		for(int i=k-sirina;i<=k+sirina;i++){
			suma+=m.at(r-sirina).at(i);
		}
		for(int i=k-sirina;i<=k+sirina;i++){
			suma+=m.at(r+sirina).at(i);
		}
		for(int i=r-sirina+1;i<r+sirina;i++) suma+=m.at(i).at(k-sirina);
		for(int i=r-sirina+1;i<r+sirina;i++) suma+=m.at(i).at(k+sirina);
		}
		else{
			planina=false;
			prva=true;

		}
		if(m.at(r).at(k)>suma&&!prva){
			planina=true;
			sumalast=suma;
			prva=true;
			sirina++;
		}
		else if(suma>sumalast){
			sirina++;
			sumalast=suma;
			suma=0;
		}
		else{
			sirina--;
			planina=false;
		}
		if(!planina){
            if(sirina<0) sirina=0;
            if(r-sirina<0||k-sirina<0||r+sirina>=m.size()|| k+sirina>m.at(0).size()) sirina--;
            if(sirina<0) sirina=0;
			std::vector<int> v{r,k,sirina,0};
			if(brojac==0) v.at(3)=-1;
		
			return v;
		}
		brojac++;
	}
}
Matrica NajvecaPlaninaMatrice (Matrica m) {
	// provjera
	for(int i=0;i<m.size();i++) for(int j=0;j<m.at(i).size();j++) if(m.at(i).size()!=m.at(0).size()) throw std::domain_error("Matrica nije korektna");
	if(m.size()==0||m.at(0).size()==0) return Matrica();
	if(m.at(0).size()==1||m.size()==1||m.size()==2&&m.at(0).size()==2){
		double max=m.at(0).at(0);
		for(int i=0;i<m.size();i++) for(int j=0;j<m.at(0).size();j++) if(m.at(i).at(j)>max) max=m.at(i).at(j);
		Matrica tmp(1);
		tmp.at(0).push_back(max);
		return tmp;
	}
	//
	std::vector<std::vector<int>> planine,planinet;
	for(int i=1;i<m.size()-1;i++){
		for(int j=1;j<m.at(i).size()-1;j++){
			planinet.push_back(dajPlaninu(m,i,j));
		}
	}
	for(int i=0;i<planinet.size();i++){
		if(planinet.at(i).at(3)!=-1) planine.push_back(planinet.at(i));
	}
	if(planine.size()==0) {
		double max=m.at(0).at(0);
		for(int i=0;i<m.size();i++) for(int j=0;j<m.at(0).size();j++) if(m.at(i).at(j)>max) max=m.at(i).at(j);
		Matrica tmp(1);
		tmp.at(0).push_back(max);
		return tmp;
	}
	std::vector<int> max(planine.at(0));

	for(int i=0;i<planine.size();i++){
 
		if(planine.at(i).at(2)>max.at(2)) max=planine.at(i);
		else if(max.at(2)==planine.at(i).at(2)&&m.at(planine.at(i).at(0)).at(planine.at(i).at(1))>m.at(max.at(0)).at(max.at(1))) max=planine.at(i);
		else if(max.at(2)==planine.at(i).at(2)&&m.at(planine.at(i).at(0)).at(planine.at(i).at(1))==m.at(max.at(0)).at(max.at(1))&&planine.at(i).at(0)>max.at(0)){
			max=planine.at(i);
		}
		else if(max.at(2)==planine.at(i).at(2)&&m.at(planine.at(i).at(0)).at(planine.at(i).at(1))==m.at(max.at(0)).at(max.at(1))&&planine.at(i).at(0)==max.at(0)&&planine.at(i).at(1)>max.at(1)){
			max=planine.at(i);
		}
	}
	if(max.at(2)<1) return Matrica();
	Matrica tmpmat(2*max.at(2)+1);

	int brojac=0;
	for(int i=max.at(0)-max.at(2);i<=max.at(0)+max.at(2);i++){
		for(int j=max.at(1)-max.at(2);j<=max.at(1)+max.at(2);j++ ) tmpmat.at(brojac).push_back(m.at(i).at(j));
		brojac++;
	}
	return tmpmat;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0||n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	std::cout<<"Unesite elemente matrice:\n";
	auto a=UnesiMatricu(m,n);
	try{
	Matrica mat=NajvecaPlaninaMatrice(a);
	std::cout<<"Najveca planina unesene matrice je:\n";
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.at(i).size();j++) std::cout<<std::setw(6)<<mat.at(i).at(j);
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	}

	return 0;
}
