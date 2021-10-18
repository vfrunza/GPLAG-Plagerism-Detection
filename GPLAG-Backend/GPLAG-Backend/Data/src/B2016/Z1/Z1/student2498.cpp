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

bool DaLiJeNeparan (int broj) {  // pomocna funckija za dio sa odvratnim br
	if(broj==0) return true; 
	if(broj%2!=0) return true;
	else return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> v1, bool logic) {
	
	std::vector<int> v2;
	
	for(int i=0; i<v1.size(); i++) {            // izbaci duplikate iz vectora
		for(int j=i+1; j<v1.size(); j++) {
			if(v1[i]==v1[j]) {
				v1.erase(v1.begin()+j);
				j--;
			}
		}
	}
	
	for(int i=0; i<v1.size(); i++) {
		int br(v1[i]);
		int ostatak(0);
		unsigned long long int novi_br(0);       // at1
		long long int desetice(1);
	
		while(br!=0) {                        // pretvorba decimal u ternarni
			
			ostatak = br%3;
			ostatak = std::abs(ostatak);
			novi_br = novi_br + ostatak*desetice;
			desetice *= 10;
			br /= 3;
		}
		
		if(logic==true) {                    // izdvajanje opakih
			
			int b0(0), b1(0), b2(0);
			while (novi_br!=0) {
				
				if(novi_br%10 == 0) b0++;
				else if (novi_br%10 == 1) b1++;
				else b2++;
				novi_br/= 10;
			}
			
			if(b0%2==0 && b1%2==0 && b2%2==0) v2.push_back(v1[i]);
			
		}
		

		
		else if(logic==false) {             // izdvajanje odvratnih
			
			int b0(0), b1(0), b2(0);
			while(novi_br!=0) {
				
				if(novi_br%10 == 0) b0++;
				else if(novi_br%10 == 1) b1++;
				else  b2++;
				novi_br /= 10;

			}
			
		/*	if( (b0%2!=0 && b1%2!=0 && b2%2!=0) || ( b0==0 && b1%2!=0 && b2%2!=0) || (b0%2!=0 && b1==0 && b2%2!=0) || 
			(b0%2!=0 && b1%2!=0 && b2==0) || (b0%2!=0 && b1==0 && b2==0) || (b0==0 && b1%2!=0 && b2==0) ||
			(b0==0 && b1==0 && b2%2!=0)) v2.push_back(v1[i]);*/    
			
			if(DaLiJeNeparan(b0) && DaLiJeNeparan(b1) && DaLiJeNeparan(b2)) v2.push_back(v1[i]);
		}
		
	}
	
	return v2;
}

int main ()
{
	std::vector<int> v1, v2, v3;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;) {
		std::cin >> broj;
		if(broj==0) break;
		v1.push_back(broj);
	}
	v2 = IzdvojiGadne(v1, true);
	std::cout << "Opaki: ";
	for(int i=0; i<v2.size(); i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << std::endl << "Odvratni: ";
	v3 = IzdvojiGadne(v1, false);
	for(int i=0; i<v3.size(); i++) {
		std::cout << v3[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}