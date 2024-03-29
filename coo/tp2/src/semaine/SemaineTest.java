package semaine;

import semaine.Semaine;
public class SemaineTest
{
    Semaine jour;
    boolean isTravaille;
    
    public SemaineTest(String jour)throws IllegalDayException
    {
	switch(jour)
	    {

	    case "LUNDI":
		this.jour=Semaine.LUNDI;
		this.isTravaille=true;
		break;

	    case "MARDI":
		this.jour=Semaine.MARDI;
		this.isTravaille=true;
		break;

	    case "MERCREDI":
		this.jour=Semaine.MERCREDI;
		this.isTravaille=true;
		break;

	    case "JEUDI":
		this.jour=Semaine.JEUDI;
		this.isTravaille=true;
		break;

	    case "VENDREDI":
		this.jour=Semaine.VENDREDI;
		this.isTravaille=true;
		break;

	    case "SAMEDI":
		this.jour=Semaine.SAMEDI;
		this.isTravaille=false;
		break;

	    case "DIMANCHE":
		this.jour=Semaine.DIMANCHE;
		this.isTravaille=false;
		break;

	    default:
		throw new IllegalDayException("jour pas bon");
		break;
	    }
    }

  
    public SemaineTest(int jour)throws IllegalDayException
    {
	switch(jour)
	    {

	    case 1:
		this.jour=Semaine.LUNDI;
		this.isTravaille=true;
		break;

	    case 2:
		this.jour=Semaine.MARDI;
		this.isTravaille=true;
		break;

	    case 3:
		this.jour=Semaine.MERCREDI;
		this.isTravaille=true;
		break;

	    case 4:
		this.jour=Semaine.JEUDI;
		this.isTravaille=true;
		break;

	    case 5:
		this.jour=Semaine.VENDREDI;
		this.isTravaille=true;
		break;

	    case 6:
		this.jour=Semaine.SAMEDI;
		this.isTravaille=false;
		break;

	    case 7:
		this.jour=Semaine.DIMANCHE;
		this.isTravaille=false;
		break;

	    default:
		throw new IllegalDayException("jour pas bon");
		break;
	    }
    }

	public Semaine lendemin()
	{
	    Semaine neutre;
	    int ordinal=this.ordinal;
	    if( ordinal !=7)
		return  neutre=new Semaine(ordinal+1);
	    return	neutre=new Semaine (1);
	}

	public boolean estTravaille()
	    {
		return this.isTravaille;
	    }





	public static void main(String [] args)
	{
	
	    Semaine day=new Semaine(args[0]);

	    for(int i=0;i<7;i++)
		{
		    if (day.estTravaille())
			System.out.println("oops le"+day.name+"est un jour de boulot\n");
		    else
			System.out.println("ouf! le"+day.name+"est un jour de congé\n");	
		}
	    day=Semaine.lendemin();

	}
}
