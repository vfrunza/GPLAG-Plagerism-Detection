#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> IzdvojiGadne (vector<int> vec, bool b) {
	vector<int> opaki;
	vector<int> odvartni;
	vector<int> temp;
	for(int i=0; i<vec.size(); i++) {
		for(int j=i+1; j<vec.size(); ) {
			if(vec[i]==vec[j]) {
				for(int k=j; k<vec.size()-1; k++) {
					vec[k]=vec[k+1];
				}
				vec.resize(vec.size()-1);
			}
			else j++;
		}
	}
	
	for(int i=0; i<vec.size(); i++) {
		int exc=fabs(vec[i]);
		if(exc==0) continue;
		vector<int> temp;
		for(int j=0; ; j++) {
			if(exc<3) {
				temp.push_back(exc);
				break;
			}
			int ostatak=exc-((int)(exc/3))*3;
			temp.push_back(ostatak);
			exc=(int)(exc/3);
		}
		if(b>0) {
			int br0(0), br1(0), br2(0);
			for(int k=0; k<temp.size(); k++) {
				if(temp[k]==0) br0++;
				else if(temp[k]==1) br1++;
				else if(temp[k]==2) br2++;
				else break;
			}
			if((br0%2==0 || br0==0) && (br1%2==0 || br1==0) && (br2%2==0 || br2==0)) {
				opaki.push_back(vec[i]);
			}
		}
		else if(b<=0) {
			long br0(0), br1(0), br2(0);
			for(int k=0; k<temp.size(); k++) {
				if(temp[k]==0) br0++;
				else if(temp[k]==1) br1++;
				else if(temp[k]==2) br2++;
				else break;
			}
			if((br0==0 || br0%2!=0) && (br1==0 || br1%2!=0) && (br2==0 || br2%2!=0)) {
				odvartni.push_back(vec[i]);
			}
		}
	}
	if(b>0) return opaki;
	else if(b<=0) return odvartni;
}


int main ()
{
	vector<int> vec, vec1, vec2;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int temp;
	do {
		cin >> temp;
		vec.push_back(temp);
	} while(temp!=0);
	for(int i=0; i<vec.size(); i++) {
		for(int j=i+1; j<vec.size(); ) {
			if(vec[i]==vec[j]) {
				for(int k=j; k<vec.size(); k++) {
					vec[k]=vec[k+1];
				}
				vec.resize(vec.size()-1);
			}
			else j++;
		}
	}
	vec.resize(vec.size()-1);
	vec1=IzdvojiGadne(vec,true);
	cout <<"Opaki: ";
	for(int i=0; i<vec1.size(); i++) {
		cout << vec1[i] << " ";
	}
	vec2=IzdvojiGadne(vec,false);
	cout << endl <<"Odvratni: ";
	for(int i=0; i<vec2.size(); i++) {
		cout << vec2[i] << " ";
	}

	return 0;
}