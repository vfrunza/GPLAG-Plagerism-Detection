/*B 2016/2017, Zadaća 1, Zadatak 2*/
#include <iostream>
#include <vector> //pa nam neće trebati #include<utility> za funkciju move
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;
using std::cin; using std::cout;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double> (br_kolona));
}
int BrojRedova(Matrica m){
	return m.size();
}
int BrojKolona(Matrica m){
	if(BrojRedova(m) == 0) return 0; 	//jer ako je BrojRedova == 0 ne smije se ni pozvati fja
	return m[0].size(); //slučaj: isključivo prava a ne grbava matrica
}
Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for (int i{}; i < br_redova; i++){
		for (int j{}; j < br_kolona; j++){
			cin >> m[i][j];
		}
	}
	return m;
}
void IspisiMatricu(Matrica m){
	for (std::vector<double> red : m){	//uzima red po red
		for(double x : red) cout << std::setw(4) << x;
		cout << std::endl;
	}
}

// bitno: matricu proslijeđenu funkciji spasi u novu matricu 
Matrica HorizOgledaloMatrica (Matrica m){	// vraća horizontalnu ogledalo matricu (od matrice m)
	Matrica hm(m); 	//matricu hm inicijaliziram na vrijednosti matrice m, iste su sada
	int br_redova(BrojRedova(hm)), br_kolona(BrojKolona(hm)); 	//br_redova dobija vrijednost vrijednosti vraćene iz fje BrojRedova od matrice hm (ista priča za br_kolona)
	for(int i{}; i < br_redova; i++){
		for(int j{}; j < br_kolona; j++) hm[i][j] = m[i][br_kolona-1-j];
	}
	return hm;
}
Matrica VertOgledaloMatrica (Matrica m){ //fja vraća matricu vertikalno ogledalo od matrice m
	Matrica vm(m); 	//vertikalna matrica sad je ista kao matrica m
	int br_kolona(BrojKolona(vm)), br_redova(BrojRedova(vm));
	for(int i{}; i < br_kolona; i++){
		for(int j{}; j < br_redova; j++){
			vm[j][i] = m[(br_redova-1)-j][i]; //koordinate: prvo j pa onda i(kao x i y)
		}
	}
	return vm;
}
Matrica HiVOgledaloMatrica (Matrica m){
	Matrica hvm(m); //i horiz. i vetik. izmjena članova matrice m
	hvm = VertOgledaloMatrica(hvm);
	hvm = HorizOgledaloMatrica(hvm);
	return hvm;
}

Matrica OgledaloMatrica(Matrica m){
	bool grbava(false); //prepostavljamo da nije grbava
	for(int i{}; i < m.size(); i++) {//m.size() <--redovi
			if (m[i].size() != m[0].size()) {grbava = true; break;}
	}
	if (grbava) throw std::domain_error("Matrica nije korektna");
	int br_redova(BrojRedova(m)), br_kolona(BrojKolona(m));
	int br_redove_mvelike(3*br_redova), br_kolona_mvelike(3*br_kolona);	//kreiranje matrice od 3*..redova i 3*...kolona
	Matrica mvelika(br_redove_mvelike, std::vector<double> (br_kolona_mvelike));
	Matrica mpromjeniva(m);
	Matrica h(HorizOgledaloMatrica(m));
	Matrica v(VertOgledaloMatrica(m));
	Matrica hv(HiVOgledaloMatrica(m));
	
	/*	 0 0 1 1 2 2
		 _ _ _ _ _ _ kpk
	0	|
	0	|
	1	|
	1	|
	2	|
	2	|
		kpp				*/
	
	int koji_put_p{}; 	//: 0 ili 1 ili 2 KOJI PUT P
	for(int i{}, p{}; i < br_redove_mvelike; i++){
			int koji_put_k{}; 	//koji put po redu je dostignut kraj male matrice (tj k - 1): 0 ili 1 ili 2
			for (int j{}, k{}; j < br_kolona_mvelike; j++){
				
			if(koji_put_p % 2 == 0 && koji_put_k == 1) mpromjeniva = v;
			else if (koji_put_p == 1 && koji_put_k % 2 == 0) mpromjeniva = h;
			else if (koji_put_p == 1 && koji_put_k == 1) mpromjeniva = m;
			else mpromjeniva = hv;
			mvelika[i][j] = mpromjeniva[p][k]; 	//šalta k i j istovremeno (k to mi je kao j(ot), p kao i)
			
			if (k == br_kolona - 1){
				k = -1; 	//da bi krenulo od nule (jer će se povećati za 1 u sljedećoj 'iteraciji')
				koji_put_k++;  
			}
			k++;
		}
		if (p == br_redova - 1 && (koji_put_p == 0 || koji_put_p == 1))	{
			p = -1; //da bi p krenulo od nule	
			koji_put_p++;
		}
		p++;
	}
	return mvelika;
}


int main (){
//	cin.ignore(10000, '\n'); //brisanje spremnika
	cout << "Unesite dimenzije matrice (m n): ";
	int a, b;
	cin >> a >> b;
	if(a < 0 || b < 0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cin.ignore(10000, '\n');
try{
	cout << "Unesite elemente matrice: "; 
	Matrica m(UnesiMatricu(a, b));
	cout << std::endl << "Rezultantna matrica: " << std::endl;
	Matrica velikam(OgledaloMatrica(m));
	IspisiMatricu(velikam);
}	
catch (std::domain_error izuzetak){
	cout << izuzetak.what() << std::endl;
}

	return 0;
}