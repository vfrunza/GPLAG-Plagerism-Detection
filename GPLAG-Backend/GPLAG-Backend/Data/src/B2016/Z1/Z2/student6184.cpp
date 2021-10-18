/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return Matrica(broj_redova,std::vector<double>(broj_kolona));
}

int BrojRedova(Matrica a){
	return a.size();
}

int BrojKolona(Matrica a){
	return a[0].size();
}

Matrica UnesiMatricu(int broj_redova,int broj_kolona){
	auto a(KreirajMatricu(broj_redova,broj_kolona));
		for(int i=0;i<broj_redova;i++){
			for(int j=0;j<broj_kolona;j++){
				std::cin>>a[i][j];
			}
		}
	return a;
}

void IspisiMatricu(Matrica a){
	for(int i=0;i<BrojRedova(a);i++){
		for(int j=0;j<BrojKolona(a);j++){
			
			std::cout<<std::setw(4)<<a[i][j];
		}
		std::cout<<std::endl;
	}

}


Matrica h(Matrica a){
	auto b(KreirajMatricu(a.size(),a[0].size()));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++){
			b[i][j]=a[i][BrojKolona(a)-j-1];
		}
	}
	return b;
}

Matrica v(Matrica a){
	auto b(KreirajMatricu(BrojRedova(a),BrojKolona(a)));
	for(int i=0;i<BrojRedova(a);i++){
		for(int j=0;j<BrojKolona(a);j++){
			b[i][j]=a[BrojRedova(a)-i-1][j];
		}
	}
	return b;
}


Matrica hv(Matrica a){
	auto b(h(a));
	auto c(v(b));
	return c;
}



Matrica OgledaloMatrica(Matrica a){
	if(a.size()==0) return {};
	if(a[0].size()==0) return KreirajMatricu(a.size()*3,0);
	bool grbava(false);
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++)
		if(a[i].size()!=a[j].size()) grbava=true;
	}
	if(grbava) throw std::domain_error("Matrica nije korektna");
	auto m=KreirajMatricu(BrojRedova(a)*3,BrojKolona(a)*3);
	if(BrojRedova(m)==0) return {};
	auto kombinovana(hv(a));
	auto vertikalna(v(a));
	auto horizontalna(h(a));
	int brojac1(0);
	int brojac2(0);

	
	for(int i=0;i<BrojRedova(m);i++){
				
		for(int j=0;j<BrojKolona(m);j++){
			if(i==BrojRedova(a) || i==BrojRedova(a)*2) brojac1=0;
			if(j==BrojKolona(a) || j==BrojKolona(a)*2 || j==BrojKolona(a)*3) brojac2=0;
			
			
			if((i<BrojRedova(a) && j<BrojKolona(a)))
			m[i][j]=kombinovana[brojac1][brojac2];
			else if(i>BrojRedova(a)*2-1 && j<BrojKolona(a))
			m[i][j]=kombinovana[brojac1][brojac2];
			else if(i>BrojRedova(a)*2-1 && j>BrojKolona(a)*2-1)
			m[i][j]=kombinovana[brojac1][brojac2];
			else if((i>BrojRedova(a)-1 && j<BrojKolona(a)) || (i>BrojRedova(a)-1 && j>BrojKolona(a)*2-1))
			m[i][j]=horizontalna[brojac1][brojac2];
			else if(i<BrojRedova(a) && j>BrojKolona(a)*2-1)
			m[i][j]=kombinovana[brojac1][brojac2];
			else if((i<BrojRedova(a) && j>BrojKolona(a)-1) || (i>2*BrojRedova(a)-1 && j>BrojKolona(a)-1))
			m[i][j]=vertikalna[brojac1][brojac2];
			
			else m[i][j]=a[brojac1][brojac2];
		
			brojac2++;
		
			
		}
			brojac2=0;
			brojac1++;
	}
	
	
return m;
}



int main ()
{
	try{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(n<0 || m<0 ){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica a(UnesiMatricu(m,n));
	std::cout<<std::endl;
	std::cout<<"Rezultantna matrica:"<<std::endl;
	IspisiMatricu(OgledaloMatrica(a));
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}

	return 0;
}