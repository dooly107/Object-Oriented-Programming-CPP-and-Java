// This is the main class for HW7 Part2
// This program is filled with compile errors.
public class Main {

   public static void main(String[] args) {
      if (args.length != 0) {
         System.out.println("Usage: java Main");
         return;
      }

      Base b = new Base( );
      Derived d = new Derived( );

      b.f1( ); 
      d.f2( ); 
    }
}

