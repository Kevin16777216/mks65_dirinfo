#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(){
  struct stat st;
  stat("demo.txt",&st);
  printf("size of demo.txt: %d Bytes\n",st.st_size);
  printf("permissions of demo.txt: %d\n",st.st_mode);
  printf("last accessed of demo.txt: %s\n",ctime(&(st.st_atime)));
  printf("last modified of demo.txt: %s\n", ctime(&(st.st_mtime)));
  return 0;
}
