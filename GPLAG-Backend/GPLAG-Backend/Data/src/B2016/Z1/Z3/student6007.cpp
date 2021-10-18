#include <iostream>
#include <vector>

int BrojPodnizova(std::vector<double> v){
	int broj(0);
	int j = 0;
	for(int i=0; i<v.size()-1;i++){
		j=i;
		while(v[i]<v[i+1]) i++;
			broj++;
			if(j==i-1 && i!=v.size()-2) broj--;
			
	}
	return broj;
}
std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> pomocni;
	int velicina = BrojPodnizova(v);
	pomocni.resize(velicina);
	for(int i=0; i<pomocni.size();i++)
		pomocni[i].resize(0);
	
	for(int i=0; i<pomocni.size(); i++){
		for(int j=0; j<v.size()-1; j++){
		while (v[j+1]<v[j]) {
			pomocni[i].push_back(v[j]);
			pomocni[i].push_back(v[j+1]);
		}
		if(pomocni[i].size()==0 || pomocni[i].size()==1) i--;
		}
	}
	return pomocni;
}
int main () {
	std::vector<double> niz = {1,3, 2, 6, 7, 9,10, 4, 3,1,7};
	std::vector<std::vector<double>> poziv;
	poziv = RastuciPodnizovi(niz);
	for(int i = 0; i<poziv.size(); i++){
		for(int j=0;j<poziv[0].size(); j++){
			std::cout<<" "<<poziv[i][j];
		}
		std::cout<<std::endl;
	}

	return 0;
}