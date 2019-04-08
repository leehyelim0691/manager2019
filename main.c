#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
	LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  	int is_login=0,c=0; // 로그인 여부 (0 NO, 1 Yes)
  	int menu_id=-1;
 	int count=0; 

	if (argc != 2) {
		printf("Usage : manager <datafile>\n");
		return 0;
 	 }

	else{
		count = load_file(userlist, argv[1]);
		if(count==-2) exit(EXIT_SUCCESS);	
		else if(count==-1) count=0;
		
	}
	printf(">Welcome!!\n");
 
	 while(1){
		menu_id = ask_menu(is_login);

		if(menu_id==0){
			if(is_login==0) is_login = login(userlist, count);
 	                if(is_login==-1) continue;
		}
		else if(menu_id==1) {
			c=join(userlist, count);
			count=c;
		}
    		else if (menu_id==2){
                        printf("User list (id/password)\n");
			for(int i=0;i<count;i++){
				printf("[%d] %s / %s\n",i+1,userlist[i]->id,userlist[i]->password);
			}
		}
    		else if (menu_id==3) {
			printf("%d records saved to %s!\n",count,argv[1]);
			logout(&is_login);
			break;
		}
		
		else if(menu_id==-2)
			is_login=0;
		}
		save_file(userlist, count, argv[1]);
  	return 0;
}

