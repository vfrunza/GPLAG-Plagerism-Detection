/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>





using std::cout;
using std::cin;
using std::vector;

int Pretvori_u_terarni(int x){
	int tmp(x);
	int cifra;
	int broj(0);
	int i(0);
	
	while (tmp!=0){
		cifra=tmp%3;
		broj=pow(10,i)*cifra + broj;
		tmp=tmp/3;
		i++;
		
	}
	return broj;
}

vector<int> IzdvojiGadne(vector<int> v, bool O_Da_Li_Je){
	vector<int> vektor;
	
	
	if (O_Da_Li_Je){
		
		for (int i(0); i<v.size(); i++){
				int cifra;
				long int tmp,tmp2;
		int brojac0(0), brojac1(0), brojac2(0);
		
		
		
		
		brojac0=0;
		brojac1=0;
		brojac2=0;
		
			tmp2=v[i];
			v[i]=Pretvori_u_terarni(v[i]);
			if (v[i]<0) tmp=abs(v[i]);
			else tmp=v[i];
			if (tmp==std::numeric_limits<int>::min() || tmp==std::numeric_limits<int>::max()) continue;
			while (tmp!=0){
				cifra= tmp%10;
				if (cifra==0) brojac0++;
				if (cifra==1) brojac1++;
				if (cifra==2) brojac2++;
				tmp=tmp/10;
			}     
			
			 if(vektor.size()!=0 ) for(int j(0); j<vektor.size(); j++){
			 	if (tmp2==vektor[j]) goto ovdje;
			 	
			 }
			 if (brojac0%2==0 && brojac1%2==0 && brojac2%2==0) vektor.push_back(tmp2);
			ovdje: int a(0);
		
		}
	}
	else {
		
		for (int i(0); i<v.size(); i++){
				int cifra;
				long int tmp, tmp2;
		int brojac0(0), brojac1(0), brojac2(0);
		
		
	
		
		
		
		
			tmp2=v[i];
			v[i]=Pretvori_u_terarni(v[i]);
			if (v[i]==0) vektor.push_back(v[i]);
			if (v[i]<0) tmp=abs(v[i]);
			else tmp=v[i];
			if (tmp==std::numeric_limits<int>::min() || tmp==std::numeric_limits<int>::max()) continue;
			while (tmp!=0){
				cifra= tmp%10;
				if (cifra==0) brojac0++;
				if (cifra==1) brojac1++;
				if (cifra==2) brojac2++;
				tmp=tmp/10;
			} 
			
		 if(vektor.size()!=0 ) for(int j(0); j<vektor.size(); j++){
			 	if (tmp2==vektor[j]) goto ovdje1;
			 	
			 }
			 if (brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) vektor.push_back(tmp2);
			 if (brojac1==0 && brojac0%2!=0 && brojac2%2!=0)  vektor.push_back(tmp2);
			 if (brojac0==0 && brojac1%2!=0 && brojac2%2!=0)	vektor.push_back(tmp2);
			 if (brojac2==0 && brojac0%2!=0 && brojac1%2!=0)	vektor.push_back(tmp2);
			 if (brojac1==0 && brojac0==0 && brojac2%2!=0)	vektor.push_back(tmp2);
			 if (brojac1==0 && brojac2==0 && brojac0%2!=0)	vektor.push_back(tmp2);
			 if (brojac0==0 && brojac2==0 && brojac1%2!=0)	vektor.push_back(tmp2);
			ovdje1: int a(0);
			
		
		}
	}
	return vektor;
}

int main ()
{   
	cout << "Unesite brojeve (0 za prekid unosa): ";
	vector<int> brojevi;
	int n;
	do {
	
	cin >> n;
	if (n==0) break;
	else brojevi.push_back(n);
	} while (n!=0);
	
	vector<int> opaki;
	vector<int> odvratni;
	
	opaki=IzdvojiGadne(brojevi,true);
	odvratni=IzdvojiGadne(brojevi,false);
	
	cout << "Opaki: ";
	for (int x: opaki){
		cout << x << " ";
	}
	cout << std::endl;
	cout << "Odvratni: ";
	for (int y: odvratni){
		cout << y << " ";
	}

	return 0;
}