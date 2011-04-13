#ifndef MENUVANISHSTATECLASS_H
#define MENUVANISHSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define MENU_VANISH_STATE 12 

class MenuVanishStateClass
: public StateClass
{
public:
	MenuVanishStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Vanishing;

};

#endif
