// benbachir hamza M2 IIPE
#include <omp.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include<math.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    
    double sum=0,sum1=0;
    double Pi,Pi_seq;
    int i,epsi;
    int debut,fin;
    int debut_seq,fin_seq;
    
    
    printf("donner la valeur de epsi: ");
    scanf("%d", &epsi);

    
    // calcule parallel using openmp
    
    #pragma omp parallel 
    { 
        #pragma omp for
        debut = clock();
    for (i=0; i<=epsi*100; i++) {
    
        sum += ((i&1) ? -1.0 : 1.0) / (2*i + 1) ;
        
    }
        fin =  clock();
    }
     Pi= 4*sum;
         
         printf("The value of Pi is %f\n",Pi);
     printf("Approximate value of PI is %.9f\n", Pi);
     printf("temps parallele=%f\n", (double)(fin-debut)/CLOCKS_PER_SEC);
     printf("\n"); 
   
     
     // calcul sequenciel 

     debut_seq = clock();
    for (i=0; i<=epsi*100; i++) {
    
        sum1 += ((i&1) ? -1.0 : 1.0) / (2*i + 1) ;
        
    }
        fin_seq =  clock();  
        Pi_seq= 4*sum1;

     printf("The value of Pi is %f\n",Pi_seq);
     printf("Approximate value of PI is %.9f\n", Pi_seq);
     printf("temps sequenciel=%f\n", (double)(fin_seq-debut_seq)/CLOCKS_PER_SEC);
   
      return 0;

 } 
