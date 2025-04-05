package Java.ExaProgra2;

class Rectangulo extends Figura{
    private double largo;
    private double ancho;

    public Rectangulo(double largo, double ancho){
        this.largo = largo;
        this.ancho = ancho;
    }

    public double getLargo(){return largo;}
    public void setLargo(double largo){this.largo = largo;}

    public double getAncho(){return ancho;}
    public void setAncho(double ancho){this.ancho = ancho;}
    
    @Override
    public double calcularArea(){
        return largo*ancho;
    }
}
