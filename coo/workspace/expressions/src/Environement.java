
public class Environement {

	
	Map<Variable,Constante>memoire=new HashMap<Variable,Contante>();
	
	public Constante getValeur(Variable v) throws VariableNonLieeException
	{
		if(!memoire.keySet().contain(v))throw new VariableNonLieeException(v);
	return memoire.get(v);
	}
	
	public void setValeur(Variable v ,Contrainte c){
		memoire.put(v,c)}
	}
	
}
