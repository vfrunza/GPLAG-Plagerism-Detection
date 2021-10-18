/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> DVector;
using std::cout;
using std::cin;
using std::endl;





int PrebrojRastuci(DVector a){
	int i(0),br(0);
	while(i<a.size()){
		if(i==a.size()-1)break;
		if(a[i]<=a[i+1]){
			
			while(a[i]<=a[i+1]){
				i++;
				if(i==a.size()-1)break;
			}
			br++;
		}
		if(i==a.size()-1)break;
		i++;
	}
	
	return br;
}
int PrebrojOpadajuci(DVector a){
	
	int br(0),i(0);
	while(i<a.size()){
		
		if(a[i]>=a[i+1]){
			while(a[i]>=a[i+1]){
				i++;
				if(i==a.size()-1)break;
			}
			br++;
		}
		if(i==a.size()-1)break;
		i++;
		if(i==a.size()-1)break;
	}
	
	return br;
}

Matrica RastuciPodnizovi (DVector a){
	int red(PrebrojRastuci(a));
	Matrica h(red);
	int br(0);
	for(int i(0);i<a.size();i++){
		if(i==a.size()-1)break;
		if(a[i]<=a[i+1]){
			DVector k;
			k.push_back(a[i]);
			
			while(a[i]<=a[i+1]){
				k.push_back(a[i+1]);
				i++;
				if(i==a.size()-1)break;
			}
		h[br]=k;
		br++;
		
	}if(i==a.size()-1)break;
	}
	return h;
}

Matrica OpadajuciPodnizovi(DVector a){
	int red(PrebrojOpadajuci(a));
	Matrica h(red);
	int br(0);
	for(int i(0);i<a.size();i++){
		if(i==a.size()-1)break;
		if(a[i]>=a[i+1]){
			DVector k;
			k.push_back(a[i]);
			while(a[i]>=a[i+1]){
				k.push_back(a[i+1]);
				i++;
				if(i==a.size()-1)break;
			}
			h[br]=k;
			br++;
		}
		if(i==a.size()-1)break;
	
	
	}
	
	return h;
}




int main ()
{
	
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	DVector a;
	for(int i(0);i<n;i++){
		double br;
		cin>>br;
		a.push_back(br);
	}
	
	Matrica b(RastuciPodnizovi(a));
	
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(int i(0);i<b.size();i++){
			for(int j(0);j<b[i].size();j++)
				cout<<b[i][j]<<" ";
			cout<<endl;
			
		}
		Matrica c(OpadajuciPodnizovi(a));
	cout<<"\nMaksimalni opadajuci podnizovi: "<<endl;
		for(int i(0);i<c.size();i++){
			for(int j(0);j<c[i].size();j++)
				cout<<std::setprecision(12)<<c[i][j]<<" ";
			cout<<endl;
			
		}
	
	
	return 0;
}