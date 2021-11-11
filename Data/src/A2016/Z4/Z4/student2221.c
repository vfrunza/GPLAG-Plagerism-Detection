#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 0.0001

float formirajBroj(char* s)
{
	float broj = 0;
	int i = 0, negativan = 1;
	if (s[i] == '-')
	{
		negativan = -1;
		i++;
	}
	while (s[i] != '.' && s[i] != '\0')
	{
		broj = broj*10 + s[i] - '0';
		i++;
	}
	if (s[i] == '\0')
	return negativan * broj;
	
	i++;
	float k = 0.1;
	while (s[i] != '\0')
	{
		broj += (s[i] - '0')*k;
		k *= 0.1;
		i++;
	}
	
	return negativan * broj;
}

int isNumber(char* s)
{
	int i = 0, m = 1, tacka = 0;
	if(s[0] == '-')
	{
		i++;
	}
	while(s[i] != '\0')
	{
		if((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			m = 0;
			return 0;
		}else if(tacka && s[i] == '.')
		{
			m = 0;
			return 0;
		}
		if(s[i] == '.' && i-1 > 0 && s[i-1] != '-')
		{
			if(s[i-1] == '-') return 0;
			tacka = 1;
		}
		i++;
	}
	return 1;
}

int testirajString(char* s)
{
	int i = 0, m = 1;
	while(s[i] != '\0')
	{
		if(s[i] == '(')
		{
			i++;
			char temp[50] = {'\0'};
			int brojac = 0;
			while(s[i] != ',' && s[i] != '\0')
			{
				temp[brojac] = s[i];
				i++; brojac++;
				if(s[i] == '\0')
				{
					return 0;
				}
				
			}
			temp[brojac] = '\0';
			i++;
			if(!isNumber(temp) || s[i] == '\0') return 0;
			brojac = 0;
			while(s[i] != ')' && s[i] != '\0')
			{
				temp[brojac] = s[i];
				i++; brojac++;
				if(s[i] == '\0')
				{
					return 0;
				}
				
			}
			temp[brojac] = '\0';
			if(!isNumber(temp) || s[i] == '\0') return 0;
			if(s[i] != ')') return 0;
			i++;
			if(s[i] == ',' && s[i + 1] != '(') return 0;
			else if(s[i] == '\0') return 1;
		}else return 0;
		i++;
	}
	return 1;
}

char* obuhvat (char* s, float x1, float y1, float x2, float y2)
{
	int i = 0, brojacPom = 0;
	char pom[1000] = {'\0'};
	//if(!testirajString(s))
	//{
//		s = 0;
//		return 0;
//	}
	while (s[i] != 0)
	{
		float x = 0, y = 0;
		if (s[i] == '(')
		{
			char broj[50], brojac = 0;
			while (s[i] != ')')
			{
				if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '.')
				{
					broj[brojac] = s[i];
					brojac++;
				}
				if (s[i] == ',')
				{
					broj[brojac] = '\0';
					x = formirajBroj(broj);
					brojac = 0;
				}
				i++;
			}
			if(brojac != 0) return 0;
			broj[brojac] = '\0';
			y = formirajBroj(broj);
			if ((x1 <= x || fabs(x1-x) <= eps) && (x<=x2 || fabs(x-x2) <= eps) 
			&& (y1 <= y || fabs(y-y1) <= eps) && (y <= y2 || fabs(y-y2) <= eps))
			{
				int k = i;
				while (k > 0 && s[k] != '(')
				{
					k--;
				}
				while (s[k] != '\0' && s[k] != ')')
				{
					pom[brojacPom] = s[k];
					brojacPom++;
					k++;
				}
				pom[brojacPom] = ')';
				brojacPom++;
				pom[brojacPom] = ',';
				brojacPom++;
				pom[brojacPom] = '\0';
				
			}
		}
		if(s[i] == '\0') break;
		i++;
	}
	i = 0;
	while (pom[i] != '\0')
	{
		s[i] = pom[i];
		i++;
	}
	if(i != 0 && s[i-1] == ',')
	{
		s[i-1] = '\0';
	}else s[0] = '\0';
	return s;
}

int main()
{
char s[] = "(1.1,5.5),(1.2,5.5),(1.3,5.5),(1.4,5.5),(1.5,5.5)";
char* rez = obuhvat(s, 1.2, 5.499, 1.4, 5.501);
printf("%s", rez);


}