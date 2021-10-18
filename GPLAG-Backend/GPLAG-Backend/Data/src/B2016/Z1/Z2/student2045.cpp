#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return Matrica(broj_redova,std::vector<double>(broj_kolona));
}int BrojRedova(Matrica m){
	return m.size();
}int BrojKolona(Matrica m){
	return m[0].size();
}Matrica UnesiMatricu(int br_redova,int br_kolona){
	Matrica a(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++)
		for(int j=0;j<br_kolona;j++){
			std::cin>>a[i][j];
		}return a;
}void IspisiMatricu(Matrica m){
	for(int i=0;i<BrojRedova(m);i++){
		for(int j=0;j<BrojKolona(m);j++)
			
		
			std::cout<<" "<<m[i][j];
			std::cout<<std::endl;

}}Matrica OgledaloMatrica(Matrica a){
	Matrica m(KreirajMatricu(3*BrojRedova(a),3*BrojKolona(a)));
			if(BrojKolona(a)<0 || BrojRedova(a)<0) throw std::domain_error ("Matrica nije korektna");
	for(int i=0;i<BrojRedova(a);i++){
		for(int j=0;j<BrojKolona(a);j++){
			m[i][j]=a[BrojRedova(a)-i-1][BrojKolona(a)-j-1];
			m[i][j+BrojKolona(a)]=a[BrojRedova(a)-i-1][j];
			m[i][j+2*BrojKolona(a)]=a[BrojRedova(a)-i-1][BrojKolona(a)-j-1];
			m[i+BrojRedova(a)][j]=a[i][BrojKolona(a)-j-1];
			m[i+BrojRedova(a)][j+BrojKolona(a)]=a[i][j];
			m[i+BrojRedova(a)][j+2*BrojKolona(a)]=a[i][BrojKolona(a)-j-1];
			m[i+2*BrojRedova(a)][j]=a[BrojRedova(a)-i-1][BrojKolona(a)-j-1];
			m[i+2*BrojRedova(a)][j+BrojKolona(a)]=a[BrojRedova(a)-i-1][j];
			m[i+2*BrojRedova(a)][j+2*BrojKolona(a)]=a[BrojRedova(a)-i-1][BrojKolona(a)-j-1];
		}}return m;
}
int main (){
	try{
		std::cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		std::cin>>m;
		std::cin>>n;
		if(n<0 || m<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		else{
		std::cout<<"Unesite elemente matrice:";
		Matrica A=UnesiMatricu(m,n);
		Matrica B=OgledaloMatrica(A);
		std::cout<<"\nRezultantna matrica:\n";
		IspisiMatricu(B);
		}}catch(std::domain_error izuzetak){
			std::cout<<izuzetak.what()<<std::endl;
		}
	return 0;
}