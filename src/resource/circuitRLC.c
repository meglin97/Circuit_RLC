#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
// Systeme d'EDO
void systeme(double S[2],double U[2],double E,double R,double L,double C){
    S[0]=U[1];
    S[1]=-U[1]*R/L-U[0]/(L*C)-E/(L*C);
}


int main(){
    printf("***************************************************\n");
    printf("Projet Méthode Numérique : Modélisation Circuit RLC\n");
    printf("***************************************************\n");

    int N = 10000;          // Nombre d'echantillons temporels
    double t_i = 0.0E+00;   // Temps initial
    double t_f = 1.0E+02;   // Temps final
    double t[N];            // Tableau temps
    double dt;              // Pas de temps
    double E = 1.0E+00;     // Force electromotrice du generateur [V]
    double R = 1.0E-01;     // Resitance totale du circuit [ohm]
    double L = 1.0E+00;     // Inductance de la bobine [H]
    double C = 1.0E+00;     // Capacite electrique [F]
    double u = 1.0E+00;     // Tension initiale aux bornes du condensateur [V]
    double dudt = 1.0E+00;  // Dérivée initiale de u [V.s-1]
    double U[2][N];         // Vecteur contenant u et du/dt pour chaque temps
    double U_t[2];          // Vecteur contenant u et du/dt pour un temps t
    double S[2];            // Systeme d'ODE tel que dU/dt = S(U)
    
    // Méthode d'Euler
    FILE* file =fopen("results_euler.txt","w");
    // Conditions initiales
    U[0][0] = u;
    U[1][0] = dudt;
    t[0] = t_i;
    for(int i =0;i<N;i++){
        t[i] = i * (t_f - t_i)/N + t_i;
        dt = t[i] - t[i-1]; 
        U_t[0] = U[0][i-1];
        U_t[1] = U[1][i-1];
        systeme(S,U_t,E,R,L,C);
        U[0][i] = U[0][i-1] + dt *S[0];
        U[1][i] = U[1][i-1] + dt *S[1];
        fprintf(file, "%.6E     %.6E\n",t[i],U[0][i]);
    }
    fclose(file);

    return 0;
}