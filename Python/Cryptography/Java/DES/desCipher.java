package desCipher;
import java.security.*;
import javax.crypto.*;
public class desCipher
{
	public static void main(String [] argv)
	{
		try 
		{
			System.out.println("DES ALgorithm Encryption");
			KeyGenerator kg = KeyGenerator.getInstance("DES");
			SecretKey sk = kg.generateKey();
			Cipher des;
			des = Cipher.getInstance("DES/ECB/PKCS5Padding");
			des.init(Cipher.ENCRYPT_MODE, sk);
			byte [] text = "SecretInformation".getBytes();
			System.out.println("Message[ByteFormat]: "+ text);
			System.out.println("Message:"+new String(text));
			byte [] textEncrypted = des.doFinal(text);
			System.out.println("Encrypted Message: "+textEncrypted);
			des.init(Cipher.DECRYPT_MODE, sk);
			byte [] textDecrypted = des.doFinal(textEncrypted);
			System.out.println("Decrypted Message: "+textDecrypted);
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
	}
}
