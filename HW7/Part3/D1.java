public class D1 extends B {

   public D1( ) { }

   public static void f1( ) {System.out.println("D1 f1");}
   public void f3( ) {System.out.println("D1 f3");}
   private static void f4( ) {System.out.println("D1 f4");}

   public void f5( ) {System.out.println("D1 f5");}
   private void f6( ) {System.out.println("D1 f6");}

   public void d1Caller( ) {f1( ); f3( ); f4( ); f5( ); f6( );}
}

