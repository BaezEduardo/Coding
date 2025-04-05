package Java.Actividad10;

import java.awt.*;
import javax.swing.*;
//import java.util.*;

public class Flowlayout {
    public static void main(String[] args) {
        JButton boton1 = new JButton("Hola");
        JToggleButton btn = new JToggleButton("Pulsado");
        
        JFrame marco = new JFrame();
        marco.setTitle("FlowLayout");
        marco.setSize(400, 300);
        marco.setLocationRelativeTo(null);
        marco.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        marco.setVisible(true);
        marco.setLayout(new FlowLayout());
        marco.add(boton1);
        marco.add(btn);
    }
}
