#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"



/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	int choose;
	do{
		clearScreen();
	printf(" ***Student Management System Using C***\n\n");
		printf("\t\tCHOOSE YOUR ROLE\n");
		printf("\t===============================\n");
		printf("\t[1] Admin.\n");
		printf("\t[2] Student.\n");
		printf("\t[3] Teacher.\n");
		printf("\t[0] Exit the Programm.\n");
		printf("\t===============================\n");
		printf("\tEnter The Choice: ");
	scanf("%d",&choose);
	getchar();
	switch(choose){
			case 1:{
				admin();
				break;
			}
			case 2:{
				printf("chua lam @@ xin thong cam!\nBam enter de ve home!");
				getchar();
				break;
			}
			case 3:{
				printf("chua lam @@ xin thong cam!\nBam enter de ve home!");
				getchar();
				break;
			}
			case 0:{
				break;
			}
			default:{
				printf("lua chon cua ban k hop le, moi nhap lai!\n");
				break;
			}
		}
	}while(choose != 0);
	printf("========= Thank You ==========\n");
	printf("======== See You Soon ========");
	return 0;
}


