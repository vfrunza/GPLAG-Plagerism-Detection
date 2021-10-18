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
#include<vector>
#include<cmath>
#include<stdexcept>
#include<algorithm>

tempate<typename t1,typename t2,typename t3,typename t4, typename t5>
void SortirajPodrucijeVrijednosti(t2 p1, t1 k1, t2 p2,t3 p3,t4 fun(t4,t4), bool val(t5,t5)){
	sort(p1,p1+(k1-p1),val);
	//for(int i=0;i<k1-p1;i++) cout<<p1[i]<<endl;
	sort(p2,p2+(k1-p1),val);
	auto pom1=p1, pom2=p2,pom3 =p3;
	bool a=0;
	while(pom1 !=k1){
		auto pom33=p3;
		while(pom33 !=p3+(k1-p1)) {
			if(fun(*pom1,*pom2)==*pom33) {
				auto temp= *pom33; *pom33=*pom3; *pom3=temp;
				a=1;
			}
			pom33++;
		}
		if(a==0) throw logic_error("Vrijednost koja odgovara nekom od parovanije nadjena" );
		a=0;
		pom1++;
		pom2++; pom3++;
		
	}
}

bool prost(int n ) {
	if(n<0) n=-n;
	if(n==0 || n==1) return false;
	if(n==2) return true;
	for(int i=2;i<n;i++) if(n%i==0) return false;
	return true;
}

bool prostifaktori(int a,int b) {
	int br1=0; br2=0;
	int temp=a;
	int temp1=b;
	for(int i=1; i<temp; i++) if(prost(i) && a%i==0) {br1++;temp/=i;i--}
	for(int i=1; i <temp1; i++) if(prost(i) && b%i==0) {br2++;temp1/=i;i--}
	// cout <<a<<"<->"<<br<<" "<<b<<"<->"<<br2<<" ";
	
	if(br1==br2 && a>b) return true;
	return br1>br2;
	
	//return false;
}


int f(int a,int b) {
	return -2*a+b;
}


int main ()
{
	return 0;
}