package processus; // a modifier si besoin

public class ThreadMultiCast extends Thread {
    
	public void run() {
	    long start = System.currentTimeMillis();
	    // boucle tant que la durée de vie du thread est < à 5 secondes
	    while( System.currentTimeMillis() < ( start + (1000 * 5))) {
	      // traitement
	      System.out.println("Ligne affichee par le thread");
	      try {
	        // pause
	        Thread.sleep(500);
	      }
	      catch (InterruptedException ex) {}
	    }
	 }    
}

