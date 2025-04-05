import javax.swing.*;
import java.awt.*;

public class Main{
    public static void main(String[] args) {
        JFrame frame = new JFrame("Ejemplo de Componentes en Java");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 500);
        frame.setLayout(new BorderLayout());

        // PANEL PRINCIPAL
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2, 10, 10));

        // Etiqueta (JLabel)
        JLabel etiqueta = new JLabel("Etiqueta: Nombre:");
        panel.add(etiqueta);

        // Campo de texto (JTextField)
        JTextField campoTexto = new JTextField();
        panel.add(campoTexto);

        // Boton (JButton)
        JButton boton = new JButton("Enviar");
        panel.add(boton);

        // Casilla de verificación (JCheckBox)
        JCheckBox checkBox = new JCheckBox("Estas de acuerdo?");
        panel.add(checkBox);

        // Botones de opcion (JRadioButton con ButtonGroup)
        JRadioButton opcion1 = new JRadioButton("Opción 1");
        JRadioButton opcion2 = new JRadioButton("Opción 2");
        ButtonGroup grupoBotones = new ButtonGroup();
        grupoBotones.add(opcion1);
        grupoBotones.add(opcion2);
        panel.add(opcion1);
        panel.add(opcion2);

        // Lista desplegable (JComboBox)
        String[] opciones = {"Seleccionar", "Java", "Python", "C++"};
        JComboBox<String> comboBox = new JComboBox<>(opciones);
        panel.add(comboBox);

        // area de texto
        JTextArea areaTexto = new JTextArea(5, 20);
        JScrollPane scrollArea = new JScrollPane(areaTexto);
        panel.add(scrollArea);

        // Lienzo (Canvas)
        Canvas lienzo = new Canvas() {
            public void paint(Graphics g) {
                g.setColor(Color.RED);
                g.fillOval(20, 20, 50, 50);
            }
        };
        lienzo.setSize(100, 100);
        panel.add(lienzo);

        // Barra de desplazamiento (JScrollBar)
        JScrollBar barraDesplazamiento = new JScrollBar(JScrollBar.HORIZONTAL);
        panel.add(barraDesplazamiento);

        // Menu (JMenuBar, JMenu, JMenuItem)
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Opciones");
        JMenuItem item1 = new JMenuItem("Abrir");
        JMenuItem item2 = new JMenuItem("Guardar");
        menu.add(item1);
        menu.add(item2);
        menuBar.add(menu);
        frame.setJMenuBar(menuBar);

        // Agregar panel al frame
        frame.add(panel, BorderLayout.CENTER);

        // Mostrar ventana
        frame.setVisible(true);
    }
}
