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

using std::cout;
using std::cin;
typedef std::vector<double> Vec;
typedef std::vector<std::vector<double>> Matrica;


int Brojredova(Matrica M){
	return M.size();
}

int Brojkolona(Matrica M){
    if(M.size()==0) return 0; 
    else{
	return M[0].size();
    }
}

Matrica Kreiraj (int Noredovi, int Nokolone){
	return Matrica(Noredovi, Vec(Nokolone));
}
Matrica Unesi(int Noredovi , int Nokolone){
	auto Povratna_Matrica(Kreiraj(Noredovi,Nokolone));
	for(int i=0; i<Noredovi;i++){
		for(int j=0; j<Nokolone;j++){
			cin>> Povratna_Matrica[i][j];
		}
	}
	return Povratna_Matrica;
}

void Ispisi(Matrica M){
	for(int i=0; i<Brojredova(M);i++){
		for(int j=0; j<Brojkolona(M);j++){
			cout<<std::setw(4) << M[i][j];
		}
		cout<<std::endl;
	}
}
Matrica Horizontalna(Matrica M){
		int velicina=Brojkolona(M);
		
	for(int k=0;k<Brojredova(M);k++){
		int j=velicina-1;
	for(int i=0;i<velicina/2;i++){
	    double temp=M[k][i];
	    M[k][i]=M[k][j];
	    M[k][j]=temp;
	    j--;
	    
	}

	}
	
  
  return M;
	
}

Matrica Vertikalna(Matrica M){
	int velicina=Brojredova(M);
	int j=velicina-1;
		for(int i=0;i<velicina/2;i++){
				Vec temp;
				temp=M[i];
				M[i]=M[j];
				M[j]=temp;
				j--;
			}
		
	
	return M;
}

Matrica Kombinuj(Matrica M){
	Matrica Povratna_Matrica;
	Povratna_Matrica=Horizontalna(Vertikalna(M));
	return Povratna_Matrica;
	
}

Matrica OgledaloMatrica(Matrica M){
    Matrica h=Horizontalna(M);
    Matrica v=Vertikalna(M);
    Matrica hv=Kombinuj(M);
    int m;
    m=Brojredova(M);
    int n;
    n=Brojkolona(M);
    for(int i=1;i<m;i++){
    if(M[0].size()!=M[i].size()) throw std::domain_error ("Matrica nije korektna");
    }
    int Redovi=m*3;
    int Kolone=n*3;
    Matrica Povratna_Matrica(Redovi,Vec(Kolone));
    if(M.size()==0) return Povratna_Matrica;
    for(int i=0;i<Redovi/3;i++){
    	for(int j=0;j<Kolone/3;j++){
    		Povratna_Matrica[i][j]=hv[i][j];
    	}
    }
    int k=0;
    for(int i=Redovi/3;i<Redovi-(Redovi/3);i++){
      for(int j=0;j<Kolone/3;j++){
    		Povratna_Matrica[i][j]=h[k][j];
    	}
    	k++;
    }
    int l=0;
    for(int i=Redovi-Redovi/3;i<Redovi;i++){
    	 for(int j=0;j<Kolone/3;j++){
    		Povratna_Matrica[i][j]=hv[l][j];
    	}
    	l++;
    }
    int s;
    for(int i=0;i<Redovi/3;i++){
    	s=0;
    	for(int j=Kolone/3; j<Kolone-Kolone/3;j++){
    		Povratna_Matrica[i][j]=v[i][s];
    		s++;
    	}
    	
    }
    int p;
    int r=0;
    for(int i=Redovi/3; i<Redovi-Redovi/3;i++){
    	p=0;
    	for(int j=Kolone/3; j<Kolone-Kolone/3;j++){
    		Povratna_Matrica[i][j]=M[r][p];
    		p++;
    	}
    	r++;
    }
    int o;
    int w=0;
    for(int i=Redovi-Redovi/3;i<Redovi;i++){
    	o=0;
    	for(int j=Kolone/3;j<Kolone-Kolone/3;j++){
    		Povratna_Matrica[i][j]=v[w][o];
    		o++;
    	}
    	w++;
    }
    int z;
    for(int i=0;i<Redovi/3;i++){
    	z=0;
    	for(int j=Kolone-Kolone/3;j<Kolone;j++){
    		Povratna_Matrica[i][j]=hv[i][z];
    		z++;
    	}
    }
    int a=0;
    int b;
    for(int i=Redovi/3;i<Redovi-(Redovi/3);i++){
    	b=0;
      for(int j=Kolone-Kolone/3;j<Kolone;j++){
    		Povratna_Matrica[i][j]=h[a][b];
    		b++;
    	}
    	a++;
    }
    int x=0;
    int y;
    for(int i=Redovi-Redovi/3;i<Redovi;i++){
    	y=0;
    	 for(int j=Kolone-Kolone/3;j<Kolone;j++){
    		Povratna_Matrica[i][j]=hv[x][y];
    		y++;
    	}
    	x++;
    }
    
  
	
   
   return Povratna_Matrica;
	
}

int main ()
{ 
	int m,n;
    cout<<"Unesite dimenzije matrice (m n): ";
	cin>> m >> n;
	if(m<0 or n<0) cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
	cout<<"Unesite elemente matrice: ";
	Matrica OgledajMe;
   OgledajMe=Unesi(m,n);
   cout<<std::endl;
   cout<<"Rezultantna matrica:"<< std::endl;
   Ispisi((OgledaloMatrica(OgledajMe)));
	}
	return 0;
}