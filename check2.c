#include<stdio.h>
#include"captcha.h"

int check2(int height, int width, int pixels[height][width]);
int check2lowconnect(int height, int width, int pixels[height][width], int lastconnectpos[72], int currentconnectpos[72], int checkline, int a);
int check2upconnect(int height, int width, int pixels[height][width], int lastconnectpos[72], int currentconnectpos[72], int checkline, int a);
int checkupperend(int height, int width, int pixels[height][width], int checkline, int a);
int checklowerend(int height, int width, int pixels[height][width], int checkline, int a);

int check2(int height, int width, int pixels[height][width]){
    int i=height-1,j=0,k=0,checkstart=0, connected=1, confirm1=0, confirm2=0,start=1, lastk=0;
    int currentconnectpos[72]={-1};
    int lastconnectpos[72]={-1};
    while(j<width){
        i=height-1;
        checkstart=0;
        k=0;
        while(i>=0){
            if(pixels[i][j]==1 && checkstart==0){
                checkstart=1;
                lastconnectpos[i]=-1;
                currentconnectpos[i]=-1;
            }
            if(pixels[i][j]==0 && (checkstart==1 || checkstart==2)){
                checkstart=2;
                if(start==1){
                    lastconnectpos[i]=i;
                }
                else{
                    currentconnectpos[i]=i;
                }
            }
            
            if(pixels[i][j]==1 && checkstart==2){
                checkstart=3;
            }
            if(checkstart==3){
                lastconnectpos[i]=-1;
                currentconnectpos[i]=-1;
            }
            i--;
        }
        if((j!=0 && checkstart==3 && start==0 && connected==1 && check2upconnect(height, width, pixels, lastconnectpos, currentconnectpos, j, 1)==0) || (start==0 && checkstart<3 && connected==1)){
            start=1;
            //printf("1");
            if((checkupperend(height, width, pixels, j-1, 1)==1) && connected==1){
                confirm1=1;
                connected=0;
            }
            
        }
        
        if(checkstart!=3){
            start=1;
            i=0;
            while(i<72){
                lastconnectpos[i]=-1;
                i++;
            }
        }
        i=height-1;
        if(start==0){
            while(i>=0){
                lastconnectpos[i]=currentconnectpos[i];
                i--;
            }
        }
        if(start==1 && checkstart==3){
            start=0;
        }
        j++;
    }
    i=0;
    while(i<72){
        currentconnectpos[i]=-1;
        lastconnectpos[i]=-1;
        i++;
    }
    i=0;
    start=1;
    j=width-1;
    connected=1;
    lastk=height-1;
    k=0;
    while(j>=0){
        i=0;
        checkstart=0;
        k=0;
        while(i<height){
            if(pixels[i][j]==1 && checkstart==0){
                checkstart=1;
                lastconnectpos[i]=-1;
                currentconnectpos[i]=-1;
            }
            if(pixels[i][j]==0 && (checkstart==1 || checkstart==2)){
                checkstart=2;
                if(start==1){
                    lastconnectpos[i]=i;
                }
                else{
                    currentconnectpos[i]=i;
                }
            }
            
            if(pixels[i][j]==1 && checkstart==2){
                checkstart=3;
                if(start==0){
                    k=i;
                }
            }
            if(checkstart==3){
                lastconnectpos[i]=-1;
                currentconnectpos[i]=-1;
            }
            i++;
        }
        if((j!=width-1 && checkstart==3 && start==0 && connected==1 && check2lowconnect(height, width, pixels, lastconnectpos, currentconnectpos, j, -1)==0) || (start==0 && checkstart<3 && connected==1)){
            start=1;
            //printf("9");
            if((checklowerend(height, width, pixels, j+1, -1)==1) && connected==1){
                confirm2=1;
                connected=0;
            }
            else if(k>lastk){
                connected=0;
            }
        }
        if(start==0){
            lastk=k;
        }
        if(checkstart!=3){
            start=1;
            i=0;
            while(i<72){
                lastconnectpos[i]=-1;
                i++;
            }
        }
        i=height-1;
        if(start==0){
            while(i>=0){
                lastconnectpos[i]=currentconnectpos[i];
                i--;
            }
        }
        if(start==1 && checkstart==3){
            start=0;
        }
        j--;
    }
    //printf("%d %d\n", confirm1, confirm2);
    if(confirm1==1 && confirm2==1){
        
        return 1;
    }
    else{
        return 0;
    }
}

int check2upconnect(int height, int width, int pixels[height][width], int lastconnectpos[72], int currentconnectpos[72], int checkline, int a){
    int i=height-1, checkstart=0;
    while(i>=0){
        if(pixels[i][checkline]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[i][checkline]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            if(pixels[i][checkline-a]==0 && lastconnectpos[i]==-1){
                return 0;
            }
        }
        if(lastconnectpos[i]!=-1){
            if(pixels[lastconnectpos[i]][checkline+a]==0 && currentconnectpos[i]==-1){
                return 0;
            }
        }
        if(pixels[i][checkline]==1 && checkstart==2){
            checkstart=3;
        }
        i--;
    }
    return 1;
}

int check2lowconnect(int height, int width, int pixels[height][width], int lastconnectpos[72], int currentconnectpos[72], int checkline, int a){
    int i=0, checkstart=0;
    while(i<height){
        if(pixels[i][checkline]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[i][checkline]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            if(pixels[i][checkline-a]==0 && lastconnectpos[i]==-1){
                return 0;
            }
        }
        if(lastconnectpos[i]!=-1){
            if(pixels[lastconnectpos[i]][checkline+a]==0 && currentconnectpos[i]==-1){
                return 0;
            }
        }
        if(pixels[i][checkline]==1 && checkstart==2){
            checkstart=3;
        }
        i++;
    }
    return 1;
}

int checkupperend(int height, int width, int pixels[height][width], int checkline, int a){
    int i=height-1, checkstart=0;
    while(i>=0){
        if(pixels[i][checkline]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[i][checkline]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            if(pixels[i][checkline+a]==0){
                return 0;
            }
        }
        if(pixels[i][checkline]==1 && checkstart==2){
            checkstart=3;
        }
        i--;
    }
    return 1;
}
int checklowerend(int height, int width, int pixels[height][width], int checkline, int a){
    int i=0, checkstart=0;
    while(i<height){
        if(pixels[i][checkline]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[i][checkline]==0 && (checkstart==1 || checkstart==2)){
            checkstart=2;
            if(pixels[i][checkline+a]==0){
                return 0;
            }
        }
        if(pixels[i][checkline]==1 && checkstart==2){
            checkstart=3;
        }
        i++;
    }
    return 1;
}
