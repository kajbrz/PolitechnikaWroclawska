#pragma once
enum level
{
	random,
	easy,
	medium,
	hard
};

struct indexing{
	int index; 
	bool isEnd;
	indexing(int index, bool isEnd){
		this->index=index;
		this->isEnd=isEnd;
	}
};
