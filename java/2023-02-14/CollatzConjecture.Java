import java.math.BigInteger;
import java.util.Scanner;

public class CollatzConjecture {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //Create scanner
        Collatz c = new Collatz();//Create new collatz object

        try { //Beginning of code section that's to be monitored for exceptions
            while (true) {
                BigInteger num = input.nextBigInteger(); //Read bigint
                if (num.compareTo(BigInteger.ONE) < 0) { //Checks if num is 0 or less
                    input.close();
                    break;
                }
                c.calculateCollatz(num);
                System.out.println(); //Newline after the sequence
            }
        } catch(Exception e) { //End of monitored code & action if exception is detected
            System.out.println("Invalid value entered. Exiting program.");
			input.close();
        }
    }
}

class Collatz {
    private final BigInteger two = BigInteger.valueOf(2);//Variable to store 2 as a bigint
    public Collatz() { //Initialize empty constructor

    }
    public void calculateCollatz(BigInteger num){
        BigInteger remainder; //Remainder for calculations
        System.out.print(num + " "); //Print first number in collatz sequence
        while(num.compareTo(BigInteger.ONE) != 0) { //While num isnt equal to 1 (compareTo returns 0, if values are equal)
            remainder = num.remainder(two); //Finds remainder of num mod 2
            if(remainder.compareTo(BigInteger.ZERO) == 0) { //Checks if remainder == 0
                num = num.divide(two);
                System.out.print(num + " ");
            } else {
                num = num.multiply(BigInteger.valueOf(3));
                num = num.add(BigInteger.ONE);
                System.out.print(num + " ");
            }
        }
    }
}
