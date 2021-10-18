/*B 2016/2017, Zadaća 1, Zadatak 3
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.*/
	
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
const double Eps = 0.0000000001;
typedef vector<vector<double>>Matrica;


bool JesuLiJednaki (double x, double y){
	return fabs(x-y)<=Eps*(fabs(x)+fabs(y));
}
 
Matrica RastuciPodnizovi (vector<double>v1){
	Matrica mat;
	int m=1;
	vector<double>v;
	//Ako je prazan proslijedjeni vektor
	if(v1.size()==0)return mat;
	//AKo su svi isti
	double clan=v1[0];
	int br=0;
	for(int i(0);i<v1.size();i++){
		if(JesuLiJednaki(v1[i],clan))
		br++;
	}
	if(v1.size()==br){
		
		mat.resize(1);
		mat[0].resize(br);
		for(int i(0);i<br;i++){
			
		mat[0][i]=clan;
		}
		return mat;
		
		
	}
 //Vektor podnizova
       bool a=false;
    for(int i(0);i<int(v1.size()-1);i++){
    	if(v1[i]<=v1[i+1] ) {
    	v.push_back(v1[i]);
    	a=true;
    	}
    
    	else if(a==1){
    		v.push_back(v1[i]);
    		a=false;
    		
    	}
    	
    	else continue;
    }
    //Ako nema nijednog rastuceg ni opadajuceg niza
     if(v.size()==0)return mat;
     
    int l=v1.size()-1;
    if(v1[l]>=v1[l-1]) v.push_back(v1[l]);
    //Ispitivanje vektora podniza
    //cout<<"Vektor rastuci podnizova: ";
     //for(int i(0);i<v.size();i++){
    //	cout<<v[i]<<" ";
    //}
    //Kreiranje matrice
    //Broj redova
    for(int i(0);i<int(v.size()-1);i++){
    	if(v[i]>v[i+1]) 
    		m++;
    		else if(JesuLiJednaki(v[i],v[i+1]))continue;
    	}
    	//provjera broji li dobro redove
    	//cout<<endl<<"Broj redova je: "<<m<<endl;

	mat.resize(m);
	bool b=false;
	int brkolona=0,k=0;
	//Broji kolone 
	for(int i(0);i<=int(v.size()-1);i++){
		if(b){
			while(k<m && b==1){
				mat[k].resize(brkolona+1);
				k++;
				b=0;
			}
		}
		brkolona=0;
	
		for(int j(i);j<int(v.size()-1);j++){
		if(v[j]>v[j+1]){
			i=j;
			break;
		}
		else {
			brkolona++;
			b=true;
			continue;
			}
			}
		
	}
	//cout<<endl<<brkolona<<endl;
	
		//	if(brkolona==0){
		//	if(v[v.size()-2]<=v[v.size()-1]){ 
		//	brkolona=2;
		//	mat[m-1].resize(2);
		//	}
		//	}
//	Provjera broji li dobro kolone
	//for(int i(0);i<m;i++){
	//		cout<<"Broj kolona "<<i<<"-tog reda je "<<mat[i].size()<<endl;
	//		}
	//Popunjavanje matrice
	int w=0;
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			
			mat[i][j]=v[w];
			w++;
		}
	}
	
	return mat;
}



Matrica OpadajuciPodnizovi (vector<double>v1){
	Matrica mat;
	int n=1;
	vector<double>v;
	if(v1.size()==0)return mat;
		double clan=v1[0];
	int br=0;
	for(int i(0);i<v1.size();i++){
		if(JesuLiJednaki(v1[i],clan))
		br++;
	}

	if(v1.size()==br){
		
		mat.resize(1);
		mat[0].resize(br);
		for(int i(0);i<br;i++){
			
		mat[0][i]=clan;
		}
		return mat;
		
		
	}
    //Vektor podnizova
    
    bool a=false;

    for(int i(0);i<int(v1.size()-1);i++){
    	if(v1[i]>=v1[i+1]) {
    	v.push_back(v1[i]);
    	a=true;
    	}
    	
    	else if(a==1 ){
    		v.push_back(v1[i]);
    		a=false;
    	
    	}
    	else continue;
    }
    if(v.size()==0 )return mat;
    int l=v1.size()-1;
    if(v1[l]<v1[l-1]) v.push_back(v1[l]);
    //Ispitivanje vektora podniza
    
  // cout<<"Vektor podnizova: ";
//for(int i(0);i<v.size();i++){
  //  	cout<<v[i]<<" ";
    //}
    //Kreiranje matrice
    //Broj redova
    for(int i(0);i<int(v.size()-1);i++){
    	if(v[i]<v[i+1]) 
    		n++;
    	}
    	//provjera broji li dobro redove
    	//cout<<endl<<"Broj redova je: "<<n<<endl;

	mat.resize(n);
	bool b=false;
	int brkolona=0,k=0;
	
	for(int i(0);i<=int(v.size()-1);i++){
		if(b){
			while(k<n && b==1){
				mat[k].resize(brkolona+1);
				k++;
				b=0;
			}
		}
		brkolona=0;
		for(int j(i);j<int(v.size()-1);j++){
		if(v[j]<v[j+1]){
			i=j;
			break;
		
		}
		else {
			brkolona++;
			b=true;
			
		
			
			continue;
			}
			}
			
		
			}
			//cout<<endl<<brkolona<<endl;
			//if(brkolona==0 ){
			//if(v[v.size()-2]>=v[v.size()-1]){
			//brkolona=2;
			//mat[n-1].resize(2);
			//}
			//}
	//KOlone provjera jel dobro izbrojao
	//for(int i(0);i<n;i++){
		
	
	//	cout<<"Broj kolona "<<i<<"-tog reda je "<<mat[i].size()<<endl;
		
	//}
	int w=0;
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			
			mat[i][j]=v[w];
			w++;
		}
	}
	
	return mat;
}
int main ()
{ 
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	vector<double>v(n),v1,v2;
	cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		cin>>v[i];
	}
	//	cout<<"Velicina vektora: "<<v.size()<<endl;
	v1=v;
	v2=v;
	Matrica mat=RastuciPodnizovi(v1);
	cout<<"Maksimalni rastuci podnizovi:"<<endl; 
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	//Opadajuci
	mat=OpadajuciPodnizovi(v2);
	cout<<"Maksimalni opadajuci podnizovi:"<<endl; 
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[i].size();j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	
	/*	 {0.1111111111, 0.1111111119, 0.11, 0.1, -0.11, -0.111};
	
	Maksimalni rastuci podnizovi: 
0.1111111111 0.1111111119 
Maksimalni opadajuci podnizovi: 
0.1111111119 0.11 0.1 -0.11 -0.111 */
		return 0;
}