public class Main {

   public static void main(String[] args) {

      B b = new B( );
      D1 d1 = new D1( );
      D2 d2 = new D2( );
/*
      System.out.println("Base and b calls");
      B.f1( ); //B f1
      b.f1( ); //B f1
      b.f3( ); 
      b.bCaller( ); //B f1 B f2 B f3 B f4
      System.out.println(" ");

      System.out.println("D1 and d1 calls");
      D1.f1( ); //D1 f1
      d1.f1( ); //D1 f1
      d1.f3( ); //D1 f3
      d1.f5( ); //D1 f5
      d1.d1Caller( ); //D1 f1 D1 f3 D1 f3 D1 f5 D1 f6
      System.out.println(" ");
     
      System.out.println("d1.bCaller");
      d1.bCaller( ); //B f1 B f2 D1 f3 B f4
      System.out.println(" ");
*/
      System.out.println("D2 and d2 calls");
//      D2.f1( ); //D2 f1
//      d2.f1( ); //D2 f1
//      d2.f3( ); //D2 f3
//      d2.f5( ); //D2 f5
//      d2.f7( ); //D2 f7
      d2.d2Caller( ); //D2 f1 D2 f3 D2 f4 D2 f5 D2 f7
      System.out.println(" ");

    }
}

