/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
using namespace std;
#include<stdexcept>
#include<vector>
#include<iostream>
#include<iomanip>
typedef vector<vector<double>> Matrica;
int BrojRedova(Matrica m)
{
	return m.size();
}


int BrojKolona(Matrica m)
{
	return m[0].size();}
std::vector<std::vector<double>> KreirajMatricu(int broj_redova,
 int broj_kolona) {
 return std::vector<std::vector<double>>(broj_redova,
 std::vector<double>(broj_kolona));
}




	Matrica Horizontalna(Matrica m)
	{
		Matrica nova(KreirajMatricu(m.size(), m[0].size()));
		 int pomoc(BrojKolona(m)-1);
		 for(int i=0;i<BrojRedova(m);i++)
		 {
		 	for(int j=0;j<BrojKolona(m);j++)
		 	{
		 		nova[i][j]=m[i][pomoc];
		 		pomoc--;
		 	}
		 	pomoc=BrojKolona(m)-1;
		 }
		 return nova;
		
	}
	Matrica Vertikalna(Matrica m)
	{
		Matrica nova(KreirajMatricu(m.size(), m[0].size()));
		int pomoc(BrojRedova(m)-1);
		for(int i=0;i<m.size();i++)
		{
			for(int j=0;j<m[i].size();j++)
			{
				nova[i][j]=m[pomoc][j];
				
			}
pomoc--;			
		}
		return nova;
	}
	Matrica Kombinovana(Matrica m)
	{
		Matrica nova(KreirajMatricu(m.size(), m[0].size()));
		int pomoc_1(BrojKolona(m)-1);
		int pomoc_2(m.size()-1);
		for(int i=0;i<m.size();i++)
		{
			for(int j=0;j<BrojKolona(m);j++)
			{
				nova[i][j]=m[pomoc_2][pomoc_1];
				pomoc_1--;
			}
			pomoc_2--;
			pomoc_1=BrojKolona(m)-1;
		}
		return nova;
	}
	Matrica OgledaloMatrica(Matrica m)
	{
			if(BrojRedova(m)==0 && BrojKolona(m)==0)
		{
			auto nova(KreirajMatricu(0,0));
			return nova;
		}
		for(int i=0;i<m.size()-1;i++)
		{
			if(m[i].size()!=m[i+1].size()) throw domain_error("Matrica nije korektna.");
		}
	
		if(m.size()!=0 && m[0].size()==0)
		{
			auto nova(KreirajMatricu(m.size()*3, 0));
			return nova;
		}
		auto nova(KreirajMatricu(m.size()*3, BrojKolona(m)*3));
		auto KombinovanaMatrica(Kombinovana(m));
		auto VertikalnaMatrica(Vertikalna(m));
		auto HorizontalnaMatrica(Horizontalna(m));
		int pomoc_1(0), pomoc_2(0);
		for(int i=0;i<m.size();i++)
		{
			for(int j=0;j<BrojKolona(m);j++)
			nova[i][j]=KombinovanaMatrica[i][j];
		}
		for(int i=0;i<m.size();i++)
		{
			for(int j=BrojKolona(m);j<BrojKolona(m)*2;j++)
			{
				nova[i][j]=VertikalnaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_2=0;
			pomoc_1++;
			
		}
		pomoc_1=0, pomoc_2=0;
		for(int i=m.size();i<m.size()*2;i++)
		{
			for(int j=0;j<BrojKolona(m);j++)
			{
				nova[i][j]=HorizontalnaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_2=0;
			pomoc_1++;
		}
		pomoc_1=0;
		pomoc_2=0;
		
		for(int i=0;i<m.size();i++)
		{
			for(int j=BrojKolona(m)*2;j<BrojKolona(m)*3;j++)
			{
				nova[i][j]=KombinovanaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_2=0;
			pomoc_1++;
		}
		pomoc_1=0;
		pomoc_2=0;
		for(int i=m.size();i<m.size()*2;i++)
		{
			for(int j=BrojKolona(m);j<BrojKolona(m)*2;j++)
			{
				nova[i][j]=m[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_1++;
			pomoc_2=0;
		}
		pomoc_1=0;
		pomoc_2=0;
		for(int i=m.size();i<m.size()*2;i++)
		{
			for(int j=BrojKolona(m)*2;j<BrojKolona(m)*3;j++)
			{
				nova[i][j]=HorizontalnaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_1++;
			pomoc_2=0;
		}
		pomoc_1=0;
		pomoc_2=0;
		for(int i=m.size()*2;i<m.size()*3;i++)
		{
			for(int j=0;j<BrojKolona(m);j++)
			{
				nova[i][j]=KombinovanaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_2=0;
			pomoc_1++;
		}
		pomoc_1=0;
		pomoc_2=0;
		for(int i=m.size()*2;i<m.size()*3;i++)
		{
			for(int j=BrojKolona(m);j<BrojKolona(m)*2;j++)
			{
				nova[i][j]=VertikalnaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_1++;
			pomoc_2=0;
		}
		pomoc_2=0;
		pomoc_1=0;
		for(int i=m.size()*2;i<m.size()*3;i++)
		{
			for(int j=BrojKolona(m)*2;j<BrojKolona(m)*3;j++)
			{
				nova[i][j]=KombinovanaMatrica[pomoc_1][pomoc_2];
				pomoc_2++;
			}
			pomoc_1++;
			pomoc_2=0;
		}
		return nova;
	}
	
	
void IspisiMatricu(Matrica m) {
 for(int i = 0; i < BrojRedova(m); i++) {
 for(int j = 0; j < BrojKolona(m); j++)
 cout <<setw(4) << m[i][j];
 cout <<endl;
 }
}
Matrica UnesiMatricu(int br_redova, int br_kolona) {
 auto m(KreirajMatricu(br_redova, br_kolona));
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++) {
 
 cin >> m[i][j];
 }
 return m;
}
int main ()
{
	try {
		double broj_redova, broj_kolona;
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>broj_redova>>broj_kolona;
		if(broj_redova<0 or broj_kolona<0)
		{
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;}
			cout<<"Unesite elemente matrice: ";
			Matrica Test(UnesiMatricu(broj_redova,broj_kolona));
			cout<<endl;
			cout<<"Rezultantna matrica: "<<endl;
			Matrica Rezultat=OgledaloMatrica(Test);
			IspisiMatricu(Rezultat);}
	
	catch (domain_error izuzetak) {
		cout <<izuzetak.what() <<endl;
	}
	return 0;
	
	
}