/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
vector<vector<double>> RastuciPodnizovi(vector<double> v){
	vector<vector<double>> novi;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]<v[i+1] || v[i]-v[i+1]<0.0000000001){
			vector<double> h;
			h.push_back(v[i]);
			while((v[i]<v[i+1] || v[i]-v[i+1]<0.0000000001) && i!=v.size()-2){
				h.push_back(v[i+1]);
				i++;
			}
			if(i==v.size()-2 && (v[i]<v[i+1] || v[i]-v[i+1]<0.0000000001))
			h.push_back(v[i+1]);
			novi.push_back(h);
		}
	}
	return novi;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> v){
	vector<vector<double>> novi;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]>v[i+1] || v[i+1]-v[i]<0.0000000001){
			vector<double> h;
			h.push_back(v[i]);
			while((v[i]>v[i+1] || v[i+1]-v[i]<0.0000000001) && i!=v.size()-2){
				h.push_back(v[i+1]);
				i++;
			}
			if(i==v.size()-2 && (v[i]>v[i+1] || v[i+1]-v[i]<0.0000000001))
			h.push_back(v[i+1]);
			novi.push_back(h);
			
		}
	}
	return novi;
}
int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double> v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		v.push_back(h);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	vector<vector<double>> novi=RastuciPodnizovi(v);
	for(int i=0;i<novi.size();i++){
		for(int j=0;j<novi[i].size();j++){
			cout<<novi[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	novi=OpadajuciPodnizovi(v);
	for(int i=0;i<novi.size();i++){
		for(int j=0;j<novi[i].size();j++){
			cout<<novi[i][j]<<" ";
		}
		cout<<endl;
	}
	 /*std::vector<double> brojevi {0.1111111111, 0.1111111119, 0.11, 0.1, -0.11, -0.111};
    std::vector<std::vector<double>> rastuci {RastuciPodnizovi(brojevi)}, opadajuci {OpadajuciPodnizovi(brojevi)};

	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for (auto niz : rastuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }

	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    for (auto niz : opadajuci)
    {
        for (auto broj : niz)
            std::cout << std::setprecision(12) << broj << " ";
        std::cout << std::endl;
    }*/
	
	return 0;
}