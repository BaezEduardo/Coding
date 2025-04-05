package Java.ExaProgra22;

abstract class Empleado {
    protected int horasTrabajadas;
    protected double sueldoPorHora;

    public Empleado(int horasTrabajadas, double sueldoPorHora){
        this.horasTrabajadas = horasTrabajadas;
        this.sueldoPorHora = sueldoPorHora;
    }

    public int getHorasTrabajadas(){
        return horasTrabajadas;
    }
    public double getSueldoPorHora(){
        return sueldoPorHora;
    }

    public abstract double calcularSalario();
}
