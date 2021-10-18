/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
 #include<iostream>
 #include<vector>
 
#include <iomanip>
 
using namespace std;

vector<vector<double>> KreirajMatricu(int br_redova, int br_kolona) {
 return vector<vector<double>>(br_redova, vector<double>(br_kolona));
}

 vector<vector<double>> RastuciPodnizovi(vector<double>v){
	
	
	vector<vector<double>> mat=KreirajMatricu(0,0);
    if(v.size()<=1)return mat;
    int red=1;
    
    for(int i=0; i<v.size();i++){
      	int pocetak=i;
      	if(i==v.size()-1)break;
      	while(i!=v.size()-1 and v[i]<=v[i+1]){
      	if(i+1==v.size()-1){i++; break;}
      	i++;
      	}
      	int kraj=i;
      	if(kraj==pocetak)continue;
        mat.resize(red);
        mat[red-1].resize(kraj-pocetak+1);
        int p=pocetak;
        
        for(int j=0;j<kraj-p+1;j++){
        	mat[red-1][j]=v[pocetak];
        	pocetak++;
        	if(pocetak>kraj)break;
        }
        red++;
      	
      }
		
		
		
		return mat;
	}


    
 vector<vector<double>> OpadajuciPodnizovi(vector<double>v){
	
	
	vector<vector<double>> mat=KreirajMatricu(0,0);
	if(v.size()<=1)return mat;
    
    int red=1;
    
    for(int i=0; i<v.size()-1;i++){
      	int pocetak=i;
      	while(i!=v.size()-1 and v[i]>=v[i+1]){
      	if(i+1==v.size()-1){i++; break;}
      	i++;
      	}
      	int kraj=i;
      	if(kraj==pocetak)continue;
        mat.resize(red);
        mat[red-1].resize(kraj-pocetak+1);
        int p=pocetak;
        
        for(int j=0;j<kraj-p+1;j++){
        	mat[red-1][j]=v[pocetak];
        	pocetak++;
        	if(pocetak>kraj)break;
        }
        red++;
      	
      }
		
		
		
		return mat;
	}
   


int main (){
	
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<double>v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		double a;
		cin>>a;
		v.push_back(a);
	}
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	vector<vector<double>> mat=RastuciPodnizovi(v);
	for(int i=0;i<mat.size();i++){
		for(int j=0; j<mat[i].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	vector<vector<double>> mat1=OpadajuciPodnizovi(v);
	for(int i=0;i<mat1.size();i++){
		for(int j=0; j<mat1[i].size();j++){
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}