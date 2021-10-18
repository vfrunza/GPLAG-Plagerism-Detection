#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using namespace std;
typedef vector<vector<double>> matrica;
// funkcija kreira matricu
matrica Kreirajmatricu(int brojredova,int brojkolona)
{
return matrica(brojredova,vector<double>(brojkolona));
}
// funkcija vraca broj redova matrice
int Brojredova(matrica m)
{
return m.size();
}
// funkcija vraca broj kolona matrice
int Brojkolona(matrica m)
{
return m[0].size();
}
//funckija ispisuje matricu
void Ispisimatricu(matrica m)
{
for(int i=0;i<Brojredova(m);i++){
for(int j=0;j<Brojkolona(m);j++)
cout<<setw(4)<<m[i][j];
cout<<endl;
}}
//funcija omogucava unosenje matrice
matrica Unesimatricu(int brojredova,int brojkolona)
{
matrica m(Kreirajmatricu(brojredova,brojkolona));
cout<<"Unesite elemente matrice: "<<endl;
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
{
cin>>m[i][j];
}
return m;
}
//funkcija vrsi provjeru grbave matrice
void Provjerigrbavu(matrica m)
{
for(int i=0;i<Brojredova(m)-1;i++)
{if(m[i].size()!=m[i+1].size())
throw std::domain_error( "Matrica nije korektna" );
}
}







//funcija vrsi vertikalno pomjeranje
matrica Vertikalnopomjeranje(matrica m,int brojredova,int brojkolona)
{ 
	matrica vertikalnamatrica(Kreirajmatricu(brojredova,brojkolona));
	for(int i=0;i<brojredova;i++)
{
for(int j=0;j<brojkolona;j++)
 vertikalnamatrica[i][j]=m[brojredova-i-1][j];


}
return vertikalnamatrica;
}
//funkcija vrsi horizontalno pomjeranje
matrica Horizontalnopomjeranje(matrica m,int brojredova,int brojkolona)
{
matrica horizontalnamatrica(Kreirajmatricu(brojredova,brojkolona));
	for(int i=0;i<brojredova;i++)
{
for(int j=0;j<brojkolona;j++)
 horizontalnamatrica[i][j]=m[i][brojkolona-j-1];


}
return horizontalnamatrica;
}
// finalna matrica
matrica Finalnamatrica(matrica horizontalnamatrica,matrica vertikalnamatrica,matrica horizontalnovertikalnamatrica,matrica finalnamatrica,matrica m,int brojredova,int brojkolona)
{
//ubaci hv gore lijevo
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[i][j]=horizontalnovertikalnamatrica[i][j];
//ubaci gore v
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[i][brojkolona+j]=vertikalnamatrica[i][j];
//ubaci gore desno hv
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[i][2*brojkolona+j]=horizontalnovertikalnamatrica[i][j];
//ubaci lijevo h
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[brojredova+i][j]=horizontalnamatrica[i][j];
//ubaci u sredinu m
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[brojredova+i][brojkolona+j]=m[i][j];
//ubaci desno h
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[brojredova+i][2*brojkolona+j]=horizontalnamatrica[i][j];
//ubaci dole lijevo hv
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[2*brojredova+i][j]=horizontalnovertikalnamatrica[i][j];
//ubaci dole v
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[2*brojredova+i][brojkolona+j]=vertikalnamatrica[i][j];
//ubaci dole desno hv
for(int i=0;i<brojredova;i++)
for(int j=0;j<brojkolona;j++)
finalnamatrica[2*brojredova+i][2*brojkolona+j]=horizontalnovertikalnamatrica[i][j];

return finalnamatrica;

}
matrica OgledaloMatrica(matrica m)
{
try{

Provjerigrbavu(m);
int brojredova(m.size());
int brojkolona(0);
if(brojredova>0)
brojkolona=m[0].size();
matrica horizontalnamatrica(Horizontalnopomjeranje(m,brojredova,brojkolona));
matrica vertikalnamatrica(Vertikalnopomjeranje(m,brojredova,brojkolona));
matrica horizontalnovertikalnamatrica(Horizontalnopomjeranje(m,brojredova,brojkolona));
 horizontalnovertikalnamatrica=Vertikalnopomjeranje(horizontalnovertikalnamatrica,brojredova,brojkolona);
//kreiranje finalne matrice
matrica finalnamatrica(Kreirajmatricu(3*brojredova,3*brojkolona));
finalnamatrica=Finalnamatrica(horizontalnamatrica,vertikalnamatrica,horizontalnovertikalnamatrica,finalnamatrica,m,brojredova,brojkolona);
return finalnamatrica;
}
catch(const std::domain_error e)
{
cout << e.what() << '\n';
matrica praznaMatrica;
return praznaMatrica;
}
}

int main ()
{
	int brojredova,brojkolona;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>brojredova;
    cin>>brojkolona;
    if ((brojredova<0) or (brojkolona<0))
    {
    cout << "Dimenzije matrice moraju biti nenegativne!";
    return 0;
    }
	

    matrica m=Unesimatricu(brojredova,brojkolona);
	auto ogledalomatrica=OgledaloMatrica(m);
	cout<<"Rezultantna matrica: "<<endl;
	Ispisimatricu(ogledalomatrica);

	
	
	return 0;
}