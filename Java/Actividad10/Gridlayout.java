package Java.Actividad10;

import javax.swing.*;
import java.awt.*;

public class Gridlayout {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Ejemplo de GridLayout");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);

        // Crear un panel con GridLayout (3 filas, 3 columnas)
        JPanel panel = new JPanel(new GridLayout(3, 3, 10, 10)); // Espaciado de 10px

        // Agregar botones al panel
        for (int i = 1; i <= 9; i++) {
            panel.add(new JButton("Botón " + i));
        }

        // Agregar el panel al frame
        frame.add(panel);
        frame.setVisible(true);
    }
}
