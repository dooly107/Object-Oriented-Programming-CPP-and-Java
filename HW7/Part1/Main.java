// This is the main class for HW7 Part1
// This assignment demonstrates inheritance, overriding, overloading and 
// polymorphism
//
// NOTE: Java assumes a number such as 1.0 is a double and it must be
// explicity cast to a float if a single precision floating point number
// is to be used in an expression.
public class Main {

   public static void main(String[] args) {
      if (args.length != 0) {
         System.out.println("Usage: java Main");
         return;
      }

      Base b = new Base( );
      Derived d = new Derived( );

      b.f1(1); // prints "Base f1(int)"
      b.f1( ); // prints "Base f1( )"

      d.f1(1); // prints "Base f1(int)"
      d.f1((float) 1.0); // prints "Derived f1(float)"
      d.f1( ); // prints "Base f1"

      b = d;
      b.f1(1); // prints "Base f1(int)"
      // b.f1((float) 1.0); // This is an error!
      b.f1( ); // prints "Base f1"

    }
}

