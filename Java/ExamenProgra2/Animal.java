package Java.ExamenProgra2;

public abstract class Animal {
    protected String nombre;
    protected String raza;
    protected int edad;

    public Animal(String nombre, String raza, int edad) {
        this.nombre = nombre;
        this.raza = raza;
        this.edad = edad;
    }

    public String getNombre() {
        return nombre;
    }

    @Override
    public String toString() {
        return "Nombre: " + nombre + ", Raza: " + raza + ", Edad: " + edad;
    }
}
