package counter;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class GraphicalCounter {

	protected Counter compteur;
	protected JTextField saisie;
	
	public GraphicalCounter(Counter cpt) {
			this.compteur = cpt;
	}
	
	private JButton init() {
		JButton ini = new JButton("Initialiser");
		ini.addActionListener(new InterneActionListenerCompteur());
		return ini;
	}

	private JButton increment() {
		JButton inc = new JButton("IncrM-CM-)menter");
		inc.addActionListener(new InterneActionListenerCompteur());
		return inc;
	}

	private JTextField saisie() {
		JTextField j = new JTextField(5);
		j.addActionListener(new InterneActionListenerCompteur());
		this.saisie = j;
		return j;
	}
	
	private JLabel affichage() {
		return new JLabel("Entrez un entier");
	}

	private JFrame frame() {
		JFrame f = new JFrame("" + this.compteur);
		f.addWindowListener(new FermeWindowEvent());
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
	
		panel1.setLayout(new FlowLayout());
		panel1.add(this.init());
		panel1.add(this.increment());
		
		panel2.setLayout(new FlowLayout());	
		panel2.add(this.affichage());
		panel2.add(this.saisie());
		
		
		f.add(panel1, BorderLayout.SOUTH);
		f.add(panel2, BorderLayout.NORTH);
		
		f.pack();
		f.setVisible(true);
		return f;
	}
	
  public static void main(String[] args) {
 
 			GraphicalCounter graph = null;
  	
  		if(args.length == 0)
  			afficheErreur();
  		
  		if(args[0].equals("simple")) {
  			graph = new GraphicalCounter(new SimpleCounter());
  		} else if(args[0].equals("modulaire")) {
  			if(args.length != 2)
  				afficheErreur();
  			int nb = Integer.parseInt(args[1]);
  			graph = new GraphicalCounter(new ModularCounter(nb));
  		} else if(args[0].equals("geometrique")) {
  			if(args.length != 2)
  				afficheErreur();
  			int nb = Integer.parseInt(args[1]);
  			graph = new GraphicalCounter(new CompteurGeometrique(nb));
  		} else {
  			afficheErreur();
  		}
  		
  		graph.frame();
  		
  		
/*  		GraphicalCounter graph = new GraphicalCounter(new SimpleCounter());
  		GraphicalCounter graph2 = new GraphicalCounter(new ModularCounter(7));
  		GraphicalCounter graph3 = new GraphicalCounter(new CompteurGeometrique(3));
  		
  		JFrame maFenetre = graph.frame();
	 		JFrame maFenetre2 = graph2.frame();
	 		JFrame maFenetre3 = graph3.frame();
  */}

	public static void afficheErreur() {
		System.out.println("Erreur \nUsage : java -jar compteur.jar [simple | modulaire X | geometrique X] oM-CM-9 X est un entier");
		System.exit(0);
	}


	private class InterneActionListenerCompteur implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			if(e.getActionCommand() == "IncrM-CM-)menter" ) {
				GraphicalCounter.this.compteur.increment();
				GraphicalCounter.this.saisie.setText(""+GraphicalCounter.this.compteur.getCurrentValue());
			}
			else if(e.getActionCommand() == "Initialiser" ) {
				GraphicalCounter.this.compteur.init(Integer.parseInt(GraphicalCounter.this.saisie.getText()));
			}
		}
	}

	private class FermeWindowEvent extends WindowAdapter {
		public void windowClosing(java.awt.event.WindowEvent e) {
			System.exit(0);
		}
	}  



