package aesCipher;
import java.io.*;
import java.util.*;
import java.security.*;
import javax.crypto.*;
import javax.crypto.spec.*;

public class aesCipher
{
	private static SecretKeySpec secretKey;
	private static byte[] key;
	
	public static void setKey(String myKey)
	{
		MessageDigest sha;
		try
		{
			key = myKey.getBytes("UTF-8");
			sha = MessageDigest.getInstance("SHA-1");
			key = sha.digest(key);
			key = Arrays.copyOf(key, 16);
			secretKey = new SecretKeySpec(key,"AES");
		}
		catch(NoSuchAlgorithmException e)
		{
			e.printStackTrace();
		}
		catch(UnsupportedEncodingException e)
		{
			e.printStackTrace();
		}
	}
	public static String encrypt(String strToEncrypt,String secret)
	{
		try
		{
			setKey(secret);
			Cipher c = Cipher.getInstance("AES/ECB/PKCS5Padding");
			c.init(Cipher.ENCRYPT_MODE, secretKey);
			return Base64.getEncoder().encodeToString(c.doFinal(strToEncrypt.getBytes()));
		}
		catch(NoSuchAlgorithmException e)
		{
			e.printStackTrace();
		}
		catch(BadPaddingException e)
		{
			e.printStackTrace();
		}
		catch(NoSuchPaddingException e)
		{
			e.printStackTrace();
		}
		catch(InvalidKeyException e)
		{
			e.printStackTrace();
		}
		catch(IllegalBlockSizeException e)
		{
			e.printStackTrace();
		}
		return strToEncrypt;
	}
	public static String decrypt(String strToDecrypt,String secret)
	{
		try
		{
			setKey(secret);
			Cipher c = Cipher.getInstance("AES/ECB/PKCS5Padding");
			c.init(Cipher.DECRYPT_MODE, secretKey);
			return new String(c.doFinal(Base64.getDecoder().decode(strToDecrypt)));
		}
		catch(NoSuchAlgorithmException e)
		{
			e.printStackTrace();
		}
		catch(BadPaddingException e)
		{
			e.printStackTrace();
		}
		catch(NoSuchPaddingException e)
		{
			e.printStackTrace();
		}
		catch(InvalidKeyException e)
		{
			e.printStackTrace();
		}
		catch(IllegalBlockSizeException e)
		{
			e.printStackTrace();
		}
		return strToDecrypt;
	}

	public static void main(String [] args)
	{
		final String SecretKey = "AnnaUniversity";
		String OriginalString = "www.annauniv.edu";
		String EncryptedString = aesCipher.encrypt(OriginalString,SecretKey);
		String DecryptedString = aesCipher.decrypt(EncryptedString,SecretKey);
		System.out.println("URL Encryption using AES Algorithm");
		System.out.println("Original String: "+OriginalString);
		System.out.println("Encrypted String: "+EncryptedString);
		System.out.println("Decrypted String: "+DecryptedString);
	}
}
