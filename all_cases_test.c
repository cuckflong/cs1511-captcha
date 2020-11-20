#include<stdio.h>
#include"captcha.h"
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char* argv[]){
    char num=argv[1][0], findex='0', lindex='0';
    char name[20];
    
        findex='0';
        lindex='0';
        while(findex<='9'){
            lindex='0';
            while(lindex<='9'){
                //strcpy(name, num);
                strcpy(name, "digit/");
                name[6] = num;
                name[7] = '_';
                name[8] = findex;
                name[9] = lindex;
                strcpy(&(name[10]), ".pbm");
                printf("File is %s\n", name);
                char* args[] = {"./alltest", name, NULL};
                
                pid_t pid;
                
                if ((pid = fork()) == -1)
                    perror("fork error");
                else if (pid == 0) {
                    execv("./alltest", args);
                    printf("Return not expected. Must be an execv error.n");
                }
                usleep(20000);
                lindex++;
            }
            findex++;
        }

    
}
