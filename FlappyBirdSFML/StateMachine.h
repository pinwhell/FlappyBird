#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace sermmor {
	/* About unique_ptr:
	https://web.archive.org/web/20160329143115/http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=400
	http://en.cppreference.com/w/cpp/memory/unique_ptr/operator%3D
	*/
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine();

		void addState(StateRef newState, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		StateRef & getActiveState();

	private:
		std::stack<StateRef> states;
		StateRef newState;
		bool isRemoving;
		bool isAdding;
		bool isReplacing;

		void doRemoveProcessState();
		void doAddProcessState();
	};
}