#include<iostream>
#include<vector>
#include<stdexcept>
#include<iomanip>
/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

using namespace std;
void horiz(vector<vector<double>> &mat){
	
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size()/2;j++){
			
			double pomocni=mat[i][j];
			mat[i][j]=mat[i][mat[i].size()-j-1];
			mat[i][mat[i].size()-j-1]=pomocni;
		}
	}
	
}

void vert(vector<vector<double>> &mat){
		
	
	for(int i=0;i<mat.size()/2;i++){
		vector<double> pomocni= mat[i];
		mat[i]=mat[mat.size()-i-1];
		mat[mat.size()-1-i]=pomocni;
	}
}

void horizvert(vector<vector<double>> &mat){
	horiz(mat);
	vert(mat);
}

vector<vector<double>> NapraviMatricu(int br_redova, int br_kolona){
	if(br_redova<0 || br_kolona<0) throw "Dimenzije matrice moraju biti nenegativne!";
	vector<vector<double>> mat;
	mat.resize(br_redova);
	
	for(int i=0;i<mat.size();i++) mat[i].resize(br_kolona);
	return mat;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat){
	if(mat.size()==0) return mat;
	
	for(int i=0;i<mat.size();i++)
		if(mat[i].size()!=mat[0].size()) throw domain_error("Matrica nije korektna");
	if(mat[0].size()==0) {
		int brr=3*mat.size();
		return NapraviMatricu(brr,0);
	}
	vector<vector<double>> horizontalna=mat;
	horiz(horizontalna);
	vector<vector<double>> vertikalna=mat;
	vert(vertikalna);
	vector<vector<double>> mjesovita=mat;
	horizvert(mjesovita);
	int br_red=3*mat.size();
	int br_kolona=3*mat[0].size();
	vector<vector<double>> velika=NapraviMatricu(br_red,br_kolona);
	
	br_red=mat.size();
	br_kolona=mat[0].size();

	
	for(int i=0;i<velika.size();i++){
		
		for(int j=0;j<velika[0].size();j++){
			//cout<<i << " " << j<<endl;
			int y=j-br_kolona*(j/br_kolona);
			int x=i-br_red*(i/br_red);
			
			if((i/br_red==0 || i/br_red==2) && (j/br_kolona==0 || j/br_kolona==2))
				velika[i][j]=mjesovita[x][y];
			
			else if(i/br_red==1 &&  (j/br_kolona==0 || j/br_kolona==2))
				velika[i][j]=horizontalna[x][y];
			
			else if(j/br_kolona==1 && (i/br_red==0 || i/br_red==2))
				velika[i][j]=vertikalna[x][y];
			
			else
				velika[i][j]=mat[x][y];
			
		}
	}
	return velika;
	
		
}

int main ()
{
	
	try{
		int m, n;
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m>>n;
		vector<vector<double>> matrica=NapraviMatricu(m,n);
		cout<<"Unesite elemente matrice: "<<endl;
		for(int i=0;i<matrica.size();i++){
			for(int j=0;j<matrica[0].size();j++){
				cin>>matrica[i][j];
				
			}
				
		}
		matrica=OgledaloMatrica(matrica);
		cout<<"Rezultantna matrica: "<<endl;
		
		for(int i=0;i<matrica.size();i++){
			for(int j=0;j<matrica[0].size();j++)
				cout<<setw(4)<<matrica[i][j];
			cout<< endl;
		}
		
	}
	catch(domain_error e){
		cout<<e.what()<< endl;
	}
	catch(const char poruka[] ){
		cout<<poruka;
	}
	return 0;
}