package Java.ExamenProgra2;

import java.util.Enumeration;
import java.util.Vector;

public class Inventario {
    private static final int MAX_ANIMALES = 100;
    private Animal[] animales;
    private int contador;

    public Inventario() {
        animales = new Animal[MAX_ANIMALES];
        contador = 0;
    }

    public boolean agregarAnimal(Animal animal) {
        if (contador < MAX_ANIMALES) {
            animales[contador] = animal;
            contador++;
            return true;
        } else {
            System.out.println("Inventario lleno. No se puede agregar más animales.");
            return false;
        }
    }

    public boolean eliminarAnimal(String nombre) {
        for (int i = 0; i < contador; i++) {
            if (animales[i] != null && animales[i].getNombre().equalsIgnoreCase(nombre)) {
                for (int j = i; j < contador - 1; j++) {
                    animales[j] = animales[j + 1];
                }
                animales[contador - 1] = null;
                contador--;
                return true;
            }
        }
        System.out.println("Animal no encontrado.");
        return false;
    }

    public void imprimirInventario() {
        if (contador == 0) {
            System.out.println("El inventario está vacío.");
        } else {
            System.out.println("Inventario de la tienda:");
            for (int i = 0; i < contador; i++) {
                if (animales[i] != null) {
                    System.out.println(animales[i]);
                }
            }
        }
    }

    public Enumeration<Perro> getPerros() {
        Vector<Perro> perros = new Vector<>();
        for (int i = 0; i < contador; i++) {
            if (animales[i] instanceof Perro) {
                perros.add((Perro) animales[i]);
            }
        }
        return perros.elements();
    }
}
