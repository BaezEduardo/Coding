package Java.ExaProgra2;

public class Main {
    public static void main(String[] args) {
        Figura rectangulo = new Rectangulo(10, 5);
        Figura circulo = new Circunferencia(7);
        Figura triangulo = new Triangulo(6, 8);

        System.out.println("Área del Rectángulo: " + rectangulo.calcularArea());
        System.out.println("Área de la Circunferencia: " + circulo.calcularArea());
        System.out.println("Área del Triángulo: " + triangulo.calcularArea());
    }
}
