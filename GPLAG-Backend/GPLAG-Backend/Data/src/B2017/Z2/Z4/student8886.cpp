/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
void Ispisi(int x){
	std::cout<<x<<" ";
}
int Unos(int x){
	std::cin>>x;
	return x;
}
int SumaCifara(int x){
	if(x==0) return 0;
	return abs(x%10)+SumaCifara(x/10);
}
bool Sortiran_vektor(int x, int y){
	if(SumaCifara(x)==SumaCifara(y)) return x<y;
	return SumaCifara(x)<SumaCifara(y);
}
int BrojFaktora(int x){
	if(x<0) x=-x;
	int y;
	int brojac(0);
	if(x==1 || x==0)return 1;
	else{
		int k=x%2;
		while(k==0){
			y=x/2;
			x=y;
			k=x%2;
			brojac++;
		}
		for(int j=3; j<=x; j+=2){
			int k=x%j;
			while(k==0){
				y=x/j;
				x=y;
				k=x%j;
				brojac++;
			}
		}
	}
	return brojac;
}
bool ProstiFaktori(int x, int y){
	if(BrojFaktora(x)==BrojFaktora(y)) return x>y;
	return BrojFaktora(x)>BrojFaktora(y);
}
template <typename tip, typename tip1, typename tip2>
auto SortirajPodrucjeVrijednosti(tip begin, tip end, tip1 begin2, tip2 begin3, int fun(int x, int y), bool fun1(int, int))->decltype(*begin+*end){
	if(std::distance(begin2,end)==0 || std::distance(begin,end)==0 || std::distance(begin3,end)==0) return 0;
	std::sort(begin,end, fun1);
//	std::for_each(begin,end,Ispisi);
//	std::cout<<std::endl;
//	std::for_each(begin2,begin2+(end-begin),Ispisi);
	std::sort(begin2,begin2+(end-begin), fun1);
//	std::cout<<std::endl;
//	std::for_each(begin2,begin2+(end-begin),Ispisi);
	std::sort(begin3,begin3+(end-begin), fun1);
//	std::cout<<std::endl;
//	std::for_each(begin3,begin3+(end-begin),Ispisi);
    
	int size=end-begin;
	
	    
	    while(begin!=end){
		auto rez=fun(*begin,*begin2);
		
		//std::cout<<"***"<<rez<<"***";
	    //std::cout<<std::binary_search(begin3, begin3+size, rez, fun1);
	    auto it=std::find(begin3,begin3+size, rez);
	    if(it!=begin3+size){
	        
	    	std::rotate(begin3+(it-begin3),begin3+(it-begin3)+1,begin3+size);
	    }
	    else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	    //std::for_each(begin3,begin3+size,Ispisi);
	    //std::cout<<"Trazeni broj nalazi se na poziciji "<<std::lower_bound(begin3,begin3+size,rez,fun1)-begin3<<std::endl;
	    begin++;
	    begin2++;
	    
	}
	
//	std::cout<<rez;
//	std::for_each(begin2,begin2+(end-begin),Ispisi);
	
	return 0;
}

int main ()
{
//	std::vector<int> S1= {35, 12, 8, 111, 20, 4}, S2  = {61, 39, 5, 313, 42, 13} , S3  = {195, 46, 634, 22, 113, 126};
//	std::sort(S3.begin(),S3.end(), Sortiran_vektor);
//	std::for_each(S3.begin(),S3.end(),Ispisi);
//	SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), [](int x, int y){return x+2*y;}, Sortiran_vektor);
	try{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> S1(n),  S2(n), S3(n);
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<n; i++){
		int x;
		std::cin>>x;
		S1.at(i)=x;
		for(int j=0; j<i; j++) if(S1.at(j)==x) i--;
	} 
//	std::transform(S1.begin(),S1.end(), S1.begin(), Unos);
	std::cin.ignore(1000, '\n');
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<n; i++){
		int x;
		std::cin>>x;
		S2.at(i)=x;
		for(int j=0; j<i; j++) if(S2.at(j)==x) i--;
	} 
//	std::transform(S2.begin(),S2.end(), S2.begin(), Unos);
	std::cin.ignore(1000,'\n');
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<n; i++){
		int x;
		std::cin>>x;
		S3.at(i)=x;
		for(int j=0; j<i; j++) if(S3.at(j)==x) i--;
	} 
//	std::transform(S3.begin(),S3.end(), S3.begin(), Unos);
	std::cin.ignore(1000,'\n');
	std::cout<<std::endl;
	SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), [](int x, int y){return -2*x+y;}, ProstiFaktori);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	for(int i=0; i<S1.size(); i++) std::cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl;
	}catch(std::logic_error Izuzetak){
		std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
	}
	
	//Napraviti funkciju za prostefaktore
	return 0;
}