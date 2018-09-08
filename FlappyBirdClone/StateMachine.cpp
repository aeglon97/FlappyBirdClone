#include "StateMachine.hpp"

namespace Sonar
{
	//constructor
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		//if removing current state AND it's not empty
		if (this->_isRemoving && !this->_states.empty())
		{
			//remove that state
			this->_states.pop();
			if (!this->_states.empty())
			{
				//run top state
				this->_states.top()->Resume(); 
			}
			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}

			//initialize and run state
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}
	StateRef &StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}