#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Création de polynome

typedef struct {
	int degre;
	double* polynome;
	int* degre_de_chacun;	
}Polynome;

Polynome* Creation_de_polynome(int puissance){
	Polynome* polynome;
	polynome=malloc(sizeof(Polynome));
	polynome->degre=puissance;
	polynome->polynome=(double*)malloc((puissance+1)*sizeof(double));
	polynome->degre_de_chacun=(int*)malloc((puissance+1)*sizeof(int));
	
	return polynome;
}

Polynome* remplissage_polynome(Polynome* polynome){
	
	for(int i=0;i<(polynome->degre+1);i++){
		printf("entrez coef et degre :");
		scanf("%lf %d",&polynome->polynome[i], &polynome->degre_de_chacun[i]);
	}
	
	return polynome;
}

void affichage_polynome( Polynome* polynome){
	
	printf("f(x)=");
	for(int i=0;i<(polynome->degre+1);i++){
		if(i+1==polynome->degre+1){
			printf("(%lf)x^(%d)",polynome->polynome[i],(polynome->degre_de_chacun[i]));
		}
		else{
			printf("(%lf)x^(%d)+",polynome->polynome[i],(polynome->degre_de_chacun[i]));
		}
	}
	printf("\n");	
}
 
double evaluation( Polynome* polynome, double point){
int accu=0;
for(int i=0;i<(polynome->degre+1);i++)
{
	accu=accu+(polynome->polynome[i])*pow(point,(polynome->degre_de_chacun[i]));
}
return accu;
}

Polynome* derive(Polynome* polynome){
	Polynome* derive=Creation_de_polynome(polynome->degre-1);
	for(int i=0; i<(derive->degre+1); i++)
	{
		derive->polynome[i]=(polynome->polynome[i])*(polynome->degre_de_chacun[i]);
		derive->degre_de_chacun[i]=(polynome->degre_de_chacun[i]-1);
	}
		
	 return derive;
}

//polynome1 sera celle qui à le plus grand degre 
Polynome* somme_de_polynome(Polynome* polynome1,Polynome* polynome2)
{
	int i;
	int j;
	Polynome* resultat=Creation_de_polynome(polynome1->degre);
	
return resultat;
}

int main(){
	Polynome* p1;
	Polynome* deri;
	Polynome* sommes;
	int degre;
	double point=3;
	double eval;
	double test=pow(2,10);
	printf("%lf \n",test);
	printf("veuillez enter le degre de votre polynome: ");
	scanf("%d",&degre);
	p1=Creation_de_polynome(degre);
	remplissage_polynome(p1);
	affichage_polynome(p1);
	eval=evaluation(p1,point);
	printf("Evaluation au point donné %lf \n",eval);
	deri=derive(p1);
	affichage_polynome(deri);
	sommes=somme_de_polynome(p1,deri);
	affichage_polynome(sommes);
	free(sommes);
	free(deri);
	free(p1);
	
	return 0;
}
		
	
