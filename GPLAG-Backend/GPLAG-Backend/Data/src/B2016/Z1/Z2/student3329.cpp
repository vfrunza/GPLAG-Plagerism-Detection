/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica Hvvhv(Matrica v, int rv, int kv){
	Matrica vrati(rv);
	
	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[rv-i-1][kv-j-1]);
	
	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[rv-i-1][j]);

	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[rv-i-1][kv-j-1]);
		
	return vrati;
}
Matrica Hmh(Matrica v, int rv, int kv){
	Matrica vrati(rv);
	
	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[i][kv-j-1]);
	
	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[i][j]);
	
	for(int i=0; i<rv; i++)
		for(int j=0; j<kv; j++)
			vrati[i].push_back(v[i][kv-j-1]);
		
	return vrati;
}

Matrica OgledaloMatrica(Matrica v){
	int red(v.size());
	int kolona;
		if(red!=0) kolona=v.at(0).size();
		else kolona=0;
	
	for(int i=0; i<red; i++)
		if(v.at(i).size()!=kolona)
			throw std::domain_error("Matrica nije korektna");
	
	Matrica o(3*red,std::vector<double>(3*kolona));
	Matrica prenosna(red, std::vector<double>(3*kolona));
	
	for(int i=0; i<3*red; i+=red){
		if(i==0*red || i==2*red){
			prenosna=Hvvhv(v, red, kolona);
		}else if(i==1*red){
			prenosna=Hmh(v, red, kolona);
		}
		for(int k=i; k<red+i; k++)
			o.at(k)=prenosna.at(k-i);
	}
	return o;
}

int main (){
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica a(m, std::vector<double>(n));
		std::cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				std::cin>>a.at(i).at(j);
		
		Matrica b=OgledaloMatrica(a);
		
		std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
		for(int i=0; i<3*m; i++){
			for(int j=0; j<3*n; j++)
				std::cout<<std::setw(4)<<b.at(i).at(j);
			std::cout<<std::endl;
		}
	}catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
		return 0;
}