package Java.Actividad10;

import java.awt.*;
import javax.swing.*;

public class Cardlayout {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Ejemplo de CardLayout");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        // Crear el panel con CardLayout
        JPanel cardPanel = new JPanel();
        CardLayout cardLayout = new CardLayout();
        cardPanel.setLayout(cardLayout);

        // Crear las "tarjetas"
        JPanel card1 = new JPanel();
        card1.add(new JLabel("Tarjeta 1"));
        JButton next1 = new JButton("Siguiente");
        card1.add(next1);

        JPanel card2 = new JPanel();
        card2.add(new JLabel("Tarjeta 2"));
        JButton next2 = new JButton("Siguiente");
        JButton prev2 = new JButton("Anterior");
        card2.add(prev2);
        card2.add(next2);

        JPanel card3 = new JPanel();
        card3.add(new JLabel("Tarjeta 3"));
        JButton prev3 = new JButton("Anterior");
        card3.add(prev3);

        // Agregar tarjetas al panel
        cardPanel.add(card1, "1");
        cardPanel.add(card2, "2");
        cardPanel.add(card3, "3");

        // Eventos para cambiar de tarjeta
        next1.addActionListener(e -> cardLayout.show(cardPanel, "2"));
        next2.addActionListener(e -> cardLayout.show(cardPanel, "3"));
        prev2.addActionListener(e -> cardLayout.show(cardPanel, "1"));
        prev3.addActionListener(e -> cardLayout.show(cardPanel, "2"));

        // Agregar el panel de tarjetas al frame
        frame.add(cardPanel);
        frame.setVisible(true);
    }
}
