#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definição dos arquivos
FILE *arquivoA;
FILE *arquivoB;

// FUNÇÕES
// exibe os elementos do conjunto selecionado
void Exibir(int conjunto[200], int Tam) {
  for (int i = 0; i < Tam; i++) {
    printf("%d ", conjunto[i]);
  }
}
// verifica a repetição de um elemento dentro dos conjuntos
int pesquisa(int valor, int conjunto[200], int tam) {
  for (int i = 0; i < tam; i++) {
    if (conjunto[i] == valor)
      return free;
  }
  return NULL;
}
// realiza a união entres os conjuntos
int Uniao(int vetA[100], int nA, int vetB[100], int nB, int vetU[200]) {
  int tamU;
  int i;
  for (i = 0; i < nA; i++) {
    vetU[i] = vetA[i];
  }
  tamU = nA;
  for (int i = 0; i < nB; i++) {
    if (!pesquisa(vetB[i], vetU, tamU)) {
      vetU[tamU] = vetB[i];
      tamU++;
    }
  }
  return tamU;
}
// realiza a interseção entre os conjuntos
int Intersecao(int vetA[100], int nA, int vetB[100], int nB, int vetI[100]) {
  int i;
  int tamI = 0;
  for (i = 0; i < nA; i++) {
    if (pesquisa(vetA[i], vetB, nB)) {
      vetI[tamI] = vetA[i];
      tamI++;
    }
  }
  return tamI;
}
// realiza a difernça simétrica entre os conjuntos
int DiferencaSim(int vetU[100], int nU, int vetI[100], int nI, int vetDS[200]) {
  int i;
  int tamDS = 0;
  for (i = 0; i < nU; i++) {
    if (!pesquisa(vetU[i], vetI, nI)) {
      vetDS[tamDS] = vetU[i];
      tamDS++;
    }
  }
  return tamDS;
}
// realiza a operação de diferença entre os conjutnso
int Diferenca(int vetA[100], int nA, int vetB[100], int nB, int vetD[200]) {
  int i;
  int tamD = 0;
  for (i = 0; i < nB; i++) {
    if (!pesquisa(vetB[i], vetA, nA)) {
      vetD[tamD] = vetB[i];
      tamD++;
    }
  }
  return tamD;
}
// exibe os pares ordenados dos conjuntos
void ParesOr(int vetA[100], int nA, int vetB[100], int nB) {
  int i, j;
  for (i = 0; i < nA; i++) {
    for (j = 0; j < nB; j++) {
      printf("(%d,%d) ", vetA[i], vetB[j]);
    }
  }
}

// Código principal
int main() {
  system("clear");
  int conjA[100], conjB[100];
  int i, j, k, x; // variáveis auxiliares
  int indA = 0, indB = 0, EleA, EleB;
  int uniao[200], indU;
  int intersecao[100], indI;
  int dif_simetrica[200], indDS;
  int dif[100], indD;

  arquivoA = fopen("A.dat", "w+a");
  arquivoB = fopen("B.dat", "w+a");

  printf("Você pode guardar até 100 números naturais em cada conjunto!\n");
  printf("Quantos elementos terão no conjunto A? ");
  scanf("%d", &EleA);

  // definindo números aleatórios para os conjuntos
  // para o arquivo A
  srand(time(NULL)); // gera novos valores a cada vez que o programa é rodado
  
  for (i = 0; i < EleA; i++) {
    k = rand() % 400; // sorteando valores entre 0 e 400
    fprintf(arquivoA, "%d ", k);
  }

  printf("Quantos elementos terão no conjunto B? ");
  scanf("%d", &EleB);
   srand(time(NULL)); // gera novos valores a cada vez que o programa é rodado
  // para o arquivo B
  for (x = 0; x < EleB; x++) {
    j = rand() % 400; // sorteando valores entre 0 e 400
    fprintf(arquivoB, "%d ", j);
  }
  system("clear");

  // exibindo os elementos de cada conjunto
  rewind(arquivoA);
  printf("Elementos do conjunto A\n");
  printf("A = {");
  while (!feof(arquivoA)) {
    fscanf(arquivoA, "%d ", &conjA[indA]);
    printf("%d ", conjA[indA]);
    indA++;
  }
  printf("}\n\n");

  rewind(arquivoB);
  printf("Elementos do conjunto B\n");
  printf("B = {");
  while (!feof(arquivoB)) {
    fscanf(arquivoB, "%d ", &conjB[indB]);
    printf("%d ", conjB[indB]);
    indB++;
  }
  printf("}\n\n");

  fclose(arquivoA);
  fclose(arquivoB);

  // OPERAÇÕES
  // União
  indU = Uniao(conjA, EleA, conjB, EleB, uniao);
  printf("União entre os conjuntos:\n\n");
  printf("U = { ");
  Exibir(uniao, indU);
  printf("}\n\n");

  // Interseção
  indI = Intersecao(conjA, EleA, conjB, EleB, intersecao);
  printf("Interseção entre os conjuntos:\n\n");
  printf("I = { ");
  Exibir(intersecao, indI);
  printf("}\n\n");

  // Diferença Simétrica
  indDS = DiferencaSim(uniao, indU, intersecao, indI, dif_simetrica);
  printf("Diferença Simétrica entre os conjuntos:\n\n");
  printf("Ds = { ");
  Exibir(dif_simetrica, indDS);
  printf("}\n\n");

  // Diferença entre B e A
  indD = Diferenca(conjA, EleA, conjB, EleB, dif);
  printf("Diferença entre B e A:\n\n");
  printf("(B - A) = { ");
  Exibir(dif, indD);
  printf("}\n\n");

  // Pares Ordenados do produto entre A e B
  printf("Pares ordenados do produto entre A e B:\n\n");
  printf("(A * B) = { ");
  ParesOr(conjA, EleA, conjB, EleB);
  printf("}\n\n");

  return 0;
}
