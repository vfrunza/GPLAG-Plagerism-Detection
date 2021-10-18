/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/ 
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica m){
	//Unos prazne matrice
	if(m.size()==0)
	   return m;
	//Ako funkciji proslijedimo grbavu matricu 
	 for(int i=0;i<m.size();i++){
	 	for(int j=i+1;j<m.size()-1;j++){
	 	      if(m[i].size()!=m[j].size()) throw std::domain_error ("Matrica nije korektna");
	 	}
	 }
	int a=m.size();
	int b=m[0].size();
   	Matrica h(a,std::vector<double>(b));
	Matrica v(a,std::vector<double>(b));
    Matrica ogledalce(3*a,std::vector<double>(3*b));
	//Vertikalna matrica

	int k=m.size()-1;
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){

			 v.at(i).at(j)=m.at(k).at(j);
		
		}
			k--;
	}
	//Horizontalna matrica

	for(int i=0;i<m.size();i++){
		int l=m[0].size()-1;
		for(int j=0;j<m[0].size();j++){
	       
		    h[i][j]=m[i][l];
		    l--;
		}
		
	}
	
	//Kombinovana matrica
    k=m.size()-1;
	Matrica hv(a,std::vector<double>(b));
	for(int i=0;i<m.size();i++){
		int z=m[0].size()-1;
		for(int j=0;j<m[0].size();j++){
	
		 hv[i][j]=m[k][z];
			z--;
		}
			k--;
	}
	
	//"Prvi" red
			
	int j,i;
	for( i=0;i<m.size();i++){
		
	for( j=0;j<hv[0].size();j++){
		ogledalce[i][j]=hv[i][j];
	}	
	int druga=j;
	for(j=0;j<v[0].size();j++){
		ogledalce[i][druga]=v[i][j];
		druga++;
	}	
    int treca=druga;
	for(j=0;j<hv[0].size();j++){
		ogledalce[i][treca]=hv[i][j];
		treca++;
	}	
	
	}
	
	//"Drugi" red
	int o;
	k=0;
	for( o=i;o<2*m.size();o++){
		int j;
		for(j=0;j<h[0].size();j++){
			ogledalce[o][j]=h[k][j];
		}
		
		int druga=j;
		
		for(j=0;j<m[0].size();j++){
			ogledalce[o][druga]=m[k][j];
			druga++;
		}
		
		int treca=druga;
		
		for(j=0;j<h[0].size();j++){
			ogledalce[o][treca]=h[k][j];
			treca++;
		}
		k++;
	}
	
	//"Treci" red
	k=0;
	for(int p=o;p<3*m.size();p++){

	for( j=0;j<hv[0].size();j++){
		ogledalce[p][j]=hv[k][j];
	}	
	int druga=j;
	for(j=0;j<v[0].size();j++){
		ogledalce[p][druga]=v[k][j];
		druga++;
	}	
	int treca=druga;
	for(j=0;j<hv[0].size();j++){
		ogledalce[p][treca]=hv[k][j];
		treca++;
    	}	
    k++;
	}
	
	
	return ogledalce;

}


int main ()
{
	try{
	int a,b;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>a>>b;
    if(a<0 ||b<0){
	   std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	   return 0;}
	Matrica matrica(a,std::vector<double>(b));
	
	std::cout<<"Unesite elemente matrice: ";	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			std::cin>>matrica[i][j];
		}
	}
    
    Matrica nova;
	nova=OgledaloMatrica(matrica);
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica: ";
	std::cout<<std::endl;
	for(int i=0;i<nova.size();i++){
		for(int j=0;j<nova[0].size();j++){
			std::cout<<std::setw(4)<<nova[i][j];
		}
		std::cout<<std::endl;
	}
	}
	
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	
	return 0;
}