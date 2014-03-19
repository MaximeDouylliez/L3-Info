package rsx;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.MulticastSocket;
import java.util.HashMap;
	

	public class ThreadReceive extends Thread {
		MulticastSocket s=null;
		DatagramPacket p=null;
		byte[] tab;
		String t,pseudo,na;
		HashMap<String,String> map;
		

		public void run(String o) 
		{
			
		
		    	map=new HashMap<String,String>();	    	
		    	try
		    	{		    		
		    		s = new MulticastSocket(/*port*/ 7654 );
		    	} catch (IOException e1) {}
		    	p = new DatagramPacket(/*buffer*/ new byte[512],512);
		    	

		    while(true)
		    {
		    	try
		    	{
		    		p = new DatagramPacket(/*buffer*/ new byte[512],512);
		    		System.out.println("reception");
		    		s.receive(p);
		    	} catch (IOException e) {}
		    	
		    	tab =p.getData(); 
		    	//System.out.println("paquet reçu de : "+ p.getAddress()+" port "+p.getPort()+" taille" +p.getLength());
		    	t=new String(tab);
		 
		    	if(t.matches("pseudo:(.)*"))		
		    		map.put(p.getAddress().toString(),t.substring(7));
		    	
		    	else
		    	{
		    		pseudo=map.get(p.getAddress().toString());			    
		    		System.out.println("message de: "+pseudo);
		    	
		    	
		    	}
		    	
		    	
		    	
		    	 
		    }
		 
		 }    
	}
	



