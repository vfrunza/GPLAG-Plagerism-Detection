#include <stdio.h>

char* br_o_z(char *s, int x) {
	int otv = 0, zatv = 0;
	while (*s != '\0') {
		if (*(s+1) == '/' && *s == '<') zatv++;
		else if (*s == '<') otv++;
		if (zatv > otv) return NULL;
		if (x != 0 && zatv == otv) return s;
		s++;
	}
	if (otv != zatv) return NULL;
	return s;
}

char* kraj_tag(char *s) {
	int razmak = 0;
	if (*++s == '\0') return NULL;
	while (*s != '\0' && *s != '>') {
		if (*(s-1) == '/' && !((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) return NULL;
		if (*s == ' ') razmak = 1;
		if (razmak == 0 && !((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z') || (*s >= '0' && *s <= '9')) && *s != ' ') return NULL;
		if (razmak == 1 && *s != ' ') return NULL;
		s++;
	}
	if (*s == '\0') return NULL;
	return s;
}

char* tag(char *s) {
	while (*s != '\0' && *s != '>') {
		s++;
	    if(*(s-1) == '<' && *s == '/') return kraj_tag(s);
		if (*(s-1) == '<' && !((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) return NULL;
		if (*s == '<') return NULL;
	}
	if (*s == '\0') return NULL;
	return s;
}

int uporedi (char *prvi, char *drugi) {
	char a = *prvi, b = *drugi;
	if (a >= 'A' && a <= 'Z') a += 32;
	if (b >= 'A' && b <= 'Z') b += 32;
	return a != b;
}

int provjeri(char *html) {
	char *pok = NULL;
	if(br_o_z(html, 0) == NULL) return 0;
	while (*html != '\0') {
		while (*html != '<' && *html != '\0') html++;
		if (*html == '\0') break;
		if (pok == NULL) {
			if (*html == '<' && *(html+1) == '/'){ html += 2; continue; }
			if (!tag(html)) return 0;
			pok = br_o_z(html,1);
			if (!tag(pok)) return 0;
			pok+=2; html++;
			while (*pok != '>') {
				if (uporedi(pok++, html++) || (*pok == '>' && *html != '>' && *html != ' ')) return 0;
				if (*pok == ' ' && (*html == ' ' || *html == '>')) break;
			}
			pok = NULL;
			while (*html++ != '>');
		}
		html++;
	}
	return 1;
}

int main() {
	return 0;
}
