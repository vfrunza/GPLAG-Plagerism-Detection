/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int>Gadno(vector<int>,bool);
int Opak(int);
bool OpakiNije(int);
int VratiKakoTreba(int);
	int main ()
{
	vector<int>vector(5),novivektor;
	for(int i=0;i<vector.size();i++) {
		cout<<"Unesite "<<i+1<<" element vektora: ";
		cin>>vector[i];
	}
	for(int i=0;i<vector.size();i++) {
		cout<<vector[i]<<" ";
	}
	for(int i=0;i<vector.size();i++) {
		vector[i]=Opak(vector[i]);
	}
	cout<<endl;
	novivektor=Gadno(vector,true);
	for(int i=0;i<novivektor.size();i++) {
		cout<<novivektor[i]<<" ";
	}
	system("Pause");
		return 0;
}
int VratiKakoTreba(int broj) {
	int brojac=0,temp,suma=0;
	temp=broj;
	while(temp) {
		temp/=10;
		brojac++;
}
for(int i;i<brojac;i++) {
	temp=broj%10;
	suma+=temp*pow(3,i);
	broj/=10;
}
return suma;
}
vector<int>Gadno(vector<int>Vektorcic, bool jestNije) {
	vector<int>noviVektor;
	for (int i=0;i<noviVektor.size();i++) {
		if(OpakiNije(Vektorcic[i])) {
			noviVektor.push_back(VratiKakoTreba(Vektorcic[i]));
		}
	}
	return noviVektor;
}
int Opak (int broj) {
	int temp=0,brojac=0,novibr=0;
	do {
		if(broj<3) {
			novibr+=broj *pow(10,brojac);
			break;
		}
		else temp=broj/3;
		novibr+=(broj%3)* pow(10,brojac);
	} while(broj);
		broj=temp;
	brojac++;
	while(broj) {
return novibr;
}
bool OpakiNije(int broj) {
	int p1=0,p2=0,p3=0,temp;
	while(broj) {
		temp=broj%10;
		if(temp==0)p1++;
		if(temp==1)p2++;
		if(temp==2)p3++;
		broj/=10;
	}
	if(p1%3!=0 || p2%2!=0 || p3%3!=0) return false;
	return true;
}
return 0;
}