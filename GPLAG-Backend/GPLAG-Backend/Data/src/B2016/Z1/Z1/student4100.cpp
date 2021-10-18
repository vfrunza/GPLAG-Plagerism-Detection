/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

int Gadan ( int m){
	int br1(0), br2(0), br0(0);
	while ( m != 0){
		if ( m % 3 == 0){
			br0++;
		}
		if ( m % 3 == 1){
			br1++;
		}
		if ( m % 3 == 2){
			br2++;
		} 
		m = m / 3;
	}
	if (( br0 % 2 == 0 || br0 == 0) && ( br1 % 2 == 0 || br1 == 0) && ( br2 % 2 == 0 || br2 == 0))	return 1;
	
	else if (( br0 % 2 != 0 || br0 == 0) && ( br1 % 2 != 0 || br1 == 0) && ( br2 % 2 != 0 || br2 == 0)) return 2;

	else return 0;
}
std::vector<int> IzdvojiGadne ( std::vector<int>v, bool b){
	int velicina = v.size();
	std::vector<int>opak;
	std::vector<int>odvratan;
	for ( int i=0; i<velicina; i++){
		if ( Gadan(v[i]) == 1 ) opak.push_back(v[i]);
		if ( Gadan(v[i]) == 2 ) odvratan.push_back(v[i]);
		else continue;
	}
	int opaks(opak.size());
	int odvratans(odvratan.size());
	
	for (int i = 0; i < opaks; i++){
		int brojac(0);
		for (int j = i; j < opaks; j++){
			if (opak[j]==opak[i]){
				brojac++;
				if (brojac>1){
					for (int k = j; k < opaks-1; k++){
						opak[k]=opak[k+1];
					}
					opaks--;
					j--;
				}
			}
		}
	}
	for (int i = 0; i < odvratans; i++){
		int brojac(0);
		for (int j = i; j < odvratans; j++){
			if (odvratan[j]==odvratan[i]){
				brojac++;
				if (brojac>1){
					for (int k = j; k < odvratans-1; k++){
						odvratan[k]=odvratan[k+1];
					}
					odvratans--;
					j--;
				}
			}
		}
	}
	opak.resize(opaks);
	odvratan.resize(odvratans);
	
	if ( b == 1) return opak;
	else return odvratan;
}

int main ()
{
     	std::vector<int>v;
     	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
     	int n;
     	
     	do{
     		std::cin>>n;
     		if (n != 0 ) v.push_back(n);
     		
     	}while ( n != 0 );
     	
     	//opaki
     	std::cout<<"Opaki: ";
     	std::vector<int>opaki_brojevi = IzdvojiGadne(v, 1) ;
     	int opaks=opaki_brojevi.size();
     
     	/*for ( int i=0; i<opaks; i++){
     		int brojac(0);
     		for ( int j=i; j<opaks; j++){
     			if ( opaki_brojevi[j] == opaki_brojevi[i] ) {
     				brojac++;
     				if (brojac>1) {
	     				for ( int k=0; k<opaks-1; k++ ){
	     					opaki_brojevi[k] == opaki_brojevi[k+1];
	     				}
	     				opaks--;
	     				j--;
     				}
     			}
     		}
     	}*/
     	for ( int i=0; i<opaks; i++){
     		std::cout<<opaki_brojevi[i]<<" ";
     		}
     	std::cout<<"\n";
     	
     	//odvratni
     	std::cout<<"Odvratni: ";
     	std::vector<int>odvratni_brojevi = IzdvojiGadne(v, 0) ;
     	int odvratans = odvratni_brojevi.size();
     	/*for ( int i=0; i<odvratans; i++){
     		int brojac(0);
     		for ( int j=i; j<odvratans; j++){
     			if ( odvratni_brojevi[j] == odvratni_brojevi[i]){
     				brojac++;
	     			if ( brojac > 1) {
	     				for ( int k = 0; k<odvratans-1; k++){
	     					odvratni_brojevi[k] == odvratni_brojevi[k+1];
	     				}
	     				odvratans--;
	     				j--;
	     			}
     			}
     		}
     	}*/
     	for ( int i=0; i<odvratans; i++){
     		std::cout<<odvratni_brojevi[i]<<" ";
     		}
     	std::cout<<"\n";
     	
		return 0;
}