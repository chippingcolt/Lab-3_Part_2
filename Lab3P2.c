#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>

void getFile(){
	DIR *dir;
	struct dirent *sd;
	
	dir = opendir(".");
	
	if(dir == NULL)
	{
	
		printf("Error");
		exit(1);
		
	}
	
	while ( (sd = readdir(dir)) != NULL )
	{
		printf(">> %s\n", sd->d_name);
	}
	
	
	closedir(dir);
}
  
  
int main(int argc, char *argv[])
{ 
	struct stat buf;
	struct passwd pwd;
    struct passwd *result;
	
	if(argc<2)
	{
		printf("Lab 3 Part 2, type a file to choose\n");
		getFile();
	} 
	
	int i, j;
    printf("--Start of Lab 3 program--\n");
	gid_t getgid(void);
    pid_t pid = fork();
	
	
	
	if (pid < 0) {
      perror("Fork failed");
    }
    if (pid == 0) {
      for (i = 1; i < argc; i++) {
        stat(argv[i], &buf);
        printf("\n File:%s => ", argv[i]);
	
        if (getuid() == buf.st_uid) {
          printf("You have owner permissions: ");
          if (buf.st_mode & 00400) {

            printf(" read");

          }
          if (buf.st_mode & 00200) {

            printf(" write");

          }
          if (buf.st_mode & 00100) {

            printf(" execute");

          }
          printf("\n");
		  printf("Directory: %s\n", getpwuid(getuid())->pw_dir);

        } else if (getgid() == buf.st_gid) {
          printf("You have group permissions: ");
          if (buf.st_mode & 00040) {

            printf(" group_read");

          }
          if (buf.st_mode & 00020) {

            printf(" group_write");

          }
          if (buf.st_mode & 00010) {

            printf(" group_execute");

          }

        } else {
          printf("You have group permissions: ");
          if (buf.st_mode & 00004) {

            printf(" general_read");

          }
          if (buf.st_mode & 00002) {

            printf(" general_write");

          }
          if (buf.st_mode & 00001) {

            printf(" general_execute");

          }
        }
      }
      exit(0);
    }
    if (pid > 0) {
      wait(NULL);
      system("\n\n ps -H");
    }
  }
