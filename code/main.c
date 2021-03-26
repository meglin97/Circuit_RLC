#include <stdio.h>
#include <complex.h>

double fonct_Hjw(double l,double r,double c,double freq){
    double w=2*M_PI*freq;
    return r/(r+I*(l*w-(1/c*w)));
}

int main(){
    
}
