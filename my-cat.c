/* My-cat ohjelma 
Tekijä: Marianne Seppänen
Pvm: 16.6.2021
Ohjelma lukee käyttäjän antamat tiedostot ja printtaa ne ruudulle, eli toimii samoin kuin CAT-käsky. 
Koodaamisessa on käytetty apuna C-ohjelmoinnin perusteiden ohjelmointiopasta, "C-kieli ja käytännön ohjelmointi, osa 1"
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

/* Testataan, onko ohjelmalle annettu tiedostoja parametreiksi */
if (argc == 1) {
	return(0); }

int i;
for (i = 1; i < argc; i++) { /* Suoritetaan tiedostonluku niin monta kertaa, kuin käyttäjä antaa parametrejä */
	char muisti[100]; 
	FILE *tiedosto;
	if ((tiedosto = fopen(argv[i], "r")) != NULL) { 
		while (fgets(muisti, 99, tiedosto) != NULL) {
			fprintf(stdout, "%s", muisti);
		} 
	} else { /* Virheenkäsittely, jos tiedosto ei aukea */
		fprintf(stderr, "my-cat: cannot open file\n");
		exit(1); }
	fclose(tiedosto);

}

return(0);
}

