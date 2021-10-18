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

vector<vector<double>> RastuciPodnizovi(vector<double> uneseni){
	vector<vector<double>> povratni;
	vector<double> temp;
	for(unsigned int i=0;i<uneseni.size();i++){
		if(((i+1)<uneseni.size()) && (uneseni.at(i)<=uneseni.at(i+1))){
	if(temp.size()==0){
		temp.push_back(uneseni.at(i));
		temp.push_back(uneseni.at(i+1));
		
	}
	else if(temp.size()!=0){
		temp.push_back(uneseni.at(i+1));
	}
			
	}
	else{
		povratni.push_back(temp);
		temp.clear();
	}
		
	}
	
	return povratni;
	
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> uneseni)
{
	vector<vector<double>> povratni;
	vector<double> temp;
	for(unsigned int i=0;i<uneseni.size();i++){
		if(((i+1)<uneseni.size())&& (uneseni.at(i)>=uneseni.at(i+1))){
			if(temp.size()==0){
			temp.push_back(uneseni.at(i));
			temp.push_back(uneseni.at(i+1));
		}
else if(temp.size()!=0){
		temp.push_back(uneseni.at(i+1));
	}
		}
		else
		{
		povratni.push_back(temp);
		temp.clear();
		
	}
	
}
return povratni;
	
}

int main ()
{	
	
	vector<double>parametralni;
	int br_el(0), element(0);
	cout<<"Unesite broj elemenata vektora: ";
	cin>>br_el;
	cout<<"Unesite elemente vektora: ";
	for(int i(0);i<br_el;i++){
		cin>>element;
		parametralni.push_back(element);
	}
	
cout<<"Maksimalni rastuci podnizovi: ";
cout<<endl;
 vector<vector<double>>	rastuci_podniz =RastuciPodnizovi(parametralni);
	
	for(unsigned int i(0);i<rastuci_podniz.size();i++)
	{
		for(unsigned int j(0);j<rastuci_podniz[i].size();j++){
			
			cout<< rastuci_podniz[i][j]<<" ";
		
		}
	cout<<endl;
	}
	cout<<endl;
	
	cout<<"Maksimalni opadajuci podnizovi: ";
	
vector<vector<double>> opadajuci_podniz=OpadajuciPodnizovi(parametralni);

	  for(unsigned int i(0);i<opadajuci_podniz.size();i++){
	  	
	  	for(unsigned int j(0);j<opadajuci_podniz[i].size();j++){
	  		
	  		cout<<opadajuci_podniz[i][j]<<" "; 
	  		
	  	}
	  		cout<<endl; 
	  	
	  	}
	  
	return 0;
}