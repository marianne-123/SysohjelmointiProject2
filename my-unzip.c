/* My-unzip ohjelma 
Tekijä: Marianne Seppänen
Pvm: 16.6.2021
Ohjelma lukee tiedostosta RLE-koodin binaareina ja muuntaa sen merkkijonoksi, joka tulostuu ruudulle.
Koodaamisessa on käytetty apuna C-ohjelmoinnin perusteiden ohjelmointiopasta, "C-kieli ja käytännön ohjelmointi, osa 1"
Binaarilukujen muunnoksissa käytetty tutoriaalia osoitteessa: https://www.geeksforgeeks.org/program-binary-decimal-conversion/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/* Aliohjelma tiedoston sisällön RLE-dekoodausta varten. */
void decode(char* src)
{

    int len = strlen(src);
    int i, j = 0;
    int dec=0;
    char binaari[20];
 
    /* Käydään tiedoston sisältöä läpi merkki kerrallaan */
    for (i = 0; i < (len-1); i++) {
	char a = src[i];
	/* Testataan, onko seuraava merkki kirjain ja printataan se luvun osoittama määrä */
	if (isalpha(a)) {
		for (int n=0; n<dec; n++ ) {
		fprintf(stdout, "%c", src[i]); }
		}
	/* Testataan, onko seuraava merkki osa binaarilukua (0 tai 1) ja lisätään binaari-merkkijonoon */
	else {
		while (a == '1' || a == '0') {
			binaari[j++] = src[i];
			i++;
			a = src[i] ;}
		/* Muutetaan binaari normiluvuksi. Apuna käytetty tutoriaalia osoitteessa: https://www.geeksforgeeks.org/program-binary-decimal-conversion/ */
		binaari[j] = '\0';
		int bin;
		dec = 0;
    		bin = atoi(binaari);
 
    		for (int m = 0; bin; m++, bin /= 10) {
       			if (bin % 10) {
           			dec += pow(2, m); } }
		j=0;
		i--; }
    }
}

int main(int argc, char *argv[]) {

/* Testataan, onko ohjelmalle annettu tiedostoja parametreiksi */
if (argc == 1) {
	fprintf(stdout, "my-unzip: file1 [file2 ...]\n");
	return(0); }

int i;
for (i = 1; i < argc; i++) { /* Suoritetaan tiedostonluku niin monta kertaa, kuin käyttäjä antaa parametrejä */
	char muisti[100]; 
	FILE *tiedosto;
	if ((tiedosto = fopen(argv[i], "r")) != NULL) { 
		
		while (fgets(muisti, 99, tiedosto) != NULL) {
			decode(muisti); } 

	} else { /* Virheenkäsittely, jos tiedosto ei aukea */
		fprintf(stderr, "my-unzip: cannot open file\n");
		exit(1); }
	fclose(tiedosto);

}
printf("\n");
return(0);
}
