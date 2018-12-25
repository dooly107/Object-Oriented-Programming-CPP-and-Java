import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Defender extends GameObject implements EntityA{
	
	public double velX = 0;
	
	public BufferedImage player;
	Game game;
	Controller c;
	
	public Defender(double x, double y, Game game, Controller c) {
		super(x,y);
		this.game = game;
		this.c = c;

		try{
			player = ImageIO.read(new File("image/ship_copy.png"));
		} catch(IOException e) {
		}
	}
	
	public void tick() {
		x += velX;
		
		if (x <= 0) {
			x = 0;
		}
		if (x >= 768) {
			x = 768;
		}
		
		if(Logic.Collision(this, game.eb)) {
			c.removeEntity(Logic.collision_EB);
			game.lives--;
		}
	}
	
	public void render(Graphics g) {
		g.drawImage(player, (int)x, (int)y, null);
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
	
	public void setVelX(double velX) {
		this.velX = velX;
	}
	
	public Rectangle getBounds() {
		return new Rectangle ((int) x, (int) y, 32, 32);
	}
}
