#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20


void discSup_0(float lambda,float discriminant,float **u,float E){
    float r1=((-2*lambda) + sqrt(discriminant))/2;
    float r2=((-2*lambda) - sqrt(discriminant))/2;
    for(int i=0;i<N;i++){
       u[i][1]=(r2*E*exp(r1*u[i][0]) - r1*E*exp(r2*u[i][0]))/(r2-r1);
    }
}

void discEgal_0(float lambda,float **u,float E){
    float r=(-lambda);
    for(int i=0;i<N;i++){
       u[i][1]=E*(lambda*u[i][0] + 1)*exp(r*u[i][0]);
    }
}

void discInf_0(float lambda,float discriminant,float **u,float E){

}

float **equationCourant(float R,float L,float C,int t,float E){
    float w0_carre=1/L*R;
    float lambda=R/(2*L);

    //equation du second degree homogene : r² + 2*lambda*r +w0² = 0
    //discriminant = (2*lambda)² - 4*w0²
    float discriminant=4*lambda-4*w0_carre;
    float **u=malloc(sizeof(float*)*2);
    
    //lambda > w0²
    if(discriminant > 0){
        discSup_0(lambda,discriminant,u,E);

    }
    return u;
}

int main(){
    printf("***********************************************************\n");
    printf("    Projet Méthode Numérique : Modélisation Circuit RLC    \n");
    printf("***********************************************************\n");
    float r,l,c;
    printf("Entrer la valeurs de R: ");
    scanf("%f",&r);
    printf("Entrer la valeurs de L: ");
    scanf("%f",&l);
    printf("Entrer la valeurs de C: ");
    scanf("%f",&c);
    printf("R=%.2f, L=%.2f, C=%.2f\n",r,l,c);
    return 0;
}