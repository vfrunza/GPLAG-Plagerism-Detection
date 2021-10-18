/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool DaLiJeOpak (int n) {
	int br0(0), br1(0), br2(0), cifra(0);
	while (n!=0) {
		cifra=n%3;
		if (cifra==0) br0++;
		if (cifra==1) br1++;
		if (cifra==2) br2++;
		n/=3;
	}
	if ((br0%2==0 && br1%2==0 && br2%2==0) || (br0%2==0 && br1%2==0 && br2==0) || (br0%2==0 && br1==0 && br2%2==0) ||
	    (br0==0 && br1%2==0 && br2%2==0) || (br0%2==0 && br1==0 && br2==0) || (br0==0 && br1%2==0 && br2==0) ||
	    (br0==0 && br1==0 && br2%2==0) || (br0==0 && br1==0 && br2==0)) 
	    return true;
    return false;
}

bool DaLiJeOdvratan (int n) {
	int br0(0), br1(0), br2(0), cifra(0);
	while (n!=0) {
		cifra=n%3;
		if (cifra==0) br0++;
		if (cifra==1) br1++;
		if (cifra==2) br2++;
		n/=3;
	}
	if ((br0%2!=0 && br1%2!=0 && br2%2!=0) || (br0%2!=0 && br1%2!=0 && br2==0) || (br0%2!=0 && br1==0 && br2%2!=0) ||
	    (br0==0 && br1%2!=0 && br2%2!=0) || (br0%2!=0 && br1==0 && br2==0) || (br0==0 && br1%2!=0 && br2==0) ||
	    (br0==0 && br1==0 && br2%2!=0))
	    return true;
    return false;
}

bool DaLiVecPostoji (int n, std::vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		if (n==v[i]) return true;
	}
	return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool a) {
	std::vector<int> v1;
	if (a) {
	    for (int i=0; i<v.size(); i++) {
		    if (DaLiJeOpak(v[i]) && DaLiVecPostoji(v[i],v1)==false)
		        v1.push_back(v[i]);
	    }
	}
	if (a==false) {
	    for (int i=0; i<v.size(); i++) {
		    if (DaLiJeOdvratan(v[i]) && DaLiVecPostoji(v[i],v1)==false)
		        v1.push_back(v[i]);
	    }
	}
	return v1;
}

int main ()
{
	std::vector<int> v2;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do {
		std::cin >> broj;
		if (broj!=0) v2.push_back(broj);
	} while (broj!=0);
	std::vector<int> v3;
	v3=IzdvojiGadne(v2,true);
	std::cout << "Opaki: ";
	for(int i=0; i<v3.size(); i++)
	    std::cout << v3[i] << " ";
	std::cout << std::endl;
	std::vector<int> v4;
	v4=IzdvojiGadne(v2,false);
	std::cout << "Odvratni: ";
	for(int i=0; i<v4.size(); i++)
	    std::cout << v4[i] << " ";
	return 0;
}