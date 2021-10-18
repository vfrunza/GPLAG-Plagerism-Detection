/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector> 

/*void Ispisi(std::vector<int> a){
	std::cout<<"Trenutni vektor je: ";
	for(int i=0;i<a.size();i++)
		std::cout<<a[i]<<',';
		std::cout<<std::endl;
}
*/

std::vector<int> IzbaciDuplikate(std::vector<int> a){
	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
		if(a[i]==a[j]){
			a.erase(a.begin()+j);
			j--;
	}
}
}
return a;
}

std::vector<int> Ternary(int n){
	std::vector<int> v;
	int ostatak;
	while(n!=0){
		ostatak=n%3;
		v.push_back(ostatak);
		n=n/3;
	}
	return v;
}


bool DaLiJeOpak(std::vector<int> a){
	int brojac1(0);
	int brojac2(0);
	int brojac3(0);
	for(int i=0;i<a.size();i++){
			if(a[i]<0) a[i]=-a[i];
		if(a[i]==0) brojac1++;
			else if(a[i]==1) brojac2++;
			else if(a[i]==2) brojac3++;
	}
	if(brojac1%2==0 && brojac2%2==0 && brojac3%2==0)
		return true;
	
	return false;
}

bool DaLiJeGadan(std::vector<int> a){
	int brojac1(0);
	int brojac2(0);
	int brojac3(0);
	for(int i=0;i<a.size();i++){
			if(a[i]<0) a[i]=-a[i];
			if(a[i]==0) brojac1++;
			else if(a[i]==1) brojac2++;
			else if(a[i]==2) brojac3++;
	}
	if(brojac1%2!=0 && brojac2%2!=0 && brojac3%2!=0)
		return true;	
		else if(brojac1%2!=0 && brojac2==0 && brojac3%2!=0)
		return true;
		else if(brojac1==0 && brojac2%2!=0 && brojac3%2!=0)
		return true;
		else if(brojac1%2!=0 && brojac2%2!=0 && brojac3==0)
		return true;	
	
	return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> a, bool vrsta){
	std::vector<int> n(IzbaciDuplikate(a));
	std::vector<int> gadni;
	if(vrsta){											
			std::vector<int> opaki;
			for(int i=0;i<n.size();i++){
				std::vector<int> baza(Ternary(n[i]));
				if(DaLiJeOpak(baza))				
					opaki.push_back(n[i]);
			}
			return opaki;
	}

	else if (vrsta==false){
		
			for(int i=0;i<n.size();i++){
				std::vector<int> baza(Ternary(n[i]));
				if(DaLiJeGadan(baza))
				gadni.push_back(n[i]);
				
			}
		
	}
	
	
	
	return 	gadni;
}




int main ()
{
std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	std::vector<int> v;
	for(;;){
		std::cin>>n;
		if(n==0) break;
		else v.push_back(n);
	}
	//std::vector<int> v{121, 15451, 15, 179, 777};
	std::cout<<"Opaki: ";
	std::vector<int>a(IzdvojiGadne(v,true)) ;
	for(int i=0;i<a.size();i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	std::vector<int> b(IzdvojiGadne(v,false));
	for(int i=0;i<b.size();i++) std::cout<<b[i]<<" ";
	
/*	std::vector<int> v = {
	136, 123, 12, 1212, 10102, 10012, 1000, 608, 2613, -608, 333,
	333, 333, 333, 333, 333, 1000, -15, 60, 61, 15, 151, 16, 715, 7222,
};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
//std::cout<<"vrijednost vektora v nakon IzdvojiGadne: ";
for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " ";*/
	
	return 0;
}