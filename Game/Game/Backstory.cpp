#include "Precompile.hpp"
#include "Backstory.hpp"

// define a timer

 unsigned int Lifetime = 0;

//// start or restart a timer with a specific lifetime
//void StartTimer(Timer* timer, float lifetime)
//{
//    if (timer != NULL)
//        timer->Lifetime = lifetime;
//}
//
//// update a timer with the current frame time
//void UpdateTimer(Timer* timer)
//{
//    // subtract this frame from the timer if it's not allready expired
//    if (timer != NULL && timer->Lifetime > 0)
//        timer->Lifetime -= GetFrameTime();
//}
//
//// check if a timer is done.
//bool TimerDone(Timer* timer)
//{
//    if (timer != NULL)
//        return timer->Lifetime <= 0;
//
//    return false;
//}

string my;
int i = 0;
void backstoryTypewriteEffect(int& miliseconds, string& text)
{
	
	Lifetime++;//increment for timer
	if (Lifetime == 10){
		my += text[i++];
		Lifetime = 0;  
	}
	DrawText(my.c_str(), 130, 300, 50, BROWN);
}