package introihm;

/**
 * TestEvenement.java
 *
 * @author <a href="mailto:jean-christophe.routier@lifl.fr">Jean-Christophe Routier</a>
 * @version
 */
import java.awt.event.*;
import java.awt.FlowLayout;
import javax.swing.*;

public class TestEvenement2 {

	private JButton unBouton;

	public void test() {
		JFrame f = new JFrame("second event frame");
		f.addWindowListener(new FermeWindowEvent());
		f.setLocation(100, 300);
		f.setSize(100, 100);

		unBouton = new JButton("cliquez ici : il y a 2 listeners !");
		f.setLayout(new FlowLayout());

		// abonnement d'un listener :
		unBouton.addActionListener(new ActionListenerTest());
		unBouton.addActionListener(new AutreActionListenerTest());

		f.add(unBouton);

		f.pack();
		f.setVisible(true);
	}

	public static void main(String[] args) {
		new TestEvenement2().test();
	}

	// ----------------------------------------------------------------------
	// CLASSE INTERNE, revue au point 2.5 du sujet de TP
        // pour gérér la fermeture de l'application lorsuq'on fere une fenêtre
	// ----------------------------------------------------------------------
	class FermeWindowEvent extends WindowAdapter {
		public void windowClosing(java.awt.event.WindowEvent e) {
			System.exit(0);
		}
	}  
}// TestEvenement2
