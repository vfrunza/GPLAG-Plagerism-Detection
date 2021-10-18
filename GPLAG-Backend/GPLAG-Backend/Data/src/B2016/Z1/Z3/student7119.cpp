#include <iostream>
#include <vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> V) {
	std::vector<std::vector<double>> M;
	int a(0);
	for(int i(0);i<V.size()-1;i++) {
		
		if(V[i]<=V[i+1]) { 
		int j=i;
		while(j!=V.size()-1 && V[j]<=V[j+1] ) {
			j++;
			}
			
		M.push_back(std::vector<double> (0));
			M[a].resize(j-i+1);
			int p(0);
			for(int k=i;k<=j;k++) {
				M[a][p]=V[k];
				p++;
				i++;
			} 
			i--;
			a++;	
		}
		else if(V[i]>V[i+1]) i++;
		i--;	
	}
	return M;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> V) {
	std::vector<std::vector<double>> M;
	int a(0);
	for(int i(0);i<V.size()-1;i++) {
		
		if(V[i]>=V[i+1]) { 
		int j=i;
		while(j!=V.size()-1 && V[j]>=V[j+1] ) { j++;
			}
			
			
		M.push_back(std::vector<double> (0));
			M[a].resize(j-i+1);
			int p(0);
			for(int k=i;k<=j;k++) {
				M[a][p]=V[k];
				p++;
				i++;
			} 
			i--;
			a++;	
		}
			else if(V[i]<V[i+1]) i++;
			i--;
	}
	return M;
}


int main ()
{
	
	
int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double> V(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<V.size();i++) {
		std::cin>>V[i];
	}
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> M;
	M=RastuciPodnizovi(V);
	for(int i(0);i<M.size();i++) {
		for(int j(0);j<M[i].size();j++) {
			std::cout<<M[i][j]<<" ";
			
		}
		std::cout<<std::endl;
	}

	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	std::vector<std::vector<double>> M1;
	M1=OpadajuciPodnizovi(V);
	for(int i(0);i<M1.size();i++) {
		for(int j(0);j<M1[i].size();j++) {
			std::cout<<M1[i][j]<<" ";
			
		}
		std::cout<<std::endl;
	}
		return 0;
	}