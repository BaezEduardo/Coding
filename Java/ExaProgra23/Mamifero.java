package Java.ExaProgra23;

class Mamifero extends Animal{
    protected int gestacion;

    public Mamifero(String nombre, String tipoAlimentacion, int edad, int gestacion){
        super(nombre,tipoAlimentacion,edad);
        this.gestacion = gestacion;
    }

    @Override
    public void mostrarInformacion(){
        super.mostrarInformacion();
        System.out.println("Periodo de gestacion: " + gestacion + " meses");
    }
}
