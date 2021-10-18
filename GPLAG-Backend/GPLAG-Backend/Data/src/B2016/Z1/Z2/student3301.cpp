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

Matrica OgledaloMatrica (Matrica m){
	int br_redova(m.size());
	int br_kolona;
   if(m.size()>0)
	br_kolona = m[0].size();
   else 
     br_kolona = 0;
	for(int i=0; i<br_redova; i++){
		if(m[i].size()!=m[0].size())
		  throw std::domain_error("Matrica nije korektna");
	}
    Matrica v(m), h(m), VH(m);
    for(int i=0; i<(br_redova/2); i++){
    	for(int j=0; j<br_kolona; j++){
    		double temp(v[i][j]);
    		v[i][j] = v[br_redova-i-1][j];
    		v[br_redova-i-1][j] = temp;
    	}
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<(br_kolona/2); j++){
    		double temp(h[i][j]);
    		h[i][j] = h[i][br_kolona-j-1];
    		h[i][br_kolona-j-1] = temp;
    	}
    }
    VH = v;
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<(br_kolona/2); j++){
    		double temp(VH[i][j]);
    		VH[i][j] = VH[i][br_kolona-j-1];
    		VH[i][br_kolona-j-1] = temp;
    	}
    }
    
    Matrica Krajnja(3*br_redova, std::vector<double>(3*br_kolona));
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i][j] = VH[i][j];
    }
    
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	   Krajnja[i][j+br_kolona] = v[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i][j+2*br_kolona] = VH[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i+br_redova][j] = h[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i+br_redova][j+br_kolona] = m[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	Krajnja[i+br_redova][j+2*br_kolona] = h[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i+2*br_redova][j] = VH[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i+2*br_redova][j+br_kolona] = v[i][j];
    }
    for(int i=0; i<br_redova; i++){
    	for(int j=0; j<br_kolona; j++)
    	  Krajnja[i+2*br_redova][j+2*br_kolona] = VH[i][j];
    }
    return Krajnja;
}

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica mat(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			
			std::cin>>mat[i][j];
		}
	}
	try{
		Matrica k(OgledaloMatrica(mat));
		std::cout<<"Rezultantna matrica: "<<std::endl;
		for(int i=0; i<k.size(); i++){
			for(int j=0; j<k[i].size(); j++){
				std::cout<<std::setw(4)<<k[i][j];
			}
		std::cout<<std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout<<"IZUZETAK: "<<izuzetak.what()<<std::endl;
	}
	return 0;
}



