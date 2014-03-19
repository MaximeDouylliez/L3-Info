package counter;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class GraphicalCounter {
	protected Counter counter;
	private JFrame frame;
	private JButton init;
	private JButton increment;
	private JTextField saisie;
	private JLabel affichage;
	
	public GraphicalCounter(Counter c) {
		this.counter = c;
		this.init();
		this.increment();
		this.affichage();
		this.textField();
		this.frame();
	}
	
	private void init() {
		this.init = new JButton("Init");
		this.init.addActionListener(new InitActionListener());
	}
	
	private void increment() {
		this.increment = new JButton("Increment");
		this.increment.addActionListener(new IncActionListener());
	}
	
	private void textField() {
		this.saisie = new JTextField("0");
		this.saisie.setPreferredSize(new Dimension(100, 50));
	}
	
	private void affichage() {
		this.affichage = new JLabel("0");
	}
	
	private void frame() {
	this.frame = new JFrame(""+this.counter);
	this.frame.setSize(300,100);
	this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	this.frame.setLocationRelativeTo(null);
	this.frame.setResizable(false);
	
	JPanel pan1 = new JPanel();
	JPanel pan2 = new JPanel();
		
	pan1.setLayout(new FlowLayout());
	pan1.add(this.init);
	pan1.add(this.increment);
	
	pan2.setLayout(new FlowLayout());
	pan2.add(this.affichage);
	pan2.add(this.saisie);
	
	this.frame.add(pan1, BorderLayout.SOUTH);
	this.frame.add(pan2, BorderLayout.NORTH);
	//this.frame.pack();
	this.frame.setVisible(true);
	}
	
	public static void main(String[] args) {
		GraphicalCounter a = new GraphicalCounter(new SimpleCounter(4));
		GraphicalCounter b = new GraphicalCounter(new ModularCounter(20));
		GraphicalCounter c = new GraphicalCounter(new CompteurGeometrique(78));
		
		a.frame.setLocation(375, 475);
		b.frame.setLocation(1500,475);
		c.frame.setLocation(1000, 475);
		
	}
	
	private class InitActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			counter.init(Integer.parseInt(saisie.getText()));
			affichage.setText(""+saisie.getText());
		}
	}
	
	private class IncActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			counter.increment();
			affichage.setText(""+counter.getCurrentValue());
		}
	}
}