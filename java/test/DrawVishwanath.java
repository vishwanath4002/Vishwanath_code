import javax.swing.*;
import java.awt.*;

public class DrawVishwanath extends JPanel {
   
    // DDA Line Drawing Algorithm
    private void drawLine(Graphics g, int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = Math.max(Math.abs(dx), Math.abs(dy));

        float xInc = (float) dx / steps;
        float yInc = (float) dy / steps;

        float x = x1;
        float y = y1;
        for (int i = 0; i <= steps; i++) {
            g.fillRect(Math.round(x), Math.round(y), 2, 2); // Draw pixel
            x += xInc;
            y += yInc;
        }
    }


    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.BLACK);

        // Draw 'V'
        drawLine(g, 25, 50, 50, 150);
        drawLine(g, 50, 150, 75, 50);

        // Draw 'I'
        drawLine(g, 100, 50, 150, 50);
        drawLine(g, 125, 50, 125, 150);
        drawLine(g, 100, 150, 150, 150);

        // Draw 'S'
        drawLine(g, 175, 50, 225, 50);
        drawLine(g, 175, 50, 175, 100);
        drawLine(g, 175, 100, 225, 100);
        drawLine(g, 225, 100, 225, 150);
        drawLine(g, 175, 150, 225, 150);

        // Draw 'H'
        drawLine(g, 250, 50, 250, 150);
        drawLine(g, 300, 50, 300, 150);
        drawLine(g, 250, 100, 300, 100);
        
        // Draw 'W'
        drawLine(g, 325, 50, 350, 150);
        drawLine(g, 350, 150, 375, 50);
        drawLine(g, 375, 50, 400, 150);
        drawLine(g, 400, 150, 425, 50);
        
        // Draw 'A'
        drawLine(g, 450, 150, 475, 50);
        drawLine(g, 475, 50, 500, 150);
        drawLine(g, 460, 110, 490, 110);
        
        // Draw 'N'
        drawLine(g, 525, 50, 525, 150);
        drawLine(g, 525, 50, 575, 150);
        drawLine(g, 575, 50, 575, 150);
        
        // Draw 'A'
        drawLine(g, 600, 150, 625, 50);
        drawLine(g, 625, 50, 650, 150);
        drawLine(g, 610, 110, 640, 110);
        
        // Draw 'T'
        drawLine(g, 675, 50, 725, 50);
        drawLine(g, 700, 50, 700, 150);

        
        // Draw 'H'
        drawLine(g, 750, 50, 750, 150);
        drawLine(g, 750, 100, 800, 100);
        drawLine(g, 800, 50, 800, 150);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Draw VISHWANATH Using Bresenham Line Drawing Algorithm");
        DrawVishwanath panel = new DrawVishwanath();
        frame.add(panel);
        frame.setSize(825, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
