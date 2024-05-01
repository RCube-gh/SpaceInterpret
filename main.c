#include<stdio.h>
#include<string.h>
int main(int argc, char const **argv){
    char foname[100] = "a.ws";
    if(argc<=1){
        printf("specify the file\n");
        return 1;
    }else if(argc==2){
        if(strcmp(argv[1],"-h")==0){
            printf("Usage: ./ctos [File]\n -o [File_out]\n -h help\n");
            return 0;
        }
    }else if(argc>2){
        if(strcmp(argv[2],"-o") != 0 || argc > 4){
            printf("Usage: ./ctos [File]\n -o [File_out]\n -h help\n");
        }
        strcpy(foname,argv[3]);
    }

    FILE *fip,*fop;
    fip=fopen(argv[1],"r");
    if(fip==NULL){
        printf("%s file not open!\n",argv[1]);
        return 1;
    }
    fop=fopen(foname,"w");
    if(fop==NULL){
        printf("Error opening file.\n");
        return 1;
    }
    int chr;
    while((chr=fgetc(fip))!=EOF){
        if(chr=='S'){
            fputc(' ',fop);
        }else if(chr=='T'){
            fputc('	',fop);
        }else if(chr=='L'){
            fputc('\n',fop);
        }
    }
    fclose(fip);
    fclose(fop);
    return 0;

}

