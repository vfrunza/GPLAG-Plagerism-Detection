
#include <iostream>
#include <vector>
#include <cmath>


bool DaLiJeProst (int x)
{
//kopirana sa tutorijala 2
	if(x==1 || x==0) return false;
	long int m=abs(x);
	for (int i=2; i<=sqrt(m); i++) { //Fermaova teorema
		if (x%i==0) return false;
	}
	return true;

}

int PrebaciUTenarni(int n)
{
	n=abs(n);
	int temp=(n);
	int suma(0);
	int i(0);

	do {
		int cifra = temp % 3;
		temp /= 3;
		suma+= cifra*(pow(10,i));
		i++;

	} while (temp!=0);

	return suma;
	//ok
}
bool JelSimetrican(int n)
{

	int temp=PrebaciUTenarni(n);
	temp=fabs(temp);
	int novibroj(0);
	int promjenljivazapamcenje=PrebaciUTenarni(n);
	std::vector<int>zaprovjeravanje ;
	do {
		int cifra = temp % 10;
		temp /= 10;
		zaprovjeravanje.push_back(abs(cifra));
	} while (temp!=0);

	int velicina=zaprovjeravanje.size();
	for (int i=0; i<zaprovjeravanje.size(); i++) {
		if (zaprovjeravanje.at(i)!=zaprovjeravanje.at(zaprovjeravanje.size()-1-i)) return false;

	}

	return true;
	//ok
}
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool istinitost)
{

	std::vector<int> prosti, slozeni ;
	int vel=vektor.size();
	for(int i(0); i<vel; i++) {
		for(int j(i+1); j<vel; j++) {
			if(vektor.at(i)==vektor.at(j)) {
				for(int k(j); k<vel-1; k++) {
					vektor.at(k)=vektor.at(k+1);
					vel--;
					vektor.resize(vel);
					j--;
				}
			}
		}
	}

	for(int i(0); i<vektor.size(); i++) {
		if(JelSimetrican(vektor.at(i))) {

			if(DaLiJeProst(vektor[i])) {
				prosti.push_back(vektor.at(i));

				int velprost=prosti.size();

				for(int l(0); l<velprost; l++) {
					for(int s(l+1); s<velprost; s++) {
						if(prosti.at(l)==prosti.at(s)) {
							for(int z(s); z<velprost-1; z++) {
								prosti.at(z)=prosti.at(z+1);
								velprost--;
								prosti.resize(velprost);
								s--;
							}
						}
					}
				}
			}






			else {
				slozeni.push_back(vektor[i]);

				int velslozeni=slozeni.size();

				for(int l(0); l<velslozeni; l++) {
					for(int s(l+1); s<velslozeni; s++) {
						if(slozeni.at(l)==slozeni.at(s)) {
							for(int z(s); z<velslozeni-1; z++) {
								slozeni.at(z)=slozeni.at(z+1);
								velslozeni--;
								slozeni.resize(velslozeni);
								s--;
							}
						}
					}
				}
			}

		}
	}



	if(istinitost==true)return prosti;
	else return slozeni;
}


int main ()
{


	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> unesenvektor ;
	int a;
	int n;
	do {
		std::cin >> a;
		if (a==-1) break;
		unesenvektor.push_back(a);

	} while (a!=-1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> n;
	if (n!=1 && n!=0) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		do {
			std::cin >> n;
		} while (n!=1 && n!=0);
	}

	if (n==1) {
		std::vector<int> sklj=IzdvojiSimetricneTernarne(unesenvektor,true);
		if (sklj.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout <<"Prosti simetricni brojevi iz vektora su: ";
			for (int i=0; i<sklj.size(); i++) {


				if (i==sklj.size()-1) std::cout << sklj.at(i) << ".";
				else std::cout << sklj.at(i) << ", ";
			}
		}
	} else if (n==0) {
		std::vector<int> sklj=IzdvojiSimetricneTernarne(unesenvektor,false);
		if (sklj.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout <<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<sklj.size(); i++) {


				if (i==sklj.size()-1) std::cout << sklj.at(i)<< ".";
				else std::cout<< sklj.at(i) << ", ";
			}
		}
	}

	return 0;
}