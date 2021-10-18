#include <iostream>
#include <vector>
#include <cmath>

/*int Pow(int baza, int eksponent) { // ne radi
	int rezultat(baza); 
	if(eksponent==0) return 1;
	if(eksponent==1) return baza;
	for(int i=1; i<eksponent; i++) {
		rezultat=rezultat*baza;
		if(baza==eksponent-1) break;
	}
	return rezultat;
}

std::vector<int> PretvoriUTernarni(std::vector<int> decimalni) { 

	std::vector<int> ternarni;

		for(unsigned int i=0; i<decimalni.size(); i++) {
		
			int broju3(0);
		//	int copy=decimalni[i];
			unsigned int brojcifara(0); //stavila sam ovdje unsigned
				
				while(decimalni[i]!=0) {
					broju3+=(decimalni[i]%3)*pow(10, brojcifara);
					brojcifara++;
					decimalni[i]=int(decimalni[i]/3);
				}
			
			ternarni.push_back(broju3);
			
			if(i==decimalni.size()-1) break;
		}
	return ternarni;
}

std::vector<int> BrojCifara(int x) { 
	
	std::vector<int> brojcifara(3,0);
	int n=fabs(x);
	
		while(n!=0) {
			if(n%10==0) brojcifara[0]++;
			if(n%10==1) brojcifara[1]++;
			if(n%10==2) brojcifara[2]++;
			n=n/10;
		}
	
	return brojcifara;
}
 
std::vector<int> PretvoriUDecimalni(std::vector<int> x) { 
	std::vector<int> y;
	for(unsigned int i=0; i<x.size(); i++) {
		int element(0);
	//	int copy;
	//	copy=x[i];
		int counter(0);
		while(x[i]!=0) {
			element+=(x[i]%10)*pow(3, counter);
			counter++;
			x[i]=x[i]/10;
			
		}
		y.push_back(element);
		counter=0;
		element=0;
		if(i==x.size()-1) break;
	}
	return y;
}
*/
std::vector<int> PreskociDuple(std::vector<int> x) { 	
//	std::vector<int> y;
	
	for(unsigned int i=0; i<x.size(); i++) {
		
		for(unsigned int j=i+1; j<x.size(); j++) {
			
			if(x[i]==x[j]) { x.erase(x.begin()+j); }
			if(j==x.size()-1) break;
		}
		if(i==x.size()-1) break;
	//	y.push_back(x[i]);
	
}
 	return x; // ovdje sam stavila return x, dunno if this is legal or not
}

std::vector<int> BrojBr(int n);

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t) {
//	std::vector<int> v1(PreskociDuple(v));
v=PreskociDuple(v);
//	v1=PretvoriUTernarni(v1);
/////v=PretvoriUTernarni(v);
	std::vector<int> gadni;
	for(unsigned int i=0; i<v.size(); i++) {
		std::vector<int> cifre(BrojBr(v[i]));
		bool test(true);
	if(t) { for(int j=0; j<cifre.size(); j++) {
			if(cifre[j]==0) continue;
			if(cifre[j]%2!=0) {test=false; break; }
			if(j==2) break;
		} }
	else {	for(int j=0; j<cifre.size(); j++) {
		if(cifre[j]==0) continue;
		if(cifre[j]%2==0) {test=false; break; }
		if(j==cifre.size()) break;
	}
		
	}	
	if(test) gadni.push_back(v[i]);
	test=true;
	if(i==v.size()-1) break;
	}
	return PreskociDuple(gadni); // obrisala pretvoriudec, za svaki slucaj stavila i ovdje preskoci duple
}


std::vector<int> BrojBr(int n) {
	std::vector<int> counter(3,0);
	n=fabs(n);
	while(n!=0) { 
		if(n%3==0) counter[0]++;
		if(n%3==1) counter[1]++;
		if(n%3==2) counter[2]++;
		n=int(n/3);
	}
	return counter;
}



int main() {

std::cout << "Unesite brojeve (0 za prekid unosa): ";
std::vector<int> v;
for(unsigned int i=0; ; i++) {
	int x;
	std::cin >> x;
	if(x==0) break;
	v.push_back(x);
}

std::cout << "Opaki: ";
std::vector<int> opaki(IzdvojiGadne(v,1));
for(int x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
std::vector<int> odvratni(IzdvojiGadne(v,0));
for(int x : odvratni) std::cout << x << " "; 


return 0; }
