public class GeneraHiloM extends Thread{ 
   public void run()
   {
      try
   {    
      long time = (long)(Math.random()*2500);
      sleep(time);
      System.out.println("Esta es una instancia de nuestra clase: " + this.getName() + " " + time + "ms");
   }catch(InterruptedException ex){ 
      Thread.currentThread().interrupt();
   }
}
   
public static void main(String args[]){ 
   //Se generan 6 hilos
      GeneraHiloM gh1 = new GeneraHiloM(); 
      GeneraHiloM gh2 = new GeneraHiloM(); 
      GeneraHiloM gh3 = new GeneraHiloM(); 
      GeneraHiloM gh4 = new GeneraHiloM(); 
      GeneraHiloM gh5 = new GeneraHiloM(); 
      GeneraHiloM gh6 = new GeneraHiloM();
   
   //Se les asigna nombre 
      gh1.setName("Hilo1"); 
      gh2.setName("Hilo2"); 
      gh3.setName("Hilo3"); 
      gh4.setName("Hilo4"); 
      gh5.setName("Hilo5"); 
      gh6.setName("Hilo6");
   
   //Se "ejecutan" los hilos 
      gh1.start();
      gh2.start();
      gh3.start();
      gh4.start();
      gh5.start();
      gh6.start(); 
      System.out.println("Hilo Principal:" + Thread.currentThread().getName()); 
   }
}