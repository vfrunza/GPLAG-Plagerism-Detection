/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> PretvoriBrojeve (long long int n) {
	std::vector<int> v;
	if (n<0) n=(abs(n));
	
	while (n != 0) {
		v.push_back(n%3);
		n/=3;
	}
	return v;
}

std::vector<int> Ponavljanje(std::vector<int> v) {
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v[i]==v[j]) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}


bool Opaki(std::vector<int> v) {
	int br0(0), br1(0), br2(0);
	
	for(int i=0; i<v.size(); i++) {
		if (v[i]==0) br0++;
		else if (v[i]==1) br1++;
		else if (v[i]==2) br2++;
	}
 if((br0%2==0 && br1%2==0 && br2%2==0)) return true;
return false;
}


bool Odvratni(std::vector<int> v) {
	int br0(0), br1(0), br2(0);
	
	for(int i=0; i<v.size(); i++) {
		if (v[i]==0) br0++;
		else if (v[i]==1) br1++;
		else if (v[i]==2) br2++;
	}
	if((br0%2!=0 && br1%2!=0  && br2%2!=0) || (br0%2!=0 && br1%2!=0  && br2==0) || (br0==0 && br1%2!=0  && br2%2!=0) || (br0==0 && br1%2!=0  && br2==0)) return true;

	
	 return false;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool a) {
	std::vector<int> v1;
	if (a) {
	for(int i=0; i<v.size(); i++) 
		if(Opaki(PretvoriBrojeve(v[i]))) v1.push_back(v[i]);
		
		return Ponavljanje(v1);
	}
	
	else if (!a) {
	for(int i=0; i<v.size(); i++) 
		if(Odvratni(PretvoriBrojeve(v[i]))) v1.push_back(v[i]);
		
		return Ponavljanje(v1);
	}
}



//Unos brojeva
std::vector<int> UnosVektora() {
	std::vector<int> v;
	long int n;
	do {
		std::cin >> n;
		if(n!=0) v.push_back(n);
	} while(n!=0);
	return v;
}

int main ()
{

}
