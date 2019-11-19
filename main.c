#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int main(int argc, char * argv[]){
  char r[256];
  if (argc > 1){
      strcpy(r, argv[1]);
  }else{
      printf("Please enter a directory:");
      fgets(r, 200, stdin);
      r[strlen(r)-1] = '\0';
  }
  printf("\n",r);
  printf("Statistics for Directory:%s\n",r);
  char *RegFiles[500];
  char *DirFiles[500];
  struct stat temp;
  int Reglen = 0;
  int Dirlen = 0;
  int size = 0;
  DIR *d = opendir(r);
  if (!d) {
    printf("error %d: %s\n",errno,strerror(errno));
    return 0;
  }
  struct dirent *dir;
  while(dir = readdir(d)){
    stat(dir->d_name,&temp);
    size += temp.st_size;
    if(dir->d_type != 4){
      RegFiles[Reglen++] = strdup(dir->d_name);
      continue;
    }
    DirFiles[Dirlen++] = strdup(dir->d_name);
  }
  printf("\nSize of %s: %d Bytes\n\n",r,size);
  printf("Directories:\n\t");
  int i = -1;
  while(++i-Dirlen){
    printf("%s\n\t",DirFiles[i]);
    free(DirFiles[i]);
  }
  i = -1;
  printf("\nRegular Files:\n\t");
  while(++i-Reglen){
    printf("%s\n\t",RegFiles[i]);
    free(RegFiles[i]);
  }
  closedir(d);
  return 0;
}
