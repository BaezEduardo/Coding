package Java.ExamenProgra2;

import java.util.Enumeration;

public class Main {
    public static void main(String[] args) {
        Inventario tienda = new Inventario();

        // Agregando animales
        tienda.agregarAnimal(new Perro("Firulais", "Labrador", 3));
        tienda.agregarAnimal(new Gato("Michi", "Siames", 2));
        tienda.agregarAnimal(new Perro("Rex", "Pastor Alemán", 4));
        tienda.agregarAnimal(new Conejo("Bugs", "Angora", 1));

        // Imprimir todos los animales
        tienda.imprimirInventario();

        // Eliminar un animal
        System.out.println("\nEliminando a Michi...");
        tienda.eliminarAnimal("Michi");

        // Imprimir después de eliminar
        tienda.imprimirInventario();

        // Obtener y mostrar todos los perros
        System.out.println("\nPerros en la tienda:");
        Enumeration<Perro> perros = tienda.getPerros();
        while (perros.hasMoreElements()) {
            System.out.println(perros.nextElement());
        }
    }
}
