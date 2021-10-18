#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
typedef std::vector<double>Vektor;
typedef std::vector<std::vector<double>>Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i=0;i<br_redova;i++)
	for(int j=0;j<br_kolona;j++){
		cin>>m.at(i).at(j);
	}
	return m;	
	}
	
void IspisiMatricu(Matrica m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m.at(i).size();j++)
		cout<<std::setw(4)<<m.at(i).at(j);
		cout<<endl;
	}
}
int BrojRedova(Matrica m){
	return m.size();
}
int BrojKolona(Matrica m){
	return m.at(0).size();
}

Matrica HorizontalnoOgledalo(Matrica M){
	Matrica m1(M.size());
	for(int i=0;i<BrojRedova(M);i++){
		for (int j=BrojKolona(M)-1;j>=0;j--){
			m1.at(i).push_back(M.at(i).at(j));
		}
	}
	return m1;
}

Matrica VertikalnoOgledalo(Matrica M){
	Matrica m2;
	for(int i=0;i<BrojRedova(M);i++){
		m2.push_back(M.at(BrojRedova(M)-1-i));
	}
	return m2;
}
	
Matrica KombinovanoOgledalo(Matrica M){
	Matrica m2(M.size());
	m2=HorizontalnoOgledalo(VertikalnoOgledalo(M));
	return m2;
}

Vektor ViseVektora(Vektor PrviDio, Vektor DrugiDio, Vektor TreciDio){
	for(int i=0;i<DrugiDio.size();i++)PrviDio.push_back(DrugiDio.at(i));
	for(int i=0;i<TreciDio.size();i++)PrviDio.push_back(TreciDio.at(i));
	return PrviDio;
}

Matrica OgledaloMatrica(Matrica M){
	for(int i=0;i<M.size();i++){
		if(M[0].size()!=M[i].size())throw std::domain_error("Matrica nije korektna");
	}
	Matrica OGLEDALO;
	Matrica Mv=VertikalnoOgledalo(M);
	Matrica Mh=HorizontalnoOgledalo(M);
	Matrica Mvh=KombinovanoOgledalo(M);
	for(int i=0;i<BrojRedova(M);i++)OGLEDALO.push_back(ViseVektora(Mvh.at(i),Mv.at(i),Mvh.at(i)));
	for(int i=0;i<BrojRedova(M);i++)OGLEDALO.push_back(ViseVektora(Mh.at(i),M.at(i),Mh.at(i)));
	for(int i=0;i<BrojRedova(M);i++)OGLEDALO.push_back(ViseVektora(Mvh.at(i),Mv.at(i),Mvh.at(i)));
	return OGLEDALO;
}

int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice: ";
	cout<<endl;
	Matrica A(UnesiMatricu(m,n));
	try {
	
	
	Matrica B(OgledaloMatrica(A));
	cout<<"Rezultantna matrica: "<<endl;
	IspisiMatricu(B);
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
		
	
	
	
	return 0;
}