enum op{NONE,ADD,PROD,QUO};

typedef struct formule{
  Struct term t1;
  enum op operateur;
  union {
struct term add term;
    int coeff;}t2,}formule;

float valueOfFormula (formule f)
{
  switch(f.operateur){
  case NONE:
    return valueOfTerm(f.t1);
  case ADD:
    return valueOfTerm(f.t2)+valueOfTerm(f.t1);
  case PROD:
return valueOfTerm(f.t2)-coeff*valueOfTerm(f.t1);
  case QUO:
return valueOfTerm(f.t1)/valueOfTerm(f.t2)*coeff;
  default:
    exit(EXIT_FAILLURE);
    return(float) 0;

  }

  void switch (int * a,int * b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
  }

  char*strdup(const char * s1)
  {
    char *s = s1;
    char* copie = malloc(strlen(s)+1);
    char* save=copie;
    while(*s)
      *copie++=*s++;
    *s='\0';
    return  save;
