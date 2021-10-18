/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>




bool DaLiJeOpak(int m){
	std::vector<int> v;
	int x, n;
	if(m < 0) n = -m;
	else n = m;
	while(n!=0){
		x = n % 3;
		v.push_back(x);
		n/=3;
	}
		int brojac0(0), brojac1(0), brojac2(0);
		for(int i=0 ; i<v.size() ; i++){
			if(v[i]==0) brojac0++;
			else if(v[i]==1) brojac1++;
			else brojac2++;
		}
			if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0 && brojac0!=0 && brojac1!=0 && brojac2!=0) return true;
			else if(brojac0 == 0 && brojac1%2==0 && brojac2%2==0 && brojac1!=0 && brojac2!=0) return true;
			else if (brojac1 == 0 && brojac0%2==0 && brojac2%2==0 && brojac0!=0 && brojac2!=0) return true;
			else if(brojac2 == 0 && brojac1%2==0 && brojac0%2==0 && brojac0!=0 && brojac1!=0) return true;
			return false;

}

bool DaLiJeOdvratan (int m){
	std::vector<int> v;
	int x, n;
	if(m < 0) n = -m;
	else n = m;
	while(n!=0){
		x = n % 3;
		v.push_back(x);
		n/=3;
	}
		int brojac0(0), brojac1(0), brojac2(0);
		for(int i=0 ; i<v.size() ; i++){
			if(v[i]==0) brojac0++;
			else if(v[i]==1) brojac1++;
			else brojac2++;
		}
			if(brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0 && brojac0!=0 && brojac1!=0 && brojac2!=0) return true;
			else if(brojac0 == 0 && brojac1%2!=0 && brojac2%2!=0 && brojac1!=0 && brojac2!=0) return true;
			else if (brojac1 == 0 && brojac0%2!=0 && brojac2%2!=0 && brojac0!=0 && brojac2!=0) return true;
			else if(brojac2 == 0 && brojac1%2!=0 && brojac0%2!=0 && brojac0!=0 && brojac1!=0) return true;
			return false;

}

std::vector<int> Ponavljanja(std::vector<int> v){
	for(int i=0 ; i<v.size() ; i++){
		for(int j=i+1; j<v.size() ; j++){
			if(v[i]==v[j]) {v.erase(v.begin() + j); j--;}
		}
	}
	return v;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool a){
	std::vector<int> V;
	v = Ponavljanja(v);
	if(a){
		for(int i=0 ; i<v.size() ; i++){
			if(DaLiJeOpak(v[i])) V.push_back(v[i]);
		}

	}
		else {
			for(int i=0 ; i<v.size() ; i++){
				if(DaLiJeOdvratan(v[i])) V.push_back(v[i]);
			}

	}
	return V;
}




int main ()
{
	std::vector<int> brojevi;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(1){
		int n;
		std::cin>>n;
		if(n==0) break;
		else brojevi.push_back(n);
	}
	std::vector<int> opaki = IzdvojiGadne(brojevi,true);
	std::vector<int> odvratni = IzdvojiGadne(brojevi, false);
	std::cout<<"Opaki: ";
	for(int i=0 ; i<opaki.size() ; i++){
		std::cout<<opaki[i]<<" ";

	}
		std::cout<<std::endl;

		std::cout<<"Odvratni: ";
		for(int i=0 ; i<odvratni.size() ; i++){
			std::cout<<odvratni[i]<<" ";
		}



	return 0;
}
