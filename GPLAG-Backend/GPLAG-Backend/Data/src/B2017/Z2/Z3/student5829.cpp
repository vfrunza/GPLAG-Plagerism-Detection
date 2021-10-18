/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using std::vector;
using std::cout;
using std::cin;
const int EPS=0.001;

template<typename NekiTip>
	bool TestPerioda(vector<NekiTip> &vect, int p){
		int i(0);
		if(p>=vect.size() || p==0) return false;
		while(i!=vect.size()-p){
			if(vect[i]-vect[i+p]>EPS || vect[i+p]-vect[i]>EPS) return false;
			i++;
		}
		return true;
	}

template<typename NekiTip>
	int OsnovniPeriod(vector<NekiTip> vect){
		if(vect.size()<=2) return 0;
		for(int i(1);i<vect.size();i++){
			if(TestPerioda(vect,i)) return i;
		}
		return 0;
	}
	
template<typename NekiTip>
	int BrojElemenata(const vector<NekiTip> &vect, int koliko_puta, int period){
		int suma(0);
		for(int i(0);i<koliko_puta;i++){
			for(int j(0);j<period;j++){
				suma+=(int)vect[j];
			}
		}
		return suma;
	}

template<typename NekiTip>
	int **AlocirajFragmentirano(const vector<NekiTip> &vect, int &koliko_puta){
		if(vect.size()==0) throw "Prazan vektor!";
		for(int i(0);i<vect.size();i++) if(vect[i]<=0) throw std::domain_error("Neispravan vektor!");
		int period(OsnovniPeriod(vect));
		if(period==0){
			koliko_puta=2;
			period=vect.size();
		}
		else{
			koliko_puta=vect.size()/period;
			if(vect.size()%period!=0) koliko_puta++;
		}
		int **din_mat(nullptr);
		din_mat=new int*[period*koliko_puta];
		for(int i(0);i<period*koliko_puta;i++) din_mat[i]=nullptr;
		try{
			int j(0);
			for(int i(0);i<koliko_puta*period;i++){
					din_mat[i]=new int[(int)vect[j]];
					for(int k((int)vect[j]-1);k>=0;k--) din_mat[i][k]=(int)vect[period-1]-(int)vect[j]+k+1;
					j++;
					if(j==period) j=0;
			}
			return din_mat;
		}
		catch(...){
			for(int i(0);i<period*koliko_puta;i++) delete[] din_mat[i];
			delete[] din_mat;
			throw;
		}
	}

template<typename NekiTip>
	int **AlocirajKontinualno(const vector<NekiTip> &vect, int &koliko_puta){
		if(vect.size()==0) throw "Prazan vektor!";
		for(int i(0);i<vect.size();i++) if(vect[i]<=0) throw std::domain_error("Neispravan vektor!");
		int period(OsnovniPeriod(vect));
		if(period==0){
			koliko_puta=2;
			period=vect.size();
		}
		else{
			koliko_puta=vect.size()/period;
			if(vect.size()%period!=0) koliko_puta++;
		}
		int **din_mat(nullptr);
		din_mat=new int*[period*koliko_puta];
		for(int i(0);i<period*koliko_puta;i++) din_mat[i]=nullptr;
		try{
			din_mat[0]=new int[BrojElemenata(vect,koliko_puta,period)];
			int k(0);
			for(int i(1);i<period*koliko_puta;i++){
				din_mat[i]=din_mat[i-1]+(int)vect[k];
				k++;
				if(k==period) k=0;
			}
			k=0;
			for(int i(0);i<period*koliko_puta;i++){
				for(int j(0);j<(int)vect[k];j++){
					din_mat[i][j]=(int)vect[k]-j;
				}
				k++;
				if(k==period) k=0;
			}
			return din_mat;
		}
		catch(...){
			delete[] din_mat[0];
			delete[] din_mat;
			throw;
		}
	}

int main ()
{
	int n(0);
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	try{
		cout<<"Unesite elemente vektora: ";
		vector<int> vect(n);
		for(int i(0);i<n;i++){
			int k(0);
			cin>>k;
			vect[i]=k;
		}
		int koliko_puta(0),f(0);
		cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		cin>>f;
		if(f){
			int **din_mat(AlocirajFragmentirano(vect,koliko_puta));
			int period(OsnovniPeriod(vect));
			if(period==0) period=vect.size();
			int k(0);
			cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i(0);i<koliko_puta*period;i++){
						for(int j(0);j<(int)vect[k];j++){
						 cout<<std::left<<std::setw(3)<<din_mat[i][j];
						}
						cout<<std::endl;
						k++;
						if(k==period) k=0;
					}
			for(int i(0);i<period*koliko_puta;i++) delete[] din_mat[i];
			delete[] din_mat;
		}
		else{
			int **din_mat(AlocirajKontinualno(vect,koliko_puta));
			int period(OsnovniPeriod(vect));
			if(period==0) period=vect.size();
			int k(0);
			cout<<"Dinamicki alocirana matrica:"<<std::endl;
			for(int i(0);i<period*koliko_puta;i++){
				for(int j(0);j<(int)vect[k];j++){
					cout<<std::left<<std::setw(3)<<din_mat[i][j];
				}
				cout<<std::endl;
				k++;
				if(k==period) k=0;
			}
			delete[] din_mat[0];
			delete[] din_mat;
		}
	}
	catch(const char izuzetak[]){
		cout<<"Izuzetak: "<<izuzetak;
	}
	catch(std::domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch(std::bad_alloc izuzetak){
		cout<<"Izuzetak: Nedovoljno memorije!";
	}
	
	return 0;
}