/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool DaLiSuIsti(int n, std::vector<int> v) {
	for(int i=0;i<v.size();i++) {
		if(v[i]==n) return true;
	}
	return false;
}

std::vector<int> Ternarni(int n) {
	int cifra;
	std::vector<int> v;
	do {
		cifra=abs(n%3);
		v.push_back(cifra);
		n/=3;
	} while (n!=0);
	return v;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool tnt) {
	int brojac0,brojac1,brojac2;
	std::vector<int> pretvoreni,opaki,odvratni;
	for(int i=0;i<v.size();i++) {
		brojac0=0;brojac1=0;brojac2=0;
		pretvoreni=Ternarni(v[i]);
		if(i!=0) {
			if(DaLiSuIsti(v[i],opaki)) continue;
			if(DaLiSuIsti(v[i],odvratni)) continue;
		}
		for(int j=0;j<pretvoreni.size();j++) {
			if(pretvoreni[j]==0) brojac0++;
			if(pretvoreni[j]==1) brojac1++;
			if(pretvoreni[j]==2) brojac2++;
		}
		if(tnt) {
			if(brojac2!=0 && brojac1!=0 && brojac0!=0) {
				if(brojac2%2==0 && brojac1%2==0 && brojac0%2==0) opaki.push_back(v[i]);
			}
			else if (((brojac0%2==0)&&(brojac1%2==0)&&(brojac2==0))||((brojac0%2==0)&&(brojac1==0)&&(brojac2%2==0))||((brojac0==0)&&(brojac1%2==0)&&(brojac2%2==0))) opaki.push_back(v[i]);
			else if (((brojac0%2==0)&&(brojac1==0)&&(brojac2==0))||((brojac0==0)&&(brojac1==0)&&(brojac2%2==0))||((brojac0==0)&&(brojac1%2==0)&&(brojac2==0))) opaki.push_back(v[i]);
		}
		else {
			if(brojac2!=0 && brojac1!=0 && brojac0!=0) {
				if(brojac2%2!=0 && brojac1%2!=0 && brojac0%2!=0) odvratni.push_back(v[i]);
			}
			else if (((brojac0%2!=0)&&(brojac1%2!=0)&&(brojac2==0))||((brojac0%2!=0)&&(brojac1==0)&&(brojac2%2!=0))||((brojac0==0)&&(brojac1%2!=0)&&(brojac2%2!=0))) odvratni.push_back(v[i]);
			else if (((brojac0%2!=0)&&(brojac1==0)&&(brojac2==0))||((brojac0==0)&&(brojac1==0)&&(brojac2%2!=0))||((brojac0==0)&&(brojac1%2!=0)&&(brojac2==0))) odvratni.push_back(v[i]);
		}
	}
	if(tnt) return opaki;
	return odvratni;
}

int main ()
{
	std::vector<int> v;
	int x,k(0);
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin >> x;
		if(x==0 && k==0) {
			v.push_back(x);
    		break;	
		}
		else if(x!=0) v.push_back(x);
		k++;
	} while (x!=0);
	std::vector<int> a=IzdvojiGadne(v,true);
	std::cout << "Opaki: ";
	for(int i : a) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::vector<int> b=IzdvojiGadne(v,false);
	std::cout << "Odvratni: ";
	for(int i : b) {
		std::cout << i << " ";
	}
	return 0; 
}
