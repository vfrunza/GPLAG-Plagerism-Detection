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

typedef std::vector<std::vector<double>> matrica;

matrica OgledaloMatrica(matrica m){
	int redovi(m.size());
	int kolone(0);
	if(m.size()>0){
		kolone = m[0].size();
	}
	matrica hor (redovi, std::vector<double> (kolone));
	matrica ver (redovi, std::vector<double> (kolone));
	matrica komb1 (redovi, std::vector<double> (kolone));
	matrica komb (redovi, std::vector<double> (kolone));
	int k, s;
	
	bool dalijegrbava(false);
	int brojac_test;
	for(int i=0;i<m.size();i++){
		brojac_test = kolone;
		if(m[i].size() != brojac_test){dalijegrbava=true; break;}
	}
	if(dalijegrbava){
		throw std::domain_error("Matrica nije korektna");
	}
	
	for(int i=0;i<m.size();i++){
		k=0;
		for(int j=m[i].size()-1;j>=0;j--){ //kreiranje horizontalne
			hor[i][k]=m[i][j];
			k++;
		}
	}
	s=0;
	for(int j=0;j<kolone;j++){
	k=0;
		for(int i=m.size()-1;i>=0;i--){ //kreiranje vertikalne
			ver[k][s]=m[i][j];
			k++;
		}
		s++;
	}
	
	
	s=0;
	for(int j=0;j<kolone;j++){
	k=0;
		for(int i=m.size()-1;i>=0;i--){ //kreiranje komb\vert/
			komb1[k][s]=m[i][j];
			k++;
		}
		s++;
	}
	for(int i=0;i<m.size();i++){
		k=0;
		for(int j=m[i].size()-1;j>=0;j--){ //kreiranje komb\horiz/
			komb[i][k]=komb1[i][j];
			k++;
		}
	}
	matrica velika(redovi*3, std::vector<double> (kolone*3));
		
	//upisivanje kombinovane /1.1.
	for(int i=0;i<redovi;i++){
		for(int j=0;j<kolone;j++){
			velika[i][j]=komb[i][j];
		}
	}

		//upisivanje vertikalne /1.2.
	for(int i=0;i<redovi;i++){
		k=0;
		for(int j=kolone;j<kolone*2;j++){
			velika[i][j]=ver[i][k];
			k++;
		}
	}
		//upisivanje kombinovane /1.3.
	for(int i=0;i<redovi;i++){
		k=0;
		for(int j=kolone*2;j<kolone*3;j++){
			velika[i][j]=komb[i][k];
			k++;
		}
	}
		//upisivanje horizontalne /2.1.
		s=0;
	for(int i=redovi;i<redovi*2;i++){
		for(int j=0;j<kolone;j++){
			velika[i][j]=hor[s][j];
		}
		s++;
	}
		//upisivanje originalne /2.2.
		s=0;
	for(int i=redovi;i<redovi*2;i++){
		k=0;
		for(int j=kolone;j<kolone*2;j++){
			velika[i][j]=m[s][k];
			k++;
		}
		s++;
	}
		//upisivanje horizontalne /2.3.
		s=0;
	for(int i=redovi;i<redovi*2;i++){
		k=0;
		for(int j=kolone*2;j<kolone*3;j++){
			velika[i][j]=hor[s][k];
			k++;
		}
		s++;
	}
	//upisivanje kombinovane /3.1.
	s=0;
	for(int i=redovi*2;i<redovi*3;i++){
		for(int j=0;j<kolone;j++){
			velika[i][j]=komb[s][j];
		}
		s++;
	}
	//upisivanje vertikalne /3.2.
	s=0;
	for(int i=redovi*2;i<redovi*3;i++){
		k=0;
		for(int j=kolone;j<kolone*2;j++){
			velika[i][j]=ver[s][k];
			k++;
		}
		s++;
	}
	//upisivanje kombinovane /3.3.
	s=0;
	for(int i=redovi*2;i<redovi*3;i++){
		k=0;
		for(int j=kolone*2;j<kolone*3;j++){
			velika[i][j]=komb[s][k];
			k++;
		}
		s++;
	}

	return velika;
}


int main ()
{
	using std::cout; using std::cin;
	int br, brk;
	matrica GLAVNA;
	
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> br >> brk;
	if(br<0 || brk<0 || !cin){cout << "Dimenzije matrice moraju biti nenegativne!"; return 0;}
	matrica mat(br, std::vector<double> (brk));
	cout << "Unesite elemente matrice: ";
	for(int i=0;i<br;i++){
		for(int j=0;j<brk;j++){
			cin >> mat[i][j];
		}
	}
	try{
	GLAVNA = OgledaloMatrica(mat);
	cout << "\nRezultantna matrica: \n";
	for(auto x : GLAVNA){
		for(auto y : x){
			cout << std::setw(4) << std::right << y;
		}
		cout << "\n";
	}
	}
	catch(std::domain_error cigla){
		cout << cigla.what();
	}
	return 0;
}