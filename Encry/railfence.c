#include<stdio.h>
#include<string.h>

void encrypt(char *text,char *ciph,int k)
{
    
}

int main()
{
    int key,i;
    char text[100],cipher[100];
    printf("Enter key:");
    scanf("%d",&key);
    getchar();
    printf("Enter text: ");
    scanf("%[^\n]s",text);
    printf("%s",text);
    i=100;
    while(i%key!=0)
    {
        i++;
    }
    printf("i: %d\n",i);
    return 0;
}
