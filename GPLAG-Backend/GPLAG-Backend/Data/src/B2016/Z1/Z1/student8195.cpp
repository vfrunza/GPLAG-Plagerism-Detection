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

std::vector<int> IzdvojiGadne (std::vector<int> a, bool b) {
	int pomocni,terarni(0);
	int i,j,c;
	c=a.size();
	if (b==true){
	for (i=0;i<c;i++){
			int brojac0,brojac1,brojac2,brojac3;
			brojac0=0;
			brojac1=0;
			brojac2=0;
			brojac3=0;
		terarni=0;
		pomocni=a[i];
		if (pomocni<0) {pomocni=pomocni*(-1);}
		for (j=0;j<20;j++){
			int brojac(0);
			terarni=terarni+((pomocni%3)*pow(10,brojac));
			pomocni=pomocni/3;
			if (pomocni/3==0)  break;
			brojac++;
		}
		for (j=0;j<20;j++){
		if (terarni/10==0) break;
		if (terarni%10==2) {brojac2++;}
		if (terarni%10==1) {brojac1++;}
		if (terarni%10==0) {brojac0++;}
		terarni=terarni/10;
		}
		if (b==true&&(brojac2%2||brojac2==0)&&(brojac1%2||brojac1==0)&&(brojac0%2||brojac0==0)) {continue;}
		else {a.erase(a.begin()+i-brojac3); brojac3++;}
	
	} return a;}
		if (b==false){
	for (i=0;i<c;i++){
			int brojac0,brojac1,brojac2,brojac3;
			brojac0=0;
			brojac1=0;
			brojac2=0;
			brojac3=0;
		terarni=0;
		pomocni=a[i];
		for (j=0;j<20;j++){
			int brojac(0);
			terarni=terarni+((pomocni%3)*pow(10,brojac));
			pomocni=pomocni/3;
			if (pomocni/3==0)  break;
			brojac++;
		}
		for (j=0;j<20;j++){
		if (terarni/10==0) break;
		if (terarni%10==2) {brojac2++;}
		if (terarni%10==1) {brojac1++;}
		if (terarni%10==0) {brojac0++;}
		terarni=terarni/10;
		}
		if (b==false&&((brojac2%2!=0)||brojac2!=0)&&((brojac1%2!=0)||brojac1!=0)&&(((brojac0%2)!=0)||brojac0!=0))
		{continue;}
		else {a.erase(a.begin()+i-brojac3); brojac3++;}
	} return a;	}
return a; }



int main ()
{
	return 0;
}