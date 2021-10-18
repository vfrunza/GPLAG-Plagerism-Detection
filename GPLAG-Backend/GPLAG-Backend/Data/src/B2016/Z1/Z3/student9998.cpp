#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double>v){
	Matrica mat;
	if(v.size()==0) return mat;
	for(int i=0;i<v.size()-1;i++){
		std::vector<double>v1;
		int k=1;
		if(v[i]<=v[i+1]){
			for(int j=i+1;j<v.size()-1;j++){
				if(v[j]<=v[j+1]) k++;
			    else break;
			}
			for(int p=i;p<=i+k;p++)
				v1.push_back(v[p]);
			i+=(k-1);
			mat.push_back(v1);
			
		}
	}
	return mat;
}

Matrica OpadajuciPodnizovi (std::vector<double>v){
	Matrica mat;
	if(v.size()==0) return mat;
	for(int i=0;i<v.size()-1;i++){
		std::vector<double>v1;
		int k=1;
		if(v[i]>=v[i+1]){
			for(int j=i+1;j<v.size()-1;j++){
				if(v[j]>=v[j+1]) k++;
				else break;
			}
			for(int p=i;p<=i+k;p++)
				v1.push_back(v[p]);
			i+=k-1;
			mat.push_back(v1);
		}
	}
	return mat;
}

void IspisiMatricu (Matrica m){
	for(std::vector<double> red: m){
		for(double x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
}

int main ()
{
	int n;
	double x;
	std::vector<double>v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica m=RastuciPodnizovi(v);
	IspisiMatricu(m);
	std::cout<<std::endl;
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica m1=OpadajuciPodnizovi(v);
	IspisiMatricu(m1);
	return 0;
}