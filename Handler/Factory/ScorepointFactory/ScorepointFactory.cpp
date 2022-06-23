#include "ScorepointFactory.h"

Element* ScorepointFactory::createElement() const {
	return new Scorepoint();
}