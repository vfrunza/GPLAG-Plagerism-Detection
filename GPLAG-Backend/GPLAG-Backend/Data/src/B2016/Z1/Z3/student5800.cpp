#include <iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>> m;
	for(int i=0;i<v.size();i++){
		std::vector<double> a;
		while(i!=v.size()-1 && v[i+1]>=v[i] ){
			a.push_back(v[i]);
			i++;
		}
		if(v[i]>=v[i-1] && i!=0)a.push_back(v[i]);
		if(a.size()!=0)m.push_back(a);
	}
	return m;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>m;
	for(int i=0;i<v.size();i++){
		std::vector<double>a;
		while (i!=v.size()-1 && v[i+1]<=v[i] ) {
			a.push_back(v[i]);
			i++;
		}
		if( i!=0 && v[i]<=v[i-1] )a.push_back(v[i]);
		if(a.size()!=0)m.push_back(a);
	}
	return m;
}
void Ispisi(std::vector<std::vector<double>>m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++)
		std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	//std::vector<double>v(n);
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	double br;
	for(int i=0;i<n;i++){
		std::cin>>br;
		v.push_back(br);
	}
		//std::cin>>v[i];
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Ispisi(RastuciPodnizovi(v));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Ispisi(OpadajuciPodnizovi(v));
	return 0;
}