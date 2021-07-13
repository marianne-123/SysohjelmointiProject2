/* My-grep ohjelma 
Tekijä: Marianne Seppänen
Pvm: 16.6.2021
Ohjelma etsii käyttäjän antamista tiedostoista tiettyä termiä, ja printtaa ruudulle ne rivit, joista termi löytyy. 
Koodaamisessa on käytetty apuna C-ohjelmoinnin perusteiden ohjelmointiopasta, "C-kieli ja käytännön ohjelmointi, osa 1"
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

/* 1 parametri: ohjelma tulostaa ohjeen ja lopettaa */
if (argc == 1) {
	fprintf(stderr, "my-grep: searchterm [file ...]\n");
	exit(1); }

/* 2 parametriä: termiä etsitään käyttäjän syttömästä tekstistä. */
else if (argc == 2) {
   	char text[100];
	fprintf(stdout, "Type something: ");
	fgets(text, 99, stdin);
	if (strstr(text, argv[1])) {
		fprintf(stdout, "%s\n", text); }
}

/* >3 parametriä: termiä etsitään käyttäjän syöttämistä tiedostoista */
else {

	int i;
	for (i = 2; i < argc; i++) { /* Suoritetaan tiedostonluku niin monta kertaa, kuin käyttäjä antaa parametrejä */
		char muisti[100]; 
		FILE *tiedosto;
		tiedosto = fopen(argv[i], "r");
		if (tiedosto != NULL) { 
			while (fgets(muisti, 99, tiedosto) != NULL) { 
				if (strstr(muisti, argv[1])) {
				fprintf(stdout, "%s", muisti); }
			}

		} else { /* Virheenkäsittely, jos tiedosto ei aukea */
			fprintf(stderr, "my-grep: cannot open file\n");
			exit(1); }

		fclose(tiedosto);

	}
}

return(0);
}
