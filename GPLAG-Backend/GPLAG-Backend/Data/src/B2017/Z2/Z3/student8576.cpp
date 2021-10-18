#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <type_traits>
using namespace std;
template <typename Tip>
bool Periodican(const vector<Tip> &v, int n){
	if(v.size()<=n || n<=0) return false;
	for(int i=0;i<v.size()-n;i++){
		if(v.at(i)!=v.at(i+n))
		return false;
	}
	return true;
}
template <typename Tip>
int OsnovniPeriod(const vector<Tip> &v){
	for(int i=0;i<v.size();i++){
		if(Periodican(v,i))
		return i;
	}
	return 0;
}
template <typename Tip>
auto AlocirajKontinualno(const vector<Tip> &v, int &koliko_puta) -> Tip **{
	if(!v.size()) throw "Prazan vektor!";
	int period(OsnovniPeriod(v));
	int nova_vel(v.size());
	if(period){
		if(v.size()%period!=0) nova_vel+=period-v.size()%period;
		koliko_puta=nova_vel/period;
	}
	else{
		nova_vel=2*v.size();
		koliko_puta=2;
	}
	Tip suma{};
	for(int i=0;i<v.size();i++){
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
		else suma+=v.at(i);
	}
	if(period && v.size()%period!=0){
		for(int i=v.size();i<nova_vel;i++)
		suma+=v.at(i%period);
	}
	else if(!period) suma+=suma;
	try{
	Tip **p(new Tip*[nova_vel]);
	try{
		p[0]=new Tip[suma];
		if(period){
		for(int i=1;i<v.size();i++) p[i]=p[i-1]+v.at(i-1);
		for(int i=v.size();i<nova_vel;i++) p[i]=p[i-1]+v.at(i%period-1);	
		} 
		else{
		for(int i=1;i<=v.size();i++) p[i]=p[i-1]+v.at(i-1);
		for(int i=v.size()+1;i<nova_vel;i++) p[i]=p[i-1]+v.at(i-v.size()-1);
		}
		for(int i=0;i<v.size();i++){
			for(int j=1;j<=v.at(i);j++){
				p[i][v.at(i)-j]=j;
			}
		}
		if(period)
		for(int i=v.size();i<nova_vel;i++){
			for(int j=1;j<=v.at(i%period);j++){
				p[i][v.at(i%period)-j]=j;
			}
		}
		else
		for(int i=v.size();i<nova_vel;i++){
			for(int j=1;j<=v.at(i-v.size());j++){
				p[i][v.at(i-v.size())-j]=j;
			}
		}
		return p;
	}catch(...){
		delete [] p;
		throw;
	}
	}catch(...){
		throw;
	}
	
}
template <typename Tip>
auto AlocirajFragmentirano(const vector<Tip> &v, int &koliko_puta) -> Tip **{
	if(!v.size()) throw "Prazan vektor!";
	int period(OsnovniPeriod(v));
	int nova_vel(v.size());
	if(period){
		if(v.size()%period!=0) nova_vel+=period-v.size()%period;
		koliko_puta=nova_vel/period;
	}
	else{
		nova_vel=2*v.size();
		koliko_puta=2;
	}
	Tip max(v.at(0));
	for(int i=0;i<v.size();i++){
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
		if(v.at(i)>max) max=v.at(i);
	}
	try{
	Tip **p(new Tip*[nova_vel]{});
	try{
		if(period){
		for(int i=0;i<v.size();i++){
		p[i]=new Tip[v.at(i)];
		}
		for(int i=v.size();i<nova_vel;i++){
			p[i]=new Tip[v.at(v.size()%period)];
		}
		}
		else{
		for(int i=0;i<v.size();i++){
			p[i]=new Tip[v.at(i)];
		}
		for(int i=v.size();i<nova_vel;i++){
			p[i]=new Tip[v.at(i-v.size())];
		}
		}
		for(int i=0;i<v.size();i++){
			int k(0);
			for(int j=max;j>0;j--){
				p[i][v.at(i)-1-k]=j;
				k++;
				if(k==v.at(i)) break;
			}
		}
		if(period)
		for(int i=v.size();i<nova_vel;i++){
			int k(0);
			for(int j=max;j>0;j--){
				p[i][v.at(v.size()%period)-1-k]=j;
				k++;
				if(k==v.at(v.size()%period)) break;
			}
		}
		else
		for(int i=v.size();i<nova_vel;i++){
			int k(0);
			for(int j=max;j>0;j--){
				p[i][v.at(i-v.size())-1-k]=j;
				k++;
				if(k==v.at(i-v.size())) break;
			}
		}
		return p;
	}catch(...){
		for(int i=0;i<nova_vel;i++) delete [] p[i];
		delete [] p;
		throw;
	}
	}catch(...){
		throw;
	}
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	vector<int> v(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) cin>>v.at(i);
	int f;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>f;
	int x;
	if(f==1){
		try{
		int vel(OsnovniPeriod(v));
		int **p(nullptr);
		p=AlocirajFragmentirano(v,x);
		cout<<"Dinamicki alocirana matrica: "<<endl;
		if(vel){
		int k(1);
		for(int i=0;i<vel*x;i++){
			for(int j=0;j<k;j++){
				cout<<setw(3)<<left<<p[i][j];
			}
			if(k<vel) k++;
			else k=1;
			cout<<endl;
		}
		}
		else{
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v.at(i);j++)
			cout<<left<<setw(3)<<p[i][j];
			cout<<endl;
		}
		for(int i=v.size();i<v.size()*x;i++){
			for(int j=0;j<v.at(i-v.size());j++)
			cout<<left<<setw(3)<<p[i][j];
			cout<<endl;
		}
		}
		if(vel){
		for(int i=0;i<vel*x;i++) delete[] p[i];
		delete[] p;
		}else{
		for(int i=0;i<v.size()*x;i++) delete[] p[i];
		delete[] p;
		}
		}catch(bad_alloc){
			cout<<"Nedovoljno memorije";
		}
		catch(domain_error izuzetak){
			cout<<"Izuzetak: "<<izuzetak.what();
		}
		catch(const char poruka[]){
			cout<<"Izuzetak: "<<poruka;
		}
	}
	else if(!f){
		try{
		int vel(OsnovniPeriod(v));
		int **p=AlocirajKontinualno(v,x);
		cout<<"Dinamicki alocirana matrica: "<<endl;
		if(vel){
		int k(1);
		for(int i=0;i<vel*x;i++){
			for(int j=0;j<k;j++){
				cout<<setw(3)<<left<<p[i][j];
			}
			if(k<vel) k++;
			else k=1;
			cout<<endl;
		}
		}
		else{
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v.at(i);j++)
			cout<<left<<setw(3)<<p[i][j];
			cout<<endl;
		}
		for(int i=v.size();i<v.size()*x;i++){
			for(int j=0;j<v.at(i-v.size());j++)
			cout<<left<<setw(3)<<p[i][j];
			cout<<endl;
		}
		}
		delete[] p[0];
		delete[] p;
		}catch(bad_alloc){
			cout<<"Nedovoljno memorije";
		}catch(domain_error izuzetak){
			cout<<"Izuzetak: "<<izuzetak.what();
		}
		catch(const char poruka[]){
			cout<<"Izuzetak: "<<poruka;
		}
	}
	return 0;
}