#include "DepositSlot.h"

// indica se o envelope foi recebido (sempre retorna true,
// porque esta � apenas uma simula��o do software de uma abertura para dep�sito real)
bool DepositSlot::isEnvelopeReceived() const
{
	return true; // o envelope de dep�sito foi recebido
}