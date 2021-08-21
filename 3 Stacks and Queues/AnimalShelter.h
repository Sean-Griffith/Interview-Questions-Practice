#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

#include "Queue.h"
#include <typeinfo>
using namespace std;

class Animal {
    public:
        Animal(){
            m_arrivalOrder = 0;
        }
        Animal(string name){
            m_name = name;
            m_arrivalOrder = 0;
        }
        string m_name;
        int m_arrivalOrder;
};

class Dog: public Animal{};

class Cat: public Animal {};

template <typename Animal1, typename Animal2, typename Animal>
class AnimalShelter {
    public:
        AnimalShelter();
        ~AnimalShelter();

        void Clear();
        bool isEmpty() const;

        void Enqueue(Animal1 myData);
        void Enqueue(Animal2 myData);
        Animal Dequeue();
        Animal1 DequeueDog();
        Animal2 DequeueCat() const;

    private:
        Queue<Animal1>* m_animal1;
        Queue<Animal2>* m_animal2;
        int m_acceptedAnimals;
};

template <typename Animal1, typename Animal2, typename Animal>
AnimalShelter<Animal1, Animal2, Animal>::AnimalShelter(){
    m_acceptedAnimals = 0;
    m_animal1 = new Queue<Animal1>;
    m_animal2 = new Queue<Animal2>;
}

template <typename Animal1, typename Animal2, typename Animal>
AnimalShelter<Animal1, Animal2, Animal>::~AnimalShelter(){
    Clear();
}

template <typename Animal1, typename Animal2, typename Animal>
void AnimalShelter<Animal1, Animal2, Animal>::Clear(){
    m_animal1->Clear();
    m_animal2->Clear();
    delete(m_animal1);
    delete(m_animal2);
}

template <typename Animal1, typename Animal2, typename Animal>
bool AnimalShelter<Animal1, Animal2, Animal>::isEmpty() const {
    if(m_animal1->isEmpty() && m_animal2->isEmpty()){
        return true;
    } else {
        return false;
    }
}

template <typename Animal1, typename Animal2, typename Animal>
void AnimalShelter<Animal1, Animal2, Animal>::Enqueue(Animal1 myAnimal1){
    myAnimal1.m_arrivalOrder = ++m_acceptedAnimals;
    m_animal1->Enqueue(myAnimal1);
}

template <typename Animal1, typename Animal2, typename Animal>
void AnimalShelter<Animal1, Animal2, Animal>::Enqueue(Animal2 myAnimal2){
    myAnimal2.m_arrivalOrder = ++m_acceptedAnimals;
    m_animal2->Enqueue(myAnimal2);
}

template <typename Animal1, typename Animal2, typename Animal>
Animal AnimalShelter<Animal1, Animal2, Animal>::Dequeue(){
    if(m_animal1->Peek().m_arrivalOrder < m_animal2->Peek().m_arrivalOrder){
        return (Animal) m_animal1->Dequeue();
    } else {
        return (Animal) m_animal2->Dequeue();
    }
}

template <typename Animal1, typename Animal2, typename Animal>
Animal1 AnimalShelter<Animal1, Animal2, Animal>::DequeueDog(){
    return m_animal1->Dequeue();
}

template <typename Animal1, typename Animal2, typename Animal>
Animal2 AnimalShelter<Animal1, Animal2, Animal>::DequeueCat() const {
    return m_animal2->Dequeue();
}

#endif