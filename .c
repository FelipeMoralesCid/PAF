
    Nombre: Felipe Morales Cid
    RUN: 18.740.772-9
    Examen
    
    
    Algoritmo: Minima diferencia


#include <stdio.h>
#include <stdlib.h>

int main(){

  int *array,n=0,i,pot=0,resultado=0,menor,mayor;
  
  printf("\n\nIngrese la cantidad de numeros que se desea en el arreglo, el numero debe ser\nmayor que 2.\n\n");
  scanf("%d",&n);
  while (n<3)       //se genera un ciclo hasta que se tome un numero mayor o igual a 3
  {
    printf("Ingrese un valor mayor que 2.\n");
    scanf("%d",&n);
  }
  int p=n+1,x=-n;
  FILE* parte1= NULL;       //comandos para usar y crear los archivos
  FILE* parte2= NULL;
  char* nombre1 = "entrada.ent"; // nombres de los archivos
  char* nombre2 = "salida.sal";
  parte1= fopen(nombre1, "w"); //abro el archivo
  fprintf(parte1,"%d\n" ,n); // <------ se guarda el primer valor de la carpeta entrada.ent
  printf("Ahora ingrese %d numeros enteros.\n",n); 
  array = (int *)malloc (p*sizeof(int)); // <------ se usa la memopria dinamica para poder tener un arreglo con entrada scanf

  for (i = 0; i < 2*n-1; ++i,++x) // el cliclo sera de 2*n-1, con n se le dara valor a las partes del arreglo (los que entran a if)
  {                               
    if (i<n)
    {
       scanf("%d",&array[i]);
       pot=pot+*(array+i);
       fprintf(parte1,"%d " ,array[i]);
    }
    else                          // cuando se entre a else ya se habran sumado todos los numeros y se usara el suguiente algoritmo para descomponerlos
      {
        
        resultado=resultado + *(array+x);//con "resultado" igual a 0 se le sumara (ejemplo{1,2,3,4,5}) 1 resultando en 1
        //luego al total de la suma se le resta resultado*2 (15-2)quedando 13. al sumarlo 2 a resultado (resultado=3)*2=6 15-6 = 9 etc
        *(array+x)=abs(pot-(2*resultado));

        if (x==0){
          menor=*(array+x);
                                  //sencillo algoritmo para escoger el numero menos
        }
        else if(*(array+x)<menor){

          menor=*(array+x);
        }


       }
     

    }    

        

  
  fclose(parte1); // se cierra el archivo 1
  parte2=fopen(nombre2,"w"); // se abre el 2
  fprintf(parte2,"%d\n",menor); // le inscribo el numero menor
  fclose(parte2); // lo cierro
  free(array); //libero
  return 0; // fin

}


