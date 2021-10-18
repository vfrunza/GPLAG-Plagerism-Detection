#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <float.h>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(vector<double> V){
	Matrica M;
	int k{},j{};
	if(V.size()==0)
		return M;
	for(int i=0; i<int(V.size())-1; i++){
			if(V[i]<=V[i+1] || fabs(V[i]-V[i+1])<DBL_MIN){
			M.resize(1+k);
			for(j=i; j<int(V.size())-1; j++){
				if(V[j]<V[j+1] || fabs(V[j]-V[j+1])<DBL_MIN){
					M[k].push_back(V[j]);
				}
				else{
					M[k].push_back(V[j]);
					break;
				}
			
			}
			if(j==int(V.size())-1){
				M[k].push_back(V[j]);
			}
			i=j;
			k++;
		}
		if(i==int(V.size())-2)
            break;
	}
	return M;
}
Matrica OpadajuciPodnizovi(vector<double> V){
	Matrica M;
	int k{},j{};
	if(V.size()==0)
		return M;
	for(int i=0; i<int(V.size())-1; i++){
		if(V[i]>V[i+1] || fabs(V[i]-V[i+1])<DBL_MIN){
			M.resize(1+k);
			for(j=i; j<int(V.size())-1; j++){
				if(V[j]>V[j+1] || fabs(V[j]-V[j+1])<DBL_MIN){
					M[k].push_back(V[j]);
				}
				else{
					M[k].push_back(V[j]);
					break;
				}
				if(j==int(V.size())-1)
            		break;
			}
			if(j==int(V.size())-1){
				M[k].push_back(V[j]);
			}
			i=j;
			k++;
		}
		if(i==int(V.size())-2)
            break;
	}
	return M;
	
}
int main ()
{

	int n;
	std::vector<double> V;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	Matrica Rastuci;
	Matrica Opadajuci;
	cout<<"Unesite elemente vektora: ";
	if(n>0){
		double k;
		int i{};
		while(i!=n){
			cin>>k;
			V.push_back(k);
			i++;
		}
		Rastuci=RastuciPodnizovi(V);
		Opadajuci=OpadajuciPodnizovi(V);
	}

	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	 for(std::vector<double> red : Rastuci) {
      for(double x : red) std::cout <<std::setprecision(10) << x<<" ";
            std::cout << std::endl;
   }
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;;
   	for(std::vector<double> red : Opadajuci) {
      for(double x : red) std::cout <<std::setprecision(10) << x<<" ";
            std::cout << std::endl;
   }
	
	return 0;
}