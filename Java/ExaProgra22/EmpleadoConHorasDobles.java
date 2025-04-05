package Java.ExaProgra22;

class EmpleadoConHorasDobles extends Empleado{
    private int horasExtras;

    public EmpleadoConHorasDobles(int horasTrabajadas, double sueldoPorHora){
        super(40,sueldoPorHora);
        this.horasExtras = horasTrabajadas - 40;
    }
    
    @Override
    public double calcularSalario(){
        return(40 * sueldoPorHora) + (horasExtras * sueldoPorHora * 2);
    }
}
