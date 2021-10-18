/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	Matrica a(broj_redova);
	for(int i=0;i<broj_redova;i++)
		a[i].resize(broj_kolona);
		
	return a ;
}

int BrojRedova(Matrica a){
	return a.size();
}

int BrojKolona(Matrica a){
	return a[0].size();
}

/*Matrica UnesiMatricu(int broj_redova,int broj_kolona){
	auto a(KreirajMatricu(broj_redova,broj_kolona));
		for(int i=0;i<broj_redova;i++){
			for(int j=0;j<broj_kolona;j++){
				std::cin>>a[i][j];
			}
		}
	return a;
}*/


Matrica DodajUMatricu(Matrica a,std::vector<double> v){
	
	for(int i=0;i<v.size();i++){
		a[a.size()].push_back(v[i]);
	}
	return a;
}





Matrica RastuciPodnizovi(std::vector<double> v) {
			int brojac(1);
			int brojac1(0);
			Matrica a;
			for(int i=0;i<v.size();i++){
				brojac=1;
					for(int j=i+1;j<v.size();j++){
						if(v[i]<=v[j]){ 
							brojac++;
							i++;
						}
						else if(v[i]>v[j] ) { 
							if(v[j]<v[j+1]) brojac1--;
							brojac1++;
							break;
						}
							
					}
					
					
					if(brojac!=1){
						
				a.resize(brojac1+1);
				a[brojac1].resize(brojac);
						int b(a.size());
						std::cout<<" a.size()= "<<b<<std::endl;
					
				int m=0;
				int pom(i-brojac+1);
				for(int k=0;k<brojac;k++){
					if(brojac==1) break;
					a[brojac1][m]=v[pom];
				
					pom++;
					m++;
				}
					}
			
			}

	return a;

}


Matrica OpadajuciPodnizovi(std::vector<double> v){
	int brojac(1);
			int brojac1(0);
			Matrica a;
			for(int i=0;i<v.size();i++){
				brojac=1;
					for(int j=i+1;j<v.size();j++){
						if(v[i]>=v[j]){ 
							brojac++;
							i++;
						}
						else if( v[i]<v[j] ) { 
							if(v[j]<v[j+1]) brojac1--;
							if(i==v.size()) break;
							brojac1++;
							break;
						}
							
					}
					
					
					if(brojac!=1){
						
				a.resize(brojac1+1);
				a[brojac1].resize(brojac);
						int b(a.size());
						std::cout<<" a.size()= "<<b<<std::endl;
					
				int m=0;
				int pom(i-brojac+1);
				for(int k=0;k<brojac;k++){
					if(brojac==1) break;
					a[brojac1][m]=v[pom];
				
					pom++;
					m++;
				}
					}
			
			}

	return a;

}
	


int main ()
{
	std::vector<double> v{1,3,2,6,7,9,10,4,3,1,7};
	Matrica a(OpadajuciPodnizovi(v));
	std::cout<<"size of a "<<a.size()<<std::endl;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++)
		std::cout<<a[i][j]<<" ";
		std::cout<<std::endl;
	}
	
	
}