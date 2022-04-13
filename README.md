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
- stack est plus ou moins un vector sans iterateur. 
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
Constructeur par remplissage     | ``explicit vector (size_typen, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())`` |  <ul><li>n = nombres d'éléments à créer</li><li>val = valeur de chaque élément</li></ul> | Construction d'un container avec un nombres d'éléments déterminés dont la valeur peut etre déterminée ou non | Ce constructeur peut prendre 1 ou 2 parametres  <ul><li> 1 param : le container sera rempli de 0 (choisi par défaut)</li><li>2 param = le container sera rempli de la valeur choisi en 2nd param</li></ul>|
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

Bon pour la suite, le processus est simple, on va commencer par finir l'implémentation des constructeurs, on va se rendre compte qu'il nous manque des fonctions pour pouvoir finir l'implémentation, donc on va implémenter ses fonctions jusqu'à avoir implémenter ce beau tableau de fonctions : 

	/**
    * ------------------------ FT::VECTOR ------------------------- *
    *
    * - Coplien form:
    * constructor:        	Construct vector 
	* 		- default constructor
	*		- fill constructor
	*		- range constructor
    * destructor:         	Destruct vector
    * operator=:            Assign vector
    *
    * - Iterators:
    * begin:                Return iterator to beginning 
    * end:                  Return iterator to end 
    * rbegin:               Return reverse iterator to reverse beginning 
    * rend:                 Return reverse iterator to reverse end 
    *
    * - Capacity:
    * size:                 Return size
    * max_size:             Return maximum size
    * resize:               Change size
    * capacity:             Return size of allocated storage capacity
    * empty:                Test whether vector is empty
    * reserve:              Request a change in capacity
    *
    * - Element access:
    * operator[]:           Access element
    * at:                   Access element
    * front:                Access first element
    * back:                 Access last element
    *
    * - Modifiers:
    * assign:               Assign vector content
	*		- vector content with int
	*		- vector content with iterator
    * push_back:            Add element at the end
    * pop_back:             Delete last element
    * insert:               Insert elements
    * erase:                Erase elements
    * swap:                 Swap content
    * clear:                Clear content
    *
    * - Non-member function overloads:
    * relational operators: Relational operators for vector
    * swap:                 Exchange contents of two vectors
    * ------------------------------------------------------------- *
    */

Petit tips : 
- Avant de vous lancer dans l'implémentation des fonctions autres que les constructeurs une par une sans comprendre, je vous invite à vous balader dans [la doc des fonctions de vector](https://www.cplusplus.com/reference/vector/vector/). Vous comprendrez bien vite (normalement, si vous avez bien tout suivi jusqu'ici), que l'implementation d'insert et reserve est PRIMORDIALE.
L'idée est donc de commencer par implémenter ses deux petits bébés pour que l'implémentation du reste soit plutot fluide.      
      
- Je vous conseille vivement de vous familiariser avec l'idee du [TDD](https://en.wikipedia.org/wiki/Test-driven_development) : tester avant d'implementer. Vous aurez une bien meilleure vision de l'utilité de la fonction et vous saurez repondre a cette utilité de maniere concrete.      
     

### Stack      
     
Pour se familiariser avec stack :     
→ [std::stack](https://www.cplusplus.com/reference/stack/stack/?kw=stack)  
     
#### Le mot clef friend    




### Map

Pour se familiariser avec map :      
→ [std::map](https://cplusplus.com/reference/map/map/?kw=map)      

#### 1. Map     
Une map est un conteneur qui stocke des elements formés par une combinaison valeur/clef.    
- La clef : permet de trier et identifier les elements, c'est toujours une donnée simple. Cette clef doit être unique.  
- la valeur mappée stocke le contenu associe a cette clef, elle peut être une donnee complexe comme une liste ou bien un int, une string, etc. Elle peut egalement ne pas être unique, contrairement à la clef.      
	→ Ces deux informations sont regroupées dans le type membre value_type qui est un type de paire combinant les deux.     
- La map s'affiche toujours par ordre alphabetique ou numerique. Il existe aussi une map desordonnee mais ce n'est pas ce qu'on va utiliser ici.    
- L'operator[] n'a besoin d'acceder qu'a la clef, pas la valeur.     

```
typedef ft::pair<const Key, T> 		value_type;
```

→ Pour plus de visibilite sur l'utilisation des fonctions de map : https://www.youtube.com/watch?v=aEgG4pidcKU / https://code-examples.net/fr/q/33b8d0

#### 2. ft::pair
→ [std::pair](https://www.cplusplus.com/reference/utility/pair/)      
Cette classe permet de regrouper deux valeurs dans une meme information. 
- T1 = premier element -> clef.
- T2 = deuxieme element -> la valeur. 
Cette classe est a reimplenter pour pouvoir l'utiliser dans map.


#### 3. std::less
→ [std::less](https://www.cplusplus.com/reference/functional/less/)      
Cette classe est une classe d'operateur. Elle va nous permettre de trier nos informations, tel que dans les algorithme standard. Il faut comprendre ici que cette classe peut etre remplacée par une autre classe d'operateur selon son objectif (ex : std::greater // std::negate // etc..). Tout depend de l'objectif. 

#### 4. Les arbres binaires 
→ Un arbre binaire est une structure de donnee qui permet de stocker et d'organiser des elements de n'importe quel type.
A titre de comparaison, on a la liste chainee (qu'on maitrise normalement plutot pas mal a ce stade) qui comporte une suite d'elements. Pour ce qui est de l'arbre binaire, on va se retrouver avec deux suite d'elements : right et left.

 ##### a. L'arbre binaire simple (BST) ou binary search tree (ABR).
Concernant les arbres binaires simples, on a donc deux suite d'elements. 
Pour chaque noeud, on va se retrouver avec, a droite tous ce qui est plus grand ou egal et a gauche, tous ce qui est plus petit. Il faut donc comprendre que chaque noeud n'a donc que 2 branches, une branche a droite et une branche a gauche (d'ou le mot "binaire" finalement). L'interet de l'utilisation de l'arbre binaire plutot que d'une liste c'est : sa rapidite. 
Sauf que l'arbre binaire presenté tel quel n'est parfois par forcement plus rapide.

exemple:
On souhaite stocker des nombres allant de 0 a 100, on va se retrouver avec quelque chose qui serait finalement plus interessant dans une liste chainee que dans un arbre binaire finalement : 

LISTE CHAINEE        
![liste chainee](https://user-images.githubusercontent.com/57404773/162003377-5603e61d-dbaa-42a3-90e4-2ae382967d5c.png)

ARBRE BINAIRE        
![arbre-binaire](https://user-images.githubusercontent.com/57404773/162003405-9aedb1c4-966c-4ac3-ac06-ed424b85a0ba.png)

Je sais pas vous mais meme visuellement on voit bien que c'est pas opti. Pour regler ce probleme, plusieurs idees d'equilibrage ont alors ete developpees.
 
 ##### b. L'arbre binaire equilibre, l'AVL       
Dans cette option, on part de la meme base et on va travailler en plus l'equilibre. La regle qui regit l'arbre AVL est que :        
→ la différence des hauteurs des deux sous-arbres ne dépasse pas 1.       
            
Pour permettre cette equilibre, chaque insertion va impliquer des [calculs savants](https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20AVL.htm) que je ne maitrisent pas et que je vous laisse decouvrir.      
Mais dans l'idee, on va remonter de noeud en noeud en verifiant que la regle qui regit l'AVL soit respectee. Si ce n'est pas le cas, on va effectuer une rotation a gauche, une rotation a droite ou une double rotation.    
→ Pour plus de [visibilite](https://visualgo.net/en/bst) et d'explication concernant l'AVL. 
→ Pour comprendre le système de l'[AVL](https://www.youtube.com/watch?v=Jj9Mit24CWk&list=PLlsmxlJgn1HJRYU7YIf8DSEg8_DGwSV29&index=3) et un exemple d'implémentation.

 ##### c. Le Red Black Tree (RBT)
 → [code source](http://cs.brown.edu/people/jwicks/libstdc++/html_user/stl__tree_8h-source.html)
 On se trouve ici dans l'algo qu'a choisi d'utiliser la stl pour implementer map. C'est le plus rapide en terme d'insertion et de suppression. Dans l'idée, il va reprendre l'idée de base de l'AVL mais va ajouter d'autres cas qui vont impliquer parfois une non rotation. 
S'ajoute egalement un membres types : la couleur. 
Pour comprendre le systeme de coloration et de rotation du RBT, voici quelques ressources : 
- https://www.happycoders.eu/algorithms/red-black-tree-java/ 
- https://www.programiz.com/dsa/red-black-tree 

#### 4. L'implémentation 
→ Pour une question d'optimisation on va partir sur un arbre rouge et noir. 
Comme dans un arbre dans la vrai vie, on va creer des feuilles, nos nodes. 

 ##### a. RBTree_node 
 







---

## Notes 

---
## Tests : 
- https://github.com/Mazoise/42TESTERS-CONTAINERS
- https://github.com/mli42/containers_test
- https://github.com/5atchm1n/ft_containers-tester-42
---

### 🎉 Final Grade 🎉    

In progress 

--- 
🍄 ENJOY 🍄
