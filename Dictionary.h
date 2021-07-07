#pragma once
#include "Entry.h"

class Dictionary
{
public:
	Dictionary(bool (*compare)(void* firstKey, void* secondKey));
	void insert(void* key, void* value);
	void update(void* key, void* value);
	void remove(void* key);
	void* get(void* key);
private:
	Entry* _lastEntry;
	bool (*_compare)(void* firstKey, void* secondKey);
};

