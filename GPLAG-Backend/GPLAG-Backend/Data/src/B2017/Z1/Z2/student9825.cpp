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
#include <iomanip>
bool DaLiJePlanina (std::vector<std::vector<double>> M,int centari,int centarj, int a)
{

	{

		int h=0,vel=M.at(centari).at(centarj);
		a=(a-1)/2;



		int suma=0,sumanova=0;
		for(int i=centari-a; i <= centari+a; i++) {
			for(int j=centarj-a; j<=centarj+a; j++) {


				if(j==centarj)j++;

				if(h==0)
					suma+=M.at(i).at(j);


				else sumanova+=M.at(i).at(j);

			}

		}
		h=1	;




		a--;



	}
	return 1;
}
std::vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>> M)
{

	int a=M.size();
	if(a!=0) {
		int	b=M[0].size();

		int indeksi=a,indeksj=b,vel=0,vrh=0;
		for (std::vector<double> x : M) {
			if(x.size()!=b);
			//	greska(error)!!!!!!!
		}    //da li je grbava?

		if(a>b)a=b;

		if(a%2==0)a--;

		int vrhi=(a-1)/2,vrhj=vrhi;


		do {

			do {
				for(int i=0; i<M.size(); i++) {
					for(int j=0; j<b; j++) {

						if(i==vrhi-1&&j==vrhj-1)
							break;

					}
				}
				if(	DaLiJePlanina(M,vrhi-1,vrhj-1,a) )

					if(a>vel)vel=a;
					else if(M.at(vrhi-1).at(vrhj-1)>vrh)vrh=M.at(vrhi-1).at(vrhj-1);
					else if(vrhi-1<indeksi)indeksi=vrhi-1;
					else if (vrhj-1<indeksj)indeksj=vrhj-1;


				if(vrhj+(a-1)/2<b)vrhj++;
				else {
					vrhj=(a-1)/2;
					vrhi++;
				}



			} while((vrhi-1+(a-1)/2)<=M.size()&&(vrhj-1+(a-1)/2)<=b);


			if(vel!=0) {

				std::vector<std::vector<double>> pomocna;
				int m=0,n=0;
				for(int k=indeksi-(vel-1)/2; k<indeksi+(vel-1)/2; k++) {
					for(int l=indeksj-(vel-1)/2; l<indeksj+(vel-1)/2; l++) {


						pomocna[m][n]=M.at(k).at(l);
						n++;
					}
					m++;
				}
				return pomocna;
			} else a--;
		} while (a!=0);



		return M;
	}
}
int main ()
{
	int m,n;
	double p;
	std::vector<std::vector<double>> M;


	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;




	if(m<0||n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}


	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {

			std::cin>>p;
			M[i].push_back(p);
		}
	}

	std::cout<<"Najveca planina unesene matrice je: ";

	/*	M=(NajvecaPlaninaMatrice(M) );
	if(M.size()!=0){
		for(int k=0; k<M.size(); k++) {
			for(int l=0; l<M.size(); l++) {
	*/

	std::cout<<std::right<<std::setw(6)<<M[M.size()-1][0];





	std::cout<<"\n";



	return 0;
}