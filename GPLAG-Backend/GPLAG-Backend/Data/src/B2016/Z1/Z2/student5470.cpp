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
typedef std::vector<std::vector<double>> Matrica;


Matrica OgledaloMatrica (Matrica mat) {
    for(int i=0;i<mat.size();i++) {
        for(int j=i;j<mat.size();j++)
            if(mat.at(i).size()!=mat.at(j).size()) throw std::domain_error("Matrica nije korektna");
    }
    if(mat.size()==0) return mat;
    Matrica horizont(mat);
    int k;
    for(int i=0; i<mat.size();i++) {
    	k=mat.at(0).size()-1;
        for(int j=0; j<k;j++) {
            double pom(horizont.at(i).at(k));
            horizont.at(i).at(k)=horizont.at(i).at(j);
            horizont.at(i).at(j)=pom;
    		k--;
        }
    }
    
    Matrica vertik(mat);
    
    for(int j=0; j<mat.at(0).size();j++) {
    	k=mat.size()-1;
        for(int i=0; i<k;i++) {
            double pom(vertik.at(k).at(j));
            vertik.at(k).at(j)=vertik.at(i).at(j);
            vertik.at(i).at(j)=pom;
    		k--;
        }
    }
    
    Matrica mix(vertik);
    
    for(int i=0; i<mat.size();i++) {
    	k=mat.at(0).size()-1;
        for(int j=0; j<k;j++) {
            double pom(mix.at(i).at(k));
            mix.at(i).at(k)=mix.at(i).at(j);
            mix.at(i).at(j)=pom;
    		k--;
        }
    }
        
    Matrica ogledalo(3*mat.size(),std::vector<double>(3*mat.at(0).size()));
    
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat.at(0).size();j++)
            ogledalo.at(i).at(j)=mix.at(i).at(j);
    }
    int i1,j1;
    i1=0;
    for(int i=0;i<mat.size();i++) {
    	j1=0;
        for(int j=mat.at(0).size();j<(2*(mat.at(0).size()));j++) {
            ogledalo.at(i).at(j)=vertik.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=0;i<mat.size();i++) {
    	j1=0;
        for(int j=(2*mat.at(0).size());j<(3*mat.at(0).size());j++) {
            ogledalo.at(i).at(j)=mix.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=mat.size();i<(2*mat.size());i++) {
    	j1=0;
        for(int j=0;j<mat.at(0).size();j++) {
            ogledalo.at(i).at(j)=horizont.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=mat.size();i<(2*mat.size());i++) {
    	j1=0;
        for(int j=mat.at(0).size();j<(2*mat.at(0).size());j++) {
            ogledalo.at(i).at(j)=mat.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=mat.size();i<(2*mat.size());i++) {
    	j1=0;
        for(int j=(2*mat.at(0).size());j<(3*mat.at(0).size());j++) {
            ogledalo.at(i).at(j)=horizont.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=(2*mat.size());i<(3*mat.size());i++) {
    	j1=0;
        for(int j=0;j<mat.at(0).size();j++) {
            ogledalo.at(i).at(j)=mix.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=(2*mat.size());i<(3*mat.size());i++) {
    	j1=0;
        for(int j=mat.at(0).size();j<(2*mat.at(0).size());j++) {
            ogledalo.at(i).at(j)=vertik.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    i1=0;
    for(int i=(2*mat.size());i<(3*mat.size());i++) {
    	j1=0;
        for(int j=(2*mat.at(0).size());j<(3*mat.at(0).size());j++) {
            ogledalo.at(i).at(j)=mix.at(i1).at(j1);
            j1++;
        }
        i1++;
    }
    return ogledalo;
}

int main ()
{	int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
   	std::cin>>m>>n;
   	if(m<0 || n<0) {
   	    std::cout<<"Dimenzije matrice moraju biti nenegativne! ";
   	    return 0;
   	}
   	std::cout<<"Unesite elemente matrice: ";
   	Matrica matrix(m,std::vector<double>(n));
   	for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix.at(0).size();j++)
            std::cin>>matrix.at(i).at(j);
   	}
   	Matrica ogledalo;
   	try {
        ogledalo=OgledaloMatrica(matrix);
   	}
   	catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
   	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
   	for(int i=0;i<ogledalo.size();i++) {
        for(int j=0;j<ogledalo.at(0).size();j++) 
            std::cout<<std::right<<std::setw(4)<<ogledalo.at(i).at(j);
            std::cout<<std::endl;
   	}
    return 0;
}