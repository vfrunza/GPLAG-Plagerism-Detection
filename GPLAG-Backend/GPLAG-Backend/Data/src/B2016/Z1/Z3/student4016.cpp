/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;

vector <vector<double>> RastuciPodnizovi(vector<double> realbr){
	
	vector <vector<double>> pomocni;
	vector <double> pomocni2;
	for (int i=0; i<realbr.size()-1; i++){
		pomocni2.resize(0);
		int a;
		if(realbr[i]<=realbr[i+1]){
			pomocni2.push_back(realbr[i]);
			
			for (int j=i; j<realbr.size()-1; j++){
				if(realbr[j]<=realbr[j+1]){
				pomocni2.push_back(realbr[j+1]);
				a=j+1;
			} else break;
		}
		
	}
	if(pomocni2.size()==0){
		
	} else {
	pomocni.push_back(pomocni2);
	i=a;
		
	}
	
}
	return pomocni;
}
vector <vector<double>> OpadajuciPodnizovi(vector<double> realbr2){
	vector<vector<double>>pomocniop;
	vector <double> pomocni3;
	int b;
	for (int i=0; i<realbr2.size()-1; i++){
		pomocni3.resize(0);
		if(realbr2[i]>=realbr2[i+1]){
			pomocni3.push_back(realbr2[i]);
		
		for (int j=i; j<realbr2.size()-1; j++){
			if(realbr2[j]>=realbr2[j+1]){
				pomocni3.push_back(realbr2[j+1]);
				b=j+1;
			} else break;
			
		}
		}
	 if(pomocni3.size()==0 || b<i){
	}
	else {
		pomocniop.push_back(pomocni3);
		i=b;
	}
	}
	return pomocniop;
}
int main ()
{
	int n;
	vector <double> pomocni;
	cout <<"Unesite broj elemenata vektora: ";
	cin >>n;
	cout <<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++){
		double m;
		cin >>m;
		pomocni.push_back(m);
	}
	vector <vector<double>> referentni(RastuciPodnizovi(pomocni));
	cout <<"Maksimalni rastuci podnizovi: \n";
	for (int i=0; i<referentni.size(); i++){
		for (int j=0; j<referentni[i].size(); j++){
			cout <<referentni[i][j]<<" ";
		} cout <<endl;
	}
	cout <<"Maksimalni opadajuci podnizovi: \n";
	referentni=OpadajuciPodnizovi(pomocni);
	for (int k=0; k<referentni.size(); k++){
		for (int s=0; s<referentni[k].size(); s++){
			cout <<referentni[k][s]<<" ";
		} cout <<endl;
	}
	return 0;
}