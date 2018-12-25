import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.JFrame;


public class Game extends Canvas implements Runnable {
	private static final long serialVersionUID = 1L;
	//Variables
	public static final int WIDTH = 800;
	public static final int HEIGHT = 600;
	public static final int SCALE = 2;
	public final String GameTitle = "Space Invaders";
	
	private boolean running = false;
	private Thread thread;
	public boolean shipshooting = true;
	
	//userinput
	public int enemy_killed = 0;
	public int score = 0;
	public int enemy_row = 1;
	public int enemy_col = 1;
	public int enemy_count;
	public double gbafrate = 1.0;
	public int droprate = 20;
	public int enemyfirerate = 100;
	public int lives = 1;
	public AudioClip ShootingSoundDefender;
	public AudioClip ShootingSoundAlien;
	public AudioClip Background;

	private BufferedImage image = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_RGB);
	
	//private Defender defender;
	private Controller c;
	private Alien alien;
	private Menu menu;
	
	public ArrayList<EntityA> ea;
	public ArrayList<EntityB> eb;

	
	public enum STATE{
		MENU,
		GAME,
		END_VICTORY,
		END_LOSE
	};
	
	public STATE State = STATE.MENU;
	
	
	private void init() {
		ShootingSoundDefender = Applet.newAudioClip(getClass().getResource("music/defender_gun.wav"));
		ShootingSoundAlien = Applet.newAudioClip(getClass().getResource("music/alien_gun.wav"));
		Background = Applet.newAudioClip(getClass().getResource("music/background.wav"));
		
		addKeyListener(new KeyInput(this));
		menu = new Menu(this);
		Background.play();
	}

	
	private synchronized void start() {
		if (running) {
			return;
		}
		running = true;
		thread = new Thread(this);
		thread.start();
	}
	
	private synchronized void stop() {
		if (!running) {
			return;
		}
		running = false;
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.exit(1);
	}

	
	public void run() {
		init();
		long lastTime = System.nanoTime();
		final double amountofticks = 60.0;
		double ns = 1000000000 / amountofticks;
		double delta = 0;
		int updates = 0;
		int frame = 0;
		long timer = System.currentTimeMillis();
		while(running) {
			//GAME LOOP
			long now = System.nanoTime();
			delta += (now - lastTime) / ns;
			lastTime = now;
			if (delta >= 1) {
				tick();
				updates++;
				delta--;
			}
			render();
			frame++;
			
			if (System.currentTimeMillis() - timer > 1000) {
				timer += 1000;
				System.out.println(updates + " Ticks, Fps " + frame);
				updates = 0;
				frame = 0;
			}
			
		}
		stop();
	}

	private void tick() {
		if (State == STATE.GAME) {
			//defender.tick();
			c.tick();
		}
	}
	
	private void render() {
		BufferStrategy bs = this.getBufferStrategy();
		if (bs == null) {
			createBufferStrategy(3);
			return; 
		}
		Graphics g = bs.getDrawGraphics();
		///////////
		
		g.drawImage(image, 0, 0, getWidth(),getHeight(), this);

		
		if (State == STATE.GAME) {
			//defender.render(g);
			c.render(g);
			g.setColor(Color.white);
			Font fnt1 = new Font("arial", Font.BOLD, 12);
			g.setFont(fnt1);
			g.drawString("Score:", 10, 10);
			g.drawString(Integer.toString(score), 50, 10);
			g.drawString("Lives:", 700, 10);
			g.drawString(Integer.toString(lives), 750, 10);
			if (enemy_count == 0) {
				State = STATE.END_VICTORY;
			}
			if (lives == 0) {
				State = STATE.END_LOSE;
			}

		}else if (State == STATE.MENU) {
			menu.render(g);
		}else if (State == STATE.END_VICTORY) {
			g.setColor(Color.white);
			Font fnt1 = new Font("arial", Font.BOLD, 100);
			g.setFont(fnt1);
			g.drawString("VICTORY", 170, 300);
		}else if (State == STATE.END_LOSE) {
			g.setColor(Color.white);
			Font fnt1 = new Font("arial", Font.BOLD, 100);
			g.setFont(fnt1);
			g.drawString("YOU LOSE", 170, 300);
		}
		///////////
		g.dispose();
		bs.show();
	}
	
	//KEYBOARD INPUTS
	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		if (State == STATE.GAME) {
			if (key == KeyEvent.VK_RIGHT) {
				c.defender.setVelX(5);
			}
			else if (key == KeyEvent.VK_LEFT) {
				c.defender.setVelX(-5);
			}
			else if (key == KeyEvent.VK_SPACE) {
				ShootingSoundDefender.play();
				try {
					c.addEntity(new Bullet(c.defender.getX(), c.defender.getY(), this, c, shipshooting));
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}
		}
		else if (State == STATE.MENU) {
			if (key == KeyEvent.VK_Q) {
				enemy_row--;
				if (enemy_row < 1) {
					enemy_row = 1;
				}
			}
			else if (key == KeyEvent.VK_W) {
				enemy_row++;
				if (enemy_row > 8) {
					enemy_row = 8;
				}
			}
			else if (key == KeyEvent.VK_E) {
				enemy_col--;
				if (enemy_col < 1) {
					enemy_col = 1;
				}
			}
			else if (key == KeyEvent.VK_R) {
				enemy_col++;
				if (enemy_col > 20) {
					enemy_col = 20;
				}
			}
			else if (key == KeyEvent.VK_A) {
				gbafrate = gbafrate - 0.1;
				if (gbafrate < 0) {
					gbafrate = 0.0;
				}
			}
			else if (key == KeyEvent.VK_S) {
				gbafrate = gbafrate + 0.1;
				if (gbafrate > 2.0) {
					gbafrate = 2.0;
				}
				
			}
			else if (key == KeyEvent.VK_D) {
				droprate--;
				if (droprate < 10) {
					droprate = 10;
				}
			}
			else if (key == KeyEvent.VK_F) {
				droprate++;
				if (droprate > 40) {
					droprate = 40;
				}
			}
			else if (key == KeyEvent.VK_Z) {
				enemyfirerate = enemyfirerate - 100;
				if (enemyfirerate < 100) {
					enemyfirerate = 100;
				}
			}
			else if (key == KeyEvent.VK_X) {
				enemyfirerate = enemyfirerate + 100;
				if (enemyfirerate > 1000) {
					enemyfirerate = 1000;
				}
			}
			else if (key == KeyEvent.VK_C) {
				lives--;
				if (lives < 1) {
					lives = 1;
				}
			}
			else if (key == KeyEvent.VK_V) {
				lives++;
				if (lives > 10) {
					lives = 10;
				}
			}
			else if(key == KeyEvent.VK_ENTER) {
				//defender = new Defender(400,550,this,c);
				c = new Controller(this);
				ea = c.getEntityA();
				eb = c.getEntityB();
				enemy_count = enemy_row * enemy_col;
				State = STATE.GAME;
			}
		}
	}
	
	
	public void keyReleased(KeyEvent e) {
		int key = e.getKeyCode();
		if (key == KeyEvent.VK_RIGHT) {
			c.defender.setVelX(0);
		}
		else if (key == KeyEvent.VK_LEFT) {
			c.defender.setVelX(0);
		}
	}
	
	public int getEnemy_Killed() {
		return enemy_killed;
	}
	
	public void setEnemy_Killed(int enemy_killed) {
		this.enemy_killed = enemy_killed;
	}
	
	
	public static void main (String args[]) {
		Game game = new Game();

		game.setPreferredSize(new Dimension(800, 600));
		game.setMaximumSize(new Dimension(800, 600));
		game.setMinimumSize(new Dimension(800, 600));

		JFrame frame = new JFrame(game.GameTitle);
		frame.add(game);
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
		
		game.start();
	}
}