#include<stdio.h>
#include<string.h>
int main()
{
  int offset,i;
  char text[100];
  scanf("%[^\n]s",text);
  printf("Enter the offset value:");
  scanf("%d",&offset);
  for(i=0;i<strlen(text);i++)
  {
    if(text[i]>='a' && text[i]<='z')
    {
      text[i]=((text[i]-'a'+offset)%26)+'a';
    }
  }
  printf("\n%s",text);
  return 0;
}