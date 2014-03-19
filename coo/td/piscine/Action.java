public abstract class Action
{
    protected EtatAction etat=EtatAction.NON_TERMINE;
    public void faire() throws ActionTermineException
    {
	if(this.etat==EtatAction.TERMINE) throw new ActionTermineException();
	this.contenuFaire();
    }
    protected abstract void contenuFaire();
    public boolean isTermine()
    {
return (this.etat=EtatAction.TERMINE);
    }
}