package Tarea2;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Alex
 */
import Clase.Moneda;
import java.util.Scanner;
import Clase.*;

public class main {

    public static Moneda[] lst_moneda;
    public static Object[][] lst_Dueño;
    public static int cont = 0;

    public static int contador = 0;

    public static void main(String[] args) {
        boolean menu = true;
        lst_Dueño = new Object[10][3];
        lst_moneda = new Moneda[1];
        while (menu == true) {
            System.out.println("Menu");
            System.out.println("¿Que Accion desea realizar? seleccione No.");
            System.out.println("1. Crear moneda");
            System.out.println("2. Crear usuario");
            System.out.println("3. transferencia a monedero");
            System.out.println("4. transferencia a usuario");
            System.out.println("5. Listado de usuarios");
            System.out.println("6. salir");
            Scanner valmenu = new Scanner(System.in);
            int menu1 = valmenu.nextInt();
            switch (menu1) {
                case 1:
                    cMoneda();
                    break;
                case 2:
                    cDueño();
                    break;
                case 3:
                    TransferenciaM();
                    break;
                case 4:
                    TransferenciaU();
                    break;
                case 5:
                    mostraUser();
                    break;
                case 6:
                    menu = false;
                    break;
            }
        }
    }

    static public void cMoneda() {
        System.out.println("Escriba el nombre de la moneda:");
        Scanner nombreM = new Scanner(System.in);
        String nombre = nombreM.nextLine();
        System.out.println("Escriba la cantidad maxima de monedas");
        Scanner cant = new Scanner(System.in);
        int max = cant.nextInt();
        lst_moneda[0] = new Moneda(nombre, max);
    }

    private static void cDueño() {
        System.out.println("Escriba el nombre del Usuario:");
        Scanner nombreM = new Scanner(System.in);
        String nombre = nombreM.nextLine();
        lst_Dueño[cont][0] = contador;
        lst_Dueño[cont][1] = nombre;
        lst_Dueño[cont][2] = 0;
        cont++;
        contador++;
    }

    private static void TransferenciaM() {
        System.out.println("Escriba el id del Usuario:");
        Scanner scan = new Scanner(System.in);
        int id = scan.nextInt();
        System.out.println("Escriba la cantidad a transferir");
        Scanner scan1 = new Scanner(System.in);
        int cantidad = scan1.nextInt();
        lst_moneda[0].setCantMax(lst_moneda[0].getCantMax() - cantidad);
        lst_Dueño[id][2] = cantidad;
        lst_moneda[0].setUser(lst_Dueño);
        System.out.println(lst_moneda[0].getCantMax());
    }

    private static void TransferenciaU() {
        System.out.println("Escriba el id del Usuario1:");
        Scanner scan = new Scanner(System.in);
        int id = scan.nextInt();
        System.out.println("Escriba el id del Usuario2:");
        Scanner scan2 = new Scanner(System.in);
        int id2 = scan2.nextInt();
        System.out.println("Escriba la cantidad a transferir");
        Scanner scan1 = new Scanner(System.in);
        int cantidad = scan1.nextInt();
        int valor = (int) lst_Dueño[id][2];
        lst_Dueño[id][2] = valor - cantidad;
        lst_Dueño[id2][2] = (int) lst_Dueño[id2][2] + cantidad;
    }
    
    private static void mostraUser() {
        for (int i = 0; i < lst_moneda.length; i++) {
            for (int i1 = 0; i1 < cont; i1++) {          
                System.out.println(lst_moneda[i].getUser()[i1][1] + " tiene " + lst_moneda[i].getUser()[i1][2] + " "+lst_moneda[i].getNombreM());
            }
        }
    }
}