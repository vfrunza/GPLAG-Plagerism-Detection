#if 0
#include <stdio.h>
#include <stdlib.h>
char ToUp (char c) {return c >= 'a' && c <= 'z' ? c - 32 : c;}
int poredi (const char *a, const char *b, const char *c)
{
	if (b == c || !*a) return 0;
	if (*b++ != '/') return 0;
	while (*a && b < c)
		if (ToUp(*a++) != ToUp(*b++))
			return 0;
	return !*a && b == c;
}
int poredi2 (const char *a, const char *b, const char *c, const char *d)
{
	if (*c++ != '/') return 0;
	while (a < b && c < d)
		if (ToUp(*a++) != ToUp(*c++))
			return 0;
	return a == b && c == d;
}
void prekopiraj (char *dest, const char *a, const char *b)
{
	while (a < b)
		*dest++ = *a++;
	*dest = 0;
}
void pobrisi (char **c, int l)
{
	int i;
	for (i = 0; i < l; ++i)
		free(c[i]);
	free (c);
}
int provjeri (const char *c)
{
	int kap = 10, i;  /* kapacitet: neka bude 10 za pocetak */
	char ** stack = malloc (sizeof (char *) * kap);
	int brojt = 0; /* broj tagova */
	while (*c)
		{
			if (*c == '<')
			{
				const char *poc = c, *kraj = c;
				while (*kraj && *kraj != '>' && *kraj != ' ')
					kraj++;
				if (kraj > poc)
					poc++;
				if (brojt > 0 && poredi(stack[brojt - 1], poc, kraj))
					free (stack[--brojt]);
				else 
				{
					if (brojt == kap)
						{
							kap *= 2;
							stack = realloc (stack, sizeof (char *) * kap);
						}
					stack[brojt] = malloc (sizeof (char *) * (kraj - poc + 1));
					prekopiraj(stack[brojt++], poc, kraj);					
				}

			}
			c++;
		}
	pobrisi (stack, brojt);
	return !brojt;
}
int provjeri_pom (const char *a, const char *b)
{
	int br = 0;
	while (a < b)
		{
			if (*a == '<' && *(1 + a) != '/')
				{
					const char *poc = a, *kraj = a;
					while (kraj < b && *kraj != '>' && *kraj != ' ')
						kraj++;
					if (kraj > poc)
						poc++;
					const char *n = kraj;
					while (n < b && *n != '<' && *(n + 1) != '/')
						n++;
					if (n == b) return 1;
					n++;
					const char *v = n;
					while (v < b && *v != '>')
						v++;
					if (v == b) return 1;
					if (poredi2 (poc, kraj, n, v))
						return 0;
					else return provjeri_pom(kraj, n);
				}
			a++;
		}
	return 0;
}
int Len (const char *c)
{
	int br = 0;
	while (*c++) br++;
	return br;
}
int provjeri2 (const char *c)
{
	return provjeri_pom(c, c + Len (c)) == 0;
}
#include <string.h>
int main() {
{//AT12 (skriveni): zbog hardkodiranja (broj tagova)

	char html[5001 * 9 + 1] = "<p>e"; //5000 <a> tagova jedan pored drugog i sve to u jednom <p> tagu
	const char *poc_a = "<a>t", *kraj_a = "</a>f";
	int i; 
	for (i = 0; i < 5000; ++i)
		strcat (strcat (html, poc_a), kraj_a);
	strcat (html, "p</p>");
	//string izgleda kao: <p>e<a>t</a>f<a>t</a>f<a>t</a>f ... <a>t</a>f<a>t</a>fp</p>
	//svi su uredno otvoreni i zatvoreni!
	printf ("Provjera 1: %d\n", provjeri (html));
	//sada neki <a> tag izmijenimo da bude <i> tag, naravno da nisu svi otvoreni/zatvoreni validno
	html[24] = 'i';
	printf ("Provjera 2: %d\n", provjeri (html));
}
return 12;	
{//AT11 (skriveni): dugi tagovi (zbog hardkodiranja)
	const char *t1 = "<JedanBasJaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaakoDugHTMLTagKojiJeStavljenOvdjeRadiHardKodiranja>"
					"ovo je cisto stavljeno da vidimo je li napravljena matrica gdje je duzina hardkodirana"
					"</JedanBasJaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaakoDugHTMLTagKojiJeStavljenOvdjeRadiHardKodiranja>";
	const char *t2 = "<Taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaag>"
					"tag."
					"<Taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaagg>"; //dva g na kraju
	printf ("Provjera 1: %d\nProvjera 2: %d", provjeri(t2), provjeri(t1));
}
return 11;
{//AT10: nastavak, neregularan HTML
	printf ("Provjera  7: %d\n", provjeri("<p>razmak prije p a poslije / </ p>"));
	printf ("Provjera  8: %d\n", provjeri("<p   >a ovo je ipak validno, razmaci NAKON p</p>"));
	printf ("Provjera  9: %d\n", provjeri("<p   >i ovo je validno, razmaci NAKON p</p    >"));
	printf ("Provjera 10: %d\n", provjeri("<></>")); /* nije validno */
	printf ("Provjera 11: %d\n", provjeri("")); /* ok */
	printf ("Provjera 12: %d\n", provjeri("                                            ")); /* ok */
	printf ("Provjera 13: %d\n", provjeri("< p> razmak prije p i prije / p, sto nije ispravno!  </ p>"));
	
}	
{//AT9: bas neregularan HTML

	printf ("Provjera  1: %d\n", provjeri("<p>ovdje ide greska <, znak 'manje' ne smije biti ovdje, pise se inace &lt;</p>"));
	printf ("Provjera  2: %d\n", provjeri("<p>jos gore, xd, </ </p>"));
	printf ("Provjera  3: %d\n", provjeri("<p>jos gore^2, xd, </p </p>"));
	printf ("Provjera  4: %d\n", provjeri("<p>jos gore, xd</p><p"));
	printf ("Provjera  5: %d\n", provjeri("<p>hah, nesto fino p </p><p></p>"));
	printf ("Provjera  6: %d\n", provjeri("< p> razmak prije p </p>"));
}
return 9;	
{//AT8: HTML je validan i sa velikim slovima za TAGove, tipa <p>paragraf</P>
	
	printf ("Provjera 1: %d\n", provjeri("<a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A>"));
	printf ("Provjera 2: %d\n", provjeri("<P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P>"));
	printf ("Provjera 3: %d\n", provjeri("<DiV><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P><dIv>"));
	printf ("Provjera 3: %d\n", provjeri("<DiV><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</A></P></dIv>"));
	printf ("Provjera 4: %d\n", provjeri("<h1><P><a href='https://etfba.slack.com'>DODJITE svi na HABER (etf.ba)!</B></P></h1>"));
	
}
return 8;
{//AT7: vise zatvorenih nego otvorenih
	printf ("Provjera 1: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a></span></span>"));
	printf ("Provjera 2: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a><span></span></span>"));
	printf ("Provjera 3: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</span></span></span>"));
	printf ("Provjera 4: %d\n", provjeri("<span><span><span><a href='https://etf.unsa.ba'>etf.unsa.ba stranica</a></span></span></span>"));
	
}
return 7;
{//AT6 (skriveni): ugnijezdeni tagovi (div u div u div-u)
	const char *t1 = "<div id='1' class='container'>"
						"<div id='1-1' class='container'>"
							"<div id='1-1-1' class='container'>"
								"Ovo je unutrasnji DIV, 1-1-1, nalazi se u 1-1 div-u"
								"koji se nalazi u 1 div-u"
							"</div>"
						"</div>"
						"<div id='1-2' class='container'>"
						"</div>"
						"<div id='1-3' class='container'>"
							"<div id='1-3-1>Div 1-3-1"
							"</div>"
							"<div id='1-3-2>"
								"<div id='1-3-2-1'>"
									"'najunutrasnji' div xD"
								"</div>"
							"</div>"
							"<div id='1-3-3>DIV"
							"</div>"
						"</div>"
						"<div id='1-4' class='container'>"
						"</div>"
					"</div>"
					"<div id='2'>"
					"</div>";
	const char *t2 = "<div><div><a></a><div><div></div></div></div>";
	printf ("Provjera 2: %d\n", provjeri (t2));  /* 4 otvorena, 3 zatvorena*/
	printf ("Provjera 1: %d", provjeri (t1));
}	
return 6;
{//AT5: real-world example (dio stranice etf.unsa.ba, sa popravljenim <br> tagovima)
char etfunsaba[] = "<center>"
	"<a href=\"http://icat.etf.unsa.ba/\">"
        "<p class=\"tekst\">"
        "<span class=\"linkovi\">"
		"XXVI International Conference on Information,"
		"<br></br>"
		"Communication and Automation Technologies"
		"<br></br>"
		"<br></br>"
		"<strong>ICAT 2017</strong><br></br>"
		"<br></br>"
		"Sarajevo, Bosnia and Herzegovina<br></br>"
		"October 26-28, 2017.<br></br>"
		"</span>"
        "</p>"
        "</a>"
    "</center>";
    printf ("Provjera 1: %d\n", provjeri (etfunsaba));
    //izmijenimo prvi tag <center> da bude <zenter>, pa onda nema zatvarajuceg
    etfunsaba[1] = 'z';
    printf ("Provjera 2: %d\n", provjeri (etfunsaba));
	
}
return 5;	
{//AT4: Prazni tagovi
	printf ("Provjera 1: %d\n", provjeri ("<b></b>"));
	printf ("Provjera 2: %d\n", provjeri ("<html><head><title></title></head><body><p></p></body></html>"));
	printf ("Provjera 3: %d\n", provjeri ("<i>                          </i>"));
	printf ("Provjera 4: %d\n", provjeri ("      <i>              </i>      "));
	printf ("Provjera 5: %d\n", provjeri ("      <i>      <b></b>        </i>      "));
	printf ("Provjera 6: %d\n", provjeri ("      <i>      <b></b>        <i>      ")); 
}	
return 4;
{//AT3: pogresno zatvoreni tagovi i bez tagova
 printf ("Provjera 1: %d\n", provjeri ("<h3>Ovo je naslov velicine 3. h3 je skracenica za 'header of size 3', h1 je najveci!</h2>")); 
 printf ("Provjera 2: %d\n", provjeri ("Ovo je neki isjecak HTML-a koji je potpuno validan - nema tagova"));
}
return 3;
{//AT2: funkcija ne bi trebala da mijenja proslijedjeni string
 //ispravan prototip funkcije je: const char *provjeri (const char *string);
 printf ("Provjera 1: %d\n", provjeri ("<div><h4>Naslov</h4><p>Danasnja vijest</div>")); /* <p> nije zatvoren */
 printf ("Provjera 2: %d\n", provjeri ("<div><h4>Naslov</h4><p>Danasnja vijest</p></div>"));
}
	return 0;
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<b><a>proba</b></a>";
	char tekst3[] = "<b><b></b></b>";
	printf("%d ", provjeri(tekst1));
	printf("%d ", provjeri(tekst2));
	printf("%d ", provjeri(tekst3));
	return 0;
}
#endif
#include <stdio.h>

int provjeri(char* p)
{
	char* pok = p;
	int brojac_otvorenih = 0;
	int brojac_zatvorenih = 0;
	int i=0, j=0;
	char tagovi[25][20];
	while(*p!='\0')
	{
		if(*p=='<' && *(p+1)!='/')
			brojac_otvorenih++;
		else if(*p=='<' && *(p+1)=='/')
			brojac_zatvorenih++;
		p++;
	}
	if(brojac_zatvorenih != brojac_otvorenih)
		return 0;
	if(brojac_otvorenih==0)
		return 1;
	p = pok;
	while(*p!='\0')
	{
		if(*p=='<' && *(p+1)!='/')
		{
			p++;
			if(*p==' ' || *p=='>')
				return 0;
			while(*p!='>' && *p!=' ')
			{
				char c = *p;
				if(c>='A' && c<='Z')
					c+=32 ;
				tagovi[i][j] = c;
				j++;
				p++;
			}
			tagovi[i][j] = '\0';
			i++;
			j=0;
		}
		else if(*p=='<' && *(p+1)=='/')
		{
			p++;
			p++;
			if(*p==' ' || *p=='>')
				return 0;
			while(*p!='>' && *p!=' ')
			{
				char c = *p;
				if(c>='A' && c<='Z')
					c+=32;
				if(c!=tagovi[i-1][j] || tagovi[i-1][j]=='\0')
					return 0;
				p++;
				j++;
			}
			i--;
			j=0; 
		}
		p++;
	}
	return 1;
}

int main() {
	printf("%d", provjeri("<html><a></a></html>"));
	return 0;
}
