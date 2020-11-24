
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  time_t t;
  char inStr [128];

  srand((unsigned)time(&t)); // Inizializzo il generatore di numeri casuali usando il time current come seed

  printf("Inserisci la stringa da cifrare\n");
  fgets(inStr, 128, stdin); // Input della stringa
  inStr [strlen(inStr) - 1] = '\0';

  char c, key [strlen(inStr)], outStr [strlen(inStr)], verifica [strlen(inStr)];
  int b;

  while ((c = getchar()) != '\n' && c != EOF);

  do {
    printf("Hai già la chiave di cifratura da utilizzare?\nSe sì digita 1, altrimenti digita 0\n");
    scanf(" %d", &b); // Ho trovato online che basta mettere uno spazio prima di %c per non avere problemi con lo \n dell'input stream precedente
    while ((c = getchar()) != '\n' && c != EOF);

    if (b == 1) { // Controllo se l'utente ha o non ha la chiave
      while (strlen(key) < strlen(inStr)) { // Richiedo la chiave ogni volta che l'utente la inserisce più corta della stringa da cifrare
        printf("Inserisci la chiave per cifrare di lunghezza uguale o maggiore rispetto alla stringa\n");
        fgets(key, 128, stdin);
      }
      key [strlen(key) - 1] = '\0';
      for (int i = 0; i < strlen(inStr); i++)
      outStr [i] = key [i] ^ inStr [i];
    }
    else if (b == 0) {
      for (int i = 0; i < strlen(inStr); i++) { // For per confrontare con lo XOR carattere per carattere subito dopo averlo generato per calcolarae la nuova stringa
        key [i] = 32 + (rand() % 96);
        outStr [i] = key [i] ^ inStr [i];
      }
    }
  } while (b != 0 && b != 1);

  printf("Input: %s\n", inStr);
  printf("Output: %s'\n'", outStr);
  printf("Chiave: %s\n", key);

  for (int i = 0; i < strlen(inStr); i++)
    verifica [i] = key [i] ^ outStr [i];
  
  printf("Verifica: %s\n", verifica);
  return 0;
}