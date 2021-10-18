#include <isotream>
/*
class String{
	char *string;
	int broj_znakova;
public:
	String(int velicina=0):string(new char[velicina+1]),broj_znakova(velicina){}
	String (char *p);
	String (const String &s);
	String &operator=(const String &s);
	String &operator=(char *s);
	void DajDuzinu() const {return broj_znakova;}
	friend std::ostream &Ispisi(std::ostream &tok, String &s);
	char &operator[](String &s);
	friend String &operator+(const String &s1, const String &s2);
	friend String &operator+(const String &s1, char *p);
	friend String &operator+(char *p, const String &s1);
	friend String &operator+=(const String &s1, const String &s2);
	
}
*/
int main(){
	int niz[10];
	for(int i(0);i<10;i++) niz[i]=i+1;
	int *p;
	p=niz[2];
	std::cout<<*p;
	std::cout<<"Edvin!";
	return 0;
}