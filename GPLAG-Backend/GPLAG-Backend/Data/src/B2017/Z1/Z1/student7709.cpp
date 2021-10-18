
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>

class Lik
{
public:
	virtual void IspisiSpecificnosti()  const=0;
	virtual double DajObim() const =0;
	virtual double DajPovrsinu() const =0;
	virtual void Ispisi() const
	{
		IspisiSpecificnosti();
		std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
	}
	virtual ~Lik() {};
};

class Krug: public Lik
{
	double r;
	static  constexpr double PI = 3.141592653589793;
public:
	Krug (double r): r(r)
	{
		if(r<=0) throw
			std::domain_error ("Neispravni parameteri");
	};
	double DajObim() const override
	{
		return 2*r*PI;
	}

	double DajPovrsinu() const override
	{
		return r*r*PI;
	}
	void IspisiSpecificnosti() const override
	{
		std::cout<<"Krug poluprecnika "<<r<<std::endl;
	}
};

class Pravougaonik : public Lik
{
	double a, b;
public:
	Pravougaonik(double a, double b): a(a), b(b)
	{
		if(a<=0 || b<=0) throw std::domain_error("Neispravni parametri");
	};

	double DajObim() const override
	{
		return 2*a+2*b;
	}
		double DajPovrsinu() const override
	{
		return a*b;
	}

	void IspisiSpecificnosti() const override
	{
		std::cout<<"Pravougaonik sa stranicama duzine"<<a<<" i "<<b<<std::endl;
	}
};

class Trougao: public Lik
{
	double a,b,c;
public:
	Trougao(double a, double b, double c): a(a), b(b), c(c)
	{
		if(a+b<=c || b+c<=a || a+c<=b ||  a<=0 || b<=0  || c<=0)
			throw std::domain_error("Neispravni parametri");
	};

	double DajObim() const override
	{
		return a+b+c;
	}

	double DajPovrsinu() const override
	{
		double s((a+b+c)/2);
		return std::sqrt(s*(s-a)*(s-b)*(s-c));
	}

	void IspisiSpecificnosti() const override
	{
		std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
	}
};


int main()
{
	std::cout<<"Koliko zelite likova: ";
	int n;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::vector<std::shared_ptr<Lik>> v;
	for(int i =1; i <= n; i++) {
		try {
			bool ispravno(false);
			while (!ispravno) {
				std::cout<<"Lik "<<i<<": ";
				char slovo;
				std::cin>>slovo;
				if(slovo=='P') {
					
					
					double a, b;
					char zarez;
					std::cin>>a>>zarez>>b;
					if(std::cin && zarez==',') {

						v.push_back(std::make_shared<Pravougaonik>(a,b));
						ispravno = true;
					} else 
					{
						std::cin.clear();
					}
				}	else if(slovo == 'K') {

					double a;
					std::cin>>a;

					if(std::cin && std::cin.peek()== '\n') {
						v.push_back(std::make_shared<Krug> (a));
						ispravno = true;
					}

					else if(slovo == 'T') {
						double a, b, c;
						char zarez, zarez2;
						std::cin>>a>>zarez>>b>>zarez2>>c;
						if(std::cin && zarez == ', ' && zarez2==', ') {
							v.push_back(std::make_shared<Trougao>(a,b,c));
							ispravno=true;
						} else {
							std::cin.clear();
						}
					} else
						std::cin.clear();

					if(!ispravno) throw
						std::domain_error("Neispravno");
				}
			} catch(std::domain_error izuzetak) {
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
			}
			std::cin.ignore(10000,'\n');
		}

		std::cout<<std::endl;
		for(int i= 0; i < n; i++)

		{
			v[i]->Ispisi();
		}
	}
		return 0;
	}
