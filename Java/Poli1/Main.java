package Java.Poli1;

public class Main {
    public static void main(String[] args) {
        Animal miMascota = new Perro();
        miMascota.hacerSonido(); // Llama al método del perro

        miMascota = new Gato();
        miMascota.hacerSonido(); // Llama al método del gato
    }
}
