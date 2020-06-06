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

Matrice* calcul_de_la_somme(Matrice* mat1, Matrice* mat2){
	Matrice* matrice_resultante;	
	if (mat1->ligne==mat2->ligne && mat1->colone==mat2->colone){
		matrice_resultante=creation_de_matrice(mat1->ligne,mat1->colone);
		for (int i=0;i<mat1->ligne;i++){
			for(int j=0;j<mat1->colone;j++){
				
				matrice_resultante->ma_matrice[i][j]=(mat1->ma_matrice[i][j])+(mat2->ma_matrice[i][j]);
			}
		}
	}
	return matrice_resultante;
}

/*calcul du produit*/

Matrice* calcul_du_produit(Matrice* mat1, Matrice* mat2){
	Matrice* matrice_resultante;
	int j;
	int k;
	double accumilateur=0;	
	if (mat1->colone==mat2->ligne){
		matrice_resultante=creation_de_matrice(mat2->colone,mat1->ligne);
		for (int i=0;i<mat1->ligne;i++){			
			for (j=0;j<mat2->colone;j++){
				for (k=0;k<mat2->ligne;k++){	
					accumilateur=accumilateur+(mat1->ma_matrice[i][k])*(mat2->ma_matrice[k][j]);
				}
				matrice_resultante->ma_matrice[i][j]=accumilateur;
				accumilateur=0;
			}
		}
	
}
return matrice_resultante;
}

/*calcul de la trace de la matrice */

double trace_dune_matrice(Matrice* m1){
	double trace=0;
	
	for ( int i=0;i<(m1->ligne);i++){
		trace=trace+m1->ma_matrice[i][i];
	}
	return trace;
}

/*calcul du déterminant*/

//a)extraction de la mineur

Matrice* extraction_de_la_matrice_mineur(Matrice* m1,int ligne, int colone){
	Matrice* mineur;
	mineur=creation_de_matrice((m1->ligne)-1,(m1->colone)-1);
	for (int i=0;i<m1->ligne;i++){
		if(i!=ligne){	
		for (int j=0;j<m1->colone;j++){
			if(j!=colone){
		    printf("%d  %d",i,j);
			mineur->ma_matrice[i][j]=m1->ma_matrice[i][j];
		}
			}
		}
	}
return mineur;
}

//b)calcul d'un determinat d'une matrice a deux dimention

double determiant(Matrice* m1){
	double det;
	det=(m1->ma_matrice[0][0]*m1->ma_matrice[1][1])-(m1->ma_matrice[1][0]*m1->ma_matrice[0][1]);
	return det;
}
//enfin calcul du determiant 

double calcul_du_determinant(Matrice* m1){
	Matrice* mineur;
	double det;
	//int signe=1;
	//int acc=0;//il contiendra tout la reponce des multiplication de coef pour chque ligne.
	
	for (int i=0; i<(m1->ligne);i++){
		//mineur=extraction_de_la_matrice_mineur(m1);
		
	if(m1->ligne>2){
				
		//det=m1->ma_matrice[0][0]*determiant(mineur);
	}
	else
	{
		//det=determiant(mineur);
	}
	
	
}
return 0;
}

int main(){
	Matrice* m1;
	Matrice* m2;
	/*Matrice* somme;
	Matrice* multi;
	double trace;
	double det;*/
	m1=creation_de_matrice(4,4);
	//m2=creation_de_matrice(2,2);
	printf("remplissage M1\n");
	remplissage_de_la_matrice(m1);
	/*printf("remplissage M2\n");
	remplissage_de_la_matrice(m2);
	printf("affichage M1\n");
	* */
	affichage_de_matrice(m1);
	/*printf("affichage M2\n");
	affichage_de_matrice(m2);
	multi=calcul_du_produit(m1,m2);
	printf("produit\n");
	affichage_de_matrice(multi);
	trace=trace_dune_matrice(m1);
	printf("la trace est : %f\n",trace);
	det=calcul_du_determinant(m1);
	printf("determiant : %f\n",det);
	* */
	
	m2=extraction_de_la_matrice_mineur(m1,1,2);
	affichage_de_matrice(m2);
	liberation_de_la_memoire(m1);
	liberation_de_la_memoire(m2);
	//liberation_de_la_memoire(multi);
	return 0;
	
}
	
		 		 
	
