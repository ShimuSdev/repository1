#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 10
int data[SIZE];



void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%10);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", data[i]);
    }
}

int main(){

    //RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    WriteToConsole();


int i , j , cache_content[2000], cache_size, k , x , count=0;


printf("\nEnter the size of the cache:");
scanf("%d",&cache_size);

for(i = 0 ; i < cache_size ; i++ )
            cache_content[i]= -1;
                       j = 0 ;

for(i = 0 ; i < SIZE ; i++){

        x=0;
        for( k = 0 ; k < cache_size ; k++ )
            if(cache_content[k] == data[i])
                    x = 1;
                        if (x == 0)
                            {
                              cache_content[j] = data[i];
                              j = (j+1)%cache_size;
                              count++;

                           }
                }
    printf("\nHit = %d",SIZE - count);
    printf("\nMiss = %d",count);

}
