public class D extends B implements I {

   public D( ) { };

   public void foo(int j) {i = 5;}  // B 

   public void foo(short s, D d,  double df) {System.out.println("D foo(short, D, double)");}

   public void bar(short s, D d,  double df) {System.out.println("D bar(short, D, double)");}

   public void dPrint( ) {
      System.out.println("i: "+i+", s: "+s);
   }
}
