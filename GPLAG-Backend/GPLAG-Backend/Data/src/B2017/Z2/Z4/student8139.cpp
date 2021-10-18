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
#include <stdexcept>
#include <functional>
#include <algorithm>
using namespace std;
	template<typename tip1, typename tip2, typename tip3, typename funtip1, typename funtip2>
	void SortirajPodrucjeVrijednosti(tip1 p1, tip1 p2, tip2 p3, tip3 p4, funtip1 funkcija1, funtip2 funkcija2){
		tip2 pom=p3+(p2-p1);
		tip3 kraj=p4+(p2-p1);
		tip3 sacuvaj=p4;
		sort(p1, p2, funkcija2);
		sort(p3, pom, funkcija2);
		int br(0);
		while(p1!=p2){
			decltype(*p4+*p4) temp=funkcija1(p1, p3);
			p4=sacuvaj;
			int broj(0);
			while(p4!=kraj){
				if(*p4==temp){
					 decltype(*p4+*p4) premjesti=*p4;
					*p4=*(sacuvaj+br);
					*(sacuvaj+br)=premjesti;
					broj++;
					break;
				}
				
				p4++;
			}
			if(broj==0)throw logic_error("vrijednosti nema");
			br++;
			p1++;
		}
	}
	
	int prva (int x, int y){
		return -2*x+y;
		
	}
	
	bool druga (int x, int y){ 
		int br1(0);
		for(int i=1;i<=x;i++){
			if(x%i==0)br1++;
			
		} 
		int br2(0); 
		for(int i=1;i<=y;i++){
			if(y%i==0)
			br2++;} 
			if(br1>br2)return x; 
			else return y;}
int main ()
{
	int n;
	cout<<"unesi broj elemenata";
	cin>>n;
	vector<int>v1(n), v2(n), v3(n);
	cout<<"unesi elemente prvog";
	int br1(0);
	bool prom1(false);
	for(int i=0;i<n;i++){
		int broj;
		cin>>broj;
		br1++;
		if(br1>1){
		for(int j=0;j<br1-1;j++)
		if(broj==v1[j])prom1=true;
		}
		if(prom1)continue;
		v1.push_back(broj);
	}
	cout<<"unesi elemente drugog";
	int br2(0);
	bool prom2(false);
	for(int i=0;i<n;i++){
		int broj;
		cin>>broj;
		br2++;
		if(br2>1){
		for(int j=0;j<br2-1;j++)
		if(broj==v2[j])prom2=true;
		}
		if(prom2)continue;
		v2.push_back(broj);
	}
	cout<<"unesi elemente treceg";
	int br3(0);
	bool prom3(false);
	for(int i=0;i<n;i++){
		int broj;
		cin>>broj;
		br3++;
		if(br3>1){
		for(int j=0;j<br3-1;j++)
		if(broj==v3[j])prom3=true;
		}
		if(prom3)continue;
		v3.push_back(broj);
	}
	SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), prva, druga);
	
	
	return 0;
}