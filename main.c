#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int opc,n,cont,d,d1,d2,s,band,i,signo,j;
	float x,p,band2,fact,R;
	do{
		printf("Menu\n");
		printf("1) Ejercicio 1\n");
		printf("2) Ejercicio 2\n");
		printf("3) Ejercicio 3\n");
		do{
			scanf("%d",&opc);
			if( opc < 1 || opc > 3)
				printf("Error en la opcion de lectura");
		}while(opc < 1 || opc > 3);
		switch(opc){
			case 1: 
				cont=0;
				printf("\nIngrese numero: ");
				scanf("%d",&n);
				while(n > 9){
					d = 1;
					while(n >= 10){
						d *= n%10;
						n /= 10;
					}
					d *= n;
					cont++;
					n = d;
				}
				printf("\nEntrada: %d - Salida: %d",n,cont);	
			break;
			case 2: 
				printf("\nIngrese el valor X: ");
				scanf("%f",&x);
				printf("\nIngrese la precision de la medida: ");
				scanf("%f",&p);	
				band2 = x;
				cont = 3;
				R = band2;				
				do{
					band2 = R;
					fact = 1;
					for(i=1;i<=cont;i++){
						fact *= i;
					}
					R = (pow(x,cont))/fact;
					cont = cont+2;
				}while( (band2 - R) > p );
				signo = 1;
				R = 0;
				for(i=1;i<=cont;i=i+2){
					fact = 1;
					for(j=1;j<=i;j++){
						fact *= j;
					}
					R = R + signo*(pow(x,i))/fact;
					signo *= -1;
				}	
				printf("\nEntrada: %f - Salida: %f\n",x,R);			
			break;
			case 3: 
				printf("\nIngrese numero entre 0 y 99: ");
				do{	scanf("%d",&n);	}while(n < 0 || n > 99);
				band = n;
				cont = 0;			
				do{
					if(n == 0) break;
					d1 = n%10;
					d2 = n/10;
					s = d1 + d2;
					n = d1*10 + s%10;
					cont++;
				}while(n != band); 
				printf("\nEntrada: %d, Salida: %d\n",band,cont);	
			break;
		}
	}while(opc != 4);
	return 0;
}
