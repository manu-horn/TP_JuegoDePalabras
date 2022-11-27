#include "Juego.h"

Juego::Tablero Juego::crearTablero(Nat tamano) {
    Casillero casillero;
    casillero.letra = ' ';
    casillero.turnoJugado = 0;
    casillero.ocupado = false;
    for (int i = 0; i < tamano ; ++i) {
        for (int j = 0; j < tamano ; ++j) {
            tablero[i][j] = casillero;
        }
    }
    return tablero;
}

Juego::Jugadores Juego::repartirFichas(Variante v, Nat cantJugadores, Repositorio rep) {
    jugador::Mano mano(TAMANIO_ALFABETO,0);
    Ocurrencia fichasQuePusoDesde = {};
    Letra ficha;
    jugador jugador1;
    jugador1.mano = mano;
    jugador1.puntaje = 0;
    jugador1.fichasQuePusoDesde = fichasQuePusoDesde;
    Jugadores jugadores1(cantJugadores, jugador1);
    for (int i = 0; i < cantJugadores; ++i) {
        for (int j = 0; j < v.cantFichas(); ++j) {
            ficha = rep.front();
            rep.pop_front();
            jugadores[i].mano[ord(ficha)]++;
        }
    }
    return jugadores1;



}
Juego ::Juego(Nat numJugadores, Variante var, Repositorio rep): v(var){
    numJug = numJugadores;
    _rep = rep;
    turnoActual = 0;
    tablero = crearTablero(v.tamanoTablero());
    jugadores = repartirFichas(v, numJugadores, rep);

}
const  Nat Juego :: numJugadores() const{
    return numJug;
};
/*
void ubicar(Ocurrencia o);
const variante obtenerVariante() const;
const Nat obtenerTurno() const;
const Nat obtenerPuntaje() const;
const bool EsjugadaValida(Ocurrencia o) const;
const Letra fichaEnPosicion(Nat fila , Nat columna) const;
const bool hayFicha(Nat fila, Nat columna) const;
const Nat cuantasDeEstaTiene(Letra l, Nat idCliente) const;
*/