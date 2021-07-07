#include "Dictionary.h"

Dictionary::Dictionary(bool (*compare)(void* firstKey, void* secondKey))
{
	_compare = compare;
	_lastEntry = nullptr;
}
void Dictionary::update(void* key, void* value)
{
	if (key == nullptr || value == nullptr)
		return;

	Entry* iterator = _lastEntry;
	while (iterator)
	{
		if (_compare(iterator->key, key))
			iterator->value = value;

		iterator = iterator->previous;
	}
}
void Dictionary::remove(void* key)
{
	if (key == nullptr)
		return;

	Entry* iterator = _lastEntry;
	while (iterator)
	{
		if (_compare(iterator->key, key))
		{
			if (iterator->previous)
				iterator->previous->next = iterator->next;

			if (iterator->next)
				iterator->next->previous = iterator->previous;
			else
				_lastEntry = iterator->previous;

			return;
		}

		iterator = iterator->previous;
	}
}
void* Dictionary::get(void* key)
{
	if (key == nullptr)
		return nullptr;

	Entry* iterator = _lastEntry;
	while (iterator) 
	{
		if (_compare(iterator->key, key))
			return iterator->value;

		iterator = iterator->previous;
	}

	return nullptr;
}
void Dictionary::insert(void* key, void* value)
{
	if (_lastEntry) 
	{
		if (get(key) != nullptr)
			return;

		Entry* entry = new Entry(key, value, _lastEntry, nullptr);
		_lastEntry->next = entry;
		_lastEntry = entry;
	}
	else 
	{
		_lastEntry = new Entry(key, value, nullptr, nullptr);
	}
}