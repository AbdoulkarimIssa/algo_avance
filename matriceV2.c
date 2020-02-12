#include <stdio.h>
#include <stdlib.h>

/*structure de la matrice*/

typedef struct {
	int ligne;
	int colone;
	double** ma_matrice;	
}Matrice;

/* creation de la matrice */

Matrice* creation_de_matrice(int ligne, int colone){
	Matrice* mat;
	mat=malloc(sizeof(Matrice));
	mat->ligne=ligne;
	mat->colone=colone;
	mat->ma_matrice=(double**)malloc(ligne*sizeof(double*));
	for(int i=0;i<ligne;i++){
		mat->ma_matrice[i]=malloc(colone*sizeof(double));
	}
	return mat;
}



/* liberation de la memoire*/

void liberation_de_la_memoire(Matrice* mat){
	for (int i=0;i<(mat->ligne);i++){
		free(mat->ma_matrice[i]);
	}
	free(mat->ma_matrice);
}

/* affichage_de_matrice*/

void affichage_de_matrice(Matrice* mat){
	for(int i=0;i<mat->ligne;i++){
		printf("|");
		for(int j=0;j<mat->colone;j++){
			printf("%f ",mat->ma_matrice[i][j]);
		}
		printf("|");
		printf("\n");
	}
}

/* remplissage des matrice*/

void remplissage_de_la_matrice(Matrice* mat){
	for(int i=0; i<mat->ligne; i++){
		for(int j=0;j<mat->colone;j++){
			printf("entrer une valeur : ");
			scanf("%lf",&(mat->ma_matrice[i][j]));
		}
	}
}
/*calcul du somme des matrices*/

/*double** calcul_de_la_somme(){
	double** matrice_resultante;
	if (ligne1==ligne2 && colones1==colones2){
		matrice_resultante=creation_de_matrice(ligne1,colones1);
		for (int i=0;i<ligne1;i++){
			for(int j=0;j<colones1;j++){
				matrice_resultante[i][j]=matrice1[i][j]+matrice2[i][j];
			}
		}
	}
	return matrice_resultante;
}
*/
	
int main(){
	Matrice* m1;
	m1=creation_de_matrice(1,2);
	remplissage_de_la_matrice(m1);
	affichage_de_matrice(m1);
	liberation_de_la_memoire(m1);
	return 0;
	
}
	
		 		 
	
