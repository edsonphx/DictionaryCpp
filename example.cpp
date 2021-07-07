#include <iostream>
#include <string>
#include "Dictionary.h"

int main()
{
    Dictionary* dict = new Dictionary(
        [](void* firstKey, void* secondKey) 
        {
            return ((std::string*)firstKey)->compare(*(std::string*)secondKey) == 0; 
        });
    
    dict->insert(new std::string("Edson"), new int(17));

    int* age = (int*)dict->get(new std::string("Edson"));
    std::cout << *age << std::endl;

    dict->update(new std::string("Edson"), new int(18));

    age = (int*)dict->get(new std::string("Edson"));
    std::cout << *age << std::endl;

    dict->remove(new std::string("Edson"));

    age = (int*)dict->get(new std::string("Edson"));
    std::cout << "PointerAdress: " << age << std::endl;

    dict->insert(new std::string("EdsonPhx"), new int(19));

    age = (int*)dict->get(new std::string("EdsonPhx"));
    std::cout << *age << std::endl;
}