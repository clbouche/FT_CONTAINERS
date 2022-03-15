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
     
#### 1. Random_access_iterator
On trouve dans cette documentation, toutes les fonctions et les variables membres de notre container. Parmis ces membres types, 
on trouve des iterateurs qui utilisent une autre librairie.    
→ [std::random_access_iterator_tag](https://cplusplus.com/reference/iterator/RandomAccessIterator/)   
→ [Pour mieux comprendre les differents types d'itérateurs](https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp)    
→ [Code source pour implémenter cette catégorie d'itérateurs](https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01052_source.html)

Maintenant qu'on a mit en place la catégorie d'itérateurs qui nous permettra de développer les itérateurs de notre container vector, on peut revenir à notre container.

#### 2. Reverse_iterator    
Héééééé non, on va devoir implémenter une nouvelle librairie pour pouvoir continuer avec nos itérateurs.    
→ [Pour comprendre ce qu'est un reverse_iterator](https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator)
//capture ecran cppreference.

Donc finalement, on comprend qu'un reverse_iterator est finalement un pointeur sur un iterator. Cependant, un pointeur peut 
etre tout autre chose qu'un itérateur. Nous allons donc avoir besoin maintenant des iterators_trait.    
   
→ [Introduction à iterator_traits](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits).
Iterator_trait est une structure qui sert d'interface pour accéder aux attributs d'un iterator (value_type, difference_type, 
etc..) on parle donc d'un iterator sans se soucier selon si c'est un pointeur ou non.    
Voila grosso modo ce à quoi sert iterator_trait. Bon, revenons maintenant à nos reverse_iterator.   
     
Reverse_iterators est une classe qui possede quasi exclusivement des surcharges d'opérateurs, de TOUS les opérateurs.    
On va tout de meme lui implémenter des constructeurs et un destructeur pour etre cohérent et puis apres on passe aux opérateurs.

#### 3. Les constructeurs de vector. 
Apres avoir implémenter tous ce petit monde on va pouvoir ENFIN revenir à notre container. Pour que ce petit fonctionne correctement on va donc se lancer en premier lieu dans l'implémentation des constructeurs, simple me direz vous ?      
Petite présentation des constructeurs dont on aura besoin : 
      
| Type de constructeur           | Prototype             | Parametres     | Description       |   Notes |   
| -------------------------------|-----------------------|----------------|-------------------|---------|    
Constructeurs par défaut         | ``explicit vector (const allocator_type& alloc = allocator_type()) `` | Aucun | Construction d'un container sans éléments. | [comprendre le mot clé explicit](https://nodatek.com/article7/tuto-cpp-le-mot-cle-explicit)|
Constructeur par remplissage     | ``explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())`` |  <ul><li>n = nombres d'éléments à créer</li><li>val = valeur de chaque élément</li></ul> | Construction d'un container avec un nombres d'éléments déterminés dont la valeur peut etre déterminée ou non | Ce constructeur peut prendre 1 ou 2 parametres  <ul><li> 1 param : le container sera rempli de 0 (choisi par défaut)</li><li>2 param = le container sera rempli de la valeur choisi en 2nd param</li></ul>|
Constructeur par portée          | ``template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) `` | <ul><li>first = un iterateur sur la premiere valeur</li><li>last = un iterateur sur la derniere valeurli></ul> | Contruction d'un container avec autant d'éléments que l'intervalle entre first et last. | Les deux constructeurs pouvant se confondre puisqu'on envoie 2 arguments sans préciser correctement leur nature. 

 ##### a. Enable if      
Comme on a vu juste avant, les deux derniers constructeurs prennent chacun 2 arguments. On peut penser que l'argument de modele InputIterator permettent de faire la différence mais que nenni ! InputIterator est un simple nom descriptif.
→ [Pour comprendre l'utilité d'enable_if](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/)
En gros il faut comprendre que notre compilateur c'est un gros feignant. S'il peut éviter de faire une conversion, il prendra toujours cette option, sauf si on lui précise de faire l'inverse. En l'occurence, lorsqu'on envoie,

```
 	ft::vector<int>		my_vector_int2(6, 4);
```
on souhaite construire un vector de 6 éléments dont la valeur de chacun est 4. 
Sauf que notre petit compilateur il se simplifie grandement la vie à envoyer ces arguments a notre 3e constructeur qui ne nécessite pas de conversion parce que, comme dit précédemment, InputIterator n'est qu'un nom descriptif. On va donc devoir lui donner une condition d'entrée dans tel ou tel constructeur. Cette condition c'est de vérifier si notre argument T (notre 2e arg) est de type integral. 


##### b. Is_integral
Maintenant qu'on a implémenter 'enable if' il faut bien faire suivre une condition. On va donc maintenant devoir implémenter is_integral. Let's go !     
→ [Notre classe is_integral](https://www.cplusplus.com/reference/type_traits/is_integral/)      
L'idée de cette classe est de vérifier la nature de notre 2nd argument passé en parametre donc.     
Bon de base is_integral hérite encore de pleins d'autres classes mais j'aimerais bien tester mon vector un jour. Donc on va se simplifier la tache :       
- On va utiliser true et false à la place de true_type et false_type      
- Et on va s'éviter d'implémenter is_integral_constant parce que tout ce qu'on a besoin c'est uniquement de savoir si notre argument est un int ou non. Un const int autant qu'un int, reste un int.     
        
| fundamental integral types | Implementation |
|----------------------------| ---------------|
bool ; char ; wchar_t ; signed char ; short int ; int ; long int ; long long int ; unsigned char ; unsigned short int ; unsigned int ; unsigned long int ; unsined long long int ;      | true           |
char16_t  ; char32_t         | pas à implementer car c'est du C++11 (oui, on a implémenté enable if alors que c'est aussi du C++11 mais on pouvait pas trop faire autrement, et en plus c'est demandé dans le sujet) |
tout le reste                | false          |
 
Hourraaaaa ! On va pouvoir implémenter de notre vector maintenant, félicitations si vous etes arrivés jusque là. Allez, on a encore beaucoup de boulot. 

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


---
