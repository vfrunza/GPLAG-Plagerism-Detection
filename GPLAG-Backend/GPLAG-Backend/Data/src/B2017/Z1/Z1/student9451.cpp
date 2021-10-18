/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>
int BrojniSistem (int n) {
int br_1=0;
int br_2=0;
int br_3=0;
do {
int cifra =std::abs (n%3);
if(cifra==2) br_1++;
else if (cifra==1) br_2++;
else if (cifra==0) br_3++;
n/=3;

} while  (n!=0); 
if((br_1%2==0 || br_1==0) && (br_2%2==0 || br_2==0) && (br_3%2==0 || br_3==0)) return 1;
else if ((br_1%2==1 || br_1==0) && (br_2%2==1 || br_2==0) && (br_3%2==1 || br_3==0)) return 0;
else return -1;
}

std::vector<int> IzdvojiGadne (std::vector<int> sistem, bool x) {
for(int i=0;i<sistem.size();i++) {
for(int j=i+1;j<sistem.size();j++) {
	if(sistem[i]==sistem[j]) {
		sistem.erase(sistem.begin()+j);
		j--;
	}
}	
}	
std::vector<int> brojni;
std::vector<int> brojevi;
for(int i=0;i<sistem.size();i++) {
if(BrojniSistem(sistem[i])==1) brojni.push_back(sistem[i]);
else if (BrojniSistem(sistem[i]==0)) brojevi.push_back(sistem[i]);
}

if(x==true) return brojni;
else return brojevi;


	
}

int main ()
{
int m;
std::cout<<"Unesite brojeve (0 za prekid unosa): ";

std::vector<int> sistem;
while (m!=0){
std::cin>>m;
if(m==0) break;
sistem.push_back (m);
}
std::cout<<"Opaki: ";
for (int k: IzdvojiGadne(sistem,true)) { std::cout<<k<<" ";}
std::cout<<std::endl;
std::cout<<"Odvratni: ";
for (int h: IzdvojiGadne(sistem,false)) {std::cout<<h<<" ";}

	return 0;
}