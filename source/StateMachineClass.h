#ifndef STATEMACHINECLASS_H
#define STATEMACHINECLASS_H

class StateMachineClass
{
public:
	StateMachineClass();

	void Run(class CommonDataClass* CommonData);

	void Draw(class CommonDataClass* CommonData);

	void Switch(int NewState);

	virtual ~StateMachineClass();

private:
	class StateClass** List;

	int Current;

	int Requested;
};

#endif
