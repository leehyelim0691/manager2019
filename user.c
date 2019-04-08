#include "user.h"

int load_file(LOGIN* list[], char* filename){
  int count=0,make=0,c=0;
#ifdef DEBUG_MODE
	FILE *datafile = fopen(filename, "r");
         printf("DEBUG>> datafile opened! \n");
 #endif
 if(datafile==NULL){
	printf("%s file not exist! make anyway? (Yes 1, No 2) >>",filename);
	scanf("%d",&make);
	if(make==2) return -2;
	else if(make==1) return -1;
} 
while(!feof(datafile)){
    list[c]=(LOGIN*)malloc(sizeof(LOGIN));
    fscanf(datafile,"%s %s",list[c]->id,list[c]->password);
	if(c>0){
		if(list[c]->id[0]=='\0'||list[c]->password=='\0') count=c-1;
	}
    c++;
}


  printf("%d records read!\n",count+1);
  fclose(datafile);
  return count+1;
}

int join(LOGIN* list[], int count){
  char id[20], pass[20];
  while(1){
    printf("Enter new username >> ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
	return count;
    }
    else{
      printf("Enter password >> ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count]->password, pass);
      printf("New user added!\n");
return count+1;
     
    }
  }
}

int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id >> ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("No such user!!\n");
    return 0;
  }
  else{
    printf("Enter password >> ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!!\n");
      return 0;
    }
  }
}

void logout(int* is_login){
  *is_login = 0;
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  fclose(datafile);
}
