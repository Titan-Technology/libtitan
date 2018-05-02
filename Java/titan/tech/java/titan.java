package titan.tech.java;

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.net.UnknownHostException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.text.DateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class titan{
	//Public Usable Functions and Variables
	public static void out(String output)
		{
			System.out.print(output);
		}
	public static void outln(String outputln)
		{
			System.out.println(outputln);
		}
	public static String stringin(String in)
		{
			Scanner reader = new Scanner(System.in);
			in = reader.nextLine();
			reader.close();
			return in;
		}
	public static void newline()
		{
			System.out.println(" ");
		}
	public static int intin(int in)
		{
			Scanner reader = new Scanner(System.in);
			in = reader.nextInt();
			reader.close();
			return in;
		}
	public static void add2file(String filename,String contents) 
		{
			BufferedWriter bw = null;
			FileWriter fw = null;
			try 
				{
					File file = new File(filename);
					if (!file.exists()) 
						{
							file.createNewFile();
						}
					fw = new FileWriter(file.getAbsoluteFile(), true);
					bw = new BufferedWriter(fw);
					bw.write(contents);
				} 
			catch(IOException e) 
				{
					e.printStackTrace();
				} 
			finally 
				{
					try 
						{
							if (bw != null)
								bw.close();
							if (fw != null)
								fw.close();
						} 
					catch(IOException ex) 
						{
							ex.printStackTrace();
						}
				}
		}
	public static void writefile(String filename,String contents) 
		{
			BufferedWriter bw = null;
			FileWriter fw = null;
			try 
				{
					fw = new FileWriter(filename);
					bw = new BufferedWriter(fw);
					bw.write(contents);
				} 
			catch(IOException e) 
				{
					e.printStackTrace();
				} 
			finally 
				{
					try 
						{
						if (bw != null)
							bw.close();
						if (fw != null)
							fw.close();
						} 
					catch(IOException ex) 
						{
							ex.printStackTrace();
						}
				}

		}
	public static void readfile(String filename) 
		{
			BufferedReader br = null;
			FileReader fr = null;
			try 
				{
					fr = new FileReader(filename);
					br = new BufferedReader(fr);
					String sCurrentLine;
					while ((sCurrentLine = br.readLine()) != null) 
						{
							System.out.println(sCurrentLine);
						}
				} 
			catch(IOException e) 
				{
					e.printStackTrace();
				} 
			finally 
				{
					try
						{
							if (br != null)
								br.close();

							if (fr != null)
								fr.close();
						} 
					catch(IOException ex) 
						{
							ex.printStackTrace();
						}

				}	

		}
	 public static void gettime() 
	 	{
	        Calendar cal = Calendar.getInstance();
	        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
	        System.out.print(sdf.format(cal.getTime()));
	    }
	 public static void getdate()
	 	{
		 	LocalDate localDate = LocalDate.now();
	        System.out.print(DateTimeFormatter.ofPattern("yyy/MM/dd").format(localDate));
	 	}
	 public static void getdateandtime()
	 	{
		 	Calendar cal = Calendar.getInstance();
	        System.out.print(sdf.format(cal.getTime()));
	 	}
	public static void system(String cmd)
		{
			titan obj = new titan();
			String output = obj.executeCommand(cmd);
			System.out.println(output);
		}
	public static void getusername()
		{
			System.out.print(System.getProperty("user.name"));
		}
	public static String hostname2ip(String hostname)
		{           
			InetAddress address = null;
			try
				{
					address = InetAddress.getByName(hostname);
				}
			catch(UnknownHostException e)
				{
					System.exit(2);
				}
			String IP = address.getHostAddress();
			return IP;
		}
	 public static void sleep(int time) throws InterruptedException 
	 	{
	            Thread.sleep(time);
	    }
	//Private Library Functions and voids
    private static final DateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	private String executeCommand(String command)
		{
			StringBuffer output = new StringBuffer();
			Process p;
			try
				{
					p = Runtime.getRuntime().exec(command);
					p.waitFor();
					BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()));
					String line = "";			
					while((line = reader.readLine())!= null)
						{
							output.append(line + "\n");
						}
				}
			catch(Exception e)
				{
					e.printStackTrace();
				}
			return output.toString();
		}
}