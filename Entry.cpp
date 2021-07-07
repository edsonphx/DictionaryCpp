#include "Entry.h"

Entry::Entry(void* keyPtr, void* valuePtr, Entry* previousPtr, Entry* nextPtr)
{
	key = keyPtr;
	value = valuePtr;
	previous = previousPtr;
	next = nextPtr;
}