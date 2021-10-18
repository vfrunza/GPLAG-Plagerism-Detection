	#include <iostream>
	#include <vector>
	#include <limits>
	
	using std::cout;
	using std::cin;
	
	int Duplikat (int broj,std::vector<int>brojevi,int k) {
	    for (long long int i=0; i<brojevi.size(); i++) {
	    	if (i!=k) 
	    		if (broj==brojevi.at(i))
	            	return i;
	        if (i==brojevi.size()-1) break;
	    }
	    return 0;
	}
	std::vector<int> IzdvojiGadne (std::vector<int> moji_brojevi, bool sta_hoces) {
		std::vector <int> novi_brojevi1,novi_brojevi2;
		int nula(0),kec(0),dvica(0);
		if (sta_hoces==true) {
			for (long long i=0; i<moji_brojevi.size(); i++) {
				nula=0; kec=0; dvica=0;
				int nesto(moji_brojevi.at(i));
				while (nesto!=0) {
					int pomocna(nesto%3);
					if (pomocna==0)
						nula++;
					if (pomocna==1)
						kec++;
					if (pomocna==2)
						dvica++;
					nesto=int(nesto/3);
				}
				if ((nula%2==0) && (kec%2==0) && (dvica%2==0))
					if (moji_brojevi.at(i)!=0)
						novi_brojevi1.push_back(moji_brojevi.at(i));
				if (i==moji_brojevi.size()-1)
					break;
			}
			for (long long int i=0; i<novi_brojevi1.size(); i++) {
				int broj(novi_brojevi1.at(i));
				int e(0);
				int j(0);
				while (j<novi_brojevi1.size()) {
					e=Duplikat(broj,novi_brojevi1,i);
					if (e) break;
					j++;
				}
				if (e)
					novi_brojevi1.erase(novi_brojevi1.begin()+e);
				if (i==novi_brojevi1.size()-1)
					break;
			}
			return novi_brojevi1;
		}
		else {
			for (long long int i=0; i<moji_brojevi.size(); i++) {
				nula=0; kec=0; dvica=0;
				int nesto(moji_brojevi.at(i));
				while (nesto!=0) {
					int pomocna(nesto%3);
					if (pomocna==0)
						nula++;
					if (pomocna==1)
						kec++;
					if (pomocna==2)
						dvica++; 
					nesto/=3;
				}
				if ((nula%2==1 && kec%2==1 && dvica%2==1) || (nula%2==1 && kec%2==1 && dvica==0) || (dvica%2==1 && kec%2==1 && nula==0)|| (dvica%2==1 && nula%2==1 && kec==0) || (dvica%2==1 && nula==0 && kec==0) || (dvica==0 && nula==0 && kec%2==1) || (dvica==0 && nula%2==1 && kec==0))
					if (moji_brojevi.at(i)!=0)
						novi_brojevi2.push_back(moji_brojevi.at(i));
				if (i==moji_brojevi.size()-1)
					break;
			}
			for (long long int i=0; i<novi_brojevi2.size(); i++) {
				int broj(novi_brojevi2.at(i));
				int e(0);
				int j(0);
				while (j<novi_brojevi2.size()) {
					e=Duplikat(broj,novi_brojevi2,i);
					if (e) novi_brojevi2.erase(novi_brojevi2.begin()+e);
					j++;
				}
				if(i==novi_brojevi2.size()-1)
					break;
			}
			return novi_brojevi2;
		}
	}
	int main () {
		/*  121 15451 15 179 777 ;136 123 12 1212 10102 10012 1000 608 2613 -608 333 333 333 333 333 333 1000 -15 60 61 15 151 16 715 7222;  2460 608 426 6560 364*/
		cout<< "Unesite brojeve (0 za prekid unosa): ";
		std::vector <int> brojevi;
		int broj(0); 
		while (std::cin >> broj, broj!=0) 
			brojevi.push_back(broj);
		auto opaki (IzdvojiGadne(brojevi, true));
		cout << "Opaki: ";
		for (int i=0; i<opaki.size(); i++) 
			cout<<opaki[i]<<" ";
		auto odvratni (IzdvojiGadne(brojevi, false));
		cout << std::endl << "Odvratni: ";
		for (int j=0; j<odvratni.size(); j++)
			cout<<odvratni[j]<<" ";
		return 0;
	}
	
	