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

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova,int br_kolona) {
	if(br_redova<0 || br_kolona<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	return Matrica(br_redova,std::vector<double>(br_kolona));
}
int BrojRedova(Matrica m) {
	return m.size();
}
int BrojKolona(Matrica m) {
	if(BrojRedova(m)==0) return 0; else return m[0].size();
}
Matrica UnesiMatricu(int br_redova,int br_kolona) {
	if((br_redova<0 || br_kolona<0)) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	else if(br_redova==0 || br_kolona==0){
	;
	}
	auto m(KreirajMatricu(br_redova,br_kolona));
	std::cout << "Unesite elemente matrice:" << std::endl;
	for(int i=0;i<br_redova;i++)
	for(int j=0;j<br_kolona;j++)
	std::cin>>m[i][j];
	return m;
}
void IspisiMatricu(Matrica m) {
	for(int i=0;i<BrojRedova(m);i++) {
	for(int j=0;j<BrojKolona(m);j++)
	std::cout<<std::setw(4)<<m[i][j];
	std::cout<<std::endl;
}
}
Matrica v(Matrica mv) {
	for(int i=0;i<BrojRedova(mv)/2;i++)
		for(int j=0;j<BrojKolona(mv);j++)
			std::swap(mv[i][j],mv[BrojRedova(mv)-i-1][j]);
	return mv;
}
Matrica h(Matrica mh) {
	for(int j=0;j<BrojKolona(mh)/2;j++)
	for(int i=0;i<BrojRedova(mh);i++)
	std::swap(mh[i][j],mh[i][BrojKolona(mh)-j-1]);
	return mh;
}
Matrica OgledaloMatrica(Matrica x) {
	auto x3(KreirajMatricu(BrojRedova(x)*3,BrojKolona(x)*3));
	auto mh(KreirajMatricu(BrojRedova(x),BrojKolona(x)));
	auto mv(KreirajMatricu(BrojRedova(x),BrojKolona(x)));
	auto mhv(KreirajMatricu(BrojRedova(x),BrojKolona(x)));
	mh=h(x);
	mv=v(x);
	mhv=v(h(x));
	for(int i=0;i<BrojRedova(x);i++)
	for(int j=0;j<BrojKolona(x);j++)
	x3[i][j]=mhv[i][j];
	for(int i=0;i<BrojRedova(x);i++)
	for(int j=BrojKolona(x),jj=0;j<2*BrojKolona(x);j++,jj++)
	x3[i][j]=mv[i][jj];
	for(int i=0;i<BrojRedova(x);i++)
	for(int j=BrojKolona(x)*2,jj=0;j<BrojKolona(x)*3;j++,jj++)
	x3[i][j]=mhv[i][jj];
	for(int i=BrojRedova(x),ii=0;i<2*BrojRedova(x);i++,ii++)
	for(int j=0;j<BrojKolona(x);j++)
	x3[i][j]=mh[ii][j];
	for(int i=BrojRedova(x),ii=0;i<2*BrojRedova(x);i++,ii++)
	for(int j=BrojKolona(x),jj=0;j<2*BrojKolona(x);j++,jj++)
	x3[i][j]=x[ii][jj];
	for(int i=BrojRedova(x),ii=0;i<2*BrojRedova(x);i++,ii++)
	for(int j=BrojKolona(x)*2,jj=0;j<BrojKolona(x)*3;j++,jj++)
	x3[i][j]=mh[ii][jj];
	for(int i=2*BrojRedova(x),ii=0;i<3*BrojRedova(x); i++,ii++)
	for(int j=0;j<BrojKolona(x);j++)
	x3[i][j]=mhv[ii][j];
	for(int i=2*BrojRedova(x),ii=0;i<3*BrojRedova(x);i++,ii++)
	for(int j=BrojKolona(x),jj=0;j<2*BrojKolona(x);j++,jj++)
	x3[i][j]=mv[ii][jj];
	for(int i=2*BrojRedova(x),ii=0;i<3*BrojRedova(x);i++,ii++)
	for(int j=BrojKolona(x)*2,jj=0;j<BrojKolona(x)*3;j++,jj++)
	x3[i][j]=mhv[ii][jj];
	return x3;
}
int main ()
{
	try {
int m,n;
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>m>>n;

auto M(UnesiMatricu(m,n));
std::cout<<"Rezultantna matrica: "<<std::endl;
IspisiMatricu(OgledaloMatrica(M));
}
catch(std::domain_error izuzetak) {
	std::cout<<izuzetak.what()<<std::endl;
}
	return 0;
}