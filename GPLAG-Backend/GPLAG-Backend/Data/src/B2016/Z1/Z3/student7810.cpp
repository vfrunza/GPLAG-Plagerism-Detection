/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

	vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> m;
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) break;
		if(v.at(i)<=v.at(i+1)){
			int j=i;
			vector<double> a;
			while(v.at(j)<=v.at(j+1) && j<v.size()){
				a.push_back(v.at(j));
				j++;
				if(j==v.size()-1) break;
			}
			a.push_back(v.at(j));
			m.push_back(a);
			i=j;
		}
	}
	return m;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> op){
	vector<vector<double>> m1;
	for(int i=0;i<op.size();i++){
		if(i==op.size()-1) break;
		if(op.at(i)>=op.at(i+1)){
			int j=i;
			vector<double> a1;
			while(op.at(j)>=op.at(j+1) && j<op.size()){
				a1.push_back(op.at(j));
				j++;
				if(j==op.size()-1) break;
			}
			a1.push_back(op.at(j));
			m1.push_back(a1);
			i=j;
		}
	}
	return m1;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<double> v ;
	for(int i=0;i<n;i++){
		double x;
		cin>>x;
		v.push_back(x);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	vector<vector<double>> rastuci=RastuciPodnizovi(v);
	for(int i=0;i<rastuci.size();i++){
		for(int j=0;j<rastuci[i].size();j++){
			cout<<rastuci[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	vector<vector<double>> opadajuci=OpadajuciPodnizovi(v);
	for(int i=0;i<opadajuci.size();i++){
		for(int j=0;j<opadajuci[i].size();j++){
			cout<<opadajuci[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}