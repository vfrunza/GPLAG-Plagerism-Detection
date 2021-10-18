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
using std::vector;
typedef std::vector<std::vector<double>> mat;

mat KreirajMat(int br_redova, int br_kolona){     //Kreira matricu sa zadanim brojem redova i kolona
	return mat(br_redova, vector<double>(br_kolona));
}


mat UnesiMat(int br_redova, int br_kolona){     //Unos sa tastature matricu sa zadanim brojem redova i kolona
	mat m(KreirajMat(br_redova, br_kolona));
	for (int i=0; i<br_redova; i++)
	for (int j=0; j<br_kolona; j++){
		std::cin>>m[i][j];
	}
	return m;
}

void IspisiMat (mat m){       // Ispis matrice
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++)
		std::cout<<std::setw(4)<<std::right<<m[i][j];
		std::cout<<std::endl;
	}
}

mat HorizontalnoOgledalo(mat m){           //horizontalno ogledalo
	mat h(m.size());
    int l;
    for(int i=0; i<m.size(); i++)
        h[i].resize(m[0].size());
	for(int i=0; i<m.size(); i++){
		l=m[0].size()-1;
		for(int j=0; j<m[i].size(); j++){
		h[i][l]=m[i][j];
		l--;
		}
	}
	return h;
}

mat VertikalnoOgledalo(mat m){            //vertikalno ogledalo
	mat v(m.size());
    for(int i=0; i<m.size(); i++)
        v[i].resize(m[0].size());
	int l=m.size()-1;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++)
		v[l][j]=m[i][j];
		l--;
	}
	return v;
}

mat KombOgledalo(mat m){                  //kombinovano ogledalo
	return VertikalnoOgledalo(HorizontalnoOgledalo(m));
}

mat OgledaloMatrica(mat m){
	if(m.size()==0)
		return m;
	if(m.size()!=0 && m[0].size()==0)
		{
			m.resize(3*m.size());
			return m;
		}
	for(int i=0; i<m.size();i++)
	if(m[i].size()!=m[0].size()) throw
	std::domain_error ("Matrica nije korektna");
	int BrojROM=(3*m.size());
	int BrojKOM=(3*m[0].size());
	mat OM(KreirajMat(BrojROM, BrojKOM));
	
	mat h=HorizontalnoOgledalo(m);
	mat v=VertikalnoOgledalo(m);
	mat hv=KombOgledalo(m);
	mat M=mat(m);
	
	for(int i=0; i<m.size(); i++)
		for(int j=0; j<m[i].size(); j++)
			OM[i][j]=hv[i][j];
		
	for(int i=0;i<m.size(); i++)
		for(int j=m[i].size(), n=0; j<m[i].size()*2; j++, n++)
			OM[i][j]=v[i][n];
		
	for(int i=0; i<m.size(); i++)	
		for(int j=m[i].size()*2,n=0; j<m[i].size()*3; j++, n++) 
			OM[i][j]=hv[i][n];
		
    int f=0;
    for(int i=m.size(); i<m.size()*2; i++){
    	int k=0;
    	for(int j=0; j<m[f].size(); j++){
    		OM[i][j]=h[f][k];
    		k++;
    	}
    	f++;
    }
    
    f=0;
    for(int i=m.size(); i<2*m.size(); i++){
    	int k=0;
    	for(int j=m[f].size(); j<2*m[f].size(); j++){
    		OM[i][j]=m[f][k];
    		k++;
    	}
    	f++;
    }
    
    f=0;
    for(int i=m.size(); i<2*m.size(); i++){
    	int k=0;
        for(int j=2*m[f].size(); j<3*m[f].size(); j++){
    		OM[i][j]=h[f][k];
    		k++;
    	}
    	f++;
    }
    
    f=0;
    for(int i=2*m.size(); i<3*m.size(); i++){
    	int k=0;
    	for(int j=0; j<m[f].size(); j++){
    		OM[i][j]=hv[f][k];
    		k++;
    	}
    	f++;
    }
    
    f=0;
    for(int i=2*m.size(); i<3*m.size(); i++){
    int k=0; 
    for(int j=m[f].size(); j<2*m[f].size(); j++){
    		OM[i][j]=v[f][k];
    		k++;
    	}
        f++;
    }
    
    f=0;
    for(int i=2*m.size(); i<3*m.size(); i++){
    int k=0;
    	for(int j=2*m[f].size(); j<3*m[f].size(); j++){
    		OM[i][j]=hv[f][k];
    		k++;
    	}
    	f++;
    }
	return OM;
}
int main (){
	
	
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout<<"Unesite elemente matrice: \n";
	mat M(UnesiMat(m,n));
	std::cout<<"Rezultantna matrica: "<<std::endl;
	IspisiMat(OgledaloMatrica(M));
	return 0;
}