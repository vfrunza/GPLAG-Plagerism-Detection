#include <iostream>
#include <vector>
#include <iomanip>

void IspisiMatricu(std::vector<std::vector<double>> Mat){
		for(std::vector<double> red: Mat){
		for(double x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v){
	std::vector<std::vector<double>>Matrica(6);
int n(v.size()),br_redova(0);
if(v[0]<=v[1]) Matrica[br_redova].push_back(v[0]);
for(int i=1;i<n;i++){
	if(i!=n-1 and v[i]>=v[i-1] ) Matrica[br_redova].push_back(v[i]);
	else if( (i+1)<n and  v[i]<=v[i+1]){
		br_redova++;
		Matrica[br_redova].push_back(v[i]);
	}
	else if( (i+1)>=n and v[i]>=v[i-1]){
		Matrica[br_redova].push_back(v[i]);
	}
}
return  Matrica;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v){
std::vector<std::vector<double>>Matrica(6);
int n(v.size()),br_redova(0);
if(v[0]>=v[1]) Matrica[br_redova].push_back(v[0]);
for(int i=1;i<n;i++){
	if(i!=n-1 and v[i]<=v[i-1]) Matrica[br_redova].push_back(v[i]);
	else if((i+1)<n  and v[i]>=v[i+1] ){
		br_redova++;
		Matrica[br_redova].push_back(v[i]);
	}
	else if( (i+1)>=n and v[i]<=v[i-1]){
		Matrica[br_redova].push_back(v[i]);
	}
	
}
return  Matrica;
}
int main ()
{   std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::vector<double>v(n);
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
    	std::cin>>v[i];
    }
	std::vector<std::vector<double>>Mat;
	std::vector<std::vector<double>>Mat2;
	Mat=RastuciPodnizovi(v);
	Mat2=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
	IspisiMatricu(Mat);
	std::cout<<"Maksimalni opadajuci podnizovi:"<<std::endl;
	IspisiMatricu(Mat2);
	return 0;
}