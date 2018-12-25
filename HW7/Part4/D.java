public class D extends B {

   void foo(float f) {
      System.out.println("D:foo(float)");
   }

   void foo(int i, B b, float f) {
      System.out.println("D:foo(int, B, float)");
   }

   void foo(short s, B b, float f) {
      System.out.println("D:foo(short, B, float)");
   }

   void foo(char c, D d) {
      System.out.println("D:foo(char, D)");
   }

   void foo(short s, double d) {
      System.out.println("D:foo(short, double)");
   }

   void foo(short s, B b) {
      System.out.println("D:foo(short, B)");
   }
}
