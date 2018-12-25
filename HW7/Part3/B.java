public class B {

   public B( ) { }

   public static void f1( ) {System.out.println("B f1");}
   private static void f2( ) {System.out.println("B f2");}
   public void f3( ) {System.out.println("B f3");}
   private static void f4( ) {System.out.println("B f4");}

   public void bCaller( ) {f1( ); f2( ); f3( ); f4( );}
}

