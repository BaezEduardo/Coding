package Java.ExaProgra2;

class Triangulo extends Figura{
    private double altura;
    private double ancho;

    public Triangulo(double altura, double ancho){
        this.altura = altura;
        this.ancho = ancho;
    }

    public double getAltura(){return altura;}
    public void setAltura(double altura){this.altura = altura;}

    public double getAncho(){return ancho;}
    public void setAncho(double ancho){this.ancho = ancho;}

    @Override
    public double calcularArea(){
        return(ancho*altura)/2;
    }
}
