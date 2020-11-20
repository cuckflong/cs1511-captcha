#include<stdio.h>
#include"captcha.h"

int haveo(int height, int width, int pixels[height][width], int startendindex[2]);
int checkrealhole(int height, int width, int startholeindex, int endholeindex, int pixels[height][width]);
int checkconnect(int height, int width, int checkline, int pixels[height][width]);
int checkmore1(int height, int checkline, int width, int start, int pixels[height][width]);

int haveo(int height, int width, int pixels[height][width], int startendindex[2]){
    int i=0, j=0, startholeindex=0, endholeindex=0, holediff=0, diffcountstart=0, holestart=0, holenum=0;
    while(i<height){
        j=0;
        holediff=0;
        diffcountstart=0;
        while(j<width){
            if(pixels[i][j]==1 && diffcountstart==0){
                diffcountstart=1;
            }
            if(pixels[i][j]==0 && diffcountstart==1){
                diffcountstart=2;
            }
            if(diffcountstart==2 && pixels[i][j]!=pixels[i][j-1]){
                holediff++;
            }
            j++;
        }
        if(holestart==1 && holediff>=2 && checkconnect(height, width, i-1, pixels)==0){
            if(checkrealhole(height, width, startholeindex, i-1, pixels)==1){
                holenum++;
            }
            startholeindex=i;
        }
        if(holediff>=2 && holestart==0){
            holestart=1;
            startholeindex=i;
        }
        if(holediff<2 && holestart==1){
            holestart=0;
            endholeindex=i-1;
            if(checkrealhole(height, width, startholeindex, endholeindex, pixels)==1){
                if(startholeindex!=endholeindex){
                    holenum++;
                    startendindex[0]=startholeindex;
                    startendindex[1]=endholeindex;
                }
            }
        }
        i++;
    }
    return holenum;
}
int checkrealhole(int height, int width, int startholeindex, int endholeindex, int pixels[height][width]){
    int j=0, upperconfirm=1, lowerconfirm=1, checkstart=0;
    if(startholeindex==0 || endholeindex==height){
        return 0;
    }
    while(j<width){
        if(pixels[startholeindex][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[startholeindex][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[startholeindex][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(pixels[startholeindex][j]==0 && checkstart==2){
            if(pixels[startholeindex-1][j]!=1){
                lowerconfirm=0;
            }
        }
        j++;
    }
    checkstart=0;
    j=0;
    while(j<width){
        if(pixels[endholeindex][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[endholeindex][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[endholeindex][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(pixels[endholeindex][j]==0 && checkstart==2){
            if(pixels[endholeindex+1][j]!=1){
                upperconfirm=0;
            }
        }
        j++;
    }
    if(upperconfirm==1 && lowerconfirm==1){
        return 1;
    }
    else{
        return 0;
    }
}
int checkconnect(int height, int width, int checkline, int pixels[height][width]){
    int j=0, connected1=1, connected2=0, checkstart=0;
    int upperconnectposition[100]={0};
    int lowerconnectposition[100]={0};
    while(j<width){
        if(pixels[checkline+1][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline+1][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[checkline+1][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(checkstart==3){
            if(checkmore1(height, checkline, width, j, pixels)==1){
                checkstart=4;
            }
        }
        if(checkstart==4 && pixels[checkline+1][j]==0){
            checkstart=5;
        }
        if(checkstart==5 && pixels[checkline+1][j]==1){
            checkstart=6;
        }
        if(pixels[checkline+1][j]==0 && checkstart==5){
            upperconnectposition[j]=1;
        }
        if(pixels[checkline+1][j]==0 && checkstart==2){
            upperconnectposition[j]=1;
        }
        j++;
    }
    j=0;
    checkstart=0;
    while(j<width){
        if(pixels[checkline][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[checkline][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(checkstart==3){
            if(checkmore1(height, checkline, width, j, pixels)==1){
                checkstart=4;
            }
        }
        if(checkstart==4 && pixels[checkline][j]==0){
            checkstart=5;
        }
        if(checkstart==5 && pixels[checkline][j]==1){
            checkstart=6;
        }
        if(pixels[checkline][j]==0 && checkstart==5){
            lowerconnectposition[j]=1;
            /**if(pixels[checkline+1][j]==0 && upperconnectposition[j]==0){
                connected1=0;
            }**/
        }
        if(pixels[checkline][j]==0 && checkstart==2){
            lowerconnectposition[j]=1;
            if(pixels[checkline+1][j]==0 && upperconnectposition[j]==0){
                connected1=0;
            }
        }
        j++;
    }
    j=0;
    checkstart=0;
    while(j<width){
        if(pixels[checkline+1][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline+1][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[checkline+1][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(checkstart==3){
            if(checkmore1(height, checkline, width, j, pixels)==1){
                checkstart=4;
            }
        }
        if(checkstart==4 && pixels[checkline+1][j]==0){
            checkstart=5;
        }
        if(checkstart==5 && pixels[checkline+1][j]==1){
            checkstart=6;
        }
        /**if(pixels[checkline+1][j]==0 && checkstart==5){
            if(pixels[checkline][j]==0 && lowerconnectposition[j]==0){
                connected1=0;
            }
        }**/
        if(pixels[checkline+1][j]==0 && checkstart==2){
            if(pixels[checkline][j]==0 && lowerconnectposition[j]==0){
                connected1=0;
            }
        }
        j++;
    }
    j=0;
    checkstart=0;
    while(j<width){
        if(pixels[checkline][j]==1 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline][j]==0 && checkstart==1){
            checkstart=2;
        }
        if(pixels[checkline][j]==1 && checkstart==2){
            checkstart=3;
        }
        if(checkstart==3){
            if(checkmore1(height, checkline, width, j, pixels)==1){
                checkstart=4;
            }
        }
        if(checkstart==4 && pixels[checkline][j]==0){
            checkstart=5;
        }
        if(checkstart==5 && pixels[checkline][j]==1){
            checkstart=6;
        }
        /**if(pixels[checkline][j]==0 && checkstart==5){
            if(pixels[checkline+1][j]==0){
                connected2=1;
            }
        }**/
        if(pixels[checkline][j]==0 && checkstart==2){
            if(pixels[checkline+1][j]==0){
                connected2=1;
            }
        }
        j++;
    }
    if(connected1==1 && connected2==1){
        return 1;
    }
    else{
        return 0;
    }
}
int checkmore1(int height, int checkline, int width, int start, int pixels[height][width]){
    int j=start, checkstart=0;
    while(j<width){
        if(pixels[checkline][j]==0 && checkstart==0){
            checkstart=1;
        }
        if(pixels[checkline][j]==1 && checkstart==1){
            checkstart=2;
        }
        j++;
    }
    if(checkstart==2){
        return 1;
    }
    else{
        return 0;
    }
}
