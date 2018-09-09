#pragma once

namespace Sonar
{
	class State
	{
	public:
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float delta) = 0;
		//deals with time difference between frames
		virtual void Draw(float delta) = 0;

		virtual void Pause() {}
		virtual void Resume() {}
	};
}