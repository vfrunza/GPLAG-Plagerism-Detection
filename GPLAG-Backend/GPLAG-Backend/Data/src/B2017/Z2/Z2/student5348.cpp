#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <deque>
using namespace std;

typedef vector<vector<vector<double>>> kon;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};



template <typename t1>
t1 PjescaniSat(t1 kont,SmjerKretanja s1){

	int s=(int)s1;
	vector<vector<vector<typename remove_reference<decltype(kont[0][0][0])>::type>>> v1;
	vector<vector<typename remove_reference<decltype(kont[0][0][0])>::type>> v2;
	vector<typename remove_reference<decltype(kont[0][0][0])>::type> v3;
	if (kont.size()%2==0) throw domain_error("Izuzetak: 3D kontejner ne zadovoljava uvjet neparnosti");
	int x=kont.size();
	for(int k=0;k<kont.size();k++)
	{
		for(int i=0;i<kont.size();i++){
			for(int j=0;j<kont.size();j++)
				if((j<x-i && j>=i && i<=x/2)||(i>x/2&&j>=x-i-1 && i>=j))
					v3.push_back(kont[k*(s!=0 && s!=1)+i*(s==0)+(x-i-1)*(s==1)][i*(s==2)+j*(s==4||s==5)+k*(s==0 || s==1)+(x-i-1)*(s==3)][i*(s==4)+j*(s==0||s==1||s==2||s==3)+(x-i-1)*(s==5)]);
			
			v2.push_back(v3);v3.resize(0);
		}
			v1.push_back(v2);v2.resize(0);v3.resize(0);
	}
	return v1;
}

	//	[k*(s!=NaprijedNazad && s!=NazadNaprijed)+j*(s==NaprijedNazad || s==NazadNaprijed)][(x-i-1)*(s==DoljeGore || s==DesnoLijevo || s==NaprijedNazad )+i*(s==GoreDolje || s==NaprijedNazad)+j*(s==DesnoLijevo || s==LijevoDesno)][j*(s==GoreDolje || s== DoljeGore ||s==NaprijedNazad || s==NazadNaprijed)+i*(s==DesnoLijevo)+(x-i-1)*(s==DesnoLijevo)]
//GoreDole [k][i][j] 2
//DoleGore [k][size-i-1][j] 3
//DesnoLijevo [k][j][size-i-1] 5
//LiejvoDesno [k][j][i] 4
//NaprijedNazad [i][k][j] 0
//NazadNaprijed [x-i-1][k][j] 1
		

int main ()
{
	
/*	vector<vector<vector<double>>> v1{{{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30},{31,32,33,34,35}},
	{{-9,-8,-7,-6,-5},{-4,-3,-2,-1,17},{14,25,28,30,35},{19,-8,54,78,65},{22,11,72,16,67}},
	{{89,28,17,56,55},{64,93,12,81,17},{14,25,28,31,35},{19,44,53,72,65},{22,18,72,16,69}},
	{{36,37,38,42,43},{39,40,41,44,45},{46,47,48,55,56},{49,50,51,57,58},{52,53,54,59,60}},
	{{61,62,63,67,68},{64,65,66,69,70},{71,72,73,80,82},{74,75,76,81,83},{77,78,79,84,85}}};
	*/
	
	/*int d=0;
	int s;
	
	cout<<"Unesite dimenziju (x/y/z): ";
	while(1){
	cin>>d;
	if(d<=0)cout<<"Dimenzija nije ispravna, unesite opet: ";
	else break;
	}
	
	kon v1;
	vector<vector<double>> v2;
	vector<double>v3;
	cout<<"Unesite elemente kontejnera: ";
	for(int k=0;k<d;k++){
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				int x;//thefuck??
				cin>>x;
				v3.push_back(x);
			}
			v2.push_back(v3);v3.resize(0);
		}	
		v1.push_back(v2);v2.resize(0);v3.resize(0);
		}
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	while(2){
	cin>>s;
	if(s<0 || s>5) cout<<"Smjer nije ispravan, unesite opet: ";
	else break;
	}
cout<<endl;
	try{
	v1=PjescaniSat(v1,SmjerKretanja(s));
	cout<<"Pjescani sat unesene matrice je: "<<endl;
	
	for(int k=0;k<v1.size();k++){
		for(int i=0;i<v1.at(k).size();i++){
			int x=v1.size(),y=v1.at(k).size(),z=v1.at(k).at(i).size();
			if(x!=z)cout<<right<<setw(5*(x-z)/2-1)<<" ";
			for(int j=0;j<v1.at(k).at(i).size();j++){
				 //if(j!=0)cout<<" ";
				cout<<right<<setw(4)<<v1.at(k).at(i).at(j);
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what();
	}*/
	
	std::deque<std::deque<std::vector<short int>>> kont = {
        {
            {1, 2, 3},
            {5, 6, 7},
            {9, 10, 11}
        },
        {
            {-1, -2, -3},
            {-5, -6, -7},
            {-9, -10, -11}
        },
        {
            {11, 12, 13},
            {15, 16, 17},
            {19, 110, 111}
        }
    };
    std::deque<std::deque<std::vector<short int>>> kont1 {PjescaniSat (kont, SmjerKretanja::NaprijedNazad)};
    for (const std::deque<std::vector<short int>> &ploha : kont1)
        {
            for (const std::vector<short int> &red : ploha)
            {
                for (const short int &x : red)
                    std::cout << std::setw(4) << x;
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
	
	
	return 0;
}

