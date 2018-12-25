import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Bullet_Alien extends GameObject implements EntityB {
	BufferedImage image;
	Game game;
	Controller c;
		
	public Bullet_Alien(double x, double y, Game game, Controller c) throws IOException {
		super(x,y);
		this.game = game;
		this.c = c;
		try{
			image = ImageIO.read(new File("image/bullet_copy_alien.png"));
		} catch(IOException e) {
		}
	}
	
	public double getX() {
		return x;
	}
	
	public double getY() {
		return y;
	}
	
	public void tick() {
		y += 5;
	}
	
	public void render(Graphics g) {
		g.drawImage(image, (int) x, (int) y, null);
	}
	
	public Rectangle getBounds() {
		return new Rectangle ((int) x, (int) y, 32, 32);
	}
}