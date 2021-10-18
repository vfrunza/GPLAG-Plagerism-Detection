
#include <iostream>
#include<vector>
#include<deque>


enum  Smjer {Rastuci,Opadajuci};
typedef std::deque<std::vector<int>> Matrica ;





bool StepenDvojke(int a)
{

	for(int i=1; i<=a; i*=2)
		if (i==a) return true;


	return false;

}


Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> m,Smjer a)
{
	std::vector<int> s;
	std::vector<int>g;
	int velicina_matrice(0);
	Matrica mat;


	if(a==Rastuci) {

		for(int i=0; i<m.size()-1; i++) {
			if(m.at(i)<=m.at(i+1) && StepenDvojke(m.at(i))) {

				s.push_back(m.at(i));

			} else {
				if(i!=0) {
					if(m.at(i)>=m.at(i-1) && StepenDvojke(m.at(i))) {


						s.push_back(m.at(i));
					}
				}
			}

			if (i==m.size()-1) {
				if(m.at(m.size()-1) && m.at(i)>=m.at(i-1) && StepenDvojke(m.at(i)))
					s.push_back(m.at(i));
			}
			
			if(m.at(i+1)>m.at(i) && StepenDvojke((m.at(i+1)))) continue;

			if(s.size()>1) {
				mat.resize(velicina_matrice+1);
				mat.at(velicina_matrice).resize(s.size());
				for(int i=0; i<s.size(); i++) {
					mat.at(velicina_matrice).at(i)=s.at(i);
				}
				velicina_matrice++;
				s.resize(0);
			}

			if(m.at(i)>m.at(i+1) || StepenDvojke(m.at(i)==false))
				s.resize(0);




			}

		}


		if(a==Opadajuci) {

			for(int i=0; i<m.size()-1; i++) {
				if(m.at(i)>=m.at(i+1) && StepenDvojke(m.at(i))) {

					s.push_back(m.at(i));

				} else {
					if(i!=0) {
						if(m.at(i)<=m.at(i-1) && StepenDvojke(m.at(i))) {


							s.push_back(m.at(i));
						}
					}
				}
				if(i==m.size()-1) {
					if(m.at(m.size()-1) && m.at(i)<=m.at(i-1) && StepenDvojke(m.at(i)))
						s.push_back(m.at(i));
				}
				
				

                 if(m.at(i+1)<m.at(i) && StepenDvojke((m.at(i+1)))) continue;
				if(s.size()>1 ) {
					mat.resize(velicina_matrice+1);
					mat.at(velicina_matrice).resize(s.size());
					for(int i=0; i<s.size(); i++) {
					
						mat.at(velicina_matrice).at(i)=s.at(i);	
						
						
					}
					velicina_matrice++;
					s.resize(0);
				}

				if(m.at(i)<m.at(i+1) || StepenDvojke(m.at(i))==false)
					s.resize(0);

			}
		}


		return mat;



	}


	int main () {
		Matrica p;
		int broj_elem;
		std::vector<int> v;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>broj_elem;
		std::cout<<"Unesite elemente vektora: ";
		int unos;
		for(int i=0; i<broj_elem; i++) {
			std::cin>>unos;
			v.push_back(unos);

		}
		int n;
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>n;

		if(n==1) {
			std::cout<<"Maksimalni rastuci podnizovi: \n";
			p= MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		}

		if(n==2) {
			std::cout<<"Maksimalni opadajuci podnizovi: \n";
			p=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		}

		for (int i=0; i<p.size(); i++) {
			for(int j=0; j<p.at(i).size(); j++) {
				std::cout<<p.at(i).at(j)<<" ";

			}
			std::cout<<std::endl;
		}

		return 0;
	}