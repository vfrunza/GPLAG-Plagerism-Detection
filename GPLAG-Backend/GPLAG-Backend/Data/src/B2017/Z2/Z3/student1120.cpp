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
#include <new>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;
	template<typename tip>
	bool jeliperiodican(const vector<tip> &v, int &period){
		tip el=v[0];
		int k(0);
		
		int i(1);
		while(v[i]!=el){
			period++;
			i++;
		}
		while(i!=v.size() && v[i]==v[k]){
			i++;
			k++;
		}
		if(i==v.size()){
		period+=1;
		return true;
		}
		else period=v.size();
		return false;
	}

	template<typename tip>
	tip **AlocirajFragmentirano(const vector<tip> &v, int &koliko_puta){
		if(v.size()==0)throw "Prazan vektor!";
		/*for(int i=0;i<v.size();i++){
			if(v[i]<0 || v[i]==0)throw domain_error("neispravan vektor");
		}*/
		int period(0);
		bool prom=jeliperiodican(v, period);
		if(prom){
			if(v.size()%period!=0){
				//int pom=v.size()%period;
				//copy(v.begin()+pom, v.begin()+period, back_inserter(v));
				koliko_puta=v.size()/period+1;
			}
			else if(v.size()%period==0)
			koliko_puta=v.size()/period;
			
			
		}
		else if(prom==false)
			
				koliko_puta=2;
				
			//copy(v.begin(), v.end(), back_inserter(v));
		
		int **pok=nullptr;
		try{
			pok=new int *[period*koliko_puta];
			try{
				int z(0);
				for(int i=0;i<period*koliko_puta;i++){
					
					pok[i]=new int[v[z]];
					
					z++;
					if(z==period)z=0;
				}
				
				tip maks=*(max_element(v.begin(), v.end()));
				int t(0);
				for(int k=0;k<period*koliko_puta;k++){
					tip maksi=maks;
				
					for(int m=v[t]-1;m>=0;m--){
					pok[k][m]=maksi;
					maksi--;
			
					}
					t++;
					if(t==period)t=0;
				}
			
		}
		catch(bad_alloc){
			for(int i=0;i<period*koliko_puta;i++)
			delete [] pok[i];
			delete [] pok;
			throw bad_alloc();
		}
		}
		catch(...){
			throw bad_alloc();
		}
		
		return pok;
	}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<int>v(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int broj;
		cin>>broj;
		v.push_back(broj);
	}
	int opcija;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>opcija;
	int broj(0);
	int spasi(0);
	bool prom=jeliperiodican(v, spasi);
	if(opcija==1){
		try{
			int z(0);
		int **pok=AlocirajFragmentirano<int>(v, broj);
		cout<<"Dinamicki alocirana matrica:";
		for(int i=0;i<spasi*broj;i++){
			for(int j=0;j<v[z];j++){
				
			cout<<left<<setw(3)<<pok[i][j];
			
			
			}
			z++;
			if(z==spasi)z=0;
			cout<<endl;
		}
		for(int i=0;i<spasi*broj;i++)
		delete [] pok[i];
		delete [] pok;
	}
	/*catch(const char []){
		cout<<"Prazan vektor!";
	}*/
	/*catch(domain_error e){
		cout<<e.what();
	}*/
	catch(bad_alloc){
		cout<<"alokacija neuspjesna";
	}
	catch(...){
		cout<<"Prazan vektor!";
	}
	
	}
	return 0;
}