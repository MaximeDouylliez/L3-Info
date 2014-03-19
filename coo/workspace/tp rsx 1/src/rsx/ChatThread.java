package rsx;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class ChatThread 
{

	MulticastSocket s=null;
	DatagramPacket p=null;
	Scanner sc = new Scanner(System.in);
	String str=null,name=null;
	ThreadReceive thread;


	public ChatThread(String args[])
	{
	
		
		System.out.println("Votre pseudo ?\n");	
		name ="pseudo:"+ sc.nextLine();

		try {s = new MulticastSocket(/*ou port local spécifié*/ Integer.parseInt(args[1]) );
		} catch (IOException e) {}
		
		try{p = new DatagramPacket (name.getBytes(),name.length(),InetAddress.getByName(args[0]),Integer.parseInt(args[1]));	
		}catch (UnknownHostException e) {}
		
		thread = new ThreadReceive();
		thread.start();

		try
	      {
	        // pause
	        Thread.sleep(1000);
	      }
	      catch (InterruptedException ex) {}
		try {s.send(p);
		} catch (IOException e) {}	
while(thread.isAlive()) 
		{	
			str=null;
			System.out.println("Attente d'un message...: ");	
			str = sc.nextLine();
			try{p = new DatagramPacket (str.getBytes(),str.length(),InetAddress.getByName(args[0]),Integer.parseInt(args[1]));
			}catch (UnknownHostException e) {}

			try {s.send(p);
			} catch (IOException e) {}	

			try {Thread.sleep(100);
			} catch (InterruptedException e) {}
		}
		s.close();
	}	

	public static void main (String[] args)
	{
		new ChatThread(args);
	}




}
