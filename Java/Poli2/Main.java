package Java.Poli2;

class Vehiculo {
    public void mover() {
        System.out.println("El vehículo se está moviendo.");
    }
}

class Coche extends Vehiculo {
    public void mover() {
        System.out.println("El coche se está desplazando por la carretera.");
    }
}

class Bicicleta extends Vehiculo {
    public void mover() {
        System.out.println("La bicicleta se está pedaleando en el carril.");
    }
}

public class Main {
    public static void main(String[] args) {
        Vehiculo[] misVehiculos = new Vehiculo[2];
        misVehiculos[0] = new Coche();
        misVehiculos[1] = new Bicicleta();

        for (Vehiculo vehiculo : misVehiculos) {
            vehiculo.mover();
        }
    }
}
