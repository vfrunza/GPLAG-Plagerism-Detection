#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

#define EPSILON 0.00000000001

typedef vector<vector<double>> Matrica;

void IspisiMatricu (Matrica m){
   for (vector<double> red : m){
      
      for(double x : red) cout  <<  x << " ";
      cout << std::endl;
   }
}


int BrojRastucihPodnizova(vector<double> v){
	int broj(0);
	for (int i(0); i<v.size()-1; i++){
         if (v[i]<=v[i+1]){
         	broj++;
         	for (int k(i); k<v.size()-1; k++){
         		if (v[k]>v[k+1]) break;
         		i++;
         	}
         }
         
	}
	return broj;
}

int BrojOpadajucihPodnizova(vector<double> v){
	int broj(0);
	for (int i(0); i<v.size()-1; i++){
         if (v[i]>=v[i+1]){
         	broj++;
         	for (int k(i); k<v.size()-1; k++){
         		if (v[k]<v[k+1]) break;
         		i++;
         	}
         }
         
	}
	return broj;
}


Matrica RastuciPodnizovi(vector<double> v){
	Matrica a(BrojRastucihPodnizova(v));
	int k(0);
	bool prvi(true);
	for (int i(0); i<v.size()-1; i++){
				if (v[i]<v[i+1] or ((v[i]-v[i+1])<EPSILON)) { if (prvi) a[k].push_back(v[i]); a[k].push_back(v[i+1]); 
		 }
		else { 
			while (v[i]>v[i+1]) {
				i++;
				if ((i+1)==v.size()-1) break;
			}
			if (i==v.size()) break;
			
			if ((i>0) && (v[i]<v[i-1]) && (v[i]<v[i+1])) { i--; if ((i<v.size()-1) && (v[i+1]<v[i+2])){ k++; a[k].push_back(v[i+1]); }   continue; }
			k++; 
			prvi=true; 
			continue; 
			
		}
		
		
		
		prvi=false;
	}
	return a;
}

Matrica OpadajuciPodnizovi(vector<double> v){
	Matrica a(BrojOpadajucihPodnizova(v));
	int k(0);
	bool prvi(true);
	
	for (int i(0); i<v.size()-1; i++){
		if (i==v.size()) break;
		
		
		if (v[i]>v[i+1] or ((v[i+1]-v[i])<EPSILON)) { if (prvi) a[k].push_back(v[i]);
		     a[k].push_back(v[i+1]); 
		 }
		
		else { 
			while (v[i]<v[i+1]) {
				i++;
				if ((i+1)==v.size()-1) break;
		
			}
			if ((i>0) && (v[i]>v[i-1]) && (v[i]>v[i+1])) { i--;   continue; }
			k++; 
			prvi=true; 
			continue; 
			
		}
		
		
		
		prvi=false;
	}
	return a;
}



int main ()
{
	
	cout << "Unesite broj elemenata vektora: ";
	int n;
	cin >> n;
	
	cout << "Unesite elemente vektora: ";
	vector <double>  vektor;
	for (int i(0); i<n; i++){
		double a;
		cin >> a;
		vektor.push_back(a);
	}
	
	Matrica rastuca;
/*	int a,b;
a=BrojRastucihPodnizova(vektor);
b=BrojOpadajucihPodnizova(vektor);
	cout<< a << endl << b << endl;
	*/
	rastuca = RastuciPodnizovi(vektor);
	Matrica opadajuca;
	
	opadajuca = OpadajuciPodnizovi(vektor);
cout<< "Maksimalni rastuci podnizovi: " << endl;
  IspisiMatricu(rastuca);
cout<< "Maksimalni opadajuci podnizovi: " << endl;
IspisiMatricu(opadajuca);
	
	return 0;
}