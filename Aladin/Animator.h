#pragma once

class CAnimation;

class Animator
{
private:
	std::unordered_map<std::string, CAnimation> m_clips;

public:
	Animator();
	~Animator();

	void AddClip(std::string _name, CAnimation _anim);
};

