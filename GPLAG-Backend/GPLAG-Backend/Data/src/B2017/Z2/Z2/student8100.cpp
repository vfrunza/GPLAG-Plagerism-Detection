#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <deque>
#include <type_traits>
#include <iomanip>

using namespace std;

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename kont>
kont PjescaniSat(kont kontejner, SmjerKretanja smjer)
{
	for(int i=0; i<kontejner.size(); i++)
		for(int j=0; j<kontejner.at(i).size(); j++)
			for(int k=0; k<kontejner.at(i).at(j).size(); k++) {
				if(kontejner.at(i).size()!=kontejner.size() || kontejner.at(i).at(j).size()!=kontejner.size() || kontejner.at(i).size()!=kontejner.at(i).at(j).size())
					throw domain_error("\nIzuzetak: 3D matrica nema oblik kocke");
				if(kontejner.at(i).size()%2==0 || kontejner.at(i).at(j).size()%2==0)
					throw length_error("\nIzuzetak: 3D kontejner ne zadovoljava uvjet neparnosti");
			}
	
	if(kontejner.size()==0)
		return kontejner;
			
	kont pomocna;
	
	int koo=kontejner.at(0).size()/2;

	if(smjer==SmjerKretanja::GoreDolje) {
		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica.at(0))>::type NoviRed;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed.push_back(kontejner.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed.push_back(kontejner.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed.push_back(kontejner.at(i).at(j).at(k));
				}
				NovaMatrica.push_back(NoviRed);
			}
			pomocna.push_back(NovaMatrica);
		}
		return pomocna;
	} else if(smjer==SmjerKretanja::DoljeGore) {
		kont kopija1;

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica1(kontejner.size());
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica1.at(0))>::type NoviRed1;
				for(int k=0; k<kontejner.size(); k++)
					NoviRed1.push_back(kontejner.at(i).at(j).at(k));
				NovaMatrica1.at(kontejner.size()-1-j)=NoviRed1;
			}
			kopija1.push_back(NovaMatrica1);
		}

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica2;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica2.at(0))>::type NoviRed2;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed2.push_back(kopija1.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed2.push_back(kopija1.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed2.push_back(kopija1.at(i).at(j).at(k));
				}
				NovaMatrica2.push_back(NoviRed2);
			}
			pomocna.push_back(NovaMatrica2);
		}
		return pomocna;
	} else if(smjer==SmjerKretanja::DesnoLijevo) {
		kont kopija2;
		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica3;
			for(int k=kontejner.size()-1; k>=0; k--) {
				typename remove_reference<decltype(NovaMatrica3.at(0))>::type NoviRed3;
				for(int j=0; j<kontejner.size(); j++) {
					NoviRed3.push_back(kontejner.at(i).at(j).at(k));
				}
				NovaMatrica3.push_back(NoviRed3);
			}
			kopija2.push_back(NovaMatrica3);
		}

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica4;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica4.at(0))>::type NoviRed4;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed4.push_back(kopija2.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed4.push_back(kopija2.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed4.push_back(kopija2.at(i).at(j).at(k));
				}
				NovaMatrica4.push_back(NoviRed4);
			}
			pomocna.push_back(NovaMatrica4);
		}
		return pomocna;
	} else if(smjer==SmjerKretanja::LijevoDesno) {
		kont kopija3;
		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica5;
			for(int k=0; k<kontejner.size(); k++) {
				typename remove_reference<decltype(NovaMatrica5.at(0))>::type NoviRed5;
				for(int j=0; j<kontejner.size(); j++) {
					NoviRed5.push_back(kontejner.at(i).at(j).at(k));
				}
				NovaMatrica5.push_back(NoviRed5);
			}
			kopija3.push_back(NovaMatrica5);
		}

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica6;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica6.at(0))>::type NoviRed6;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed6.push_back(kopija3.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed6.push_back(kopija3.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed6.push_back(kopija3.at(i).at(j).at(k));
				}
				NovaMatrica6.push_back(NoviRed6);
			}
			pomocna.push_back(NovaMatrica6);
		}
		return pomocna;
	}

	else if(smjer==SmjerKretanja::NaprijedNazad) {
		kont kopija4;
		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica7;
			for(int j=0; j<kontejner.size(); j++) {
				NovaMatrica7.push_back(kontejner.at(j).at(i));
			}
			kopija4.push_back(NovaMatrica7);
		}

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica8;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica8.at(0))>::type NoviRed8;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed8.push_back(kopija4.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed8.push_back(kopija4.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed8.push_back(kopija4.at(i).at(j).at(k));
				}
				NovaMatrica8.push_back(NoviRed8);
			}
			pomocna.push_back(NovaMatrica8);
		}
		return pomocna;
	}

	else if(smjer==SmjerKretanja::NazadNaprijed) {
		kont kopija5;
		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica9;
			for(int j=kontejner.size()-1; j>=0; j--) {
				NovaMatrica9.push_back(kontejner.at(j).at(i));
			}
			kopija5.push_back(NovaMatrica9);
		}

		for(int i=0; i<kontejner.size(); i++) {
			typename remove_reference<decltype(kontejner.at(0))>::type NovaMatrica10;
			for(int j=0; j<kontejner.size(); j++) {
				typename remove_reference<decltype(NovaMatrica10.at(0))>::type NoviRed10;
				for(int k=0; k<kontejner.size(); k++) {
					if(j<koo && k<kontejner.size()-j && k>=j)
						NoviRed10.push_back(kopija5.at(i).at(j).at(k));
					else if(j==koo && k==koo)
						NoviRed10.push_back(kopija5.at(i).at(j).at(k));
					if(j>koo && k<=j && k>=kontejner.size()-j-1)
						NoviRed10.push_back(kopija5.at(i).at(j).at(k));
				}
				NovaMatrica10.push_back(NoviRed10);
			}
			pomocna.push_back(NovaMatrica10);
		}
		return pomocna;
	}

	return pomocna;

}


int main ()
{
	int n, smjer, pomocna;
	vector<deque<deque<int>>> kontejner;
	vector<deque<deque<int>>> pomocni;



	cout<<"Unesite dimenziju (x/y/z): ";
	cin>>n;

	if(n<0) {
		do {
			cout<<"Dimenzija nije ispravna, unesite opet: ";
			cin>>n;
		} while(n<0);
	}

	kontejner.resize(n);
	for(int i=0; i<n; i++)
		kontejner.at(i).resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			kontejner.at(i).at(j).resize(n);

	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++) {
				cin>>pomocna;
				kontejner.at(i).at(j).at(k)=pomocna;
			}

	cout<<"Unesite smjer kretanja [0 - 5]: ";
	cin>>smjer;
	if(smjer<0 || smjer>5) {
		do {
			cout<<"Smjer nije ispravan, unesite opet: ";
			cin>>smjer;
		} while(smjer<0 || smjer>5);
	}

	try {
		if(smjer==0)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::NaprijedNazad);
		else if(smjer==1)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::NazadNaprijed);
		else if(smjer==2)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::GoreDolje);
		else if(smjer==3)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::DoljeGore);
		else if(smjer==5)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::DesnoLijevo);
		else if(smjer==4)
			pomocni=PjescaniSat(kontejner, SmjerKretanja::LijevoDesno);
	} catch(domain_error e) {
		cout<<e.what();
		return 1;
	} catch(length_error e) {
		cout<<e.what();
		return 2;
	}

	cout<<"\nPjescani sat unesene matrice je: \n";

	for(int i=0; i<pomocni.size(); i++) {
		for(int j=0; j<pomocni.at(i).size(); j++) {
			for(int k=0; k<pomocni.at(i).at(j).size(); k++) {
				if(j<=pomocni.size()/2 && k==0) {
					for(int f=0; f<j; f++)
						cout<<"    ";
				} else if(j>pomocni.size()/2 && k==0) {
					for(int s=0; s<pomocni.size()-1-j; s++)
						cout<<"    ";
				}
				cout<<setw(4);
				cout<<pomocni.at(i).at(j).at(k);
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}

	return 0;
}