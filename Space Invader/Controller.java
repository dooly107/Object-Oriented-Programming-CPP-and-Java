import java.awt.Graphics;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class Controller {
	public ArrayList<EntityA> ea = new ArrayList<EntityA>();
	public ArrayList<EntityB> eb = new ArrayList<EntityB>();
	public ArrayList<Barrier> barrierlist = new ArrayList<Barrier>();
	public ArrayList<Alien> alienlist = new ArrayList<Alien>();
	public int countCol;
	public int rb;
	
	public Game game;
	public Defender defender;
	public EntityA enta;
	public EntityB entb;
	public Alien alien;
	public Barrier barrier;
	private int xpos = 80;
	private int ypos = 500;
	//Take input from setting
	public Controller(Game game) {
		this.game = game;
		this.defender = new Defender(400,550,game,this);
		
		for (int a = 0; a < game.enemy_row; a++) {
			for (int b = 0; b < game.enemy_col; b++) {
				rb = 763 - (32 * (game.enemy_col));
				addAlien(new Alien(32 + 32 * b, 10 + 50 * a, game, a, b, rb, this));
			}
		}
		
		//Barrier 1
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				addBarrier(new Barrier(xpos,ypos,game,this));
				xpos = xpos + 20;
			}
			xpos = 80;
			ypos = ypos - 10;
		}
		//Barrier 2
		xpos = 350;
		ypos = 500;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				addBarrier(new Barrier(xpos,ypos,game,this));
				xpos = xpos + 20;
			}
			xpos = 350;
			ypos = ypos - 10;
		}
		
		//Barrier 3
		xpos = 600;
		ypos = 500;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				addBarrier(new Barrier(xpos,ypos,game,this));
				xpos = xpos + 20;
			}
			xpos = 600;
			ypos = ypos - 10;
		}
		
	}

	public void tick() {
		for (int i = 0; i < ea.size(); i++) {
			enta = ea.get(i);
			enta.tick();
		}
		for (int i = 0; i < eb.size(); i++) {
			entb = eb.get(i);
			entb.tick();
		}
		for (int i = 0; i < alienlist.size(); i++) {
			alien = alienlist.get(i);
			alien.tick();
		}
		
		for (int i = 0; i < barrierlist.size(); i++) {
			barrier = barrierlist.get(i);
			barrier.tick();
		}
		
		defender.tick();
	}
	
	public void render(Graphics g) {
		for (int i = 0; i < ea.size(); i++) {
			enta = ea.get(i);
			enta.render(g);
		}
		for (int i = 0; i < eb.size(); i++) {
			entb = eb.get(i);
			entb.render(g);
		}
		for (int i = 0; i < alienlist.size(); i++) {
			alien = alienlist.get(i);
			alien.render(g);
		}
		for (int i = 0; i < barrierlist.size(); i++) {
			barrier = barrierlist.get(i);
			barrier.render(g);
		}
		defender.render(g);
	}
	
	public void addBarrier(Barrier barrier) {
		barrierlist.add(barrier);
	}
	
	public void removeBarrier(Barrier barrier) {
		barrierlist.remove(barrier);
	}
	
	public void addAlien(Alien alien) {
		alienlist.add(alien);
	}
	
	public void removeAlien(Alien alien) {
		alienlist.remove(alien);
	}
	
	public void addEntity(EntityA object) {
		ea.add(object);
	}
	public void removeEntity(EntityA object) {
		ea.remove(object);
	}
	public void addEntity(EntityB object) {
		eb.add(object);
	}
	public void removeEntity(EntityB object) {
		eb.remove(object);
	}
	
	public ArrayList<EntityA> getEntityA() {
		return ea;
	}
	public ArrayList<EntityB> getEntityB() {
		return eb;
	}
	public ArrayList<Alien> getAlien() {
		return alienlist;
	}
}
