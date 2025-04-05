package Java.Actividad10;

import java.awt.*;
import javax.swing.*;

public class Borderlayout{
 
    public static void main(String[] args) {
        JButton norte = new JButton("Boton 1 (PÁGINA_INICIO)");
        JButton oeste = new JButton("Boton 2 (LÍNEA_INICIO)");
        JButton centro = new JButton("Boton 3 (CENTRO)");
        JButton este = new JButton("Boton 4 (LÍNEA_FIN)");
        JButton sur = new JButton("Boton 5 (PÁGINA_FIN)");
       
        JFrame marco = new JFrame();
        marco.setTitle("BorderLayout");
        marco.setSize(500,250);
        marco.setLocationRelativeTo(null);
        marco.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        marco.setVisible(true);
       
        marco.setLayout(new BorderLayout(10, 60) );
       
        marco.add(norte, BorderLayout.NORTH);
        marco.add(oeste, BorderLayout.WEST);
        marco.add(centro, BorderLayout.CENTER);
        marco.add(este, BorderLayout.EAST);
        marco.add(sur, BorderLayout.SOUTH);
    }
}
