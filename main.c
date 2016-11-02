#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int rec(char *s){
  DIR *p;
  struct dirent *e;
  struct stat buf;
  
  int sum = 0;
  p = opendir(s);
  if (!p){
    return sum;
  }
  e = readdir(p);
  while (e){
      if (e->d_type == DT_REG){
	stat(e->d_name,&buf);
        sum += buf.st_size;}
      e = readdir(p);
    }  
  closedir(p);
  return sum;
}


int lisdir(char *s){
  DIR *p;
  struct dirent *e;
  p = opendir(s);

  if (!p){
    printf("Directory not found.\n");
    return -1;
  }
  
  else{    
    e = readdir(p); 
    printf("Statistics for directory: %s\n", s );
    printf("Total Directory Size: %d Bytes\n", rec(s));
    printf("Directories:\n");
    while (e){
      if (e->d_type == DT_DIR){
	printf("\t%s\n", e->d_name);}
      e = readdir(p);
    }
    closedir(p);
    
    p = opendir(s);
    e = readdir(p);
    printf("Regular Files:\n");
    while (e){
      if (e->d_type == DT_REG){
	printf("\t%s\n", e->d_name);}
      e = readdir(p);
    }    
  }
  closedir(p);
  return 0;
}



int main (){
  DIR *p;
  return lisdir("./");
}
