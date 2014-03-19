package introihm;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class TestPanel {


	/*
	 * on utilise le conteneur par défaut "getContentPane"
	 */
	public void testContentPane() {
		JFrame f = new JFrame("getContent frame");
		f.addWindowListener(new FermeWindowEvent());
		f.setLocation(200, 100);
		// on ajoute un "label" (champ de texte non modifiable) dans le conteneur f
		f.add(new JLabel("on peut ajouter des composants au \"Container\" par défaut d'une \"JFrame\""),BorderLayout.CENTER);
		// on ajoute un bouton dans f
		f.add(new JButton("un Button"),BorderLayout.NORTH);
		f.add(new JButton("un autre Button"),BorderLayout.SOUTH);

		// /!\ NB : avant le 1.5 f.add(Component) n'était pas possible, il fallait dans ce cas
		// remplacer les 2 lignes précédentes par :
		// Container content = f.getContentPane();
		// content.add(new JLabel("un Label"));
		// content.add(new JButton("un Button"));

		// on ajuste la taille de la fenêtre selon les "tailles préférrées" des composants graphiques
		// contenus par la fenêtre
		f.pack();
		f.setVisible(true);
	}

	/*
	 * La différence avec la méthode précédente est la création
	 * d'un container ("content") qui est, une fois "rempli",
	 * désigné comme conteneur (setContentPane) de la fenêtre pour
	 * remplacer le container par défaut
	 */
	public void testSetContentPane() {
		JFrame f = new JFrame("setContent frame");
		f.addWindowListener(new FermeWindowEvent());
		f.setLocation(200, 300);

		// on crée le container "spécifique"
		Container content = new JPanel();
		content.add(new JLabel("ici on utilise un container qui remplace celui par défaut"));
		content.add(new JButton("Button"));

		// la difference avec methode precedente est la ligne
		// suivante (plus les 4 lignes ci-dessus) on n'utilise
		// pas le "contentpane" par défaut, voir interet avec
		// methoode suivante
		f.setContentPane(content);

		f.pack();
		f.setVisible(true);
	}

	/*
	 * pour illustrer l'intérêt d'avoir des conteneurs différents
	 * du conteneur par défaut, on fait changer le contenu de la
	 * fenêtre toutes les 2 secondes grâce à 2 container définis.
	 */
	public void testSetContentPaneBis() {
		JFrame f = new JFrame("changement du contenu toutes les 2 secondes (setContent frame bis)");
		f.addWindowListener(new FermeWindowEvent());
		f.setLocation(200, 400);
		f.setVisible(true);
		boolean alternance = true;

		// déifnition du premier conteneur
		Container content = new JPanel();
		content.setLayout(new GridLayout(2, 1));
		content.add(new JLabel("ATTENTION : NUMERO 1"));
		content.add(new JButton("Button"));
		content.setBackground(Color.GREEN);
		// définition du second conteneur
		Container content2 = new JPanel();
		content2.setLayout(new FlowLayout());
		content2.add(new JLabel("UN PANEL DIFFERENT ! NUMERO 2"));
		content2.add(new JTextField("avec un JTextField"));
		content2.add(new JButton("et un autre JButton"));
		content2.setBackground(Color.YELLOW);


		// on utilise alternativement l'un ou l'autre des conteneurs
		while (true) {
			if (alternance) {
				f.setContentPane(content);
			} else { // alternance = false
				f.setContentPane(content2);
			}
			f.pack(); // mise à jour
			f.validate();
			alternance = !alternance; // on change !!!
			// pause de 2 secondes
			try {
				Thread.sleep(2000);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

	}
    
    public static void main(String[] args) {
	TestPanel t = new TestPanel();
	
	t.testContentPane();
	t.testSetContentPane();
	t.testSetContentPaneBis();
	
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
}
