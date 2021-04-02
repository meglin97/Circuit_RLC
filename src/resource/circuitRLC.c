#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20
#define E 5

float *discSup_0(float lambda,float discriminant,float temps[N]){
    float r1=((-2*lambda) + sqrt(discriminant))/2;
    float r2=((-2*lambda) - sqrt(discriminant))/2;
    static float u[N];
    for(int i=0;i<N;i++){
       u[i]=(r2*E*exp(r1*temps[i]) - r1*E*exp(r2*temps[i]))/(r2-r1);
    }
    return u;
}

float *discEgal_0(float lambda,float temps[N]){
    static float u[N];
    float r=(-lambda);
    for(int i=0;i<N;i++){
       u[i]=E*(lambda*temps[i] + 1)*exp(r*temps[i]);
    }
    return u;
}

//w²=-(discriminant)
float *discInf_0(float lambda,float w,float temps[N]){
    static float u[N];
    for(int i=0;i<N;i++){
        u[i] = E*(cos(w*temps[i]) + sin(w*temps[i]))*exp(-lambda*temps[i]);
    }
    return u;
}

void equationCourant(float R,float L,float C,int t){
    float w0_carre=1/L*R;
    float lambda=R/(2*L);

    //equation du second degree homogene : r² + 2*lambda*r +w0² = 0
    //discriminant = (2*lambda)² - 4*w0²
    float discriminant=4*lambda-4*w0_carre;
    float *u;
    float temps[N];
    for(int i=0;i<N;i++){
        temps[i]=i*(t/N);
    }
    //lambda > w0²
    if(discriminant > 0){
       u= discSup_0(lambda,discriminant,temps);
    }
    else if(discriminant < 0){
        float w=sqrt(-discriminant);
        u=discInf_0(lambda,w,temps);
    }
    else{
        u=discEgal_0(lambda,temps);
    }
    
    FILE *file=fopen("results.txt","w");
    for(int i=0;i<N;i++){
        fprintf(file,"%f    %f\n",temps[i],u[i]);
    }

}


int main(){
    printf("***************************************************\n");
    printf("Projet Méthode Numérique : Modélisation Circuit RLC\n");
    printf("***************************************************\n");
    float r,l,c;
    printf("Entrer la valeurs de R: ");
    scanf("%f",&r);
    printf("Entrer la valeurs de L: ");
    scanf("%f",&l);
    printf("Entrer la valeurs de C: ");
    scanf("%f",&c);
    equationCourant(r,l,c,20);
    return 0;
}