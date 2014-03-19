package rsx;
import java.io.*;
import java.net.MulticastSocket;
import java.net.DatagramPacket;
public class Main {

	// numero 224.0.0.1
	//7654
	// la premiere fois que tu te connecte tu envoi un message mette a a fin "pseudo:@pseudo"
	// les pc qui recoive le pseudo envoye le leur s'il n'est pas référencé puis le reference

	public static void main(String[] args){
	MulticastSocket s=null;
	DatagramPacket p=null;
	byte[] tab;
	String t;
	try {
	
		s = new MulticastSocket(/*port*/ Integer.parseInt(args[1]) );
	} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();
	}
	p = new DatagramPacket(/*buffer*/ new byte[512],512);

while(true){
	try {
		System.out.println("debut de l'écoute");
		s.receive(p);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	tab =p.getData();
	System.out.println("paquet reçu de :"+ p.getAddress()+
	"port "+
	p.getPort()+
	"taille" +
	p.getLength());
	t=new String(tab);
	System.out.println("\n valeur :"+ t);
	}
	
	}
}
