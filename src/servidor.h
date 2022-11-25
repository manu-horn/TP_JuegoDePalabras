//
// Created by clinux01 on 18/11/22.
//

#ifndef TP_JUEGODEPALABRAS_SERVIDOR_H
#define TP_JUEGODEPALABRAS_SERVIDOR_H
#include "Tipos.h"
#include "variante.h"
#include "juego.h"
class servidor{
public:
    servidor(Nat cantJug, variante v, Repositorio rep);
    void conectarCliente();
    void consultarNotificaciones(Nat idCliente);
    void recibirMensaje(Ocurrencia o, Nat idCliente);
    const Nat numeroClientesEsperados() const;
    const Nat numeroClientesConectados() const;

private:
    struct notificacion {
        string tipoNotif;
        IdCliente id;
        Nat n;
        multiset<Letra> agarraLetras;
        Ocurrencia jugada;

    };
    struct notificacionesTodos{
        vector<tuple<notificacion,Nat>> notificacionesServidor;
        vector<int> leyoHasta;
    };

    struct notificaciones{

        notificacionesTodos nTodes; /// hace falta?
        vector<vector<tuple<notificacion,Nat>>> notificacionesPorJugador;
    };
    struct Clientes{
        Nat esperados;
        Nat conectados;
    };
    Nat _idNotif;
    notificaciones _notifs;
    Clientes _clientes;
};
#endif //TP_JUEGODEPALABRAS_SERVIDOR_H
