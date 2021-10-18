#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne ( std::vector<int>v, bool x )
{

	for( unsigned int i=0; i<v.size()-1; i++) {
		for(unsigned int j=i+1; j<v.size(); j++) { // izbacujemo iz vektora elemente koji se ponavljaju
			if( v[i]==v[j] ) {
				v.erase(  v.begin() + j);
				j--;  // umanjujemo j zbog smanjenja velicine pozivom funkcije erase !
			}

		}
	}

	std::vector<int>opaki ;
	std::vector<int>odvratni ;
	int t(0);
	for ( int e : v ) { // pomocu rangovske for petlje pristupamo elementima vektora v !

		t=e;

		std::vector<long long int>histogram (3,0) ; // pomocu histograma biljezimo javljanje cifara !
		if(t>=0) {
			do {
				histogram [t%3] ++;
				t/=3;
			} while(t!=0);
		} else {
			while(t!=0) {
				histogram [-t%3] ++;
				t/=3;
			}
		}

		if(x==true) {

			bool opak(true);
			for(int i=0; i<3; i++) {
				if(histogram[i]!=0 && histogram[i]%2!=0) {
					opak=false;
					break;
				}
			}

			if(opak==true) {
				opaki.push_back(e);
			}

		}

		if(x==false) {
			bool odvratan(true);
			for(int i=0; i<3; i++) {
				if(histogram[i]!=0 && histogram[i]%2==0) {
					odvratan=false;
					break;
				}
			}

			if(odvratan==true) {
				odvratni.push_back(e);
			}

		}

	}

	if(x==true) {
		return opaki;
	} else {
		return odvratni;
	}
}

int main ()
{
	int e(0);
	std::vector<int>v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(; ;) { // beskonacna for petlja
		std::cin >> e;
		if(e==0) { // ako je unesena 0 odmah izlazimo iz petlje i prekidamo unos
			break;
		} else {
			v.push_back(e);
		}
	}

	std::cout << "Opaki: ";
	for(int x : IzdvojiGadne(v,true) ) {
		std::cout << x <<" ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int x : IzdvojiGadne(v,false) ) {
		std::cout << x <<" ";
	}
	return 0;
}
