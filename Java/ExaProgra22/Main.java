package Java.ExaProgra22;

public class Main {
    public static void main(String[] args){
        Empleado empleado;

        int horasTrabajadas = 48;
        double sueldoPorHora = 10.0;

        if (horasTrabajadas <= 40){
            empleado = new EmpleadoSinHorasExtras(horasTrabajadas, sueldoPorHora);
        }else if (horasTrabajadas <= 45){
            empleado = new EmpleadoConHorasDobles(horasTrabajadas, sueldoPorHora);
        }else {
            empleado = new EmpleadoConHorasTriples(horasTrabajadas, sueldoPorHora);
        }

        System.out.println("Salario Semanal: $" + empleado.calcularSalario());
    }
}
