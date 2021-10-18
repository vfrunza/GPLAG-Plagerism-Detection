/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

template <typename Tip>
bool ProvjeraPerioda(std::vector<Tip> v, int T){
	int a(v.size());
	while(a%T!=0)
		a--;
	for(int i=0; i<a-T; i++)
	   if(v.at(i)!=v.at(i+T)) return false;
	   return true;
}

template <typename Tip>
int Periodican(std::vector<Tip> v){
	int T(1), i(1);
	
	if(v.size()==1) return 0;
	
	for(;;){
	while(v.at(0)!=v.at(i)){
		T++;
		if(i>=v.size()-1) return 0;
		i++;
	}
	if(ProvjeraPerioda(v, T)) break;
	else{ 
		if(i>=v.size()-1) return 0;
		i++; T=1;}
	}
	
	return T;
}

template <typename Tip>
int Potpun(const std::vector<Tip> &v, int T, int &a){
	int kp(0);
	if(T==0) return 2;
	if(v.size()%T!=0){
		kp=v.size()/T+1;
		while(a%T!=0)
			a++;
	}
	else kp=v.size()/T;
	
	return kp;
}

template <typename Tip>
Tip **AlocirajFragmentirano (const std::vector<Tip> &v, int &koliko_puta){
	if(v.size()==0) throw ("Prazan vektor!");
	for (int i=0; i<v.size(); i++)
		if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	
	int T(Periodican(v));
	int h(v.size());
	if(T)
		koliko_puta=Potpun(v, T, h);
	else{
		h=2*v.size();
		koliko_puta=2;
		T=v.size();
	}
	
	Tip a(*std::max_element(v.begin(), v.end()));
	Tip **p(nullptr);
	try{
		p=new Tip*[h]{};
		int x(0);
		for(int i=0; i<koliko_puta; i++){
			for(int j=0; j<T; j++){
			p[x]=new Tip[v.at(j)];
			x++;
		}}
		x=0;
		for(int i=0; i<koliko_puta; i++){
			for(int j=0; j<T; j++){
				Tip b(a);
				for(int k=v.at(j)-1; k>=0; k--){
					p[x][k]=b;
					b--;
				}
				x++;
			}
		}   
	}
	catch(std::bad_alloc){
		for(int i=0; i<h; i++)
		    delete [] p[i];
		delete [] p;
		throw;
	}
	return p;
}

template <typename Tip>
Tip **AlocirajKontinualno (const std::vector<Tip> &v, int &koliko_puta){
	if(v.size()==0) throw ("Prazan vektor!");
	for (int i=0; i<v.size(); i++)
		if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	
	int T(Periodican(v));
	int h(v.size());
	if(T)
		koliko_puta=Potpun(v, T, h);
	else{
		h=2*v.size();
		koliko_puta=2;
		T=v.size();
	}
	
	
	Tip suma(0);
	for(int i=0; i<koliko_puta; i++)
	    for(int j=0; j<T; j++)
		    suma+=v.at(j);
	
	Tip **p(nullptr);
	try{
		p=new Tip*[h]{};
		p[0]=new Tip[suma];
		int x(0);
		Tip a(*std::max_element(v.begin(), v.end()));
		for(int i=0; i<koliko_puta; i++){
			for(int j=0; j<T; j++){
				if(x!=0) p[x]=p[x-1]+v.at(j-1);
				else if(j==0) p[x]=p[x-1]+v.at(T-1);
				Tip b(a);
				for(int k=0; k<v.at(j); k++){
					p[x][k]=b;
					b--;
				}
				x++;
			}
			
		}   
		   
	}
	catch(std::bad_alloc){
		    delete [] p[0];
		delete [] p;
		throw;
	}
	return p;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n(0);
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	try{
		std::vector<int> v(n);
	    for(int i=0; i<n; i++)
	        std::cin >> v.at(i);
	    std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	    int f(0);
	    std::cin >> f;
	    int k(0);
	    int **p(nullptr);
	    if(f==1)
	          p=AlocirajFragmentirano(v, k);
	    else  p=AlocirajKontinualno(v, k);
	    std::cout << "Dinamicki alocirana matrica:\n";
	    int h(v.size()), kp(0), T(Periodican(static_cast<const std::vector<int>>(v)));
	    kp=Potpun(static_cast<const std::vector<int>>(v), T, h);
	    int x(0);
	    	for(int i=0; i<kp; i++){
	    	for(int j=0; j<T; j++){
	    	for(int k=0; k<v.at(j); k++)
	    	    std::cout << std::left << std::setw(3) << p[x][k];
	    	std::cout << std::endl; 
	    	x++;
	    }}
	   if(f==1){
	   for(int i=0; i<h; i++)
	       delete [] p[i];
	   delete [] p;}
	   else {
	   	delete [] p[0];
	   	delete [] p;
	   }
	}
catch(std::bad_alloc){
	std::cout << "Neuspjesna alokacija!";
}
catch(std::domain_error izuzetak){
	std::cout << "Izuzetak: " << izuzetak.what();
}	
catch(...){
	std::cout << "Izuzetak: Prazan vektor!";
}
	
	return 0;
}