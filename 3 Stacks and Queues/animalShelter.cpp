/*
    An animal shelter, which holds only dogs and cats, operates on a strictly 
    "first in, first out" basis. People must adopt either the "oldest" (based on
    arrival time) of all animals at the shelter, or they can select whether they
    would prefer a dog or a cat (and will receive the oldest animal of that type).
    They cannot select which specific animal they would like. Create a data structure
    to maintain this system and implement operations such as enqueue, dequeue, dequeueDog,
    and dequeueCat. You may use the built-in LinkedList data structure.
*/
#include <iostream>
#include "AnimalShelter.h"
using namespace std;

int main(){

    /* 
        The animal shelter datastructure can be created by using two
        queues - one for dogs, one for cats. When a dog or cat is added
        to the shelter, their arrival number is recorded. When dequeuing 
        the oldest animal, the animal with the lowest arrival number is 
        dequeued from its respective queue. When dequeuing a specific animal,
        its respective queue is accessed.

        O(1) time complexity - only two values need be checked for each dequeue
        O(n) space complexity - each animal must have an integer value to record
        its arrival number.
    */

    AnimalShelter<Dog, Cat, Animal> example;
    Cat cat1, cat2, cat3, cat4, cat5;
    Dog dog1, dog2, dog3, dog4, dog5;
    example.Enqueue(cat1);
    example.Enqueue(cat2);
    example.Enqueue(dog1);
    example.Enqueue(cat4);
    example.Enqueue(dog2);
    example.Enqueue(dog3);
    example.Enqueue(dog4);
    example.Enqueue(cat3);
    example.Enqueue(dog5);
    example.Enqueue(cat5);
    cout << example.DequeueCat().m_arrivalOrder << endl;
    cout << example.Dequeue().m_arrivalOrder << endl;
    cout << example.Dequeue().m_arrivalOrder << endl;
    cout << example.DequeueDog().m_arrivalOrder << endl;
    cout << example.DequeueCat().m_arrivalOrder << endl;

    return 1;
}