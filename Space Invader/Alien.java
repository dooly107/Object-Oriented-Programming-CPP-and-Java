import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Random;

import javax.imageio.ImageIO;

public class Alien implements EntityB {
	public double x;
	public double y;
	public Game game;
	public BufferedImage alien;
	public double initialx;
	public double initialy;
	public int countCol;
	public int countRow;
	public boolean frontshoot;
	public int gbafrate;
	public int delay = 0;
	public double dx = 1;
	public double dy = 0;
	public int rb;
	public Controller c;
	public double rate;
	public int count = 0;
	public int delay2 = 0;
	public int possibility;
	
	
	public Alien(double x, double y, Game game,int countRow, int countCol, int rb, Controller c){
		this.initialx = x;
		this.initialy = y;
		this.x = x;
		this.y = y;
		this.game = game;
		this.countCol = countCol;
		this.countRow = countRow;
		this.rb = rb;
		this.c = c;
		if (countRow != (game.enemy_row - 1)) {
			this.frontshoot = false;
		}
		else {
			this.frontshoot = true;
		}
		try{
			alien = ImageIO.read(new File("image/alien_copy.png"));
		} catch(IOException e) {
		}
	}
	
	public void alien_shoot() {
		try {
			c.addEntity(new Bullet_Alien(x, y, game, c));
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	
	@SuppressWarnings("static-access")
	public void tick() {
		possibility = (int) (Math.random() * game.enemyfirerate);
		
		if (this.possibility == 32 && this.frontshoot == true) {
			alien_shoot();
			game.ShootingSoundAlien.play();
		}
		
		rate = game.gbafrate;
		if (x <= (initialx - 5)) {
			count++;
			dx = 1 + (rate * count);
			dy = game.droprate;
		}
		else if (x >= (initialx + rb)) {
			count++;
			dx = -1 - (rate * count);
			dy = game.droprate;
		}
		else {
			dy = 0;
		}
		delay++;
		if (delay == 1) {
			delay = 0;
			x = x + dx;
			y = y + dy;
		}
		
		if (Logic.Collision(this, c.defender)) {
			c.removeAlien(this);
			game.lives--;
		}
		
		if(Logic.Collision(this, game.ea)) {
			for (int i = 0; i < c.getAlien().size(); i++) {
				if ((c.getAlien().get(i).countCol == this.countCol) && (c.getAlien().get(i).countRow == this.countRow - 1)) {
					c.getAlien().get(i).frontshoot = true;
					break;
				}
			}
			c.removeAlien(this);
			c.removeEntity(Logic.collision_EA);
			game.setEnemy_Killed(game.getEnemy_Killed() + 1);
			game.score += 100;
			game.enemy_count--;
		}
	}
	
	public void render(Graphics g) {
		g.drawImage(alien, (int)x, (int)y, null);
	}
	
	public double getX() {
		return x;
	}
	
	public void setX(double x) {
		this.x = x;
	}
	
	public double getY() {
		return y;
	}
	
	public void setY(double x) {
		this.y = y;
	}
	
	public Rectangle getBounds() {
		return new Rectangle ((int) x, (int) y, 32, 32);
	}
}
