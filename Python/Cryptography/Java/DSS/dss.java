package dss;
import java.security.*;
import java.util.*;

public class dss
{
	public static void main(String [] args) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter any message : ");
		String msg = sc.nextLine();
		sc.close();
		
		KeyPairGenerator kpg = KeyPairGenerator.getInstance("DSA");
		kpg.initialize(2048);
		
		KeyPair kp = kpg.generateKeyPair();
		
		PrivateKey pk = kp.getPrivate();
		
		Signature sign = Signature.getInstance("SHA256withDSA");
		sign.initSign(pk);
		
		byte[] text = msg.getBytes();
	    sign.update(text);
	    
	    byte[] signature = sign.sign();
	    
	    System.out.println("Digital Signature for given message = "+ new String(signature,"UTF8"));
	}
}
