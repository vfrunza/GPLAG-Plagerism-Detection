/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>

using namespace std;

template <typename t>

int RastavitNaProsteFaktore(int n) {
int b,k;
int br=0;
if(n==1) br++;; 
else{
int k=n%2;
while(k==0){
        b=n/2;
        n=b;
        k=n%2;
        br++;
    	} 
    
    }
return br;
}

t SortirajPodrucjeVrijednosti(t *pocetak, t *kraj,int *poc, int *kra,t f(t a, t b), bool g(t c, t d)) {
	
	for(int i=pocetak; i<kraj; i++) {
		for(int j=i; j<kraj; j++) {
			if(RastavitNaProsteFaktore(i)>RastavitNaProsteFaktore(j)) {
				t temp=v1[i];
				v1[i]=v2[j];
				v2[j]=temp;
					if(RastavitNaProsteFaktore(i)==RastavitNaProsteFaktore(j)) {
					
					}
				
			}
		}
	}
	
			
	
}


int main ()
{
	int a;
	vector<int>v1,v2,v3;
	cout<<"Unesite broj elemenata: ";
	cin>>a;
	
	v1.resize(a);
	v2.resize(a);
	v3.resize(a);
	
	cout<<"Unesite elemente prvog vektora: ";
		for(int i=0; i<v1.size(); i++) {
			cin>>v1[i];
		}
		
	cout<<"Uneiste elemente drugog vektora: ";
		for(int i=0; i<v2.size(); i++) {
			cin>>v2[i];
		}
		
	cout<<"Uneiste elemente treceg vektora: ";
		for(int i=0; i<v3.size(); i++) {
			cin>>v3[i];
		}
		
try {
	
	cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
		for(int i=0; i< ;i++) {
			cout<<" ";
			}
	}
	catch(logic_error) {
		cout<<"Izuzetak: Vrijednost koja odgovara nekom od parova nije nadjena";
	}
		
	
	return 0;
}