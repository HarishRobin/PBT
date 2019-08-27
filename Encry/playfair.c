#include<stdio.h>
#include<string.h>

struct set
{
  char one;
  char two;
};

void search(char c1,char c2,char mat[5][5],char* ciph,int i1,int i2,int enc)
{
  int found1=0,found2=0;
  int x,y,c1row,c1col,c2row,c2col;
  //printf("%c %c\n",c1,c2);
  for(x=0;x<5;x++)
  {
    if(found1&&found2)
    {
      break;
    }
    for(y=0;y<5;y++)
    {
      if(found1==0&&c1==mat[x][y])
      {
	c1row=x;
	c1col=y;
	found1=1;
      }
      if(found2==0&&c2==mat[x][y])
      {
	c2row=x;
	c2col=y;
	found2=1;
      }
    }
  }
  //printf("Pos %d %d %d %d\n",c1row,c1col,c2row,c2col);
  if(enc==1)
  {
    if(c1col==c2col)
    {
      ciph[i1]=mat[(c1row+1)%5][c1col];
      ciph[i2]=mat[(c2row+1)%5][c2col];
      //printf("Cipher in same col: %c%c\n",ciph[i1],ciph[i2]);
    }
    else if(c1row==c2row)
    {
      ciph[i1]=mat[c1row][(c1col+1)%5];
      ciph[i2]=mat[c2row][(c2col+1)%5];
      //printf("Cipher in same row: %c%c\n",ciph[i1],ciph[i2]);
    }
    else
    {
      ciph[i1]=mat[c1row][c2col];
      ciph[i2]=mat[c2row][c1col];
      //printf("Cipher in rect: %c%c\n",ciph[i1],ciph[i2]);
    }
  }
  else
  {
      
    if(c1col==c2col)
    {
      if(c1row-1<0)
      {
	c1row=5;
      }
      if(c2row-1<0)
      {
	c2row=5;
      }
      ciph[i1]=mat[(c1row-1)%5][c1col];
      ciph[i2]=mat[(c2row-1)%5][c2col];
      //printf("Cipher in same col: %c%c\n",ciph[i1],ciph[i2]);
    }
    else if(c1row==c2row)
    {
      if(c1col-1<0)
      {
	c1col=5;
      }
      if(c2col-1<0)
      {
	c2col=5;
      }
      ciph[i1]=mat[c1row][(c1col-1)%5];
      ciph[i2]=mat[c2row][(c2col-1)%5];
      //printf("Cipher in same row: %c%c\n",ciph[i1],ciph[i2]);
    }
    else
    {
      ciph[i1]=mat[c1row][c2col];
      ciph[i2]=mat[c2row][c1col];
      //printf("Cipher in rect: %c%c\n",ciph[i1],ciph[i2]);
    }
  }
}

void encrypt(struct set obj[],char player[5][5],char* ciph,int size,int enc)
{
  int ind1=0,ind2,i,j;
  for(i=0;i<size;i++,ind1++)
  {
    ind2=ind1+1;
    search(obj[i].one,obj[i].two,player,ciph,ind1,ind2,enc);
    ind1=ind2;
  }
}

int text_trim(char *text)
{
  int len=0,i;
  for(i=0;text[i];i++)
  {
    if(text[i]!=' ')
    {
      text[len++]=text[i];
    }  
  }
  text[len]='\0';

  if(len%2!=0)
  {
    text[len]='z';
    text[++len]='\0';
  }

  return len;
}

void matrix_gen(char *key,char *alp,char player[5][5])
{
  int i,j,k_ind;
  i=j=0;
  for(k_ind=0;k_ind<strlen(key);k_ind++)
  {
      if(((key[k_ind]>='a')&&(key[k_ind]<='z'))&&alp[key[k_ind]-'a'])
      {
	alp[key[k_ind]-'a']='\0';
//	printf("Inserted %c at %d %d\n",key[k_ind],i,j);
	player[i][j]=key[k_ind];
	if(j<4)
	{
	  j++;
	}
	else
	{
	  j=0;
	  i++;
	}
      }
  }
  for(k_ind=0;k_ind<26;k_ind++)
  {
    if(alp[k_ind]&&alp[k_ind]!='q')
    {
      player[i][j]=alp[k_ind];
      if(j<4)
      {
	j++;
      }
      else
      {
	j=0;
	i++;
      }
    }
  }

}

void matrix_log(char mat[5][5])
{
  int i,j;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      printf("%c ",mat[i][j]);
    }
    printf("\n");
  }
}

void set_gen(struct set obj[],char *text,int size)
{
  int t_ind=0,set_ind;
  for(set_ind=0;set_ind<size;set_ind++)
  {
    obj[set_ind].one=text[t_ind++];
    obj[set_ind].two=text[t_ind++];
  }
}

void show_set(struct set obj[],int size)
{
  int set_ind;
  for(set_ind=0;set_ind<size;set_ind++)
  {
    printf("%c %c\n",obj[set_ind].one,obj[set_ind].two);
  }
}

int main()
{
  int i,j,t_ind,text_len=0,set_ind=0,set_size,ciph_len,ciph_size;
  char text[100];
  char key[100];
  printf("Enter the keyphrase: ");
  scanf("%[^\n]s",key);
  getchar();
  printf("Enter the text: ");
  scanf("%[^\n]s",text);
  char alp[26];
  
  for(i=0;i<26;i++)
  {
    alp[i]='a'+i;
  }
  
  char player[5][5];
  char cipher[100];
  char plaintext[100];
  matrix_gen(key,alp,player);
  
  matrix_log(player);
  
  //encrypting.. to be done
  //removing spaces from text
  text_len=text_trim(text);
  //removed
  set_size=(text_len/2);
  
  struct set sets[set_size];
//  struct set encry[set_size];
  
  set_gen(sets,text,set_size);
  show_set(sets,set_size);
  bzero(cipher,sizeof(cipher));
  encrypt(sets,player,cipher,set_size,1);
//decrypt goes here
  printf("\nCipher Text: %s\n",cipher);
  printf("Decrypting ... \n");
  ciph_len=text_trim(cipher);
  ciph_size=(ciph_len/2);
  struct set ciph_set[set_size];
//  printf("Cipher Matrix: \n");
  set_gen(ciph_set,cipher,ciph_len);
  show_set(ciph_set,ciph_size);
  bzero(plaintext,sizeof(plaintext));
  encrypt(ciph_set,player,plaintext,ciph_size,0);
  printf("Plain Text: %s\n",plaintext);
  return 0;
}