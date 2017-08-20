// IMPORTACION DE LIBRERIAS
#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
#include<stdlib.h> 

//INVOCAR FUNCION
double funcion(float X);  

// INICIO
int main(void){ 
	int SI=1; 
	do{
	  	// DECLARACION DE VARIABLES
		float Xi	   = 0;
		float Xu	   = 0;
		float error    = 0;
		float Xn 	   = 0;
		float Xr 	   = 0;
		float promedio = 0;
		float p        = 0;
		float res      = 0; 
		int cont=0, iter=0, val = 0; 
	 
	 	// INICIO DEL PROGRAMA
		printf("METODO DE BISECCION\n" );
		
		// REQUERIMIENTO DE INTERVALO 
		printf("Introduce x1\n"); 
		scanf("%f",&Xu);
		 
		printf("introduce X2\n"); 
		scanf("%f",&Xi);
		
		// CUANTAS ITERACIONES 
		printf("¿Cuantas iteraciones?\n");
		scanf("%d",&iter);
		
		printf("|Ciclo |f(Xu)   |error|  \n" ); 
		Xr=(Xi+Xu)/2;  
		do{ 
			promedio=funcion(Xu)*funcion(Xr); 
			if(promedio==0) {
				res = Xu; 	
				val = 1;
			} 
				if(promedio<0) {
					Xi= Xr;	
				} else {
					Xu= Xr; 
					Xn=(Xi+Xu)/2; 
					// CALCULO DEL ERROR
					error=fabs((Xn-Xr)/Xn); 
					printf("%.2f   %.2f  %.2f  \n",Xu,funcion(Xu),error); 
					Xr=Xn; 
					cont++;	
				} 	
			 
		} while(cont<iter); 
			printf("\n");
			
			// VALIDACION SI ENCUENTRA RAIZ
			if (val == 1) {
				printf("----------RESULTADO-----------------\n");
				printf("La raiz de la ecuacion es : %f \n", res);
				printf("------------------------------------\n\n");
			} else {
				printf("No se encontro una raiz \n");
			}
			 
			// EJECUTAR
			printf("¿Ejecutar otra vez? Si = 1, No = 0 \n" ); 
			scanf("%d",&SI); 
			
			if (SI == 0) {
				return 0;
			}
		} while(SI<=1);  
			 
} 
	
	// FUNCION A ITERAR
	double funcion(float X){ 
		return 2*pow(X,3)-5*pow(X,2);
	}
