package Java.ExaProgra23;

public class Main {
    public static void main(String[] args) {
        Perro perro = new Perro("Rex", "Carnívoro", 5, 2, "Labrador");
        Gato gato = new Gato("Milo", "Omnívoro", 3, 2, "Siamés");
        Caballo caballo = new Caballo("Spirit", "Herbívoro", 8, 11, "Heno", 3);

        System.out.println("Información del Perro:");
        perro.mostrarInformacion();

        System.out.println("\nInformación del Gato:");
        gato.mostrarInformacion();

        System.out.println("\nInformación del Caballo:");
        caballo.mostrarInformacion();
    }
}
