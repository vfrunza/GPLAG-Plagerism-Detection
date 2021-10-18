#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <algorithm>

bool TestPerioda(std::vector<int>v, int p){
	if(p>=v.size() || p==0) return false;
	bool periodican(true);
	for(int i=0; i<v.size(); i++){
		if(i+p>=v.size()) break;
		if(v[i]!=v[i+p]){
			periodican=false;
			break;
		}
	}
	return periodican;
}

int OdrediOsnovniPeriod(std::vector<int>v){
	int p(1);
	while(p<v.size()){
		bool periodican=TestPerioda(v,p);
		if(periodican==true){
			return p;
			break;
		}
		p++;
	}
	return 0;
}

std::vector<int> Produzi(std::vector<int>v, int period){
	std::vector<int> vp;
	vp.resize(period);
	for(int i=0; i<vp.size(); i++) vp[i]=v[i];
	int i(1);
	while(v.size()%period!=0 && i<period){
		if(vp[i]!=v[v.size()-1]) v.push_back(vp[i]);
		i++;
	}
	return v;
}

int maks(const std::vector<int>&v2){
	int max(v2[0]);
	for(int i=1; i<v2.size(); i++){
		if(v2[i]>max) max=v2[i];
	}
	return max;
}

std::vector<int> SimetricnoProduzi(const std::vector<int>&v, int &koliko_puta){
	std::vector<int>v2=v,vp;
	int period(OdrediOsnovniPeriod(v2));
	vp=Produzi(v2,period);
	koliko_puta=vp.size()/period;
	return vp;
}

std::vector<int> NesimetricnoProduzi(const std::vector<int>&v, int &koliko_puta){
	koliko_puta=2;
	std::vector<int>vp(v);
	std::vector<int>vpom(vp);
	for(int i=0; i<vpom.size(); i++) vp.push_back(vpom[i]);
	return vp;
}

int BrojKolona1(const std::vector<int>&v, int i, int &koliko_puta){
	std::vector<int>v1(v);
	v1=SimetricnoProduzi(v,koliko_puta);
	return v1[i];
}

int BrojKolona2(const std::vector<int>&v, int i, int &koliko_puta){
	std::vector<int>v1(v);
	v1=NesimetricnoProduzi(v,koliko_puta);
	return v1[i];
}

int BrojRedova1(const std::vector<int>&v, int &koliko_puta){
	std::vector<int>v1(v);
	v1=SimetricnoProduzi(v,koliko_puta);
	return v1.size();
}

int BrojRedova2(const std::vector<int>&v, int &koliko_puta){
	std::vector<int>v1(v);
	v1=NesimetricnoProduzi(v,koliko_puta);
	return v1.size();
}

//template <typename tipint>
int **AlocirajFragmentirano(const std::vector<int>&v, int &koliko_puta){
	if(v.size()==0) throw "Izuzetak: Prazan vektor!";
	for(int i=0; i<v.size(); i++){
		if(v[i]<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
	}
	int period(OdrediOsnovniPeriod(v));
	int **a(nullptr);
	if(period){
		int n(BrojRedova1(v,koliko_puta));
		try{
				a=(new int*[n]);
				for(int i=0; i<n; i++) a[i]=nullptr;
				try{
					for(int i=0; i<n; i++) a[i]=new int[BrojKolona1(v,i,koliko_puta)];
					
					for(int i=0; i<n; i++){
						int max(maks(v));
						for(int j=BrojKolona1(v,i,koliko_puta)-1; j>=0; j--){
							a[i][j]=max;		
							max--;
						}
					}
					std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<BrojKolona1(v,i,koliko_puta); j++){
					 std::cout<<a[i][j]<<"  ";
				}
				if(i!=n-1) std::cout<<std::endl;
			}
			return a;
				}catch(...){
					for(int i = 0; i<n; i++) delete[] a[i];
					delete[] a;
					throw;
				}
			
			}catch(...){
				std::cout<<"Problemi sa memorijom!";
			}
	}else{
		int n(BrojRedova2(v,koliko_puta));
			try{
				a=(new int*[n]);
				for(int i=0; i<n; i++) a[i]=nullptr;
				try{
					for(int i=0; i<n; i++) a[i]=new int[BrojKolona2(v,i,koliko_puta)];
					
					for(int i=0; i<n; i++){
						int max(maks(v));
						for(int j=BrojKolona2(v,i,koliko_puta)-1; j>=0; j--){
							a[i][j]=max;
							max--;
						}
					}
					std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<BrojKolona2(v,i,koliko_puta); j++){
					std::cout<<a[i][j]<<"  ";
				}
				if(i!=n-1) std::cout<<std::endl;
			}
				}catch(...){
					for(int i = 0; i<n; i++) delete[] a[i];
					delete[] a;
					throw;
				}
			
			}catch(...){
				std::cout<<"Problemi sa memorijom!";
			}
	}
	return a;
}

int **AlocirajKontinualno(const std::vector<int>&v, int &koliko_puta){
	if(v.size()==0) throw "Izuzetak: Prazan vektor!";
	for(int i=0; i<v.size(); i++){
		if(v[i]<=0) throw std::domain_error("Izuzetak: Neispravan vektor!");
	}
	int period(OdrediOsnovniPeriod(v));
	int **a(nullptr);
	if(period){
		int n(BrojRedova1(v,koliko_puta));
		try{
				a=(new int*[n]);
				for(int i=0; i<n; i++) a[i]=nullptr;
				try{
					int suma(0);
					for(int i=0; i<n; i++) suma+=BrojKolona1(v,i,koliko_puta);
					a[0]=new int[suma];
					for(int i=1; i<n; i++) a[i]=a[i-1]+BrojKolona1(v,i-1,koliko_puta);
					int k(0);
					for(int i=0; i<n; i++){
						k=BrojKolona1(v,i,koliko_puta);
						for(int j=0; j<BrojKolona1(v,i,koliko_puta); j++){
							a[i][j]=k--;			
						}
					}
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<BrojKolona1(v,i,koliko_puta); j++){
					std::cout<<a[i][j]<<"  ";
				}
				if(i!=n-1) std::cout<<std::endl;
			}
				}catch(...){
					delete[] a[0];
					throw;
				}
			
			}catch(...){
				delete a;
				std::cout<<"Problemi sa memorijom!";
			}
	}else{
		int n(BrojRedova2(v,koliko_puta));
			try{
				a=(new int*[n]);
				for(int i=0; i<n; i++) a[i]=nullptr;
				try{
					int suma(0);
					for(int i=0; i<n; i++) suma+=BrojKolona2(v,i,koliko_puta);
					a[0]=new int[suma];
					for(int i=1; i<n; i++) a[i]=a[i-1]+BrojKolona2(v,i-1,koliko_puta);
					int k(0);
					for(int i=0; i<suma; i++){
						k=BrojKolona2(v,i,koliko_puta);
						for(int j=0; j<BrojKolona2(v,i,koliko_puta); j++){
							 a[i][j]=k--;
						}
					}
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<BrojKolona2(v,i,koliko_puta); j++){
					std::cout<<a[i][j]<<"  ";
				}
				if(i!=n-1) std::cout<<std::endl;
			}
				}catch(...){
					delete[] a[0];
					throw;
				}
			
			}catch(...){
				delete a;
				std::cout<<"Problemi sa memorijom!";
			}
	}
	return a;
}

int main ()
{
	int koliko_puta(0),n;
	std::vector<int>v{1,2,3,1};
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	v.resize(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) std::cin>>v[i];
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alok(-1);
	std::cin>>alok;
	if(alok){
		try{
		int **p=AlocirajFragmentirano(v,koliko_puta);
		for(int i=0; i<BrojRedova1(v,koliko_puta); i++) delete[] p[i];
		delete[] p;
		}catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what();
		}catch(std::bad_alloc){
			std::cout<<"Nedovoljno memorije!";
		}catch(...){
			std::cout<<"Izuzetak: Prazan vektor!";
		}
	}else{
		try{
			int **p=AlocirajKontinualno(v,koliko_puta);
			delete[] p[0];
			delete[] p;
		}catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what();
		}catch(std::bad_alloc){
			std::cout<<"Nedovoljno memorije!";
		}catch(...){
			std::cout<<"Izuzetak: Prazan vektor!";
		}
	}
	return 0;
}