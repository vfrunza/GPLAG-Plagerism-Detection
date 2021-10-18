#include <iostream>
#include <vector>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
vector<vector<double>> RastuciPodnizovi ( vector<double>metallica )
{
	vector<vector<double>> iron_maiden;
	vector<int>indexi;
	vector<double>za_ubaciti;
	for(int i(0);i<metallica.size()-1;i++)
	{
		while(metallica[i]<=metallica[i+1])
		{
			indexi.push_back(i);//paamtimo indexe
			i++;
			if(i==metallica.size()-1)break;
		}
		indexi.push_back(i);
		if(indexi.size()>=2){
		for(int j(0);j<indexi.size();j++)
			za_ubaciti.push_back(metallica.at(indexi.at(j)));
		iron_maiden.push_back(za_ubaciti);
		}
		za_ubaciti.resize(0);
		indexi.resize(0);
	}	
		
	return iron_maiden; //treba vratiti vektor vektora
}
vector<vector<double>> OpadajuciPodnizovi ( vector<double>metallica )
{
	vector<vector<double>> iron_maiden;
	vector<int>indexi;
	vector<double>za_ubaciti ;
	for(int i(0);i<metallica.size()-1;i++)
	{
		while(metallica.at(i)>=metallica.at(i+1))
		{
			indexi.push_back(i);
			i++;
			if(i==metallica.size()-1)break;
		}
		indexi.push_back(i);
		if(indexi.size()>=2){
		for(int j(0);j<indexi.size();j++)
			za_ubaciti.push_back(metallica.at(indexi.at(j)));
		iron_maiden.push_back(za_ubaciti);
		}
		za_ubaciti.resize(0);
		indexi.resize(0);
	}
	return iron_maiden;//treba vratiti vektor vektora
}
int main ()
{
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	std::vector<double> glavni;
	cout << "Unesite elemente vektora: ";
	double unos;
	for(int i(0);i<n;i++)
	{
		cin >> unos;
		glavni.push_back(unos);
	}
	cout << "Maksimalni rastuci podnizovi: "<<endl;
	auto rastuci(RastuciPodnizovi(glavni));
	for(auto x:rastuci)
	{
	 	for(auto y:x)cout<<std::setprecision(12)<<y<<" ";
	 	cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	auto opadajuci(OpadajuciPodnizovi(glavni));
	for(auto x:opadajuci)
	{
		for(auto y:x)cout<<std::setprecision(12)<<y<<" ";
		cout<<endl;
	}
	return 0;
}