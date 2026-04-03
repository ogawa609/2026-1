#include <stdio.h>
#include "matrix_utils.h"



int main(){
    int rows1,cols1,rows2,cols2;
    scanf("%d %d",&rows1,&cols1);

    int matriz1[rows1][cols1];
    matrix_read(rows1,cols1,matriz1);

    scanf("%d %d",&rows2,&cols2);
    int matriz2[rows2][cols2];
    matrix_read(rows2,cols2,matriz2);

    while(1){
        
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        int comando;
        scanf("%d",&comando);

        if(comando==1){
            
            if(possible_matrix_sum(rows1,cols1,rows2,cols2)==1){

                int result[rows1][cols1];
                matrix_add(rows1,cols1,matriz1,rows2,cols2,matriz2,result);
                matrix_print(rows1,cols1,result);
                
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n");
                
            }
        }
        else if(comando==2){

            if(possible_matrix_sub(rows1,cols1,rows2,cols2)==1){

                int result[rows1][cols1];
                matrix_sub(rows1,cols1,matriz1,rows2,cols2,matriz2,result);
                matrix_print(rows1,cols1,result);
            }
            else{

                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if(comando==3){

            if(possible_matrix_multiply(cols1,rows2)==1){

                int result[rows1][cols2];
                matrix_multiply(rows1,cols1,matriz1,rows2,cols2,matriz2,result);
                matrix_print(rows1,cols2,result);
            }
            else{

                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
        }
        else if(comando==4){

            int escalar,tipo;
            scanf("%d %d",&escalar,&tipo);

            if(tipo==1){

                scalar_multiply(rows1,cols1,matriz1,escalar);
                matrix_print(rows1,cols1,matriz1);
            }
            else if(tipo==2){

                scalar_multiply(rows2,cols2,matriz2,escalar);
                matrix_print(rows2,cols2,matriz2);
            }
        }
        else if(comando==5){

            int resul1[cols1][rows1];
            int resul2[cols2][rows2];

            transpose_matrix(rows1,cols1,matriz1,resul1);
            transpose_matrix(rows2,cols2,matriz2,resul2);
            matrix_print(cols1,rows1,resul1);
            printf("\n");
            matrix_print(cols2,rows2,resul2);

        }
        else{
            break;

        }
        
        
        
        

    }

    

    return 0;
}