package generics;

import scanner.*;
import java.util.*;

public class ListChoserLegume {

     public <E implements Legume> E chose(String phrase,List<E> liste){
	int a;

	System.out.println(phrase);
	a=scanner.TestScanner.saisieEntier(liste.size()+1);

	if(a==0)
	    return null;
	else
	return liste.get(a-1);
     }
    
    public static void main(String[] args) {
	List<Carotte> lCarottes = new ArrayList<Carotte>();
	lCarottes.add(new Carotte(1));
	lCarottes.add(new Carotte(2));
	lCarottes.add(new Carotte(3));

	List<Pomme> lPommes = new ArrayList<Pomme>();
	lPommes.add(new Pomme(1));
	lPommes.add(new Pomme(2));
	lPommes.add(new Pomme(3));

	ListChoserLegume lcl = new ListChoserLegume();

	Carotte choixCarotte = lcl.chose("quelle carotte ? ",lCarottes);
	System.out.println("vous avez choisi : "+choixCarotte);

	  
	// Pomme choixPomme = lcl.chose("quelle pomme ? ",lPommes);
	

    }
}
