{
    do{
    cout << "_________________________________________________\n";
    cout << "|                                         \t|\n";
    cout <<("| UNIVERSIADAD DE SAN CARLOS DE GUATEMALA  \t| \n");
    cout << "| FACULTAD DE INGENIERIA                  \t|\n";
    cout << "| ESTRUCTURA DE DATOS                     \t|\n";
    cout << "| PROYECTO1                              \t|\n";
    cout << "| Rodolfo Alexander Avalos Soto           \t|\n";
    cout << "| Carnet: 201801210                       \t|\n";
    cout << "|                                         \t|\n";
    cout << "|\t\t MENÚ                           |\n";
    cout << "| 1. Crear jugador                        \t|\n";
    cout << "| 2. cargar json                          \t|\n";
    cout << "| 3. jugar                                \t|\n";
    cout << "| 4. reportes                             \t|\n";
    cout << "| 5. salir                                \t|\n";
    cout << "|                                         \t|\n";
    cout << "|_______________________________________________|\n";


    cin >> smenu;
    switch(smenu){
    case 1:
        juego::crearJugador();
        break;
    case 2:
        juego::leerjason();
        break;
    case 3:
        juego::elegirJugadores();
        break;
    case 4:
        juego::reportes();
        break;
    }
    }while(smenu < 5);
}
