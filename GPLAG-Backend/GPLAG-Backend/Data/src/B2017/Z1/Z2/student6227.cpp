/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector <double>> Matrica;

int BrojRedova (Matrica m){
	return m.size();
}
int BrojKolona (Matrica m){
	return m.at(0).size();
}
Matrica KreirajMatricu (int br_redova, int br_kolona){
	return Matrica (br_redova, std::vector <double> (br_kolona));
}
Matrica UnesiMatricu(int br_redova,int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i(0);i<br_redova;i++)
		for (int j(0);j<br_kolona;j++){
			std::cin >> m.at(i).at(j);
		}
	return m;	
}
void IspisiMatricu (Matrica m){
	for (int i(0);i<BrojRedova(m);i++){
		for (int j(0);j<BrojKolona(m);j++)
			std::cout << std::setw(6) << m.at(i).at(j);
		std::cout << std::endl;
	}
}

bool UporediMatrice (Matrica maksimalna, int max_i, int max_j, Matrica pomocna, int i, int j){
	if (max_i==-1) return true;
	if (BrojRedova(maksimalna)!=BrojRedova(pomocna))
		return BrojRedova(pomocna)>BrojRedova(maksimalna);
	else if (maksimalna.at(BrojRedova(maksimalna)/2).at(BrojKolona(maksimalna)/2)!=pomocna.at(BrojRedova(pomocna)/2).at(BrojKolona(pomocna)/2))
		return maksimalna.at(BrojRedova(maksimalna)/2).at(BrojKolona(maksimalna)/2)<pomocna.at(BrojRedova(pomocna)/2).at(BrojKolona(pomocna)/2);
	else if (max_i!=i) return max_i < i; 	
	return max_j > j;	
}
Matrica DajPomocnu(Matrica m, int i, int j, int k){
	Matrica pp(KreirajMatricu(2*k+1,2*k+1));
	int x(0),y(0);
	for (int u(i-k);u<=(i+k);u++){
		for (int v(j-k);v<=(j+k);v++){
			pp.at(x).at(y)=m.at(u).at(v);
			y++;
		}
		y=0;
		x++;
	}
	return pp;
}
double DajSumu (Matrica mat, int i, int j, int k){
	double sum(0);
	for (int l(i-k);l<=i+k;l++){
		for (int m(j-k);m<=j+k;m++){
			if (l==i-k || m==j-k || l==i+k || m==j+k){
				sum +=mat.at(l).at(m);
			}
		}
	}
	return sum;
}
int DajUdaljenost(Matrica m,int i,int j){
	int k=BrojKolona(m)-1, r=BrojRedova(m)-1, a,b,c,d;
	a=k-i;
	b=i;
	c=j;
	d=r-j;
	if (a<=b && a<=c && a<=d) return a;
	else if (b<=a && b<=c && b<=d) return b;
	else if (c<=a && c<=b && c<=d) return c;
	return d;
}
bool DaLiJePlanina (Matrica mat, int i, int j, double sum, int k){
	if (DajSumu(mat,i,j,k)<sum) return true;
	return false;
}

Matrica NajvecaPlaninaMatrice (Matrica m){
	Matrica k;
	int max;
	for (int i(0);i<BrojRedova(m)-1;i++){
		if (m.at(i).size()!=m.at(i+1).size()) throw std::domain_error ("Matrica nije korektna"); 
	}
	if (m.size()==0 || m.at(0).size()==0)
		return (KreirajMatricu(0,0));
	if (m.size()==2 || m.size()==1 || m.at(0).size()==1 || m.at(0).size()==2){
		max=m.at(0).at(0);
		Matrica l(KreirajMatricu(1,1));
		for (int i(0);i<BrojRedova(m);i++){
			for (int j(0);j<BrojKolona(m);j++){
				if (m.at(i).at(j)>max) max=m.at(i).at(j);		
			}
		}
		l.at(0).at(0)=max;		
		return l;
	}
	int max_i(-1),max_j(-1);
	double suma;
	Matrica maksimalna,pomocna;
	for (int i(1);i<BrojRedova(m)-1;i++){
		for (int j(1);j<BrojKolona(m)-1;j++){
			int udaljenost (DajUdaljenost(m,i,j));
			suma=m.at(i).at(j);
			for(int k(1);k<=udaljenost;k++){
				if(!DaLiJePlanina(m,i,j,suma,k)) break;
				else {
					pomocna=DajPomocnu(m,i,j,k);
					if(UporediMatrice(maksimalna,max_i,max_j,pomocna,i,j)) {
						maksimalna=pomocna;
						max_i=i;
						max_j=j;
					}
				}
				suma=DajSumu(m,i,j,k); 
			}
		}
	}
	if (maksimalna.size()==0){
		max=m.at(0).at(0);
		Matrica l(KreirajMatricu(1,1));
		for (int i(0);i<BrojRedova(m);i++){
			for (int j(0);j<BrojKolona(m);j++){
				if (m.at(i).at(j)>max) max=m.at(i).at(j);		
			}
		}
		l.at(0).at(0)=max;		
		return l;
	}
	return maksimalna;
}

int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!"; 
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	auto A (UnesiMatricu(m,n));
	try{
		auto B (NajvecaPlaninaMatrice(A));
		std::cout << std::endl << "Najveca planina unesene matrice je: " << std::endl;
		IspisiMatricu(B);
	}
	catch (std::domain_error err){
		std::cout << err.what() << std::endl;
	}
	
	return 0;
}