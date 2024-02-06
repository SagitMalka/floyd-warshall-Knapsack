#include<stdio.h>
#include "my_mat.h"


int main() {

    char chosen_fun;

    int flag = 1;

    while (flag) {
        scanf("%c", &chosen_fun);

        switch (chosen_fun) {
            case 'A':
                scan();
                break;
            case 'B':
                if(pathExist()==1){
                    printf("True\n");
                }
                else{
                    printf("False\n");
                }
                break;
            case 'C':
                shortestPath();
                break;
            case 'D':
                flag = 0;
                break;
            default:
                break;
        }

    }
    return 0;
}