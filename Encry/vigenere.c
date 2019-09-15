#include<stdio.h>
#include<string.h>
char table[26][26];

void vigneretable()
{
    for(int i = 0; i < 26; i++)
    {
        int alpha=i;
        for (int j = 0; j < 26; j++, alpha++)
        {
            table[i][j] = (alpha%26)+97;
        }
    }
    /*printf("Matrix:\n");
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            printf("%c ",table[i][j]);
        }
        printf("\n");        
    }*/
}

void encryption(char *msg,char *key,char *ciph,int len)
{
    for (int i = 0; i < len; i++)
    {
        ciph[i]=table[msg[i]-97][key[i]-97];
    }
    ciph[len]='\0';
    printf("\nCipher Text: %s\n",ciph);
}

void decryption(char *ciph,char *key,char *pt,int len)
{

    for (int i = 0; i < len; i++)
    {
        for (int j = key[i]-97, k=0; k < 26; k++)
        {
            if(table[j][k]==ciph[i])
            {
                pt[i]=k+97;
                break;
            }
        }
    }
    pt[len]='\0';
    printf("\nPlain Text: %s\n",pt);
}

int main()
{
    int keylen,msglen;
    char key[100],message[100],cipher[100],plain[100];
    vigneretable();
    printf("Enter the Message: ");
    scanf("%s",message);

    printf("Enter the Keyphrase: ");
    scanf("%s",key);

    msglen=strlen(message);
    keylen=strlen(key);

    for (int i = keylen,j=0; i < msglen; i++,j++)
    {
        if(j==keylen)
        {
            j=0;
        }
        key[i]=key[j];
    }
    
    key[msglen]='\0';

    printf("Msg:%s\nKey:%s\n",message,key);

    encryption(message,key,cipher,msglen);

    decryption(cipher,key,plain,msglen);

    return 0;
}