package example;

import titan.tech.java.titan;

public class example {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		titan.out("Hi");
		titan.newline();
		titan.outln("I build you");
		titan.newline();
		titan.out("I am ");
		titan.getusername();
		titan.newline();
		String test = titan.hostname2ip("www.google.com");
		titan.out("The IP of www.google.com is ");
		titan.out(test);
		titan.newline();
		titan.out(">>");
		String line = null;
		String test1 = titan.stringin(line);
		titan.newline();
		titan.out("You said " + test1);
		titan.newline();
		titan.system("ls");
		titan.system("dir");
		titan.getdate();
		titan.newline();
		titan.gettime();
		titan.newline();
		titan.getdateandtime();
	}

}
