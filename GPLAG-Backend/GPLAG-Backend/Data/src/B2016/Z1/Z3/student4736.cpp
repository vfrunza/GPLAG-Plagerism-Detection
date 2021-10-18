#include<iostream>
#include<vector>
#include<iomanip>


using namespace std;


typedef vector<double> Vektor;
typedef vector<vector<double>> Matrica;


Matrica RastuciPodnizovi(Vektor v){
	Matrica rezultat;
	Vektor red;
	
	for(int i=0;i<v.size()-1;i++){
		
		if(v[i]<=v[i+1]){
			red.push_back(v[i]);
			if(i==v.size()-2){
				red.push_back(v[i+1]);
				rezultat.push_back(red);
			}
			
		}
		else{
			red.push_back(v[i]);
			if(red.size()>=2){
				rezultat.push_back(red);
			}
			red = Vektor();
		}
	}
	
	return rezultat;
}





Matrica OpadajuciPodnizovi(Vektor v){
	Matrica rezultat;
	Vektor red;
	
	for(int i=0;i<v.size()-1;i++){
		
		if(v[i]>=v[i+1]){
			red.push_back(v[i]);
			if(i==v.size()-2){
				red.push_back(v[i+1]);
				rezultat.push_back(red);
			}
			
		}
		else{
			red.push_back(v[i]);
			if(red.size()>=2){
				rezultat.push_back(red);
			}
			red = Vektor();
		}
	}
	
	return rezultat;
}


void ispisiMatricu(Matrica M){
	
	for(int i=0;i<M.size();i++){
		
		for(int j=0;j<M[i].size();j++){
		
				//cout<<left<<setw(4)<<M[i][j];
				cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main ()
{
	int brojElemenata;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>brojElemenata;
	Vektor v(brojElemenata);
	
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<v.size();i++){
		cin>>v[i];
	}
	
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	Matrica RP = RastuciPodnizovi(v);
	ispisiMatricu(RP);
	
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;	
	Matrica OP = OpadajuciPodnizovi(v);
	ispisiMatricu(OP);
	
	return 0;
}