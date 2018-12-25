import java.util.ArrayList;

public class Logic {
	public static EntityA collision_EA = null;
	public static EntityB collision_EB = null;
	public static Alien collision_Alien = null;
	public static Barrier collision_Barrier = null;
	
	public static boolean Collision(EntityB entb, Defender defender) {
		if (entb.getBounds().intersects(defender.getBounds())) {
			return true;
		}
		return false;
	}
	
	
	public static boolean Collision(EntityA enta, ArrayList<EntityB> entb) {
		for (int i = 0; i < entb.size(); i++) {
			
			if (enta.getBounds().intersects(entb.get(i).getBounds())) {
				collision_EB = entb.get(i);
				return true;
			}
			 
		}
		return false;
	}
	 
	public static boolean Collision(EntityB entb, ArrayList<EntityA> enta) {
		for (int i = 0; i < enta.size(); i++) {
			 
			if (entb.getBounds().intersects(enta.get(i).getBounds())) {
				collision_EA = enta.get(i);
				return true;
			}
			 
		}
		return false;
	}
	
	public static boolean Collision(Alien alien, ArrayList<EntityA> enta) {
		for (int i = 0; i < enta.size(); i++) {
			
			if (alien.getBounds().intersects(enta.get(i).getBounds())) {
				collision_EA = enta.get(i);
				return true;
			}
			 
		}
		return false;
	}
}
