/* My-zip ohjelma 
Tekijä: Marianne Seppänen
Pvm: 29.6.2021
Ohjelma lukee tiedostosta merkkijonon ja pakkaa sen RLE-koodauksella ja muuntaa binaariluvuiksi, joka tulostuu ruudulle.
Koodaamisessa on käytetty apuna C-ohjelmoinnin perusteiden ohjelmointiopasta, "C-kieli ja käytännön ohjelmointi, osa 1"
RLE-koodauksessa on käytetty apuna tutoriaalia osoitteesta https://www.geeksforgeeks.org/run-length-encoding/
Binaariluvuiksi kääntämisessä on käytetty apuna Stackoverflowta, https://stackoverflow.com/questions/5488377/converting-an-integer-to-binary-in-c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aliohjelma luvun kääntämiseksi binaariluvuksi. Lähde: https://stackoverflow.com/questions/5488377/converting-an-integer-to-binary-in-c */
unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
} 

/* Aliohjelma tiedoston sisällön RLE-koodausta varten. Lähde: https://www.geeksforgeeks.org/run-length-encoding/ */
void encode(char* src)
{
    int rLen;
    char count[100];
    int nro;
    int len = strlen(src);
    int i, j = 0, k;
    int binluku;
 
    /* Käydään tiedoston sisältöä läpi merkki kerrallaan */
    for (i = 0; i < (len-1); i++) {
        /* Lasketaan, kuinka monta samaa merkkiä on peräkkäin */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++; }
 	nro = rLen;
        sprintf(count, "%d", rLen);
 
        /* Muutetaan merkin lukumäärä (nro) binaariluvuksi */
        for (k = 0; *(count + k); k++, j++) {
	    binluku = int_to_int(nro);
	    fprintf(stdout, "%d", binluku);
	}
	/* Lisätään itse merkki pakattuun merkkijonoon */
	fprintf(stdout, "%c", src[i]);
    }
}


int main(int argc, char *argv[]) {

/* Testataan, onko ohjelmalle annettu tiedostoja parametreiksi */
if (argc == 1) {
	fprintf(stdout, "my-zip: file1 [file2 ...]\n");
	return(0); }

int i;
for (i = 1; i < argc; i++) { /* Suoritetaan tiedostonluku niin monta kertaa, kuin käyttäjä antaa parametrejä */
	char muisti[100]; 
	FILE *tiedosto;
	if ((tiedosto = fopen(argv[i], "r")) != NULL) { 
		
		while (fgets(muisti, 99, tiedosto) != NULL) {
			encode(muisti);
			} 

	} else { /* Virheenkäsittely, jos tiedosto ei aukea */
		fprintf(stderr, "my-zip: cannot open file\n");
		exit(1); }
	fclose(tiedosto);

}

printf("\n");
return(0);
}
