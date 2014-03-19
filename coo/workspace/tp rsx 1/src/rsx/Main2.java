package rsx;
import java.io.*;
import java.net.MulticastSocket;
import java.net.DatagramPacket;
import java.net.UnknownHostException;
import java.net.*;

public class Main2 {

	
	

	public static void main(String[] args){
	MulticastSocket s=null;
	DatagramPacket p=null;


		try {
			try {
				p = new DatagramPacket (args[2].getBytes(),args[2].getBytes().length,InetAddress.getByName(args[0]),Integer.parseInt(args[1]));
			} catch (UnknownHostException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			s = new MulticastSocket(/*ou port local spécifié*/ Integer.parseInt(args[1]) );
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			s.send(p);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		s.close();
		

		
}
}
