
#include "Tipos.h"
//#include "juego.h"
#include "variante.h"
#include "Letra.h"
variante::variante(trie palabrasValidas, Nat numFichas, Abecedario abc, Nat tamanoTablero,
                   Nat lMax):abecedario(abc), universal(palabrasValidas),fichasCant(numFichas),
                             tamanioTablero(tamanoTablero){
    lmax = palabrasValidas.obtenerLmax();
};


const Nat variante::tamanoTablero() const {
    return tamanioTablero;
}

const Nat variante::cantFichas() const {
    return fichasCant;
}

Nat variante::puntajeLetra(Letra l) const {
    return abecedario[ord(l)];
}

bool variante::palabraLegitima(const Palabra &palabra) const {
    string pal;
    for (auto a : palabra) {
        pal.push_back(a);
    }
    return universal.count(pal);
}


