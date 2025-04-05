package Java.Actividad10;

import javax.swing.*;
import java.awt.*;

public class Gridbaglayout {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Ejemplo de GridBagLayout");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        // Usamos GridBagLayout
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        // Configuración de GridBagConstraints
        gbc.fill = GridBagConstraints.BOTH;  // Expandir en ambas direcciones
        gbc.insets = new Insets(5, 5, 5, 5); // Márgenes entre componentes

        // Botón 1 ocupa 2 columnas
        gbc.gridx = 0; gbc.gridy = 0; // Posición (0,0)
        gbc.gridwidth = 2; // Ocupa 2 columnas
        panel.add(new JButton("Botón 1"), gbc);

        // Botón 2
        gbc.gridx = 2; gbc.gridy = 0; 
        gbc.gridwidth = 1; // Ocupa 1 columna
        panel.add(new JButton("Botón 2"), gbc);

        // Botón 3
        gbc.gridx = 0; gbc.gridy = 1;
        panel.add(new JButton("Botón 3"), gbc);

        // Botón 4 ocupa 2 columnas
        gbc.gridx = 1; gbc.gridy = 1;
        gbc.gridwidth = 2;
        panel.add(new JButton("Botón 4"), gbc);

        frame.add(panel);
        frame.setVisible(true);
    }
}