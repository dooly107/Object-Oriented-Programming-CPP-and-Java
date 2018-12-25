import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Bullet extends GameObject implements EntityA {

	
	BufferedImage image;
	private Game game;
	private Controller c;
	private boolean shipshooting;
	
	public Bullet(double x, double y, Game game, Controller c, boolean shipshooting) throws IOException {
		super(x,y);
		this.game = game;
		this.c = c;
		this.shipshooting = shipshooting;

		try{
			image = ImageIO.read(new File("image/bullet_copy.png"));
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
		if (shipshooting == true) {
			y -= 5;
		}
		else {
			y += 5;
		}
	}
	
	public void render(Graphics g) {
		g.drawImage(image, (int) x, (int) y, null);
	}
	
	public Rectangle getBounds() {
		return new Rectangle ((int) x, (int) y, 32, 32);
	}
	
	
}
