package Java.ExaProgra23;

class Caballo extends Mamifero{
    private String comida;
    private int ejercicio;

    public Caballo(String nombre, String tipoAlimentacion, int edad, int gestacion, String comida, int ejercicio){
        super(nombre, tipoAlimentacion, edad, gestacion);
        this.comida = comida;
        this.ejercicio = ejercicio;
    }
    
    @Override
    public void mostrarInformacion(){
        super.mostrarInformacion();
        System.out.println("Comida Preferida: " + comida);
        System.out.println("Ejercicio diario: " + ejercicio + "veces al dia");
    }
}
