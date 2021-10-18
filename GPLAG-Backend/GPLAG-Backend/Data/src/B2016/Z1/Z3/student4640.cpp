#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> matrica;
matrica RastuciPodnizovi(std::vector<double> v){
	int i=0,br=0,vel=0;
	matrica rez;
	while(i<v.size()-1){
		if(v[i]<=v[i+1]){
			br=0;
			for(int j=i;j<v.size()-1;j++)if(v[j]<=v[j+1]){
				if(j+1>=v.size())break;
				br++;
			}
			else break;
			rez.push_back({});
			for(int k=i;k<=(i+br);k++)rez[vel].push_back(v[k]);
			vel++;
			i+=br;
		}
		if(i>v.size())break;
		i++;
	}
	return rez;
}
matrica OpadajuciPodnizovi(std::vector<double> v){
	int i=0,br,vel=0;
	matrica rez;
	while(i<v.size()-1){
		if(v[i]>=v[i+1]){
			br=0;
			for(int j=i;j<v.size()-1;j++)if(v[j]>=v[j+1]){
				if(j+1>=v.size())break;
				br++;
			}
			else break;
			rez.push_back({});
			for(int k=i;k<=(i+br);k++)rez[vel].push_back(v[k]);
			vel++;
			i+=br;
		}
		if(i>v.size())break;
		i++;
	}
	return rez;
}
int main(){
	matrica rez;
	std::cout<<"Unesite broj elemenata vektora: ";
	int vel;
	std::cin>>vel;
	std::vector<double>v;
	v.resize(vel);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++)std::cin>>v[i];
	std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
	rez=RastuciPodnizovi(v);
	for(std::vector<double> temp : rez){
		for(auto x : temp)std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	rez=OpadajuciPodnizovi(v);
		for(std::vector<double> temp : rez){
		for(auto x : temp)std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}