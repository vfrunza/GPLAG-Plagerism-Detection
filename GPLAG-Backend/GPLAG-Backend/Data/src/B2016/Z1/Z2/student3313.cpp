/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	
	
	return Matrica(br_redova, std::vector<double>(br_kolona,0));
}



Matrica UnesiMatricu(int br_redova, int br_kolona){
	
	Matrica m(br_redova, std::vector<double>( br_kolona) );
	if(br_redova==0) return m;
	for(int i=0; i<br_redova; i++)
	    for(int j=0; j<br_kolona; j++){
	    	       
	    	   std::cin>>m[i][j];
	    	                
	    	                
	    }
	    
	   int brojac=m[0].size();
	   for(int i=0; i<m.size(); i++){
	   	if(brojac!=m[i].size()){
	   		throw std::domain_error("Matrica nije korektna");
	   	}
	   	else{
	   		return m;
	   	}
	   }
	     
}

int BrojRedova(Matrica m){
	return m.size();
}

int BrojKolona(Matrica m){
	int k=BrojRedova(m);
	if(k>0){
	return m[0].size();}
	else return 0;
}
Matrica h(Matrica m){
	    auto pomocna(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	        int k=0,r=0;
	            for(int i=0; i<BrojRedova(m); i++) {
	            	            r=0;
	            	                    for(int j=BrojKolona(m)-1; j>=0; j--){
	            	                    	            pomocna[k][r]=m[i][j];
	            	                    	                        r++;
	            	                    }
	            	                            k++;
	            }
	            
	                return pomocna;
}

Matrica v(Matrica m) {
	auto pomocna1(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	int k=0,r=0;
	for(int i=BrojRedova(m)-1; i>=0; i--){
		        r=0;
		            for(int j=0; j<BrojKolona(m); j++){
		            	        pomocna1[k][r]=m[i][j];
		            	        
		            	                r++;
		            }
		                k++;
		                
	}
	return pomocna1;
}

Matrica hv(Matrica m){
	
	auto pomocna2(h(m));
	auto pomocna3(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	
	int k=0,r=0;
	
	for(int i=pomocna2.size()-1; i>=0; i--) {
		    r=0;
		        for(int j=0; j<pomocna2[i].size(); j++){
		        	        pomocna3[k][r]=pomocna2[i][j];
		        	                r++;
		        }
		            k++;
	}
	
	
	
	 return pomocna3;
}

Matrica OgledaloMatrica(std::vector<std::vector<double>> m) {
	auto matrica(KreirajMatricu(BrojRedova(m), BrojKolona(m)));
	int a=m.size();
	Matrica krajnja(3*a);
	if(a==0) return krajnja;
	auto gornjalijeva(hv(m));
	auto gornjasrednja(v(m));
	auto gornjadesna(hv(m));
	auto srednjalijeva(h(m));
	auto srednjadesna(h(m));
	auto donjalijeva(hv(m));
	auto donjasrednja(v(m));
	auto donjadesna(hv(m));
	int br=0,br1=0,br2=0;
	
	
	matrica.resize(3*BrojRedova(m));
	for(int i=0; i<3*BrojRedova(m); i++) matrica[i].resize(3*BrojKolona(m));
	
	
	
	for(int i=0; i<gornjalijeva.size(); i++){
		    for(int j=0; j<gornjalijeva[i].size(); j++){
		    	        matrica[i][j]=gornjalijeva[i][j];
		    }
		        br=gornjalijeva[i].size();
		            br2=gornjalijeva.size();
	}
	
	for(int i=0; i<gornjasrednja.size(); i++){
		    for(int j=0; j<gornjasrednja[i].size(); j++){
		    	        matrica[i][j+br]=gornjasrednja[i][j];
		    }
	}
	
	br1=2*br;
	for(int i=0; i<gornjadesna.size(); i++) {
		    for(int j=0; j<gornjadesna[i].size(); j++) {
		    	        matrica[i][j+br1]=gornjadesna[i][j];
		    }
	}
	
	
	for(int i=0; i<srednjalijeva.size(); i++) {
		    for(int j=0; j<srednjalijeva[i].size(); j++) {
		    	        matrica[i+br2][j]=srednjalijeva[i][j];
		    }
	}
	
	for(int i=0; i<m.size(); i++) {
		    for(int j=0; j<m[i].size(); j++) {
		    	        matrica[i+br2][j+br]=m[i][j];
		    }
	}
	
	for(int i=0; i<srednjadesna.size(); i++) {
		    for(int j=0; j<srednjadesna[i].size(); j++) {
		    	        matrica[i+br2][j+2*br]=srednjadesna[i][j];
		    }
	}
	
	for(int i=0; i<donjalijeva.size(); i++) {
		    for(int j=0; j<donjalijeva[i].size(); j++) {
		    	        matrica[i+2*br2][j]=donjalijeva[i][j];
		    }
	}
	for(int i=0; i<donjasrednja.size(); i++) {
		    for(int j=0; j<donjasrednja[i].size(); j++) {
		    	        matrica[i+2*br2][j+br]=donjasrednja[i][j];
		    }
	}
	
	for(int i=0; i<donjadesna.size(); i++) {
		    for(int j=0; j<donjadesna[i].size(); j++) {
		    	        matrica[i+2*br2][j+2*br]=donjadesna[i][j];
		    }
	}
	
	
	return matrica;
	
}

int main ()
{
	
	int m1,n1;
	Matrica A;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m1>>n1;
	if(m1<0 || n1<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
 	std::cout<<"Unesite elemente matrice:\n";
	
	 A=UnesiMatricu(m1,n1);
	 try{
	 auto x=OgledaloMatrica(A);
	 std::cout<<"Rezultantna matrica: "<<std::endl;
	 for(int i=0; i<x.size(); i++) {
	 	    for(int j=0; j<x[i].size(); j++){
	 	    	        std::cout<<std::right<<std::setw(4)<<x[i][j];
	 	    }
	 	        std::cout<<std::endl;
	 }
	 }
	 catch(std::domain_error izuzetak){
	 	std::cout<<izuzetak.what()<<std::endl;
	 }
	 

	     return 0;
}



