/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>

typedef std::vector<double> DoubleVektor;
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu (int broj_redova, int broj_kolona) {
	return Matrica(broj_redova, DoubleVektor(broj_kolona));
}
	
Matrica UnesiMatricu(int broj_redova, int broj_kolona){
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	auto m(KreirajMatricu(broj_redova, broj_kolona));
		for(int i=0;i<broj_redova;i++){
			for(int j=0;j<broj_kolona;j++){
				std::cin>>m[i][j];
			}
		}
	return m;
}

void IspisiMatricu (Matrica m) {
	for(int i=0; i<m.size(); i++){
		for(int j=0;j<m[0].size();j++){
			std::cout<<std::setw(4)<<m[i][j];
		}
		std::cout<<std::endl;
	}
}

DoubleVektor ObrniRed( DoubleVektor a){
	
	DoubleVektor novi;
	for(int i=a.size()-1;i>=0;i--){
		novi.push_back(a[i]);
	}
	return novi;
}

Matrica HMatrica (Matrica a){
	
	for(int i=0;i<a.size();i++){
		a[i]=ObrniRed(a[i]);
	}
	return a;
}

Matrica VMatrica (Matrica a){
	
	Matrica VMat;
	
	for(int i=a.size()-1;i>=0;i--){
		VMat.push_back(a[i]);
	}
	return VMat;
}

Matrica OgledaloMatrica (Matrica a){
	
	if(a.size()==0)
		return a;
		
	int sirina=a[0].size();
	for(int i=1;i<a.size();i++){
		if(a[i].size()!=sirina){
			throw std::domain_error("Matrica nije korektna");
		}
	}
	
	Matrica h=HMatrica(a), v=VMatrica(a), hv=HMatrica(VMatrica(a)); 
	
	DoubleVektor prazan;
	Matrica ogledalo;
	
	for(int i=0;i<a.size();i++){
		ogledalo.push_back(prazan);
		for(double x : hv[i]) ogledalo[i].push_back(x);
		for(double x : v[i]) ogledalo[i].push_back(x);
		for(double x : hv[i]) ogledalo[i].push_back(x);
	}
	
		for(int i=0;i<a.size();i++){
		ogledalo.push_back(prazan);
		for(double x : h[i]) ogledalo[i+a.size()].push_back(x);
		for(double x : a[i]) ogledalo[i+a.size()].push_back(x);
		for(double x : h[i]) ogledalo[i+a.size()].push_back(x);
	}
	
		for(int i=0;i<a.size();i++){
		ogledalo.push_back(prazan);
		for(double x : hv[i]) ogledalo[i+2*a.size()].push_back(x);
		for(double x : v[i]) ogledalo[i+2*a.size()].push_back(x);
		for(double x : hv[i]) ogledalo[i+2*a.size()].push_back(x);
	}
	
	return ogledalo;
	
}

int main (){

	int a,b;

	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>a>>b;
	
	if(a<0||b<0) 
		{std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}

	try {

	
 	auto Mat(UnesiMatricu(a,b));
	
		std::cout<<"Rezultantna matrica: "<<std::endl;
	IspisiMatricu(OgledaloMatrica(Mat));
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	
	return 0;
}