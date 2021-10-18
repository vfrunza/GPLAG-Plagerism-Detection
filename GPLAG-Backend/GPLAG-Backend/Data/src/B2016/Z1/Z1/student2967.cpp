/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> IzdvojiGadne(vector<int> v, bool vrijednost){
	vector<int> novi;
	vector<int> x,y;
	int kljuc1=0;
	int kljuc2=0;
	for(int i=0; i<v.size(); i++){
		
		int broj;
		broj=v[i];
	    int a, brojac1, brojac2, brojac3;
	    brojac1=0;
	    brojac2=0;
	    brojac3=0;
	    while(broj){
	    	a=(abs(broj%3));
	    	if(a==0){
	    		brojac1++;
	    	}
	    	if(a==1){
	    		brojac2++;
	    	}
	    	if(a==2){
	    		brojac3++;
	    	}
	    	broj=broj/3;
	    }
		
		if(brojac1%2==0 && brojac2%2==0 && brojac3%2==0){
			x.push_back(v[i]);
			kljuc1++;
		}
		
		if((brojac1==0 && brojac2%2!=0 && brojac3%2!=0) || (brojac2==0 && brojac1%2!=0 && brojac3%2!=0) || (brojac3==0 && brojac2%2!=0 && brojac1%2!=0) || (brojac1!=0 && brojac2!=0 && brojac3!=0 && brojac1%2!=0 && brojac2%2!=0 && brojac3%2!=0)){
			y.push_back(v[i]);
			kljuc2++;
		}
		
		
		
	}
	for(int i=0; i<kljuc1; i++){
		for(int j=i+1; j<kljuc1; j++){
			if(x[i]==x[j]){
				int shiftLeft=j;
				for(int k=j+1; k<kljuc1; k++, shiftLeft++){
					x[shiftLeft]=x[k];
				}
				kljuc1--;
				j--;
			}
		}
	}
	vector<int> whitelist1(kljuc1);
	for(int i=0; i<kljuc1; i++){
		whitelist1[i]=x[i];
	}
	
	for(int i=0; i<kljuc2; i++){
		for(int j=i+1; j<kljuc2; j++){
			if(y[i]==y[j]){
				int shiftLeft=j;
				for(int k=j+1; k<kljuc2; k++, shiftLeft++){
					y[shiftLeft]=y[k];
				}
				kljuc2--;
				j--;
			}
		}
	}
	vector<int> whitelist2(kljuc2);
	for(int i=0; i<kljuc2; i++){
		whitelist2[i]=y[i];
	}
	if(vrijednost==0){
		return whitelist2;
	}
	return whitelist1;
}

int main(){
	int n;
	vector<int> a;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		cin >> n;
		if(n!=0) a.push_back(n);
	} while(n!=0);

	
	vector<int> x;
	x=IzdvojiGadne(a,1);
	vector<int> b;
	
	cout << "Opaki: ";
	
	for(int i=0; i<b.size(); i++){
		cout << b[i] << " ";
	}
	vector<int> y;
	y=IzdvojiGadne(a,0);
	vector<int> c;
	
	cout << "\nOdvratni: ";
	for(int i=0; i<c.size(); i++){
		cout << c[i] << " ";
	}
	return 0;
	
}