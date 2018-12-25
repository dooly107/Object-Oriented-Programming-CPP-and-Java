import java.io.*;

class Main {

   public static void main(String args[]) {

      D d = new D( );

      d.foo((short) 1);

      d.foo(1);

      d.foo((short) 1, d, 1.0); 

      d.bar((short) 1, d, 1.0); 

      d.dPrint( );
   }
}
