#ifndef STATECLASS_H
#define STATECLASS_H

class StateClass
{
public:
	virtual void Start(class CommonDataClass* CommonData) = 0;

	virtual void Run(CommonDataClass* CommonData) = 0;

	virtual void Draw(CommonDataClass* CommonData) = 0;

	virtual ~StateClass();

protected:
	StateClass();

};

#endif
