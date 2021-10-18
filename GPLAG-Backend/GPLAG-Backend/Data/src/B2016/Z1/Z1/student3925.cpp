/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <cstdlib>
	
	
int ternarni (int a){
	int b, b0(0),b1(0),b2(0);
	long long int c=std::abs(static_cast<long long int>(a));
	do{
		b=c%3;
		if(b==0) b0++;
		else if(b==1) b1++;
		else if(b==2) b2++;
		c/=3;
	} while(c!=0);
	
	
	if(b0%2==0 && b1%2==0 && b2%2==0) return 1;
	else if((b0%2!=0 || b0==0) && (b1%2!=0 || b1==0) && (b2%2!=0 || b2==0)) return 2;
	else return 3;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool a) {
	std::vector<int> w ;
	if(a) {
	for(int i: v){
		if(ternarni(i)==1) {
			int b(0);
			for(int j: w) if(j==i) b++;
			if(b==0) w.push_back(i);
	
	}
	}
	}
	else {
		for(int i: v){
			if(ternarni(i)==2) {
				int b(0);
				for( int j:w) if(j==i) b++;
				if(b==0) w.push_back(i);
				
		}
	}
	}
	
	
return w;
}

int main ()
{
	
	int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): " ;
	std::vector<int> v ;
	
	
	while(1){
		std::cin>>x;
		if(x==0) break;
		else v.push_back(x);
	}
	
	std::vector<int> l,y ;
	l=IzdvojiGadne(v,1);
	y=IzdvojiGadne(v,0);
	
	std::cout << "Opaki: " ;
	for(int i(0);i<l.size();i++){
		std::cout << l[i]<<" ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int i(0);i<y.size();i++){
		std::cout << y[i] << " ";
	}

	return 0;
}