package introihm;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Test {

	public void testJFrame() {
		// on crée une JFrame "f" : une "fenêtre" avec la barre fournie par l'environnement graphique
		JFrame f = new JFrame("frame");
		// on fixe la taille de f
		f.setSize(200, 200);
		// on fixe la position de f
		f.setLocation(100, 100);

		f.add(new JLabel("un objet JFrame"));
		// on rend f visible (car l'objet existe déjà mais non visible donc non affiché)
		f.setVisible(true);

	}

	public void testJWindow() {

		// on peut créer un objet  JWindow : une fenêtre "brute"
		// On n'a que la zone d'affichage sans l'"habillage" par la couche graphique de l'environnement
		// On n'a donc pas les boutons "fermeture" "icone" "agrandissement", ni la possibilité de redimensionner		
		JWindow w = new JWindow();
		w.setSize(400, 200);
		w.setLocation(500, 100);
		w.add(new JLabel("J oindo"));
		w.setVisible(true);
	}


	public void testDialog() {
	    JOptionPane.showMessageDialog(null, "un exemple de MessageDialog");
	    // la valeur de result dépend du choix fait :
	    int result = JOptionPane.showConfirmDialog(null,"un exemple de ConfirmDialog");
	    System.out.println("result vaut :"+result);
	}

	public static void main(String[] args) {
		Test t = new Test();


		t.testJFrame();
		t.testJWindow();
		t.testDialog();
	}




}
