#pragma once
class Entry
{
public:
	Entry(void* keyPtr, void* valuePtr, Entry* previousPtr, Entry* nextPtr);
	Entry* next;
	Entry* previous;
	void* key;
	void* value;
};

