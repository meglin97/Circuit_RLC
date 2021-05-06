#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000 
// Systeme d'EDO
void F(double S[2],double U[2],double E,double R,double L,double C){
    S[0]=U[1];
    S[1]=-U[1]*R/L-U[0]/(L*C)-E/(L*C);
}

// Méthode d'Euler
void euler(double S[2],double U[2][N], double t[N], double t_i, double t_f,double E,double R,double L,double C){
    double dt;
    double U_t[2];          // Vecteur contenant u et du/dt pour un temps t
    FILE* file1 =fopen("results_euler.txt","w");
    for(int i =1;i<N;i++){
        t[i] = i * (t_f - t_i)/(N-1) + t_i;
        dt= t[i] - t[i-1]; 
        U_t[0] = U[0][i-1];
        U_t[1] = U[1][i-1];
        F(S,U_t,E,R,L,C);
        U[0][i] = U[0][i-1] + dt *S[0];
        U[1][i] = U[1][i-1] + dt *S[1];
        fprintf(file1, "%.6E     %.6E\n",t[i],U[0][i]);
    }
    fclose(file1);
}

//Méthode de Heun
void heun(double S[2],double U[2][N], double t[N], double t_i, double t_f,double E,double R,double L,double C){
    double k1[2], k2[2];
    double dt;
    double U_t[2]; 
    FILE* file2 =fopen("results_heun.txt","w");
        for(int i =1;i<N;i++){
            t[i] = i * (t_f - t_i)/N + t_i;
            dt= t[i] - t[i-1]; 
            //k1
            U_t[0] = U[0][i-1];
            U_t[1] = U[1][i-1];
            F(S,U_t,E,R,L,C);
            k1[0] = dt * S[0];
            k1[1] = dt * S[1];

            //k2
            U_t[0] = U[0][i-1] + k1[0]/2 ;
            U_t[1] = U[1][i-1] + k1[1]/2;
            F(S,U_t,E,R,L,C);
            k2[0] = dt * S[0];
            k2[1] = dt * S[1]; 

            U[0][i] = U[0][i-1] + (k1[0] + k2[0])/2;
            U[1][i] = U[1][i-1] + (k1[1] + k2[1])/2;
            fprintf(file2, "%.6E     %.6E\n",t[i],U[0][i]);
        }
        
        fclose(file2);
}


//Méthode de Runge-Kutta 4
void rk4(double S[2],double U[2][N], double t[N], double t_i, double t_f,double E,double R,double L,double C){
    double k1[2], k2[2], k3[2], k4[2]; //k dimention 2
    double dt;
    double U_t[2];          // Vecteur contenant u et du/dt pour un temps t
    FILE* file2 =fopen("results_RK4.txt","w");
        for(int i =1;i<N;i++){
            t[i] = i * (t_f - t_i)/N + t_i;
            dt= t[i] - t[i-1]; 

            //k1
            U_t[0] = U[0][i-1];
            U_t[1] = U[1][i-1];
            F(S,U_t,E,R,L,C);
            k1[0] = dt * S[0];
            k1[1] = dt * S[1];

            //k2
            U_t[0] = U[0][i-1] + k1[0]/2 ;
            U_t[1] = U[1][i-1] + k1[1]/2;
            F(S,U_t,E,R,L,C);
            k2[0] = dt * S[0];
            k2[1] = dt * S[1];

            //k3
            U_t[0] = U[0][i-1] + k2[0]/2 ;
            U_t[1] = U[1][i-1] + k2[1]/2;
            F(S,U_t,E,R,L,C);
            k3[0] = dt * S[0];
            k3[1] = dt * S[1];

            //k4
            U_t[0] = U[0][i-1] + k3[0] ;
            U_t[1] = U[1][i-1] + k3[1];
            F(S,U_t,E,R,L,C);
            k4[0] = dt * S[0];
            k4[1] = dt * S[1];

            U[0][i] = U[0][i-1] + (k1[0] + 2*k2[0] + 2*k3[0] + k4[0])/6;
            U[1][i] = U[1][i-1] + (k1[1] + 2*k2[1] + 2*k3[1] + k4[1])/6;
            fprintf(file2, "%.6E     %.6E\n",t[i],U[0][i]);
        }
        
        fclose(file2);
}

int main(){

    double t_i = 0.0E+00;   // Temps initial
    double t_f = 1.0E+02;   // Temps final
    double t[N];            // Tableau temps
    double E = 1.0E+00;     // Force electromotrice du generateur [V]
    double R = 1.0E-01;     // Resitance totale du circuit [ohm]
    double L = 1.0E+00;     // Inductance de la bobine [H]
    double C = 1.0E+00;     // Capacite electrique [F]
    double u = 1.0E+00;     // Tension initiale aux bornes du condensateur [V]
    double dudt = 1.0E+00;  // Dérivée initiale de u [V.s-1]
    double U[2][N];         // Vecteur contenant u et du/dt pour chaque temps
    double S[2];            // Systeme d'ODE tel que dU/dt = S(U)
    

     // Conditions initiales
    U[0][0] = u;
    U[1][0] = dudt;
    t[0] = t_i;

    euler(S,U,t,t_i,t_f,E,R,L,C);
    rk4(S,U,t,t_i,t_f,E,R,L,C);
    heun(S,U,t,t_i,t_f,E,R,L,C);

    
    return 0;
}