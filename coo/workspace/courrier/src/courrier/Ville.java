package courrier;
public class Ville{
    protected list<Courrier> bal;
    protected list<Courrier> sacoche;


    public void distribueCourrier(){
	for (Courrier c:Sacoche)
	c.getDestinataire().recoitCourrier(c);