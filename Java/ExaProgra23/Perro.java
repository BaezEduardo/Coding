package Java.ExaProgra23;

class Perro extends Mamifero{
    private String raza;

    public Perro(String nombre, String tipoAlimentacion, int edad, int gestacion, String raza){
        super(nombre, tipoAlimentacion, edad, gestacion);
        this.raza = raza;
    }

    @Override
    public void mostrarInformacion(){
        super.mostrarInformacion();
        System.out.println("Raza: " + raza);
    }
}
