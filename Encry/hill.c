#include<stdio.h>
#include<string.h>

void matrix_mul(int s, int* mat, int key[s][s],char* ciph,int c_ind)
{
  int r,c,val=0;
  for(r=0;r<s;r++,val=0)
  {
    for(c=0;c<s;c++)
    {
      val+=(key[r][c]*mat[c]);
    }
    ciph[c_ind]=(val%26)+'a';
  //  printf("c_ind: %d\nciph: %c\n",c_ind,ciph[c_ind]);
    c_ind++;
  }
}

void hillencry(char* text,int size,int key[size][size],char cipher[100])
{
  int i,j,pt_ind=0,tmat_ind,x,c_ind=0;
  char pt[100];
  int len=strlen(text);
  for(i=0;i<len;i++)
  {
    if(text[i]>='a' && text[i]<='z')
      pt[pt_ind++]=text[i];
  }
  pt[pt_ind]='\0';
  int pt_len=strlen(pt);
  while(pt_len%size!=0)
  {
      strcat(pt,"z");
  //    printf("plain text: %s\n",pt);
      pt_len=strlen(pt);
  }
  //printf("plain text: %s\n",pt);
  j=0,x=0;
  //printf("t_mat:\n");
  for(c_ind=0;c_ind<pt_len;c_ind+=size)
  {
    int t_mat[size];
    for(tmat_ind=0;tmat_ind<size && j<pt_len;j++)
    {
      t_mat[tmat_ind]=pt[j]-'a';
      //printf("%d ",t_mat[tmat_ind]);
      tmat_ind++;
    }
//    printf("\n");
    matrix_mul(size,t_mat,key,cipher,c_ind);
  }
  cipher[strlen(text)]='\0';
}

int main()
{
  int matsize,i,j,val;
  char text[100],cipher[100];
  int len;
  printf("Enter the key mat size:");
  scanf("%d",&matsize);
  int key[matsize][matsize];
  printf("Enter %d values:",matsize*matsize);
  
  for(i=0;i<matsize;i++)
  {
    for(j=0;j<matsize;j++)
    {
      scanf("%d",&key[i][j]);
    }
  }
  printf("Enter the text:");
  //fflush(stdin);
  scanf("%s",text);
  printf("Key:\n");
  for(i=0;i<matsize;i++)
  {
    for(j=0;j<matsize;j++)
    {
      printf("%d ",key[i][j]);
    }
    printf("\n");
  }  
  hillencry(text,matsize,key,cipher);
  printf("Cipher: %s\n",cipher);
  return 0;
}
