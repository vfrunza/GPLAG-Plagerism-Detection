/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu (int redovi, int kolone){
	return Matrica(redovi, vector<double> (kolone));
}


void IspisiMatricu (Matrica m){
		for(int i=0; i<m.size(); i++){
			for(int j=0; j<m[0].size(); j++){
			cout<<std::setw(4)<<m[i][j];
}
cout<<endl;
}
}

Matrica desno (Matrica a){
int redovi=a.size();
int kolone=a[0].size();

Matrica desno_lijevo (redovi, vector<double> (kolone));
int temp=kolone-1;

for(int j=0; j<redovi; j++){
	for(int i=0; i<kolone; i++){
		desno_lijevo[j][kolone-1-temp]=a[j][temp];
		temp--;
	}
	temp=kolone-1;

}
return desno_lijevo;

}



Matrica gore (Matrica a){
int redovi=a.size();
int kolone=a[0].size();

Matrica gore_dole (redovi, vector<double> (kolone));
int temp=redovi-1;

for(int j=0; j<kolone; j++){
	for(int i=0; i<redovi; i++){
		gore_dole[redovi-1-temp][j]=a[temp][j];
		temp--;
	}
	temp=redovi-1;

}
return gore_dole;

}

Matrica cosak(Matrica a){
    Matrica c (a.size(), vector<double> (a[0].size()));
    c=desno(a);
return c;
}




Matrica OgledaloMatrica (Matrica a ){
    Matrica temp;
    temp=a;
    if(a.size()==0) return temp;
    for(int i=0; i<a.size()-1; i++){
    	if(a[i].size()!=a[i+1].size()) throw std::domain_error("Matrica nije korektna");
    }
    
    
	int redovi=a.size();
	int kolone=a[0].size();
    int m=a.size();
    int n=a[0].size();
	Matrica cosak1 (redovi, vector<double> (kolone));
	Matrica gore_dole (redovi, vector<double> (kolone));
	Matrica desno_lijevo (redovi, vector<double> (kolone));

desno_lijevo=desno(a);
gore_dole=gore(a);
cosak1=cosak(gore_dole);

a.resize(3*redovi);
a[0].resize(3*kolone);
a=Matrica(3*redovi,vector<double>(3*kolone, 0));


kolone*=3;
redovi*=3;
for(int i=0; i<m; i++){
    for(int j=0; j<kolone; j++){
        if(j>=0 && j<n) a[i][j]=cosak1[i][j];
        else if(j<2*n) a[i][j]=gore_dole[i][j-n];
        else if(j<3*n) a[i][j]=cosak1[i][j-2*n];
    }
}




for(int i=m; i<2*m; i++){
    for(int j=0; j<kolone; j++){
        if(j>=0 && j<n)   a[i][j]=desno_lijevo[i-m][j];
        else if(j<2*n)  a[i][j]=temp[i-m][j-n];
        else if(j<3*n) a[i][j]=desno_lijevo[i-m][j-2*n];
    }
}



for(int i=2*m; i<3*m; i++){
    for(int j=0; j<kolone; j++){
        if(j>=0 && j<n) a[i][j]=cosak1[i-2*m][j];
        else if(j<2*n) a[i][j]=gore_dole[i-2*m][j-n];
        else if(j<3*n) a[i][j]=cosak1[i-2*m][j-2*n];
    }
}


	
return a;
}


Matrica UnesiMatricu (int redovi, int kolone) {
	auto m(KreirajMatricu(redovi, kolone));

	cout<<"Unesite elemente matrice: "<<endl;
	for(int i=0; i<redovi; i++){
		for(int j=0; j<kolone; j++){
			cin>>m[i][j];
	}}
	if(redovi==0 && kolone==0) return m;
	if(redovi==0) return m;
	return m;
}




int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	cin>>m>>n;
	if(m<0 || n<0) 	{
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;}
	if(m==0 && n==0) {	cout<<"Unesite elemente matrice:\nRezultantna matrica:"<<endl; return 0;}
		
	Matrica a(m, vector<double>(n));
	a=UnesiMatricu(m,n);
	cout<<"Rezultantna matrica:"<<endl;
	Matrica konacna(3*m, vector<double>(3*n));
	try{
	konacna=OgledaloMatrica(a);
	}
	catch (std::domain_error baceno){
		cout<<baceno.what();
	}

	IspisiMatricu(konacna);
	
	return 0;
}