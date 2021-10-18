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
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;
Matrica OgledaloMatrica(Matrica m){
	//provjera da li je rijec o grbavoj matrici
	bool grbava=false;
	for(int i=0; i<m.size(); i++){
		int referenti_broj=m[0].size();
		if(m[i].size()!=referenti_broj) {
			grbava=true;
			break;
		}
	}
	if(grbava) throw std::domain_error("Matrica nije korektna");
	int BrojRedova(m.size());
	int BrojKolona(0);
	Matrica hm, vm, hvm;
	//svakoj od novih matrica zadajemo potrebni format 
	hm.resize(BrojRedova);
	vm.resize(BrojRedova);
	hvm.resize(BrojRedova);
	for(int i=0; i<BrojRedova; i++){
		if(i==0) BrojKolona=m[i].size();
		hm[i].resize(BrojKolona);
		vm[i].resize(BrojKolona);
		hvm[i].resize(BrojKolona);
	}
	//dvostruka for-petlja kojom h(M) matrici(u programu nazvanoj "hm" zadajemo elemente po trazenom redoslijedu
	//takodjer na isti nacin formiramo i matricu hv(M) da bi joj u sljedecem bloku naredbi obrnuli i redove, te dobili trazenu matricu
	for(int i=0; i<BrojRedova; i++){
		for(int j=0; j<BrojKolona; j++){
			hm[i][j]=m[i][BrojKolona-1-j];
			hvm[i][j]=m[i][BrojKolona-1-j];
		}
	}
	//dvostruka for-petlja kojom v(M) matrici(u programu nazvanoj "vm") zadajemo elemente po trazenom redoslijedu
	//takodjer i hvm matrici mijenjamo redoslijed elemenata u redovima, te formiramo i zadanu hvm matricu
	for(int j=0; j<BrojKolona; j++){
		for(int i=0; i<BrojRedova; i++){
			vm[i][j]=m[BrojRedova-1-i][j];
			hvm[i][j]=hm[BrojRedova-1-i][j];
		}
	}
	//fomiramo Ogledalo matricu formata 3m x 3n
	int BrojRedovaOgledala(BrojRedova*3);
	int BrojKolonaOgledala(BrojKolona*3);
	Matrica ogledalo;
	ogledalo.resize(BrojRedovaOgledala);
	for(int i=0; i<BrojRedovaOgledala; i++)
		ogledalo[i].resize(BrojKolonaOgledala);
	//dvostruka for-petlja kojom cemo Ogledalo matrici zadati elemente na trazeni nacin
	for(int i=0; i<BrojRedovaOgledala; i++){
		for(int j=0; j<BrojKolonaOgledala; j++){
			//uslovi koji odredjuju popunjavanje ogledalo matrice elementima hvm matrice
			if(i<BrojRedova && j<BrojKolona) ogledalo[i][j]=hvm[i][j];
			if(i>=BrojRedova*2 && j<BrojKolona) ogledalo[i][j]=hvm[i-BrojRedova*2][j];
			if(i<BrojRedova && j>=BrojKolona*2) ogledalo[i][j]=hvm[i][j-BrojKolona*2];
			if(i>=BrojRedova*2 && j>=BrojKolona*2) ogledalo[i][j]=hvm[i-BrojRedova*2][j-BrojKolona*2];
			//uslovi koji odredjuju popunjavanje ogledalo matrice elementima hm matrice
			if((i>=BrojRedova && i<BrojRedova*2) && j<BrojKolona) ogledalo[i][j]=hm[i-BrojRedova][j];
			if((i>=BrojRedova && i<BrojRedova*2) && j>=BrojKolona*2) ogledalo[i][j]=hm[i-BrojRedova][j-BrojKolona*2];
			//if uslovi koji odredjuju popunjavanje ogledalo matrice elementima vm matrice
			if((j>=BrojKolona && j<BrojKolona*2) && i<BrojRedova) ogledalo[i][j]=vm[i][j-BrojKolona];
			if((j>=BrojKolona && j<BrojKolona*2) && i>=BrojRedova*2) ogledalo[i][j]=vm[i-BrojRedova*2][j-BrojKolona];
			//uslovi koji odredjuju popunjavanje ogledalo matrice elementima funckiji zadane matrice
			if((i>=BrojRedova && i<BrojRedova*2) && (j>=BrojKolona && j<BrojKolona*2)) ogledalo[i][j]=m[i-BrojRedova][j-BrojKolona];
		}
	}
	return ogledalo;
}
int main ()
{	try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
	Matrica a;
	a.resize(m);
	for(int i=0; i<m; i++)
		a[i].resize(n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			std::cin >> a[i][j];
		}
	Matrica b(OgledaloMatrica(a));
	std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++)
		std::cout<<std::right<<std::setw(4)<<b[i][j];
		std::cout<<std::endl;
	}
	}}
	catch(std::domain_error izuzetak) {
      std::cout <<"IZUZETAK: "<<izuzetak.what() << std::endl;
   }
	return 0;
}