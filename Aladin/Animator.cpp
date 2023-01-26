
#include <unordered_map>
#include <string>

#include "CAnimation.h"
#include "Animator.h"


Animator::Animator()
{
}

Animator::~Animator()
{
}

void Animator::AddClip(std::string _name, CAnimation _anim)
{
	m_clips.insert(std::make_pair(_name, _anim));
}
