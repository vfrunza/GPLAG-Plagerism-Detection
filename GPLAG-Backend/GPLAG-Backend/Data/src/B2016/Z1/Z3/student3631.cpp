/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include<vector>
#include<cstdio>
#include<iomanip>

using namespace std;
typedef vector<vector<double>> Matrica;

Matrica RastuciPodnizovi (vector<double> a){
	Matrica rastuci;
   vector<double> pod;
 
for(int i=0;i<a.size()-1;i++){
pod.clear();
while(i<a.size()-1 && a[i]<=a[i+1]){
	pod.push_back(a[i]);
	i++;
}  pod.push_back(a[i]);

if(pod.size()-1>0) rastuci.push_back(pod);
}

return rastuci; }



Matrica OpadajuciPodnizovi (vector<double> a){
	Matrica opadajuci;
    vector<double> podniz;
    int j=0;
for(int j=0;j<a.size()-1;j++){
	podniz.clear();
	while(j<a.size()-1 && a[j]>=a[j+1]){
	podniz.push_back(a[j]);
	j++;}   podniz.push_back(a[j]);
	
if(podniz.size()-1>0)
opadajuci.push_back(podniz);
	
	
}
   
	return opadajuci;
}


int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	Matrica rastuci1;
	Matrica opadajuci1;
	
	rastuci1=RastuciPodnizovi(a);
	opadajuci1=OpadajuciPodnizovi(a);
	
	for(auto niz1: rastuci1){
		for(auto broj1: niz1){
			cout<<setprecision(12)<<broj1<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(auto niz2: opadajuci1){
		for(auto broj2: niz2){
			cout<<setprecision(12)<<broj2<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}