#include<stdio.h>
#include<string.h>

void encrypt(char *text,int r,int c,char ciph_mat[r][c],char *ciph)
{
    int i,j,ci_ind=0;
//     printf("r:%d c:%d\n",r,c);
    int index[r];
    for(i=0;i<r;i++)
        index[i]=0;
    int len=strlen(text);
    
    for(i=0;i<len;i++)
    {
        ciph_mat[i%r][index[i%r]]=text[i];
//         printf("ciph_mat[%d][%d]: %c\n",i%r,index[i%r],ciph_mat[i%r][index[i%r]]);
        index[i%r]++;
    }
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            ciph[ci_ind++]=ciph_mat[i][j];
        }
    }
      printf("ci_ind: %d\n",ci_ind);
      ciph[ci_ind]='\0';
}

int main()
{
    int key,i,col,text_ind=0;
    char text[100],msg[100],ciph[100];
    printf("Enter key:");
    scanf("%d",&key);
    getchar();
    printf("Enter text: ");
    scanf("%[^\n]s",msg);
    int x=strlen(msg);
    for(i=0;i<x;i++)
    {
        if(msg[i]>='a'&&msg[i]<='z')
            text[text_ind++]=msg[i];
    }
    text[text_ind]='\0';
//     printf("pt: %s\n",text);
    i=strlen(text);
    while(i%key!=0)
    {
        i++;
    }
    col=i/key;
    
//     printf("i: %d,i/key: %d,key: %d\n",i,col,key);
    char cipher_mat[key][col];
    encrypt(text,key,col,cipher_mat,ciph);
    printf("Cipher: %s\n",ciph);
    return 0;
}
