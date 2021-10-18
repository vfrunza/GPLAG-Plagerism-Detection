#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<std::vector<int>> drugamatrica;

Matrica UnesiMatricu(int m,int n){
	Matrica M(m,std::vector<double>(n));
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			std::cin>>M.at(i).at(j);
		}
	}
	return M;
}
int DaLiJeVrh(Matrica M,int a,int b){
	int suma(0),Suma(M.at(a).at(b)),clan(M.at(a).at(b));
	int broj,brojac(0);
	do{
	for(int i(a-brojac-1);i<=a+brojac+1;i++){
		for(int j(b-brojac-1);j<=b+brojac+1;j++){
			broj=M.at(i).at(j);
			suma+=broj;
		}
	}
	if(brojac==0)
		suma=suma-Suma;
	else 
		suma=suma-Suma-clan;
	if((suma-Suma)>=0&&brojac>0)
		return brojac;
	else if((suma-Suma)>=0)
		return 0;
	
	else{
		brojac++;
		Suma=suma;
		suma=0;
	}
	if(a-brojac-1<0||b-brojac-1<0||a+brojac+1>=M.size()||b+brojac+1>=M.at(0).size())
		return brojac;
	}while(1);
	return brojac;
}


Matrica KreirajMatricu(Matrica M,int a,int b,int c){
	Matrica N;
	N.resize(2*c+1);
	int brojac(0);
	for(int i(a-c);i<=a+c;i++){
		for(int j(b-c);j<=b+c;j++){
			N.at(brojac).push_back(M.at(i).at(j));
		}
		brojac++;
	}

return N;	
}

int NajvecaMatrica(drugamatrica M){
	int brojac(-1),maxformat(M.at(0).at(0)),indeks(0);
	for(int i(0);i<M.size();i++){
		if(maxformat<M.at(i).at(0)){
			maxformat=M.at(i).at(0);
			indeks=i;
		}
	}
	for(int i(0);i<M.size();i++)
		if(maxformat==M.at(i).at(0))
			brojac++;
	if(brojac==0)
		return indeks;
	brojac=-1;
	int maxvrh(M.at(indeks).at(1));
	for(int i(0);i<M.size();i++){
		if(M.at(i).at(0)==maxformat&&M.at(i).at(1)>maxvrh){
			maxvrh=M.at(i).at(1);
			indeks=i;
		}
	}
	for(int i(0);i<M.size();i++)
		if(maxvrh==M.at(i).at(1))
			brojac++;
	if(brojac==0)
		return indeks;
	brojac=-1;
	int minI(M.at(indeks).at(2));
	for(int i(0);i<M.size();i++){
		if(M.at(i).at(1)==maxvrh && M.at(i).at(2)<minI){
			minI=M.at(i).at(2);
			indeks=i;
		}
	}
	for(int i(0);i<M.size();i++)
		if(minI==M.at(i).at(2))
			brojac++;
	if(brojac==0)
		return indeks;
	brojac=-1;
	int minY(M.at(indeks).at(3));
	for(int i(0);i<M.size();i++){
		if(M.at(i).at(2)==minI&&M.at(i).at(3)<minY){
			minY=M.at(i).at(3);
			indeks=i;
		}
	}
	return indeks;
}
	
Matrica NajvecaPlaninaMatrice(Matrica M){
Matrica N;
	drugamatrica Zapisnik;
	std::vector<int> v;
	for(int i(0);i<M.size();i++)
		if(M.at(0).size()!=M.at(i).size())
			throw std::domain_error("Matrica nije korektna");
	int x;
	if(M.size()==0||(M.size()==1&&M.at(0).size()==1))
		return M;
	if(M.size()<3||M.at(0).size()<3){
		double max(M.at(0).at(0));
		for(int i(0);i<M.size();i++)
			for(int j(0);j<M.at(0).size();j++)
				if(M.at(i).at(j)>max)
					max=M.at(i).at(j);
			N.resize(1);
			N.at(0).push_back(max);
		return N;
	}
	for(int i(1);i<M.size()-1;i++){
		for(int j(1);j<M.at(1).size()-1;j++){
			x=DaLiJeVrh(M,i,j);
			if(x){
				v.push_back(x);
				v.push_back(M.at(i).at(j));
				v.push_back(i);
				v.push_back(j);
				Zapisnik.push_back(v);
				v.resize(0);
			}
		}
	}
	if(Zapisnik.size()==0){
		double max(M.at(0).at(0));
		for(int i(0);i<M.size();i++)
			for(int j(0);j<M.at(0).size();j++)
				if(M.at(i).at(j)>max)
					max=M.at(i).at(j);
			N.resize(1);
			N.at(0).push_back(max);
		return N;
	}
	int c,a,b,d;
	d=NajvecaMatrica(Zapisnik);
	a=Zapisnik.at(d).at(2);
	c=Zapisnik.at(d).at(0);
	b=Zapisnik.at(d).at(3);
	N=KreirajMatricu(M,a,b,c);
	return N;
}


int main ()
{
	int m,n;
	try{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0||n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double>> M,M1;
 	std::cout<<"Unesite elemente matrice:"<<std::endl;
	M=UnesiMatricu(m,n);
	M1=NajvecaPlaninaMatrice(M);
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i(0);i<M1.size();i++){
		for(int j(0);j<M1.size();j++){
			std::cout<<" "<<std::setw(5)<<std::right<<M1.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error e){
		std::cout << "Izuzetak: " << e.what() << std::endl;
	}
	return 0;
}