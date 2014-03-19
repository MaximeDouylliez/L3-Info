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

public class TestEvenement {

	private JButton unBouton;

	public void test() {
		JFrame f = new JFrame("event frame");
		f.addWindowListener(new FermeWindowEvent());
		f.setLocation(100, 300);
		f.setSize(100, 100);

		unBouton = new JButton("cliquez ici");
		f.setLayout(new FlowLayout());

		// abonnement d'un listener :
		unBouton.addActionListener(new ActionListenerTest());

		f.add(unBouton);

		f.pack();
		f.setVisible(true);
	}

	public static void main(String[] args) {
		new TestEvenement().test();
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
}// TestEvenement
