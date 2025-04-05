package Java.ExaProgra23;

class Gato extends Mamifero{
    private String pedigree;

    public Gato(String nombre, String tipoAlimentacion, int edad, int gestacion, String pedigree){
        super(nombre, tipoAlimentacion, edad, gestacion);
        this.pedigree = pedigree;
    }
    
    @Override
    public void mostrarInformacion(){
        super.mostrarInformacion();
        System.out.println("Pedigri: " + pedigree);
    }
}
