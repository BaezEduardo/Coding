package Java.Progra2;

public class Main {
    public static void main(String[] args) {
        Perro miPerro = new Perro();
        miPerro.nombre = "Bobby";
        miPerro.comer();  // Método de la clase base
        miPerro.ladrar(); // Método de la clase derivada
    }
}
