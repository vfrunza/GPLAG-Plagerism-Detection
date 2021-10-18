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
using namespace std;
typedef vector<vector<double>> Matrica;
typedef vector<double>Red;
bool Grbava(Matrica Mat){
	return true;
}
Matrica OgledaloMatrica(Matrica Mat){
		int a;
		a=Grbava(Mat);
		if(!a) throw domain_error ("Matrica nije korektna");
	
	Matrica Hor(Mat),Ver(Mat),HV(Mat);
	for(int i=0;i<Hor.size();i++){
		for( int j=0;j<Hor[i].size()/2;j++){
			double temp=Hor[i][j];
			//možda -1
			Hor[i][j]=Hor[i][Hor[i].size()-j-1];
			Hor[i][Hor[i].size()-j-1]=temp;
		}
	}
	for(int i=0;i<Ver.size()/2;i++){
		Red temp=Ver[i];
		Ver[i]=Ver[Ver.size()-i-1];
		Ver[Ver.size()-i-1]=temp;
		//možda -1 opet
	}
	for(int i=0;i<HV.size();i++){
		for(int j=0;j<HV[i].size()/2;j++){
			double temp=HV[i][j];
			HV[i][j]=HV[i][HV[i].size()-j-1];
			HV[i][HV[i].size()-j-1]=temp;
		}
	}
	for(int i=0;i<HV.size()/2;i++){
		Red temp=HV[i];
		HV[i]=HV[HV.size()-i-1];
		HV[HV.size()-i-1]=temp;
	}
	int prosirired=(Mat.size()*3);
	int prosirikol=(Mat[0].size()*3);
	Matrica Povratna(prosirired);
	for(int i=0;i<Povratna.size();i++){
		Povratna[i].resize(prosirikol);
	}
	for(int i=0;i<Povratna.size();i++){
		for(int j=0;j<Povratna[0].size();j++){
			if((i<Mat.size()&&j<Mat[0].size())||(i<Mat.size()&&j/Mat[0].size()==2)||(i>=2*Mat.size() && j/Mat[0].size()==0)||(i>=2*Mat.size()&&j/Mat[0].size()==2)){
				Povratna[i][j]=HV[i%Mat.size()][j%Mat[0].size()];}
					else if((j/Mat[0].size()==1 && i<Mat.size())||(j/Mat[0].size()==1 && i>=2*Mat.size())){
				Povratna[i][j]=Ver[i%Mat.size()][j%Mat[0].size()];}
			else if((i/Mat.size()==1 &&j<Mat[0].size())||(i/Mat.size()==1 && j>=2*Mat[0].size())){
				Povratna[i][j]=Hor[i%Mat.size()][j%Mat[0].size()];
			}	
				else Povratna[i][j]=Mat[i%Mat.size()][j%Mat[0].size()];
			
		
		}
	}
	return Povratna;
}
int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) {cout<<"Dimenzije matrice moraju biti nenegativne! ";
	return 0;}
	Matrica Mat(m);
	for(int i=0;i<Mat.size();i++){
		Mat[i].resize(n);
	}
	try{
	cout<<"Unesite elemente matrice: ";
	for(int i=0;i<Mat.size();i++){
		for(int j=0;j<Mat[0].size();j++){
			cin>>Mat[i][j];
		}
	}
}
catch(...) {
 cout << "Matrica nije korektna" ;
 cin.clear();
 cin.ignore(10000, '\n');

}
	cout<<endl;
	cout<<"Rezultantna matrica: "<<endl;
	Matrica povratna;
	povratna=OgledaloMatrica(Mat);
	for(int i=0;i<povratna.size();i++){
		for(int j=0;j<povratna[i].size();j++){
			cout<<setw(4)<<povratna[i][j];
		}
		cout<<endl;
	}
/*auto m1 = OgledaloMatrica ({});
auto m2 = OgledaloMatrica ({{}, {}, {}, {}});
std::cout << "m1.size(): " << m1.size() << std::endl;
std::cout << "m2.size(): " << m2.size() << std::endl;
for (int i = 0; i < m2.size(); ++i)
	std::cout << "m2.at(" << i << ").size(): " << m2.at(i).size() << std::endl;*/
	return 0;
}