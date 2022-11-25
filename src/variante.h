
#ifndef TP_JUEGODEPALABRAS_VARIANTE_H
#define TP_JUEGODEPALABRAS_VARIANTE_H

#include "Tipos.h"

class variante{
public:
     variante(trie palabrasValidas,Nat numFichas, Abecedario abc,Nat tamanoTablero,Nat lMax);
     const Nat cantFichas() const;
     const Nat tamanoTablero() const;
    Nat puntajeLetra(Letra l) const;
    bool palabraLegitima(const Palabra& palabra) const;

private:

    Abecedario abecedario;
    trie universal;
    Nat fichasCant;
    Nat tamanioTablero;
    Nat lmax;
};





#endif //TP_JUEGODEPALABRAS_VARIANTE_H
