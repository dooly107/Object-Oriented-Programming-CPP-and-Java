import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;


public class Barrier implements EntityA{
	public int x;
	public int y;
	public int width = 40;
	public int height = 10;
	Game game;
	Controller c;
	
	public Barrier(int x, int y, Game game, Controller c) {
		this.x = x;
		this.y = y;
		this.game = game;
		this.c = c;
	}
	
	public void render(Graphics g) {
		g.setColor(Color.white);
		g.fillRect(x, y, width, height);
	}

	@Override
	public void tick() {
		// TODO Auto-generated method stub
		if (Logic.Collision(this, game.eb)) {
			c.removeEntity(Logic.collision_EB);
			c.removeBarrier(this);
		}
	}

	public Rectangle getBounds() {
		return new Rectangle ((int) x, (int) y, 40, 10);
	}

	@Override
	public double getX() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public double getY() {
		// TODO Auto-generated method stub
		return 0;
	}
}