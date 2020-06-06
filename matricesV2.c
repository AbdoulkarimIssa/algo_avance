#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Structure de la matrice*/

typedef struct {
	int line;
	int col;
	double** MATRIX;	
}matrix;

//Creation de la matrice
matrix* create_matrix (int ligne, int col) {
    
    matrix* matrice;
    matrice=malloc(sizeof(matrix));
    matrice->line=ligne;
    matrice->col=col;
    matrice->MATRIX=(double**)malloc(ligne*sizeof(double*));

    for (int i=0; i<ligne; i++){
        matrice->MATRIX[i]=malloc(col*sizeof(double));
    }
    return matrice;
}

matrix* fill_matrix (matrix* matrice) {
    
     for (int i=0; i<matrice->line; i++)
    {
       for (int j=0; j<matrice->col; j++)
       { 
           printf("Element[%d][%d] = ",i,j);
           scanf("%lf",&matrice->MATRIX[i][j]);
       }
    }
    return matrice;
}

//Addition de 2 matrices
matrix* add_matrix (matrix* matrice1, matrix* matrice2) {
    
	if (matrice1->line==matrice2->line && matrice1->col==matrice2->col){
        matrix* matrice;
		matrice=create_matrix(matrice1->line,matrice1->col);
		for (int i=0;i<matrice1->line;i++){
			for(int j=0;j<matrice1->col;j++){
				matrice->MATRIX[i][j]=matrice1->MATRIX[i][j]+matrice2->MATRIX[i][j];
			}
		}
    return matrice;
	}
    else
    { 
        printf("\nERREUR: Addition impossible, les deux matrices ne sont pas de meme format:\n");
        printf("\nFormat M1: [%d][%d]\nFormat M2: [%d][%d]",matrice1->line,matrice1->col,matrice2->line,matrice2->col);
        return NULL;
    }
    
}

//Multiplication de 2 matrices
matrix* multi_matrix (matrix* matrice1, matrix* matrice2) {
    
	if (matrice1->col==matrice2->line){
        matrix* matrice;
		matrice=create_matrix(matrice1->line,matrice2->col);

		for (int i=0;i<matrice1->line;i++){
			for(int j=0;j<matrice2->col;j++){
                double temp=0;
                for (int k=0;k<matrice2->line;k++){
                    temp+=matrice1->MATRIX[i][k]*matrice2->MATRIX[k][j];
                }
                matrice->MATRIX[i][j]=temp;
			}
		}
    return matrice;
	}
    else
    {   
        printf("\nERREUR: Muliplication impossible, le nombre de colonnes de M1 est diffrent du nombre de lignes de M2\n");
        printf("\nFormat M1: [%d][%d]\nFormat M2: [%d][%d]",matrice1->line,matrice1->col,matrice2->line,matrice2->col);
        return NULL;
    }
    
}

//Trace d'une matrice carrée
double trace(matrix *matrice){

    if (matrice->line==matrice->col)
    {   
        double acc = 0;
        for (int i = 0; i < matrice->line; i++)
        {
            for (int j = 0; j < matrice->col; j++)
            {
                if (i==j)
                {
                    acc+=matrice->MATRIX[i][j];
                }
                
            }
            
        }

        return acc; 
    }

    else
    {
        printf("\nERREUR: La matrice fournie n'est pas une matrice carree\n\nFormat de M: [%d][%d]", matrice->line, matrice->col);
    }   
}

// Determinat d'une matrice de dimensions 2x2
double det(matrix* matrice) {
    double val;
    if ( matrice->line==2 && matrice->col==2 ){

        val=(matrice->MATRIX[0][0]*matrice->MATRIX[1][1])-(matrice->MATRIX[0][1]*matrice->MATRIX[1][0]);

        return val;
	} 
    else
    {
        printf("\nERREUR: la dimension de la matrice depasse 2 \nFormat M: [%d][%d]", matrice->line,matrice->col);
        return 0;
    }
    
}

/* Mineur d'une matrice. Cette fonction me permet d'obtenir le mineur d'une matrice en eliminant la k-ieme ligne et colonne*/
matrix* mineurs(matrix* matrice, int k) {
    
    if (matrice->line == matrice->col && k < matrice->col){
        
        matrix* mineur;
		mineur=create_matrix((matrice->line)-1,(matrice->col)-1);

		for (int i=0;i<matrice->line;i++){

            int x=0;
			for(int j=0;j<matrice->col;j++){

                if (i!=0 && j!=k )
                {
                    mineur->MATRIX[i-1][x] = matrice->MATRIX[i][j];
                    
                    if ( x < (matrice->line)-1) {x++;}
                }
            }   
        }
        return mineur;
    }

    else
    {
        printf("ERREUR: verifier si la matrice fournie est carree \n");
        return NULL;
    }  
}

//Determinant d'une matrice carrée de dimensions NxN
double determinant(matrix *matrice){

    if (matrice->line==matrice->col) {

        double acc;
       
        if (matrice->line>2) {

            matrix *mineur;

            for (int j = 0; j < matrice->col; j++) {

                mineur = mineurs(matrice,j);

                if (mineur->line > 2)
                {
                    acc += (pow(-1,j)*matrice->MATRIX[0][j])*determinant(mineur);
                }
                
                if (mineur->line == 2) {

                    acc += pow(-1,j)*matrice->MATRIX[0][j]*det(mineur);
                }

            }

            return acc;
       }

        if (matrice->line < 2) { return matrice->MATRIX[0][0]; }

        else{ return det(matrice);}

    }
    
    else
    {
        printf("\nERREUR: La matrice fournie n'est pas une matrice carree\n\nFormat de M: [%d][%d]", matrice->line, matrice->col);
    }  
}

//fonction d'affichage de la matrice de dimensions N*M
void show_matrix (matrix* matrice) {

    for (int i=0; i<matrice->line; i++){
       for (int j=0; j<matrice->col; j++)
       {
           printf("%7.0lf",matrice->MATRIX[i][j]);
        }
        printf("\n");
    }
}

//fonction de suppression d'une matrice
void del_matrix (matrix* matrice) {
    
    for (int i=0; i<matrice->line; i++){
        free(matrice->MATRIX[i]);
    }
    free(matrice->MATRIX);
}

int main() {

    int ligne1,col1,ligne2,col2,choix;
    matrix *matrix1,*matrix2,*addition,*multi;
  
    printf("\n================|Calcul Matriciel|================\n");
    printf("\n======================|Menu|======================\n------------------------------------------------\n");  
    printf("Faites votre choix !\n\n");
    printf("1. Afficher le format d'une matrice de dimensions NxM \n");
    printf("2. Addition de 2 matrices\n");
    printf("3. Multiplication de 2 matrices\n");
    printf("4. Trace d'une matrice\n");
    printf("5. Determinant d'une matrice\n");
    printf("\n------------------------------------------------\nChoix ? : ");
    scanf ("%d",&choix);
    printf("\n");
    
    switch (choix) {

        case 1:

            printf("\n-------------Affichage d'une matrice de format NxM----------------\n");
            printf("\nDefinir le format la matrice :\n\nNombre de lignes de la matrice :");
                scanf ("%d",&ligne1);
                printf("Nombre de colonnes de M1 : ");
                scanf ("%d",&col1);
                matrix1=create_matrix(ligne1,col1);
                printf("\nVeuillez remplir la matrice :\n\n");
                fill_matrix(matrix1);
                printf("\n\n");
                show_matrix(matrix1);
                del_matrix(matrix1);

            break;
        
        case 2:

            printf("------------Addition de 2 Matrice----------------\n");
                
                printf("\nVeuillez saisir le format de la matrice M1 :\n\nNombre de lignes de M1 :");
                scanf ("%d",&ligne1);
                printf("Nombre de colonnes de M1 : ");
                scanf ("%d",&col1);

                printf("\nVeuillez saisir le format de la matrice M2 :\n\nNombre de lignes de M2 : ");
                scanf ("%d",&ligne2);
                printf("Nombre de colonnes de M2 : ");
                scanf ("%d",&col2);

                matrix1=create_matrix(ligne1,col1);
                matrix2=create_matrix(ligne2,col2);

                printf("\nVeuillez remplir la matrice M1\n\n");
                fill_matrix(matrix1);
                printf("\n\n");
                show_matrix(matrix1);

                printf("\nVeuillez remplir la matrice M2\n\n");
                fill_matrix(matrix2);
                printf("\n\n");
                show_matrix(matrix2);

                addition = add_matrix(matrix1, matrix2);

                if(addition != NULL){
                    printf("\nLa somme des 2 matrices est: \n\nMatrix: \n");
                    show_matrix(addition);
                    del_matrix(addition);
                }

                del_matrix(matrix1);
                del_matrix(matrix2);
                printf("\n");
            break;

        case 3:

            printf("------------Multiplication de 2 Matrice----------------\n");

                printf("\nVeuillez saisir le format la matrice M1 :\n\nNombre de lignes de M1 :");
                scanf ("%d",&ligne1);
                printf("Nombre de colonnes de M1 : ");
                scanf ("%d",&col1);

                printf("\nVeuillez saisir le format de la matrice M2 :\n\nNombre de lignes de M2 : ");
                scanf ("%d",&ligne2);
                printf("Nombre de colonnes de M2 : ");
                scanf ("%d",&col2);

                matrix1=create_matrix(ligne1,col1);
                matrix2=create_matrix(ligne2,col2);

                printf("\nVeuillez remplir la matrice M1\n\n");
                fill_matrix(matrix1);
                printf("\n\n");
                show_matrix(matrix1);

                printf("\nVeuillez remplir la matrice M2\n\n");
                fill_matrix(matrix2);
                printf("\n\n");
                show_matrix(matrix2);

                multi=multi_matrix(matrix1, matrix2);
            
                if(multi != NULL){
                    printf("\nLa multilication des 2 mmatrices est:\n\nMatrix: \n");
                    show_matrix(multi);
                    del_matrix(multi);
                }

                del_matrix(matrix1);
                del_matrix(matrix2);
                printf("\n");
            break;

        case 4:

            printf("\n-------------Trace d'une matrice de format NxN----------------\n");
            printf("\nDefinir le format la matrice M:\n\nNombre de lignes de la matrice M : ");
                scanf ("%d",&ligne1);
                printf("Nombre de colonnes de la matrice M : ");
                scanf ("%d",&col1);
                matrix1=create_matrix(ligne1,col1);
                printf("\nVeuillez remplir la matrice M:\n\n");
                fill_matrix(matrix1);
                printf("\n\n");
                show_matrix(matrix1);

                printf("\nTrace de M = %.2lf\n", trace(matrix1));

                del_matrix(matrix1);
            break;
        
        case 5:

            printf("\n-------------Determinant d'une matrice de format NxN----------------\n");
            printf("\nDefinir le format la matrice M:\n\nNombre de lignes de la matrice M : ");
                scanf ("%d",&ligne1);
                printf("Nombre de colonnes de la matrice M : ");
                scanf ("%d",&col1);
                matrix1=create_matrix(ligne1,col1);
                printf("\nVeuillez remplir la matrice M:\n\n");
                fill_matrix(matrix1);
                printf("\n\n");
                show_matrix(matrix1);

                printf("\nLe detrminant de la matrice M est: \n\ndet M = %.2lf \n", determinant(matrix1));

                del_matrix(matrix1);
            break;

        default:
            printf("Dommage !! Vous n'avez fait aucun choix");
            break;
    }

    printf("\n");
    return 0;
}