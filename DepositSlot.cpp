#include "DepositSlot.h"

// indica se o envelope foi recebido (sempre retorna true,
// porque esta é apenas uma simulação do software de uma abertura para depósito real)
bool DepositSlot::isEnvelopeReceived() const
{
	return true; // o envelope de depósito foi recebido
}