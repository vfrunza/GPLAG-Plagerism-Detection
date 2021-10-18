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
#include <vector>
#include <type_traits>
#include <algorithm>
#include <stdexcept>
int funk1(int x,int y) 
{return -2*x+y;}

int prost(int x){
	int j=2;
	int brojac(0);
	while(x!=1){
		if(x<=0) return brojac;
		if(x==j) j++;
		else if(x%j==0){
			brojac ++;
			x=x/j;
			j++;
		}
	}
	return brojac;
}
template <typename Tip1,typename Tip2,typename Tip3>


void SortirajPodrucjeVrijednosti(Tip1 *p1,Tip1 *p2,Tip2 *p3,Tip3 *p4, typename std::remove_reference<decltype(*p3)>::type funk1(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*p1)>::type),bool funk2(int,int)){
	std::sort(p1,p2,funk2);
	int duzina(0);
	while(p1!=p2){
		duzina++;
		p1++;
	}
	std::sort(p3,p3+duzina,funk2);
	int duzina2;
	for(int i=0;i<duzina;i++){
		for(int j=0;j<duzina;j++){
			if(funk1(*(p1+i),*(p3+i))==*(p4+j))
			duzina2++;
		}
	}
	if (duzina2!=duzina){
		throw std::logic_error("“Vrijednost koja odgovara nekom od parova nije nadjena");
		return 0;
	}
	else{
		for(int i=0;i<duzina;i++){
			int bio=0;
			for(int j=9;j<duzina;j++){
				if(funk1(*(p1+i),*(p3+i))==*(p4+j)){
					auto pomoc=*(p4+i);
					*(p4+i)=*(p4+j);
					*(p4+j)=pomoc;
				}
			}
		}
		
	}
}
#include <iostream>


int main ()
{
	std::vector<int> s1;
	std::vector<int> s2;
	std::vector<int> s3;
	int broj;
	std::cout<<"Unesite :";
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>broj;
		int x=0;
		int da=1;
		for(int j=0;j<i;j++){
			if(s1[i]==broj){
				x=1;
				da=0;
			}
		}
		if(da==1) s1.push_back(broj);
		i=i-x;
	}
	for(int i=0;i<n;i++){
		std::cin>>broj;
		int x=0;
		int da=1;
		for(int j=0;j<i;j++){
			if(s2[i]==broj){
				x=1;
				da=0;
			}
		}
		if(da==1) s2.push_back(broj);
		i=i-x;
	}
	for(int i=0;i<n;i++){
		std::cin>>broj;
		int x=0;
		int da=1;
		for(int j=0;j<i;j++){
			if(s3[i]==broj){
				x=1;
				da=0;
			}
		}
		if(da==1) s3.push_back(broj);
		i=i-x;
	}
	try{
		SortirajPodrucjeVrijednosti(s1.begin(),s1.end(),s2.begin(),s3.begin(),funk1(int x,int y),[](int x,int y){if(x>y&& prost(x)==prost(y)) return true; else if(prost(x)>prost (y)) return true; return false;});
		std::cout<<"";
		
	}
	catch(std::logic_error izuzetak){
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
		return 0;
	}
	
	return 0;
}