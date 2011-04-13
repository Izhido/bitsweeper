#ifndef STATECLASS_H
#define STATECLASS_H

class StateClass
{
public:
	virtual bool Start(class CommonDataClass* CommonData) = 0;

	virtual bool Run(CommonDataClass* CommonData) = 0;

	virtual void Draw(CommonDataClass* CommonData) = 0;

	virtual ~StateClass();

protected:
	StateClass();

};

#endif
