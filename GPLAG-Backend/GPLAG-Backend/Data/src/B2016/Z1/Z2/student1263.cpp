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

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu(int redovi, int kolone) {
   return Matrica(redovi, std::vector<int>(kolone));
}

Matrica SastaviOgledalo(Matrica h, Matrica v, Matrica x, Matrica hv) {
	int br_redova(x.size()), br_kolona(x[0].size());
	Matrica sastavljena(KreirajMatricu(3*br_redova,3*br_kolona));
	for(int i=0; i<3*br_redova; i++) 
		for(int j=0; j<br_kolona; j++) 
			{if(i<br_redova || i>2*br_redova) 
				for(int k=0; k<br_redova; k++) 
					for(int l=0; l<br_kolona; l++)  sastavljena[i][j]=hv[k][l];
			else for(int k=0; k<br_redova; k++) 
					for (int l=0; l<br_kolona; l++)  sastavljena[i][j]=h[k][l];}
	for(int i=0; i<3*br_redova; i++)
		for(int j=br_kolona; j<2*br_kolona; j++){
			if(i<br_redova || i>2*br_redova) 
				for(int k=0; k<br_redova; k++) 
					for(int l=0; l<br_kolona; l++)  sastavljena[i][j]=v[k][l];
			else for(int k=0; k<br_redova; k++) 
					for (int l=0; l<br_kolona; l++)  sastavljena[i][j]=x[k][l];
		}
	for(int i=0; i<3*br_redova; i++) 
		for(int j=2*br_kolona; j<3*br_kolona; j++) 
			{if(i<br_redova || i>2*br_redova) 
				for(int k=0; k<br_redova; k++) 
					for(int l=0; l<br_kolona; l++)  sastavljena[i][j]=hv[k][l];
			else for(int k=0; k<br_redova; k++) 
					for (int l=0; l<br_kolona; l++)  sastavljena[i][j]=h[k][l];}
	
	
	return sastavljena;
}

Matrica OgledaloMatrica( Matrica x ){
	Matrica ogledalo;
	if(x.size()==0) return ogledalo;
	if(x[0].size()==0) {
		int velicina =x.size();
		ogledalo=KreirajMatricu(velicina,0);
		return ogledalo;
	} 
	int br_redova(x.size()), br_kolona(x[0].size());
	
	for(int i=1; i<br_redova; i++)	
		if(x[i].size()!=x[0].size()) { 
				throw std::domain_error("Matrica nije korektna");
				break;}
	
	ogledalo=KreirajMatricu(3*br_redova,3*br_kolona);
	Matrica h(KreirajMatricu(br_redova,br_kolona)), v(KreirajMatricu(br_redova,br_kolona)), hv(KreirajMatricu(br_redova,br_kolona));
	h=x;
	v=x;
	for (int i=0; i<h.size(); i++){
		for(int j=0; j<v[i].size()/2; j++) {
			int pomocna(h[i][j]);
			h[i][j]=h[i][h[i].size()-(j+1)];
			h[i][h[i].size()-(j+1)]=pomocna;
	}
	}
	for(int i=0; i<v.size()/2; i++) {
		std::vector<int> pomocni(v[i]);
		v[i]=v[v.size()-(i+1)];
		v[v.size()-(i+1)]=pomocni;
	}
	hv=h;
	for(int i=0; i<hv.size()/2; i++) {
		std::vector<int> pomocni(hv[i]);
		hv[i]=hv[hv.size()-(i+1)];
		hv[hv.size()-(i+1)]=pomocni;
	}
	
	ogledalo=SastaviOgledalo(h,v,x,hv);
	
	return ogledalo;
}
int main ()
{	Matrica x;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin>>m;
	std::cin>>n;
	
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
		std::cout<<"Unesite clanove matrice: ";
		x=KreirajMatricu(m,n);
		for(int i=0; i<m; i++) 
			for(int j=0; j<n; j++) {
				std::cin>>x[i][j];
}
		try{
			std::cout<<"Rezultantna matrica: ";
			Matrica ogledalo(OgledaloMatrica(x));
			for(std::vector<int> red: ogledalo)
				{for(int i: red) std::cout<<i<<" ";}
				std::cout<<std::endl;
		}
		catch(std::domain_error izuzetak) {
	      std::cout<<"IZUZETAK: "<<izuzetak.what()<<std::endl;
	   }
	}	
	return 0;
}