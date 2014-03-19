#include <stdio.h>	
#include <stdlib.h>	
#include <stdbool.h>


void
space
(int n)
{
      int i;
      for(i=0;i<n*4;i++)
        {
              putchar(' ');
            
        }

}



void
indentation()
{

      char actuel,ancien;
      int cpt_imbrication;
      enum {        DEBUT,NORMAL
        }
     etat_ligne = DEBUT;
      enum {        OUT_OF_FUNCTION,IN_FUNCTION
        }
     etat_bloc = OUT_OF_FUNCTION;
      enum{        IN_COM,NOT_COM
        }
     etat_commentaire =NOT_COM;
      enum{        OVERUSED,OK
        }
     qte_com=OK;

      cpt_imbrication=0;

      while((actuel=getchar()) !=EOF)
        {
              switch (actuel)
        	{


            	case '{                ':
                	  cpt_imbrication++;
                	  if(ancien==')')
                	    {
                    	      putchar('\n');
                    	      space(cpt_imbrication);
                    	      printf("{                        \n");
                        	    
                        }

                    	  else 
                    	    putchar('{                        ');
                        	  etat_ligne=DEBUT;
                        	  break;

                        	case '
                        }
                    ':
                    	  if(ancien!='\n')
                    	    {
                        	      putchar('\n');
                        	      space(cpt_imbrication);
                        	      printf("
                        }
                    \n");
                    	    
                    }

                	  else
                	    {
                    	      printf("
                    }
                \n");
                	    
                }


            	  cpt_imbrication--;
            	  etat_ligne=DEBUT;
            	  break;

            	case '*':
            	  if (ancien=='')
            	    {
                	      if(qte_com==OVERUSED)
                		putchar('\n'); 
                	      etat_commentaire=IN_COM;
                	      printf("/*");*/
/*	    
                }
            	      */
/*	  else putchar('*');*/
/*	  break;*/
/**/
/*	case '':*/
/*	  if (ancien=='*')*/
/*	    {*/
/*                	      etat_commentaire=NOT_COM;*/
/*	      qte_com=OVERUSED;*/
/*	      putchar('');*/
/*	    
                }
*/
/*            	  break;*/
/**/
/*	case '\n':*/
/*	  if(etat_commentaire==IN_COM)*/
/*	    {*/
/*                	      printf("*/\n");
                	      printf("/*");*/
/*	    
                }
*/
/*            	  else  if(ancien!='\n' || etat_bloc==OUT_OF_FUNCTION)*/
/*	    {*/
/*                	      putchar('\n');*/
/*	      etat_ligne=DEBUT;*/
/*	      qte_com=OK;*/
/*	    
                }
*/
/**/
/*            	  break;*/
/**/
/*	default:*/
/*	  if (etat_ligne==DEBUT)*/
/*	    {*/
/*                	      etat_ligne=NORMAL;*/
/*	      space(cpt_imbrication);*/
/*	    
                }
*/
/*            	  putchar(actuel);*/
/*	  break;*/
/*	  	  */
/*	
            }
*/
/*              ancien=actuel;*/
/*    
        }
*/
/*}
*/
/**/
/*int */
/*main*/
/*() */
/*{*/
/*      indentation();*/
/*  printf("\n");	*/
/*  return 0;*/
/*}
*/
/*
