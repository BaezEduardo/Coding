package Java.ExaProgra22;

class EmpleadoSinHorasExtras extends Empleado{
    public EmpleadoSinHorasExtras(int horasTrabajadas, double sueldoPorHora){
        super(horasTrabajadas, sueldoPorHora);
    }

    @Override
    public double calcularSalario(){
        return horasTrabajadas*sueldoPorHora;
    }
}
