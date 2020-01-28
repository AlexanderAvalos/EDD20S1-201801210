/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
import java.util.Random;
import java.util.Scanner;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int valor,x,y;
        int matriz[][];
        System.out.println("Ingrese Valor para la matriz");
        Scanner teclado = new Scanner(System.in);
        valor = teclado.nextInt();
        matriz = new int[valor][valor];
        for ( x = 0; x < matriz.length; x++) {
            for ( y = 0; y < matriz.length; y++) {
                matriz[0][y]=1;
                matriz[matriz.length-1][y]=1;
                matriz[x][0]=1;
                matriz[x][matriz.length-1]=1;
                System.out.print(matriz[x][y]);  
            }    
            System.out.println();
        }
    }
}
