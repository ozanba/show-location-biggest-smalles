//Write c program to fill a 5*6 array with random 9 digit integers. the prgram then should find the minimum and 
//maximium valuess together with theri lovation. finally locations and values sould be printed

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
   int i, j, row,col, biggest=0, bC, bR, sR, sC, smallest=99999999,exist,k,m,digit,digitLog; 
   printf("How many digit: "); scanf("%d",&digit);
   digitLog= pow(10,digit-1);
   printf("How many Row and column: "); scanf("%d%d",&row,&col);
   int arr[row][col];
   
      srand(time(NULL));
   for(j=0; j<row; j++){
      for(i=0;i<col; i++){
         exist=0;
         do{
        arr[j][i]= rand()%(9*digitLog) +1*(1*digitLog);
        for(k=0;k<j;k++){

         for(m=0;m<i;m++)
            if(arr[k][m]== arr[j][i]){
                exist=1;
                break;
            }
            if(exist==1)
               break;
            }
              
      }while(exist==1);
      }
   }
    for(j=0; j<row; j++){
      for(i=0;i<col; i++)
        if(arr[j][i]>biggest){
            biggest= arr[j][i];
            bR= j;
            bC = i; 
        }

   }
   for(j=0; j<row; j++){
      for(i=0;i<col; i++)
        if(arr[j][i]<smallest){
            smallest= arr[j][i];
            sR= j;
            sC = i; 
        }

   }

   for(j=0; j<row;j++){
      for(i=0;i<col; i++)
         printf("%d     ",arr[j][i]);
      printf("\n");
   }

   printf("\nBiggest integer is %d and its %d.  row and %d. column\n",biggest,bR+1,bC+1);
   printf("\nSmallest integer is %d and its %d.  row and %d. column\n\n",smallest,sR+1,sC+1);
   


   for(j=0; j<row;j++){
      for(i=0;i<col; i++){
         if(arr[j][i]!= biggest  && arr[j][i]!= smallest )
            {
               for(k=0;k<digit;k++)
                  printf("-");
               printf("     ");
               continue;
            }
         else
            printf("%d     ",arr[j][i]);

      }
         
      printf("\n");
   }
   



   
   return 0;
}