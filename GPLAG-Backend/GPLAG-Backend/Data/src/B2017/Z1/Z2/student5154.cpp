/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
	0 0 0 15 12 6 1 25 1 5 2 9 1 1 20 15 10 5 3 2 19 130 14 8 90 6 20 12 17 2 12 3 5 1 8 4
*/
#include <iostream>
#include <vector>
#include <iomanip> 
#include <stdexcept>

using namespace std;

typedef std::vector<vector<double>> Matrica;

double NajveciVrh(vector<double> ma) {
	double maks(ma.at(0));
	for(int i(1);i<ma.size();i++) {
		if(ma.at(i)>maks) maks=ma.at(i);
	}
	return maks;
}


double Suma(Matrica mat, double vrh, int r) {
	double suma(0),suma1(0),suma2(0),suma3(0),suma4(0);
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat.at(i).size();j++) {
			if(mat.at(i).at(j)==vrh) {
				int k(i), l(j);
					for(int n(0);n<r*2+1;n++) {
					if(k-r>mat.at(i).size() or k-r<0 or l-r>mat.at(i).size() or l-r<0 or
					k-r+n>mat.at(i).size() or k-r+n<0 or l-r+n>mat.at(i).size() or l-r+n<0)	return suma;
					suma1+=mat.at(k-r).at(l-r+n);
					suma2+=mat.at(k-r+n).at(l-r);
					suma3+=mat.at(k+r).at(l-r+n);
					suma4+=mat.at(k-r+n).at(l+r);
					}
				suma=suma1+suma2+suma3+suma4-(mat.at(k-r).at(l-r)+mat.at(k+r).at(l-r)+mat.at(k-r).at(l+r)+mat.at(k+r).at(l+r));
				return suma;
			}
		}
	}
	return suma;
}

bool Grbava(Matrica mat) {
	for(int i(0);i<mat.size();i++) {
		for(int j(0);j<mat.size();j++) {
			if(mat.at(i).size()!=mat.at(j).size()) return true;
		}
	}
	return false;
}



Matrica NajvecaPlaninaMatrice(Matrica ma) {
	Matrica maa;
	bool grbava(Grbava(ma));
	double maks(NajveciVrh(ma.at(0))), suma1(0), suma2(0);
	int r(1),h(0),k(1),l(1);
	for(int i(1);i<ma.size()-1;i++) {
		for(int j(1);j<ma.at(i).size()-1;j++) {
			if(grbava) throw domain_error ("Matrica nije korektna");
			if(NajveciVrh(ma.at(i))>maks) {
				maks=NajveciVrh(ma.at(i));
				k=i;
				for(int s(0);s<ma.at(k).size();s++) {
					if(maks==ma.at(k).at(s)) l=s;
				}
			}
		}
	}
	
	for(;;) {
		suma1=Suma(ma,maks,r);	
		if(suma1>=maks) break;
		if(h>0) {
			if(suma1>=suma2) {
			r--;
			break;
			}
		}
		r++;
		if(r*2+1>ma.size() or r*2+1>ma.at(0).size()) {
			r--;
			break;
		}
		suma2=Suma(ma,maks,r);
		if(suma2>=suma1) {
			r--;
			break;
		}
		r++;
		if(r*2+1>ma.size() or r*2+1>ma.at(0).size()) {
			r--;
			break;
		}
		h++;
	}
	
	Matrica mat;
	mat.resize(2*r+1);
	for(int i(0);i<2*r+1;i++) {
		mat.at(i).resize(r*2+1);
	}
	
	for(int i(0);i<mat.size();i++) {
		for(int j(0);j<mat.at(i).size();j++) {
			mat.at(i).at(j)=ma.at(k-r+i).at(l-r+j);
		}
	}
	return mat;
}

int main ()
{
	try {
		int m,n;
		cout<<"Unesite dimenzije matrice (m i n): ";
		cin>>m>>n;
		if(m<0 or n<0) {
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		cout<<"Unesite elemente matrice: ";
		Matrica ma(m,std::vector<double> (n));
		for(int i(0);i<m;i++) {
			for(int j(0);j<n;j++) {
				cin>>ma.at(i).at(j);
			}
		}
		if(m==1) {
			cout<<endl<<"Najveca planina unesene matrice je: "<<endl<<setw(6)<<NajveciVrh(ma.at(0));
			return 0;
		}
		Matrica ma1(NajvecaPlaninaMatrice(ma));
		cout<<endl<<"Najveca planina unesene matrice je: "<<endl;
		for(int i(0);i<ma1.size();i++) {
			for(int j(0);j<ma1[0].size();j++) {
				cout<<setw(6)<<ma1.at(i).at(j);
			}
			cout<<endl;
		}
	}
	catch(domain_error izuzetak) {
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	return 0;
}