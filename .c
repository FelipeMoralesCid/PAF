
#include <stdio.h>
#include <stdlib.h>

int main(){

  int *array,n=0,i,pot=0,resultado=0,menor,mayor;
  
  printf("\n\nIngrese la cantidad de numeros que se desea en el arreglo, el numero debe ser\nmayor que 2.\n\n");
  scanf("%d",&n);
  while (n<3)
  {
    printf("Ingrese un valor mayor que 2.\n");
    scanf("%d",&n);
  }
  int p=n+1,x=-n;
  FILE* parte1= NULL;
  FILE* parte2= NULL;
  char* nombre1 = "entrada.ent";
  char* nombre2 = "salida.sal";
  parte1= fopen(nombre1, "w"); //abro el archivo
  fprintf(parte1,"%d\n" ,n);
  printf("Ahora ingrese %d numeros enteros.\n",n); 
  array = (int *)malloc (p*sizeof(int));

   
  for (i = 0; i < 2*n-1; ++i,++x)
  {
    if (i<n)
    {
       scanf("%d",&array[i]);
       pot=pot+*(array+i);
       fprintf(parte1,"%d " ,array[i]);
    }
    else
      {
        
        resultado=resultado + *(array+x);
     
        *(array+x)=abs(pot-(2*resultado));

        if (x==0){
          menor=*(array+x);

        }
        else if(*(array+x)<menor){

          menor=*(array+x);
        }


       }
     

    }    

        

  
  fclose(parte1);
  parte2=fopen(nombre2,"w"); 
  fprintf(parte2,"%d\n",menor);
  fclose(parte2);
  free(array);
  return 0;

}


