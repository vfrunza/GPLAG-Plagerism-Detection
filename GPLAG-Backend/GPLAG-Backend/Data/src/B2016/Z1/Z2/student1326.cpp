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


      std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> m) {
       
       if(m.size()==0) return m;
      	
      	if (m.size()!=0) {
      		if (m[0].size()!=0) {
      			for (int i=0; i<m.size(); i++) {
      				if (m[i].size()!=m[0].size())
      				throw std::domain_error ("Matrica nije korektna");
      			}
      		}
      	}
      	
     std::vector<std::vector<double>> rezultat (3*m.size(), std::vector<double> (m[0].size()*3));
     
     std::vector<std::vector<double>> h (m.size(), std::vector<double> (m[0].size()));
     
     for (int i=0; i<m.size(); i++) {
     	for (int j=0; j<m[0].size(); j++) {
     		h[i][j]= m[i][m[0].size()-1-j];
     	//	cout<<h[i][j]<<" ";
     		
     	}
     }
     
     std::vector<std::vector<double> > v(m.size(), std::vector<double> (m[0].size()));
     
     for (int i=0; i<m.size(); i++) {
     	for (int j=0; j<m[0].size(); j++) {
     		v[i][j]= m[m.size()-i-1][j];
     
     
      }
    }
    
    std::vector<std::vector<double>> hv(m.size(), std::vector<double> (m[0].size()));
     
     for (int i=0; i<m.size(); i++) {
     	for (int j=0; j<m[0].size(); j++) {
     		hv[i][j]= m[m.size()-i-1][m[0].size()-1-j];
     
      }
    }
    
    for (int i=0; i<m.size(); i++) {
     for (int j=0; j<m[0].size(); j++) {
      rezultat[i][j]=hv[i][j];
     }
    }
    
    
     for (int i=0; i<m.size(); i++) {
     	for (int j=m[0].size(); j<2*m[0].size(); j++) {
     		rezultat[i][j]= v[i][j-m[0].size()];
      }
    }
    
    for (int i=0; i<m.size(); i++) {
     	for (int j=2*m[0].size(); j<3*m[0].size(); j++) {
     		rezultat[i][j]= hv[i][j-2*m[0].size()];
      }
    }
    
    for (int i=m.size(); i<2*m.size(); i++) {
     	for (int j=0; j<m[0].size(); j++) {
     		rezultat[i][j]= h[i-m.size()][j];
      }
    }
    
    for (int i=m.size(); i<2*m.size(); i++) {
     	for (int j=m[0].size(); j<2*m[0].size(); j++) {
     		int broj (m[0].size());
     		rezultat[i][j]= m[i-m.size()][j-broj];
      }
    }
    
    for (int i=m.size(); i<2*m.size(); i++) {
     	for (int j=2*m[0].size(); j<3*m[0].size(); j++) {
     		rezultat[i][j]= h[i-m.size()][j-2*m[0].size()];
      }
    }
    
    for (int i=2*m.size(); i<3*m.size(); i++) {
     	for (int j=0; j<m[0].size(); j++) {
     		rezultat[i][j]= hv[i-2*m.size()][j];
      }
    }
    
    for (int i=2*m.size(); i<3*m.size(); i++) {
     for (int j=m[0].size(); j<2*m[0].size(); j++) {
      rezultat[i][j]=v[i-2*m.size()][j-m[0].size()];
     }
    }
   for (int i=2*m.size(); i<3*m.size(); i++) {
     	for (int j=2*m[0].size(); j<3*m[0].size(); j++) {
     		rezultat[i][j]= hv[i-2*m.size()][j-2*m[0].size()];
      }
    }


    return rezultat;
    
 }
 

int main () {
	
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	
	if (m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne! "; 
	
	else {std::vector<std::vector<double>> v (m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	 for (int i=0; i<m; i++) {
	  for (int j=0; j<n; j++) {
	   std::cin>>v[i][j];
	  }
	 }
	   try {
	   auto Rez (OgledaloMatrica(v));
	   std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	   for (int i=0; i<Rez.size(); i++) {
	    for (int j=0; j<Rez[i].size(); j++) {
	    std::cout<<std::setw(4)<<Rez[i][j];
	    }
	    std::cout<<std::endl;
	   }
	  }
	   catch (std::domain_error izuzetak) {
	    std::cout<<izuzetak.what() <<std::endl;
	   }
	   
	return 0;
}
}









