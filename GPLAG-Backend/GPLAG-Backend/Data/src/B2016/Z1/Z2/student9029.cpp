#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica UnosMatrice(int m, int n){
    Matrica matrica(m, Vektor(n));
    
    std::cout<<"Unesite elemente matrice:";
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            std::cin>>matrica[i][j];
    
    return matrica;
}

void IspisMatrice(Matrica matrica){
    std::cout<<"\nRezultantna matrica:\n";
    for(auto red: matrica){
        for(double broj : red)
            std::cout<< std::setw(4) << broj;
        std::cout<<std::endl;
    }
}

Matrica ObrniHorizontalno(Matrica matrica){
    for(int red=0;red<matrica.size();red++)
        for(int i=0, j=(int)matrica[red].size()-1;i<j;i++,j--){
            double pomocni=matrica[red][i];
            matrica[red][i]=matrica[red][j];
            matrica[red][j]=pomocni;
        }
    return matrica;
}

Matrica ObrniVertikalno(Matrica matrica){
    Vektor pomocni;
    for(int i=0, j=(int)matrica.size()-1;i<j;i++,j--){
        pomocni=std::move(matrica[i]);
        matrica[i]=std::move(matrica[j]);
        matrica[j]=std::move(pomocni);
    }
    return matrica;
}

Matrica OgledaloMatrica(Matrica matrica){
    
    if(!matrica.size()) return matrica;
    for(int i=1;i<(int)matrica.size();i++)
        if(matrica[0].size()!=matrica[i].size()) throw std::domain_error("Matrica nije korektna");
    
    Matrica horizontalna = ObrniHorizontalno(matrica), vertikalna = ObrniVertikalno(matrica);
    Matrica kombinovana = ObrniVertikalno(horizontalna);
    
    Matrica krajnja((int)matrica.size()*3);
    int i=0;
    for(int dokle=0;dokle<2;dokle++)
        switch(dokle){
            case(1):
            for(int red=0;red<(int)matrica.size();red++,i++){
                krajnja[i].insert(krajnja[i].end(),horizontalna[red].begin(), horizontalna[red].end());
                krajnja[i].insert(krajnja[i].end(), matrica[red].begin(), matrica[red].end());
                krajnja[i].insert(krajnja[i].end(),horizontalna[red].begin(), horizontalna[red].end());
            }
            case(0):
            for(int red=0;red<(int)matrica.size();red++,i++){
                krajnja[i].insert(krajnja[i].end(),kombinovana[red].begin(), kombinovana[red].end());
                krajnja[i].insert(krajnja[i].end(),vertikalna[red].begin(), vertikalna[red].end());
                krajnja[i].insert(krajnja[i].end(),kombinovana[red].begin(), kombinovana[red].end());
            }
            break;
        }
    
    return krajnja;
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
	
	try{
    IspisMatrice(OgledaloMatrica(UnosMatrice(m,n)));
	} catch(std::domain_error izuzetak){
	    std::cout<<izuzetak.what();
	}
	
	return 0;
} 