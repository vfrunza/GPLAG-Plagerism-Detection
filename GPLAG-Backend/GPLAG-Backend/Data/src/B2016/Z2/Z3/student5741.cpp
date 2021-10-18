/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::deque;

int SumaDjelilaca(long long int a){
	int s(0);
	for(int i=1;i<=a;i++){
		if(a%i==0){
			s=s+i;
		}
	}
	return s;
}

int BrojProstihFaktora(long long int a){
	int br(0);
	for(int i=1;i<=a;i++){
		if(a%i==0){
			a=a/i;
			br++;
		}
	}
	return br;
}

template<typename NekiTip1,typename NekiTip2,typename NekiTip3>
auto UvrnutiPresjek(NekiTip1 p1,NekiTip1 p2,NekiTip2 p3,NekiTip2 p4,f(NekiTip3))->(*p1+*p1){
	NekiTip1 pok1(p1);
	NekiTip2 pok3(p3);
	while(pok1!=p2){
		
		pok1++;
	}
}

int main ()
{
	int n1;
	cout<<"Unesite broj elemenata prvog kontenjera: ";
	cin>>n1;
	deque<int> v1;
	int br(0);
	int brojac(0);
	cout<<"Unesite elemente prvog kontenjera: ";
	while(brojac!=n1){
		int broj;
		cin>>broj;
		int i(0);
		for(;i<br;i++){
			if(broj==v1[i]){
				break;
			}
		}
		if(i==br){
			v1.push_back(broj);
			brojac++;
		}
		br++;
	}
	br=0;
	brojac=0;
	int n2;
	cout<<"Unesite broj elemenata prvog kontenjera: ";
	cin>>n2;
	deque<int> v2;
	cout<<"Unesite elemente prvog kontenjera: ";
	while(brojac!=n2){
		int broj;
		cin>>broj;
		int i(0);
		for(;i<br;i++){
			if(broj==v2[i]){
				break;
			}
		}
		if(i==br){
			v2.push_back(broj);
			brojac++;
		}
		br++;
	}
	return 0;
}