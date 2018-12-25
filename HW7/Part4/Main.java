import java.io.*;

class Main {

   public static void main(String args[]) {
      char c = 0;
      short s = 1;
      int i = 2;
      float f = 0.0f;
      double df = 1.0;

      B b = new B( );
      D d = new D( );

      System.out.println("Direct calls");    
//      d.foo(d, f); //ERROR
//      d.foo(c, d, df); //ERROR
      d.foo(df); //B:foo(double)
      d.foo(i); //D:foo(float)
//      d.foo( ); //ERROR
//      d.foo(i, d, df); //ERROR
      d.foo(c, b, f); //D:foo(int, B, float)
      d.foo(f); //D:foo(float)
      d.foo(c); //D:foo(float)
      d.foo(s, d, df);  //B:foo(short, B, double)
//      d.foo(i, d); //ERROR

      System.out.println("b.caller");
      b.caller( ); //B:foo(short) B:foo(double)

   }
}
