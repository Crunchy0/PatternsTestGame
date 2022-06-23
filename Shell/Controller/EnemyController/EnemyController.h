#ifndef ENEMYCONTROLLER
#define ENEMYCONTROLLER

#include "..\..\..\Handler\Handler.h"
#include "..\EntityController.h"

class EnemyController : public EntityController {
private:
	Handler* handler;
public:
	EnemyController(Handler* h);
	virtual bool act() override;
};

#endif