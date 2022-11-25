
#include "Tipos.h"
#include "variante.h"
#include "servidor.h"
#include "Notificacion.h"

servidor::servidor(Nat cantJug, variante v, Repositorio rep){
    _clientes.esperados = cantJug;
    _clientes.conectados = 0;
    vector<tuple<notificacion,Nat>> vacio = {};
    vector<vector<tuple<notificacion,Nat>>> porJugador(cantJug, vacio) ;
    _notifs.notificacionesPorJugador = porJugador;
    _notifs.nTodes.notificacionesServidor = {};
    vector<int> leyoHasta(cantJug,0);
    _notifs.nTodes.leyoHasta = leyoHasta;
    _idNotif = 0;



}

void servidor::conectarCliente() {


//_notifs.notificacionesPorJugador[_clientes.conectados].push_back(make_tuple(Notificacion ::nuevaIdCliente(_clientes.conectados)));
_clientes.conectados ++;
}

void servidor::recibirMensaje(Ocurrencia o, Nat idCliente) {

}

const Nat servidor::numeroClientesEsperados() const {
    return 0;
}

const Nat servidor::numeroClientesConectados() const {
    return 0;
}

void servidor::consultarNotificaciones(Nat idCliente) {

}
