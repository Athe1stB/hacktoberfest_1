import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Game extends Frame implements ActionListener {
	Panel p1;
	Panel p2;
	Button re;
	Button b[][] = new Button[3][3];
	int ar[][] = new int[3][3];
	Label l1;
	Label l2;
	Label l3;
	Label l4;
	int moves;
	private Component frame;
	Game() {
		super("9 Box-Puzzle ");
		moves = 1;
		JOptionPane.showMessageDialog(frame, "ABOUT\n\nThe 9-box puzzle is a sliding puzzle which consists of 3x3 grid of numbered\nsquares with one square missing. The squares are jumbled when the puzzle\nstart and the goal of this game is to unjumble the squares by only sliding a\nsquare into the empty space.\n\n", "9 Box-Puzzle", JOptionPane.PLAIN_MESSAGE);
		String name = JOptionPane.showInputDialog(null, "RULES\nTo move:  If there is an empty adjacent square next to a tile, a tile may be slid into the empty location.\nTo win:  The tiles must be moved back into their original positions, numbered 1 through 8.\n\nEnter your name: ", "9 Box-Puzzle", JOptionPane.QUESTION_MESSAGE);
		setVisible(true);
		setSize(500, 500);
		p1 = new Panel();
		p2 = new Panel();
		p2.setSize(500, 500);
		p2.setLayout(new GridLayout(3, 3, 4, 4));
		Color randomColor = new Color(200, 0, 0);
		p2.setBackground(randomColor);
		l1 = new Label("    ");
		Font f1 = new Font("Diag", Font.ROMAN_BASELINE, 18);
		setFont(f1);
		l2 = new Label("Moves:        ");
		l3 = new Label("Username:    ");
		l4 = new Label("    ");
		setLayout(new BorderLayout());
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				b[i][j] = new Button("  ");
				Font f2 = new Font("Diag", Font.BOLD, 40);
				b[i][j].setFont(f2);
				b[i][j].setForeground(Color.DARK_GRAY);
			}
		}
		rand();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			p2.add(b[i][j]);
		}
		re = new Button("New Game");
		re.setForeground(Color.BLACK);
		re.setBackground(Color.LIGHT_GRAY);
		p1.add(re);
		p1.add(l4);
		p1.add(l2);
		p1.add(l3);
		add(p1, BorderLayout.NORTH);
		add(p2, BorderLayout.CENTER);
		add(l1, BorderLayout.SOUTH);
		String data = l3.getText();
		data = data + name;
		l3.setText(data);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				b[i][j].addActionListener(this);
			}
		}
		re.addActionListener(this);
		addWindowListener(new myWindowAdapter());
	}


	class myWindowAdapter extends WindowAdapter {
		/*	public void windowClosing(WindowEvent we) 
                {
                        
			System.exit(0);
		}*/
		public void windowClosing(WindowEvent e) {
			int confirmed = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit the game?", "9 Box-Puzzle", JOptionPane.YES_NO_OPTION);

			if (confirmed == JOptionPane.YES_OPTION) {
				//dispose();
				System.exit(0);
			}
		}

	}


	public static void main(String s[]) {
		Game m = new Game();
	}


	public void actionPerformed(ActionEvent ae) {
		//	String data = l3.getText();
		//	l3.setText(data);
		if (ae.getSource() == re) {
			replay();
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (ae.getSource() == b[i][j]) {
					String str2 = new String("Moves: ");

					if (moves > 0) {
						str2 = str2 + moves;
						l2.setText(str2);

					}
					setcol();
					find(i, j);
					Color randomColor = new Color(173, 216, 230);
					b[i][j].setBackground(randomColor);
				}
			}
		}
		checkwin();

	}


	void replay() {
		moves = 1;
		rand();
		setcol();
		ar[2][2] = 9;
		b[2][2].setLabel(" ");
		l1.setText(" ");
		l2.setText("Moves:     ");
	}


	int checkwin() {
		int i, j, k = 1;
		int chk = 0;
		for (i = 0; i <= 2; i++) {
			for (j = 0; j <= 2; j++) {
				if (k == ar[i][j]) {
					chk++;
				}
				k++;
			}
		}
		if (chk == 9) {
			String str = new String("You Win!");
			str = str + " In Moves " + moves;
			l1.setText(str);
		}
		return 0;
	}


	int find(int i, int j) {
		int p, q, temp;
		String st1 = new String(" ");
		p = i;
		q = j;
		if (p - 1 >= 0) {
			p--;
			if (ar[p][q] == 9) {
				st1 = st1 + ar[i][j];
				b[p][q].setLabel(st1);
				b[i][j].setLabel(" ");
				ar[p][q] = ar[i][j];
				ar[i][j] = 9;
				moves++;
				return 0;
			}
		}
		p = i;
		q = j;
		if (p + 1 <= 2) {
			p++;
			if (ar[p][q] == 9) {
				st1 = st1 + ar[i][j];
				b[p][q].setLabel(st1);
				b[i][j].setLabel(" ");
				ar[p][q] = ar[i][j];
				ar[i][j] = 9;
				moves++;
				return 0;
			}
		}
		p = i;
		q = j;
		if (q - 1 >= 0) {
			q--;
			if (ar[p][q] == 9) {
				st1 = st1 + ar[i][j];
				b[p][q].setLabel(st1);
				b[i][j].setLabel(" ");
				moves++;
				ar[p][q] = ar[i][j];
				ar[i][j] = 9;
				return 0;
			}
		}
		p = i;
		q = j;
		if (q + 1 <= 2) {
			q++;
			if (ar[p][q] == 9) {
				st1 = st1 + ar[i][j];
				b[p][q].setLabel(st1);
				b[i][j].setLabel(" ");
				moves++;
				ar[p][q] = ar[i][j];
				ar[i][j] = 9;
				return 0;
			}
		}
		return 0;
	}
	void setcol() {
		for (int ii = 0; ii < 3; ii++) {
			for (int jj = 0; jj < 3; jj++) {
				Color randomColor = new Color(0, 153, 153);
				//    Color randomColor = new Color(65,105,225);
				b[ii][jj].setBackground(randomColor);

			}
		}
	}
	void rand() {
		int arr[] = new int[8];
		int k = 0, flag = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				flag = 0;
				int x = (int)(Math.random() * 8);
				x = x + 1;
				if (k == 0) {
					String str = new String(" ");
					str = str + x;
					b[i][j].setLabel(str);
					ar[0][0] = x;
					arr[k] = x;
					k++;
				} else if (k <= 7) {

					while (flag == 0) {
						int chk = 0;
						for (int a = 0; a < k; a++) {
							if (arr[a] != x) {
								chk++;
							} else a = 10;
						}
						if (k == chk) {
							String str = new String(" ");
							str = str + x;
							b[i][j].setLabel(str);
							arr[k] = x;
							ar[i][j] = x;
							k++;
							flag = 1;
						} else {
							x = (int)(Math.random() * 8);
							x = x + 1;
						}
					}
				}
				ar[2][2] = 9;
			}
		}
		setcol();

	}
}
