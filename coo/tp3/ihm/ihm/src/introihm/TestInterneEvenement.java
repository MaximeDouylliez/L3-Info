package introihm;

/**
 * TestInterneEvenement.java
 *
 * @author <a href="mailto:jean-christophe.routier@lifl.fr">Jean-Christophe Routier</a>
 * @version
 */
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class TestInterneEvenement {

	private JButton unBouton;
	private JLabel unLabel;

	public void test() {
		JFrame f = new JFrame("event frame");
		f.addWindowListener(new FermeWindowEvent());

		f.setLocation(100, 300);
		f.setSize(100, 100);

		f.setLayout(new FlowLayout());

		unBouton = new JButton("cliquez ici");

		// abonnement d'un listener :
		unBouton.addActionListener(new InterneActionListenerTest());

		f.add(unBouton);

		f.pack();
		f.setVisible(true);
	}

	public static void main(String[] args) {
		new TestInterneEvenement().test();
	}

	// ----------------------------------------------------------------------
        // le listener au clic sur le bouton
	// ----------------------------------------------------------------------

	private class InterneActionListenerTest implements ActionListener {
		public void actionPerformed(ActionEvent e) {
		    TestInterneEvenement.this.unBouton.setText("j'ai été cliqué");
		}
	}// InterneActionListenerTest



	// ----------------------------------------------------------------------
        // pour gérér la fermeture de l'application lorsuq'on fere une fenêtre
	// ----------------------------------------------------------------------
	class FermeWindowEvent extends WindowAdapter {
		public void windowClosing(java.awt.event.WindowEvent e) {
			System.exit(0);
		}
	}  
}// TestInterneEvenement
