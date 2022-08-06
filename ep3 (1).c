/***************************************************************/
/**                                                           **/
/**   Celso Tadaki Sinoka                           13682851  **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Guilherme Mota                               **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define TRUE 1
#define FALSE 0

//Misc

void printa(int N, int M[][NMAX]);
void printadouble(int N, double F[][NMAX]);

void zeramatriz (int N, int M[][NMAX]);
void printmatriz (int N, int M[][NMAX]);
void zeracerto (int N, int M[][NMAX], int p, int i);

void atualizasolucao (int N, int L[], int C[], int R[][NMAX], int lasti, int lastj);
void matrizfrequencia (int N, double F[][NMAX], double solucao, int R[][NMAX]);

void zeravetor (int N, int V[NMAX]);
void printasolucao (int N, int L[NMAX], int C[NMAX]);

//Canceladores de posicao

void postorre (int N, int M[][NMAX], int i, int j, int p);
void posbispo (int N, int M[][NMAX], int i, int j, int p);
void posrei (int N, int M[][NMAX], int i, int j, int p);
void poscavalo (int N, int M[][NMAX], int i, int j, int p);

//generate
void generate(int N, int b, int c, int r, int f, int v);

int main(int argc, char *argv[]) {


  
int N = atoi(argv[1]);
int b = atoi(argv[2]);
int c = atoi(argv[3]);
int r = atoi(argv[4]);
int f = atoi(argv[5]);
int v = atoi(argv[6]);
  
generate(N, b, c, r, f, v);

  
return 0;
  
}
void zeramatriz (int N, int M[][NMAX]){
  int i, j;
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++)
      M[i][j] = 0;
  }
}

void printa(int N, int M[][NMAX]){ 
  int i, j;
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      printf("%d ", M[i][j]);
    }
    printf(" \n");
  }
}

void printadouble (int N, double F[][NMAX]){ 
  int i, j;
  for(i = 0; i < N; i ++){
    for(j = 0; j < N; j ++){
      printf("%g ", F[i][j]);
    }  
    printf(" \n");
  }
}
void zeravetor (int N, int V[NMAX]){
  int i;
  for(i = 0; i < N; i++){
    V[i] = 0;
  } 
}

// zera o ultimo cancelamento
void zeracerto (int N, int M[][NMAX], int p, int i){
  int k, l;
  if((i - 1) >= 0){
    for((k = (i - 1) && (i - 1) >= 0); k < N; k++){
      for(l = 0; l < N; l++){
        if(M[k][l] == p)
          M[k][l] = 0;
      }
    }
  }
}
//funcao que soma 1 para cada posicao da rainha na solucao dada
void atualizasolucao (int N, int L[NMAX], int C[NMAX], int R[][NMAX], int lasti, int lastj){
  int k, l;
  k = 0, l = 0;
  
  while (k < N){
    R[L[k]][C[l]]++;
    k++;
    l++;
  }
}
void postorre (int N, int M[][NMAX], int i, int j, int p){
    int k, l;
    k = i;
    l = j;

    for(k = i; k < N; k++){
        if (M[k][l] == 0)
            M[k][l] = p;
    }
}

void posbispo (int N, int M[][NMAX], int i, int j, int p){
  int k, l;
  k = i;
  l = j;
  
  while((k < N) && (l >= 0)){
    if(M[k][l] == 0){
      M[k][l] = p;
    }
    k++;
    l--;
  }
  
  k = i;
  l = j;
  
  while((k < N) && (l < N)){
    if(M[k][l] == 0){
      M[k][l] = p;
    }
    k++;
    l++;
  }
}

void poscavalo (int N, int M[][NMAX], int i, int j, int p){
  int k, l;
  k = i;
  l = j;
    
  if ((k + 2) < N){
    if ((l - 1) >= 0){
      if(M[k+2][l-1] == 0)
        M[k+2][l-1] = p;
        k = i, l = j;
    }
    if ((l + 1) < N){
      if(M[k+2][l+1] == 0)
        M[k+2][l+1] = p;
        k = i, l = j;
    }
  }
  if ((k + 1) < N){
    if ((l - 2) >= 0){
      if(M[k+1][l-2] == 0)
        M[k+1][l-2] = p;
        k = i, l = j;
    }
    if ((l + 2) < N){
      if(M[k+1][l+2] == 0)
        M[k+1][l+2] = p;
        k = i, l = j;
    }
  }
}

void posrei (int N, int M[][NMAX], int i, int j, int p){
  int k, l;
  k = i, l = j;
  
  if ((k + 1) < N){
    if ((l - 1) >= 0){
      if (M[k+1][l-1] == 0)
        M[k+1][l-1] = p;
      k = i, l = j;
    }
    
    if ((l + 1) < N){
      if (M[k+1][l+1] == 0)
        M[k+1][l+1] = p;
      k = i, l = j;
    }
  }
}

void matrizfrequencia (int N, double F[][NMAX], double solucao, int R[][NMAX]){
    int k, l;
    for(k = 0; k < N; k++){
        for(l = 0; l < N; l++){
            F[k][l] = ((R[k][l])/solucao);
            printf ("%5.4f ", F[k][l]);
        }
      printf("\n");
    }
}

void printasolucao (int N, int L[NMAX], int C[NMAX]){
  int i, j, k, l;
  char S[NMAX][NMAX];
  
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      S[i][j] = '-';

      
    }   
  }
  k = 0;
  l = 0;
  
  while ((k < N)){
    S[L[k]][C[l]] = 'X';
    k++;
    l++;
    
  }
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      printf(" %c", S[i][j]);
      
    }
    printf("\n");
  }      
}

void generate (int N, int b, int c, int r, int f, int v){

  //utilizarei loops encadeados, um loop majoritario que apenas acaba quando encontra todas as solucoes
  //outros loops percorrem a matriz, posicionando as rainhas e retirando anteriores caso n seja possível posicionar na linha
  //se chegou até o fim da matriz, é solução, contabilizo e imprimo. Caso não haja mais, saio do loop e verifico quantas solucoes temos
  //dependendo da quantidade de solucoes eu vejo o resultado.

  int M[NMAX][NMAX];
  int i, j, p;
  int R[NMAX][NMAX];
  double solucao;
  solucao = 0.0;
  zeramatriz(N, R);

  p = 3;
  i = 0;
  j = 0;
  
  int posicionei;
  posicionei = FALSE;
  int L[NMAX], C[NMAX];
  int lasti, lastj;
  lasti = 0;
  lastj = 0;
  int ehsol;
  ehsol = TRUE;
  int procurasol;
  procurasol = TRUE;
  double F[NMAX][NMAX];
  int ehsolu = TRUE;

  zeravetor (N, L);
  zeravetor (N, C);
  

  while(procurasol == TRUE){
    
    while((i < N) && (ehsolu == TRUE)){
      posicionei = FALSE;
      j = 0;

      while((posicionei == FALSE) && ehsolu == TRUE){
        if(M[i][j] == 0){
          M[i][j] = 1;
          postorre(N, M, i, j, p);
      
          if(b == 1)
          posbispo(N, M, i, j, p);
          if(c == 1)
          poscavalo(N, M, i, j, p);
            if(r == 1)
              if(b == 0)
                posrei(N, M, i, j, p);
        
          posicionei = TRUE;

          L[lasti] = i;
          C[lastj] = j;
          lasti++, lastj++;
        
        }
        
        else if (M[i][j] != 0){
          posicionei = FALSE;
        
          if(j < N - 1)
            j++;
          else
            if(j == N - 1){
              ehsolu = FALSE;
              p--;
              zeracerto(N, M, p, i);
              L[lasti] = 0, C[lastj] = 0;
              lasti--;
              lastj--;       
              M[L[lasti]] [C[lastj]] = p-1;
              j = C[lastj];
              i--;    
            }
          }
        }
        if(ehsolu == TRUE){
          i++;
          p++;      
        }
      
        else if (ehsolu == FALSE){
      
          if(lasti >= 0){
             if(posicionei == FALSE)
                ehsolu = TRUE;
          }
        }  
      } 

      if((posicionei == TRUE) && ehsolu == TRUE){
    
        solucao++;
 
        atualizasolucao(N, L, C, R, lasti, lastj);
 
         if(v == 1){
          printasolucao(N, L, C);
          printf("\n\n");
          
        }

        p--;
            
        zeracerto(N, M, p, i);
                 
        L[lasti] = 0, C[lastj] = 0;
            
        lasti--;
        lastj--;
            
        M[L[lasti]] [C[lastj]] = p-1;
        
        j = C[lastj];
        i--;
        
      }
    
      else{
        if(solucao == 0){

        procurasol = FALSE;
             
        }
        if(solucao > 0){
    
          printf("Total de solucoes: %d\n\n\n", (int) solucao);
               
          if(f == 1){
            
          printf("Mapa de frequencias: \n");
          matrizfrequencia(N, F, solucao, R);
          }
          
          break; 
          }      
      }
      if(solucao == 0){
        printf("Nao ha solucao!. \n\n");
        procurasol = FALSE;    
      
      }  
    }
}
