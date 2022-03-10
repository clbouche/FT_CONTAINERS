<h1 align=center> FT_CONTAINERS - 42 </h1>   


## Table of contents 
- [Sujet](#Sujet)
- [Notions de bases](#Notions-de-bases)
- [Plan du projet](#Plan-du-projet)
    - [Vector](#Vector)
    - [Stack](#Stack)
    - [Map](#Map)  
- [Notes](#Notes)
- [Ressources](#Ressources)


## Sujet  

    → In this project, you will implement a few container types of the C++ standard template library

---

## Notions de bases


---

## Plan du projet

### Vector
On va commencer par construire notre premier container. Par élémination on va débuter par vector : 
- stack est un vector sans iterateur. 
- map est le container le plus compliqué à implémenter, on le gardera pour la fin.   

Pour se familiariser avec vector :     
→ [std::vector](https://cplusplus.com/reference/vector/vector/?kw=vector)         
     
1. Random_access_iterator
On trouve dans cette documentation, toutes les fonctions et les variables membres de notre container. Parmis ces membres types, 
on trouve des iterateurs qui utilisent une autre librairie.    
→ [std::random_access_iterator_tag](https://cplusplus.com/reference/iterator/RandomAccessIterator/)   
→ [Pour mieux comprendre les differents types d'itérateurs](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)    
→ [Code source pour implémenter cette catégorie d'itérateurs](https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01052_source.html)

Maintenant qu'on a mit en place la catégorie d'itérateurs qui nous permettra de développer les itérateurs de notre container vector, on peut revenir à notre container.

2. Reverse_iterator
Héééééé non, on va devoir implémenter une nouvelle librairie pour pouvoir continuer avec nos itérateurs.    
→ [Pour comprendre ce qu'est un reverse_iterator](https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator)
//capture ecran cppreference.

Donc finalement, on comprend qu'un reverse_iterator est finalement un pointeur sur un iterator. Cependant, un pointeur peut 
etre tout autre chose qu'un itérateur. Nous allons donc avoir besoin maintenant des iterators_trait.  
→ [Introduction à iterator_traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits).
Iterator_trait est une structure qui sert d'interface pour accéder aux attributs d'un iterator (value_type, difference_type, 
etc..) on parle donc d'un iterator sans se soucier selon si c'est un pointeur ou non.
Voila grosso modo ce à quoi sert iterator_trait. Bon, revenons maintenant à nos reverse_iterator. 



### Stack

### Map

---

## Notes 

---

## Ressources
#### Vector


#### Stack

#### Map

---