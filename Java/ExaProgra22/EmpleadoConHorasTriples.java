package Java.ExaProgra22;

class EmpleadoConHorasTriples extends Empleado {
    private int horasExtras;

    public EmpleadoConHorasTriples(int horasTrabajadas, double sueldoPorHora){
        super(40, sueldoPorHora);
        this.horasExtras = horasTrabajadas - 40;
    }

    @Override
    public double calcularSalario(){
        int horasDobles = 5;
        int horasTriples = horasExtras - horasDobles;
        return(40 * sueldoPorHora) + (horasDobles * sueldoPorHora * 2) + (horasTriples * sueldoPorHora * 3);
    }
}
