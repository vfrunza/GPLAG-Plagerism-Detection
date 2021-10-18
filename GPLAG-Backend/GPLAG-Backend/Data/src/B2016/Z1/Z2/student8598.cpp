/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
//HORIZONTALNA MATRICA
std::vector<std::vector<double> > Horizontalna_Matrica(std::vector<std::vector<double> > Matrica){
int i,j;
std::deque<double> pomocni;
for(i=0;i<Matrica.size();i++){
    for(j=0;j<Matrica[i].size();j++){
        pomocni.push_front(Matrica[i][j]);
    }
    for(j=0;j<pomocni.size();j++){
        Matrica[i][j]=pomocni[j];
    }
    pomocni.resize(0);
}
return Matrica;
}
//VERTIKALNA MATRICA
std::vector<std::vector<double> > Vertikalna_Matrica(std::vector<std::vector<double> > Matrica){
int i,j;
std::vector<std::vector<double> > Matrica2;
Matrica2=Matrica;
std::deque<double> pomocni;
for(i=0;i<Matrica.size();i++){
    for(j=0;j<Matrica[i].size();j++){
        pomocni.push_back(Matrica[i][j]);
    }
    for(j=0;j<pomocni.size();j++){
        Matrica2[Matrica2.size()-1-i][j]=pomocni[j];
    }
    pomocni.resize(0);
}
return Matrica2;
}
//HORIZONTALNO-VERTIKALNA MATRICA
std::vector<std::vector<double> > Horizontalno_Vertikalna_Matrica(std::vector<std::vector<double> > Matrica){
int i,j;
std::deque<double> pomocni;
Matrica=Vertikalna_Matrica(Matrica);
for(i=0;i<Matrica.size();i++){
    for(j=0;j<Matrica[i].size();j++){
        pomocni.push_front(Matrica[i][j]);
    }
    for(j=0;j<pomocni.size();j++){
        Matrica[i][j]=pomocni[j];
    }
    pomocni.resize(0);
}
return Matrica;
}
std::vector<std::vector<double> > OgledaloMatrica(std::vector<std::vector<double> > Matrica){
    std::vector<std::vector<double> > HorizontalnaMatrica=Horizontalna_Matrica(Matrica);
    std::vector<std::vector<double> > VertikalnaMatrica=Vertikalna_Matrica(Matrica);
    std::vector<std::vector<double> > Horizontalno_VertikalnaMatrica=Horizontalno_Vertikalna_Matrica(Matrica);
    std::vector<std::vector<double> > M;
    int i,j,red,kolona;
    for ( int i = 0; i < Matrica.size() ; i++ ) if ( Matrica[0].size() != Matrica[i].size() ) throw std::domain_error("Matrica nije korektna");
    red=3*Matrica.size();
    if(red==0) return M;
    kolona=3*Matrica[0].size();
    std::vector<std::vector<double> > Povratna(red, std::vector<double> (kolona));
    for(i=0;i<Matrica.size();i++){
    	for(j=0;j<Matrica[0].size();j++){
    		Povratna[i][j]=Horizontalno_VertikalnaMatrica[i][j];
    	}
    	for(j=Matrica[0].size();j<2*Matrica[0].size();j++){
    		Povratna[i][j]=VertikalnaMatrica[i][j-Matrica[0].size()];
    	} 
    	for(j=2*Matrica[0].size();j<3*Matrica[0].size();j++){
    		Povratna[i][j]=Horizontalno_VertikalnaMatrica[i][j-2*Matrica[0].size()];
    	}    
    }   
    for(i=Matrica.size();i<2*Matrica.size();i++){
    	for(j=0;j<Matrica[0].size();j++){
    		Povratna[i][j]=HorizontalnaMatrica[i-Matrica.size()][j];
    	}
    	for(j=Matrica[0].size();j<2*Matrica[0].size();j++){
    		Povratna[i][j]=Matrica[i-Matrica.size()][j-Matrica[0].size()];
    	} 
    	for(j=2*Matrica[0].size();j<3*Matrica[0].size();j++){
    		Povratna[i][j]=HorizontalnaMatrica[i-Matrica.size()][j-2*Matrica[0].size()];
    	}    
    }
    for(i=2*Matrica.size();i<3*Matrica.size();i++){
    	for(j=0;j<Matrica[0].size();j++){
    		Povratna[i][j]=Horizontalno_VertikalnaMatrica[i-2*Matrica.size()][j];
    	}
    	for(j=Matrica[0].size();j<2*Matrica[0].size();j++){
    		Povratna[i][j]=VertikalnaMatrica[i-2*Matrica.size()][j-Matrica[0].size()];
    	} 
    	for(j=2*Matrica[0].size();j<3*Matrica[0].size();j++){
    		Povratna[i][j]=Horizontalno_VertikalnaMatrica[i-2*Matrica.size()][j-2*Matrica[0].size()];
    	}    
    }
    
return Povratna;
}
int main ()
{
    int i,j,m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::vector<std::vector<double> > Matrica(m, std::vector<double> (n));
	std::vector<std::vector<double> > Matrica2(3*m, std::vector<double> (3*n));
	std::cout<<"Unesite elemente matrice: ";
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            std::cin>>Matrica[i][j];
        }
	}
	std::cout<<std::endl;
	try {
	Matrica2=OgledaloMatrica(Matrica);
	std::cout<<"Rezultantna matrica:"<<std::endl;
		for(i=0;i<3*m;i++){
	        for(j=0;j<3*n;j++){
	            std::cout<<std::setw(4)<<Matrica2[i][j];
	        }
        std::cout<<std::endl;
	}
	}
	catch  (std::domain_error korektnost ) {
	    std::cout<<korektnost.what()<<std::endl;
	}
	    
	
	return 0;
}