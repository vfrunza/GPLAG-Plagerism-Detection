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
int Vrh(std::vector<int> v, std::vector<std::vector<double>> M){
	int mod1,mod2,x(0),po_x,po_y,po_x2,po_y2;
	for(int i=0;i<v.size();i++){
		mod1=v.at(i)%10;
		for(int j=0;j<v.size();j++){
			mod2=v.at(j)%10;
			if(mod2>mod1) x=1;
		}
		if(x==1){ v.erase(v.begin()+i); i--; x=0;}
	}x=0;
	for(int i=0;i<v.size();i++){
		po_x=v.at(i)/100;
		po_y=(v.at(i)-po_x*100)/10;
		for(int j=0;j<v.size();j++){
			po_x2=v.at(j)/100;
			po_y2=(v.at(j)-po_x2*100)/10;
			if(M.at(po_x2).at(po_y2)>M.at(po_x).at(po_y)) x=1;
		}
		if(x==1){ v.erase(v.begin()+i); i--; x=0; }
	}x=0;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v.at(i)>v.at(j)) x=1;
		}
		if(x==1){ v.erase(v.begin()+i); i--; x=0;}
	}
	x=v.at(0);
	return x;
}
std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> M){
	std::vector<std::vector<double>> P;
	std::vector<double> m;
	std::vector<int> R;
	int a,stepen,t,k,suma,stara_suma,x,y,po_x,po_y;
	if(M.size()==0) return P;
	else if(M.at(0).size()==0) return P;
	a=M.at(0).size();
	for(int i=0;i<M.size();i++){
		if(a!=M.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}
	if(M.size()<=2 || M.at(0).size()<=2) {
		int najveci;
		najveci=M.at(0).at(0);
		for(int i=0;i<M.size();i++){
			for(int j=0;j<M.at(0).size();j++){
				if(M.at(i).at(j)>najveci) najveci=M.at(i).at(j);
			}
		}
		m.push_back(najveci);
		P.push_back(m);
		return P;
	}
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M.at(0).size();j++){
			x=M.at(i).at(j);
			stara_suma=x;
			stepen=1;
			xxx:
			suma=0;
			if(i-stepen>=0 && i+stepen<M.size() && j-stepen>=0 && j+stepen<M.at(0).size()){
				for(int t=i-stepen;t<=i+stepen;t++){
					for(int k=j-stepen;k<=j+stepen;k++){
						suma+=M.at(t).at(k);
					}
				} suma-=stara_suma;
			if(suma<stara_suma){ y=i*100+j*10+stepen; stepen++; stara_suma+=suma; R.push_back(y); goto xxx;}
			}
		}
	}
	y=Vrh(R,M);
	po_x=y/100;
	po_y=(y-po_x*100)/10;
	stepen=y%10;
	for(int i=po_x-stepen;i<=po_x+stepen;i++){
		for(int j=po_y-stepen;j<=po_y+stepen;j++){
			m.push_back(M.at(i).at(j));
		}
		P.push_back(m); m.resize(0);
	}
	return P;
}
int main ()
{
	try{
		std::vector<std::vector<double>> M,P;
		std::vector<double> v;
		int m,n;
		double x;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m;
		std::cin>>n;
		if(m<0 || n<0){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
		std::cout<<"Unesite elemente matrice:";
		for(int i=0;i<m;i++){
					for(int j=0;j<n;j++){
						std::cin>>x;
						v.push_back(x);
					}
					M.push_back(v); v.resize(0);
		}
		P=NajvecaPlaninaMatrice(M);
		std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
		for(int i=0;i<P.size();i++){
			for(int j=0;j<P.size();j++){
				if(j!=(P.size()-1)) std::cout<<std::setw(6)<<P.at(i).at(j);
				else std::cout<<std::setw(6)<<P.at(i).at(j)<<std::endl;
			}
		}
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}