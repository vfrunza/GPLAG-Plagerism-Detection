/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

void i(vector <vector <double>>x){
 for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
        cout<<setw(4)<<x[i][j];
    }cout<<endl;
}
}
vector <vector <double>> u (vector <vector <double>>x){
     for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
        cin>>x[i][j];
    }
}
return x;
}
bool g(vector <vector <double>>x){
    for(int i=0;i<x.size();i++){
        if(x[0].size()!=x[i].size())return true;
    }

return false;
}

vector <vector <double>> ho (vector <vector <double>>x){
vector<vector<double>>m;



m=x;
for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
        m[i][j]=x[i][x[i].size()-1-j];
    }
}
return m;
}
vector <vector <double>> vo (vector <vector <double>>x){
vector<vector<double>>m;
m=x;

for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
        m[i][j]=x[x.size()-1-i][j];
    }
}
return m;
}
vector <vector <double>>o(vector <vector <double>>x){
    vector<vector<double>>m;
    m=ho(x);
    m=vo(m);
    return m;
}

vector <vector <double>>nadovezi_r(vector <vector <double>>a,vector <vector <double>>b,vector <vector <double>>c){

vector <vector <double>>x(a.size(),vector<double>(3*a[0].size()));
if(a[0].size()==0) return x;
    for(int i=0;i<x.size();i++){
    for(int j=0;j<x[i].size();j++){
            if(j<a[i].size())x[i][j]=a[i][j];
            if(j>=a[i].size()&&j<2*a[i].size())x[i][j]=b[i][j%a[i].size()];
            if(j>=2*a[i].size())x[i][j]=c[i][j%a[i].size()];
    }
}
return x;
}
vector <vector <double>>dodaj_r(vector <vector <double>>a,vector <vector <double>>b){
    vector <vector <double>>x=a;
    for(int i=0;i<b.size();i++)x.push_back(b[i]);
    return x;
}
vector <vector <double>>OgledaloMatrica(vector <vector <double>>b){
    if(b.size()==0)return vector<vector<double>>(0) ;
    if(g(b)){throw domain_error("Matrica nije korektna");}
    vector<vector<double>>b1,b2,b3,b4,b5,b6;

    b1=o(b);
    b3=vo(b);
    b6=b2=nadovezi_r(b1,b3,b1);
    b4=ho(b);
    b5=nadovezi_r(b4,b,b4);
    b2=dodaj_r(b2,b5);
    b2=dodaj_r(b2,b6);
    return b2;
}


int main()
{	
	int m,n;
   	vector<vector<double>>b2;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0||n<0){
        cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
        
    }
   	cout <<"Unesite elemente matrice:"<<endl;
    vector<vector<double>>b(m,vector<double>(n));
    try{
    b=u(b);
    b2=OgledaloMatrica(b);
    }

    catch(domain_error a){

    cout<<a.what();

    }
    cout << "Rezultantna matrica:" <<endl;
    i(b2);
    return 0;
}
