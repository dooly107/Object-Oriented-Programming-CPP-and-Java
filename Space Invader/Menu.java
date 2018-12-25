import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;

public class Menu {
	Game game;
	public Menu(Game game) {
		this.game = game;
	}

	public void render(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		
		
		Font fnt0 = new Font("arial", Font.BOLD, 50);
		g.setFont(fnt0);
		g.setColor(Color.white);
		g.drawString("SPACE INVADER", 200, 100);
		
		Font fnt1 = new Font("arial", Font.BOLD, 30);
		g.setFont(fnt1);
		g.drawString("Number of Enemy Row: (q-)(w+)", 100, 200);
		g.drawString("Number of Enemy Column: (e-),(r+)", 100,250);
		g.drawString("Enemy Go Back Rate: (a-),(s+)", 100,300);
		g.drawString("Enemy Drop Down Rate: (d-),(f+)", 100, 350);
		g.drawString("Enemy Fire Rate: (z-),(x+)", 100, 400);
		g.drawString("Defender's Lives: (c-),(v+)", 100, 450);
		g.drawString(Integer.toString(game.enemy_row), 700, 200);
		g.drawString(Integer.toString(game.enemy_col), 700, 250);
		g.drawString(Double.toString(game.gbafrate), 700, 300);
		g.drawString(Integer.toString(game.droprate), 700, 350);
		g.drawString(Integer.toString(game.enemyfirerate), 700, 400);
		g.drawString(Integer.toString(game.lives), 700, 450);
		
		
		Font fnt2 = new Font("arial", Font.BOLD, 20);
		g.setFont(fnt2);
		g.drawString("Press enter to start game", 300, 550);

	}
	
	
}
