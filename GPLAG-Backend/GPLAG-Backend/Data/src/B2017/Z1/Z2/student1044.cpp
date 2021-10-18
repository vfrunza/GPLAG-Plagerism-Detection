/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
typedef vector<vector<double>>Matrica;
int BrojRedova (Matrica m){
	return m.size();
}
int BrojKolona (Matrica m){
	return m[0].size();
}
Matrica KreirajMatricu (int br_redova, int br_kolona){
	return Matrica (br_redova, vector<double>(br_kolona));
}
Matrica UnesiMatricu (int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i(0);i<br_redova;i++)
		for(int j(0);j<br_kolona;j++){
			cin>>m.at(i).at(j);
		}
	return m;
}
void IspisiMatricu(Matrica m){
	for(int i(0); i<BrojRedova(m);i++){
		for(int j(0); j<BrojKolona(m);j++)
			cout<<setw(6)<<m.at(i).at(j);
			cout<<endl;
	}
	
}


Matrica NajvecaPlaninaMatrice (vector<vector<double>>matrica){
	int x,y;
	int brojKolona=BrojKolona(matrica);
	int brojRedova=BrojRedova(matrica);
	vector<Matrica>vekMatrica;
	Matrica ad(brojRedova, vector<double>(brojKolona));
	for(int i(0);i<BrojRedova(matrica);i++){
		for(int j(0); j<BrojKolona(matrica);j++){
x=i; y=j;
int t=1;
//int d=0;
double sum=0, sredisnjaVrijednost=matrica.at(i).at(j);
bool imaPlaninu=false;
int duzinaPoOsi=2, z=0, duzinaPoXOsiPoz=1;
string sw="xpoz";
//Rubni slucajevi??
if((i>=1 && i<(BrojRedova(matrica)-1)) && (j>=1 && j<(BrojKolona(matrica)-1))){
Matrica a(brojRedova, vector<double>(brojKolona));
for(int k(0);k<(BrojRedova(matrica)-1)*(BrojKolona(matrica)-1);k++){
	if(k==0 || imaPlaninu){
		if(k==0){
			a.at(x).at(y)=matrica.at(x).at(y);
		}
		y=y+1;
		imaPlaninu=false;
	}
	else{
		if(sw=="ypoz"){
			y=y+1;
			z++;
			if(duzinaPoOsi==z){
				sw="xpoz";
				z=0;
			}
		}
		else if(sw=="xpoz"){
			x=x+1;
			z++;
			if(duzinaPoXOsiPoz==z){
				sw="yneg";
				z=0;
			}
		}
		else if(sw=="yneg"){
			y=y-1;
			z++;
			if(duzinaPoOsi==z){
				sw="xneg";
				z=0;
			}
		}
		else if(sw=="xneg"){
			x=x-1;
			z++;
			if(duzinaPoOsi==z){
				sw="ypoz";
				z=0;
			}
		}
	}
	sum+=matrica.at(x).at(y);
	a.at(x).at(y)=matrica.at(x).at(y);
	if(t%8==0){
		if(sum<sredisnjaVrijednost){
			sredisnjaVrijednost=sum;
			int r=((t+8)/4);
			if(r<=(brojRedova-x) && r<=y && ((brojRedova-1)-x)>=1 && ((brojKolona-1)-y)>=1){
				imaPlaninu=true;
				duzinaPoOsi+=2;
				duzinaPoXOsiPoz=duzinaPoOsi-1;
			}
			else{
				vekMatrica.push_back(a);
				break;
			}
		}
		else{
			break;
		}
	}
	t++;
}

}

	
}
		}
		return ad;
	}













int main ()
{
	int m1,n1;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m1>>n1;
	cout<<"Unesite elemente matrice:"<<endl;
	auto A(UnesiMatricu(m1,n1));
	cout<<"Najveca planina matrice je:"<<endl;
	Matrica p=NajvecaPlaninaMatrice(A);
	IspisiMatricu(p);
	
	return 0;
}