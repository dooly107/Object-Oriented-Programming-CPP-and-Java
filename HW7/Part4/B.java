public class B {

   public B( ) { };

   void foo(short s, D d,  double df) {
      System.out.println("B:foo(short, B, double)");
   }

   void foo(short s, B b) {
      System.out.println("B:foo(short, B)");
   }

   void foo(short s) {
      System.out.println("B:foo(short)");
   }

   void foo(short s, B b, float f) {
      System.out.println("B:foo(short, B, float)");
   }

   void foo(int i, B b, float f) {
      System.out.println("B:foo(int, B, float)");
   }

   void foo(double d) {
      System.out.println("B:foo(double)");
   }

   void foo(short s, double d) {
      System.out.println("B:foo(short, double)");
   }

   public void caller( ) {

      char c = 0;
      short s = 1;
      int i = 2;
      float f = 0.0f;
      double df = 1.0;

      B b = new B( );
      D d = new D( );

//      foo(d, f);
//      foo(c, d, df);
      foo(s); 
      foo(i); 
   }
}
