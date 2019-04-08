#include "menu.h"

int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
char command[10]="";
int menu_id=0;
char *line=NULL;
  size_t size = 0;
    ssize_t ret;
  char step[4][10]={"login", "join", "list", "exit" };
  if(is_login==0){
	do{
		printf(">"); 
		scanf("%s",command);
		for(int i=0;i<4;i++){
 			if(strcmp(command,step[i])==0){
				menu_id=i;
				return menu_id;
			}
			else if(i==3){
				printf("No such command!\n");
				menu_id=-2;
				 break;
			}
		}
	}while(1);
}
 else{
       while(1){ 
		if(line==NULL)
			getchar();
		printf("#"); 
		ret = getline(&line, &size, stdin);
		if(strcmp(line,"logout\n")==0){
			printf("Bye!!\n");
                        menu_id=-2;
                        break;
                }
                else printf("%s",line);
       	}
 }
  return menu_id;
}
