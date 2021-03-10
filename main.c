#include <stdio.h>
#include <string.h>

struct  person {
	char name[30];
	char tel[30];
};

enum { INSERT = 1, UPDATE, SELECT, DELETE, EXIT};
int idx = 0;
int flag = 1;
struct person perList[100];

int main(void) {

	int menu;
	int i,j;
	char name[30];
	while(1) {
		printf("1. INSERT , 2.UPDATE , 3.SELECT, 4.DELETE, 5.EXIT\n");
		printf("input menu : "); scanf("%d",&menu);

		switch(menu) {
		case INSERT :
			printf("name : "); scanf("%s",perList[idx].name);
			printf("tel : "); scanf("%s",perList[idx].tel);
			idx++;
			printf("input complete\n");
			break;
		case UPDATE :
			printf("check name : "); scanf("%s",name);
			for(i=0;i<idx;i++) {
				printf("update!!\n");
				if(strcmp(perList[i].name,name)==0) {
					printf("change tel :"); scanf("%s",perList[i].tel);
					break;
				}
			}
			break;
		case SELECT :
			printf("search name : "); scanf("%s",name);
			for(i=0;i<idx;i++) {
				if(strcmp(perList[i].name,name)==0) {
					printf("find!!\n");
					printf("name : %s / tel : %s\n",perList[i].name, perList[i].tel);
					break;
				}
			}
			break;
		case DELETE :
			printf("check name : "); scanf("%s",name);
			for(i=0;i<idx;i++) {
				if(strcmp(perList[i].name,name)==0) {
					printf("DELETE %s\n",name);
					for(j=i;j<idx-1;j++) {
						perList[j] = perList[j+1];
					}
					idx--;
				}
			}
			break;
		case EXIT :
			flag = 0;
			break;
		}
		if(flag == 0) break;
	}
	printf("종료\n");
	return 0;
}
