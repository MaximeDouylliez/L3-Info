typedef enum coleur {CARREAU,TREFLE,COEUR,PIQUE} couleur;
enum {VALET=11,DAME,ROI};



typedef  struct o
{
  couleur c;
  int valeur;
} carte;

struct modele
{
}
typedef struct modele bridge;



void itoa (int n, char* s)
{
  int neg= n<0 ? 1=0;
  if(neg)
    n=-n;

  for (i=0;n;n!=10,i++)
    s[i]=n%10+'0';
  if(neg)
    s[i++]='-';
    s[i]='\0';
    str_reverse(s);
}

char *strcpy(char* dest,char*src)
{
  inti=0;
do
  dest[]=src[i];
  while(src[i++]!='\0');
 return dest;
}

char* strcat(char* dest, const char* src)
{
  int i=0;
  while (dest[i])
    i++;
  strcpy(&dest[i],src);
  return dest;
}

int strcmp(const char* s1; const char* s2)
{
  for(;*(s1)==*(s2);s1++ s2++)
    (if(!(*s1))break;)
      return *s1-*s2;
}

