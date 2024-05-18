#include<iostream>
#include<chrono>
#define size 512



int main(){
    
    int **A = (int **)malloc(sizeof(int *)*size);
    int **B = (int **)malloc(sizeof(int *)*size);
    int **C = (int **)malloc(sizeof(int *)*size);

    for(int i=0;i<size;i++){
        A[i]=(int *)malloc(sizeof(int)*size);
        B[i]=(int *)malloc(sizeof(int)*size);
        C[i]=(int *)malloc(sizeof(int)*size);

         for(int j=0;j<size;j++){
            A[i][j]=1;
            B[i][j]=1;
         }
    }
auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++)
            C[i][j] += A[i][k] * B[k][j];
        }
    }
auto end = std::chrono::high_resolution_clock::now();

auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

std::cout<<"Time = "<<duration<<std::endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<""<<std::endl;
    }

    return 0;
}