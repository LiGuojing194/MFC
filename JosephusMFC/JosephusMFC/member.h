#pragma once
class Member
{
public:
	int m_nNumber;
	int m_nOutNumber;
	Member*m_pLeft;
	Member*m_pRight;
	Member(int x = 0,int y = 0);
	~Member();
};

