package processus; // a modifier si besoin

public class MainTest {
		  public MainTest() {
		 
		    ThreadMultiCast thread = new ThreadMultiCast();
		
		    thread.start();
		    // tant que le thread est en vie...
		    while( thread.isAlive() ) {
		      // faire un traitement...
		      System.out.println("Ligne affichée par le main");
		      try {
		        // et faire une pause
		        Thread.sleep(800);
		      }
		      catch (InterruptedException ex) {}
		    }
		  }
		  
		  public static void main(String[] args) {
		    new MainTest();
		  }

}

