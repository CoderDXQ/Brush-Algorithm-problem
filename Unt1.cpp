#include "stdio.h" 
int main() {
    FILE *fp; 
    char str[128]; 
    if((fp=fopen("123.txt","r"))==NULL) {//从文件中读
        printf("cannot open file/n"); 
    } 
    while(!feof(fp)) {
        if(fgets(str,128,fp)!=NULL)
        printf("%s",str);
    }
    fclose(fp);
}
