#include "stdafx.h"
#include "StateMachine.h"

namespace sermmor {
	StateMachine::StateMachine() { }

	StateMachine::~StateMachine() { }

	void StateMachine::addState(StateRef newState, bool isReplacing) {
		this->isAdding = true;
		this->isReplacing = isReplacing;
		this->newState = std::move(newState); // std::move prepare a var for a pointer assignation.
											  // newState value now nullptr because of std::move operaton.
											  // A unique_ptr can't assign in other way.
	}

	void StateMachine::removeState() {
		this->isRemoving = true;
	}


	void StateMachine::doRemoveProcessState()
	{
		this->states.pop();

		if (!this->states.empty())
			this->states.top()->resume(); // The state before removed state continue.

		this->isRemoving = false;
	}

	void StateMachine::doAddProcessState()
	{
		if (!this->states.empty()) {
			if (this->isReplacing)
				this->states.pop(); // Remove state to replace the current state for the new one.
			else
				this->states.top()->pause(); // Pause current state.
		}

		this->states.push(std::move(this->newState));
		this->states.top()->init(); // The new state begins.
		this->isAdding = false;
	}

	void StateMachine::processStateChanges() {
		if (this->isRemoving && !this->states.empty()) {
			this->doRemoveProcessState();
		}

		if (this->isAdding) {
			this->doAddProcessState();
		}
	}

	StateRef & StateMachine::getActiveState() {
		return this->states.top(); // top() method returns a reference, so GetActiveState() too.
	}
}
