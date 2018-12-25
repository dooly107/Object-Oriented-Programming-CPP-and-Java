public abstract class B {

   public B( ) { };

   public void foo(short s) {System.out.println("B foo(short)");};

   abstract void foo(short s, D d,  double df);

   abstract void bar(short s, D d,  double df);
}
