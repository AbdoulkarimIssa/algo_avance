#include <stdio.h>
#include <stdlib.h>

/* creation de la matrice */

double** creation_de_matrice(int ligne, int colone){

	double** matrice;
	matrice=malloc(ligne*sizeof(double*));
	for(int i=0;i<ligne;i++){
		matrice[i]=malloc(colone*sizeof(double));
	}
	return matrice;
}

/* liberation de la memoire*/

void liberation_de_la_memoire(double** matrice,int ligne, int colone){
	for (int i=0;i<ligne;i++){
		free(matrice[i]);
	}
	free(matrice);
}

/* affichage_de_matrice*/

void affichage_de_matrice(double** matrice,int ligne,int colone){
	for(int i=0;i<ligne;i++){
		printf("|");
		for(int j=0;j<colone;j++){
			printf("%f ",matrice[i][j]);
		}
		printf("|");
		printf("\n");
	}
}

/* remplissage des matrice*/

void remplissage_de_la_matrice(double** matrice, int ligne, int colone){
	for(int i=0; i<ligne; i++){
		for(int j=0;j<colone;j++){
			printf("entrer une valeur : ");
			scanf("%lf",&matrice[i][j]);
		}
	}
}
/*calcul du somme des matrices*/

double** calcul_de_la_somme(double** matrice1,int ligne1,int colones1,double** matrice2,int ligne2,int colones2){
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

/*multiplication de deux matrices*/

/*double** calcul_de_la_somme(double** matrice1,int ligne1,int colones1,double** matrice2,int ligne2,int colones2){
	double** matrice_resultante;
	if (ligne1==colones2){
		matrice_resultante=creation_de_matrice(ligne1,colones1);
		for (int i=0;i<ligne1;i++){
			for(int j=0;j<colones1;j++){
				matrice_resultante[i][j]=matrice1[i][j]*matrice2[i][j];
			}
		}
	}
	return matrice_resultante;
}*/
	
int main(){
	int ligne;
	int colone;
	double** matrice;
	printf("entrer le nombre de ligne : ");
	scanf("%d",&ligne);
	printf("entrer le nombre de colone : ");
	scanf("%d",&colone);
	matrice=creation_de_matrice(ligne,colone);
	remplissage_de_la_matrice(matrice,ligne,colone);
	affichage_de_matrice(matrice,ligne,colone);
	liberation_de_la_memoire(matrice,ligne,colone);
	return 0;
	
}
	
		 		 
	
