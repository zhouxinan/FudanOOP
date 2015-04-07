import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @ddescription
 * dict.txt contains a line of characters and end with a space. 
 * While the result.txt contains some integers. Each integer represents the
 * ith character in dict.txt. 
 * This program translate the result.txt to text according to dict.txt.  
 */
public class Translator {
	/* The name of source files */
	final static String resultName = "./result.txt";
	final static String dictName = "./dict.txt";
	
	public static void main(String[] args) {
		try {
			/* Get the dictionary */
			char[] dict = getDict();
			
			/* scan in the index and output the text */
			Scanner reader = new Scanner(new File(resultName));
			while(reader.hasNext()){
				int index = reader.nextInt();
				try{
					System.out.print(dict[index]);
				}catch(IndexOutOfBoundsException oe){
					/* An illegal integer in read, no corresponding character */
					System.err.println("\nERROR: Out of Bounds!");
				}
			}
		} catch (FileNotFoundException e) {
			System.err.println("ERROR: File not found!");
		}

	}

	/**
	 * @ddescription
	 * Read in the dict file and create the dictionary character array
	 * @return
	 * character array of dictionary
	 */
	private static char[] getDict() throws FileNotFoundException {
		Scanner dictScan = new Scanner(new File(dictName));
		String dictStr = dictScan.nextLine();
		dictScan.close();
		return dictStr.toCharArray();
	}
}
