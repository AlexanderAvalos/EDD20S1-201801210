package Clase;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Alex
 */
public class Moneda {

    private String nombreM;
    private int cantMax;
    private Object User[][];

    public String getNombreM() {
        return nombreM;
    }

    public void setNombreM(String nombreM) {
        this.nombreM = nombreM;
    }

    public int getCantMax() {
        return cantMax;
    }

    public void setCantMax(int cantMax) {
        this.cantMax = cantMax;
    }

    public Object[][] getUser() {
        return User;
    }

    public void setUser(Object[][] User) {
        this.User = User;
    }

    public Moneda(String nombreM, int cantMax) {
        this.nombreM = nombreM;
        this.cantMax = cantMax;
       
    }
   
}
