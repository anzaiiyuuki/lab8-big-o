/*
 * Course: COEN 2220 - Programming 2
 * Name: [Aida S. Mendoza Goonzalez]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [12 oct 2026]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex) //c1
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer: 
 *  getActivityIdAt. n representa la cantidad de elementos del arreglo activityIds(pero el numero no depende de n y no se duplica),
 *  returnactiivityIds[acivityIndex;] es la operacion representativa, Big-O es O(1),solo accede usando el indice
 *
 * C2 — Count active activities
 * Answer:
 * activityCOunt. N es igual a activityCount, el numero de actividades y hace N revisiones ( revisa cada ActivityCount del arreglo).
 *  La operacion representativa es " if (isActive[index]) en activityCount" (o equivalentemennte el recorrido de cada elemento del arreglo).
 *  Big-O es O(n) (revisa todo el arreglo). "for (int index = 0; index < activityCount; index++)" si hay 10 actividades, hay 10 iteraciones(el i del for loop)
 *
 *
 * C3 — Binary search
 * Answer:
 * countBinaryComparisons. N representa activityCount, la cantidad de iDs almacenados. la comparacion del elemento central "activityIds[middle] == targetId" 
 * y las que tengan igual mente el [middle] como comparacion. Big-o es O(log n) y antes de llamarlo, debe de estar en orden acendente (menor a mayor)para usar
 * binary search ( se elimina la mitad de las posibilidades en cada divicion o iteracion) si no, se es posible que un numero no sea comparado
 *
 * C4 — Halving steps
 * Answer:
 * inicio de los valores de item count ( 16)
 * 1. 16
 * 2. 8
 * 3. 4
 * 4. 2
 * 5. 1
 * depsues de que se ejecutarse, sucede:
 * 1. 16-> 8 ( 16 pasa a 8)
 * 2. 8 -> 4
 * 3. 4 -> 2
 * 4. 2 -> 1
 * 
 * hace 4 pasos y la operacion que se repite es "itemCount = itemCount / 2;"linea 73 (cada iteracion elimina aproximadamente por la mitad)
 * si 16 pasa a 32, los pasos cambian y serian 5 y se veria asi:
 * 32 -> 16
 * 16-> 8 
 * 8 -> 4
 * 4 -> 2
 * 2 -> 1
 * su big o es O(log n) porque esa parte del codigo se reduce a la mitad en cada iteracion,
 *  el num de divisiones para llegar a 1 es el crecimiento del logatirmo.
 * 
 * C5 — Distinct pairs
 * Answer:
 * El segundo loop comienza con first +1 por que se quiere contar unicamente pares distintos. 
 * el for loop de esta lo que hace es que los pone en un arreglo de dos dimensiones y solamente queremos contar el primero una vez.
 * por eso: second= first+1 linea 87. Asi siempre compara elementos que estan despies del elemento actual y se evcita que se repita los pares
 *si iniciara con 0, iniciaria (0,0) y aparecerian pares iguales. Operacion que la representa es pairCount++;. Su big O es O(n^2).
 Los dos for loops y que aumente el paircount es como se escribe. Primer ciclo se ejecuta n veces y tmb la segunda iteracion.

 * C6 — Compare the observed patterns
 * Answer:
Activity at index 2: 108
Active activities: 4
Binary comparisons for 140: 3
Halving steps for 8: 3
Halving steps for 16: 4
Halving steps for 32: 5
Possible pairs for 4 activities: 6
Possible pairs for 8 activities: 28]

este fue el output y muestra 4 patrones de crecimiento diferentes.
Acceso directo es: "Activity at index 2: 108" y la funcion es getActivityIdAt() (linea 13). accede a una posicion conocida del arreglo, siempre realiza el mismo acceso
complejidad:O(1)

Conteo de actividades es: "Active activities: 4" y es para contar las actividades activas. el programa debe de chequear cada elemento usando el for loop.
con  8 actividades, el ciclo se realizo 8 veces y su complejidad es O(n)

Busqueda binaria es: "Binary comparisons for 140: 3" la busqueda de 140 y encontro 3 comparaciones. Cada vez que compara el valor central elimina aproximadamente la mitad de 
los elementos restantes, por eso el numero de comparaciones crece lentamente incluso cuando aumenta el tamaño del arreglo y su complejidad es O(log nn)

Reduccion a la mitad son:
Halving steps for 8: 3
Halving steps for 16: 4
Halving steps for 32: 5

cuando el tamaño se duplica, solo aumenta un paso ( lo que paso desde a 8 hasta 32) esto sucede porque cada iteracion se ejecuta
itemCount = itemCount / 2; reduciendo el problema a la mitad.
complejidad es O(log n)

Pares posibles son:
Possible pairs for 4 activities: 6
Possible pairs for 8 activities: 28
el crecimiento es mucho mas rapido. Al aumentar el numero de actividades, cada actividad puede combionarse con muchas otras.
 Es un ciclo anidado (provocan cantidades grandes de comparaciones) Complejidad: O(n^2)
 *
 * C7 — Sorting decision
 * Answer:
 * uasr busqueda lineal cuando:
 * el arreglo esta desordenado, voy a realizr pocas busquedas, el conjunto de datos es pequeño y no vale la pena gastar tiempo ordenadnolo
 * ordenar primero cuando vas a realizr muchas busquedas sobre el mismo conjunto de datos. Si son muchos los ids y los vas a udar cosntantemente es recomendable usar el 
 * binary search. Ordenar primero no es lo mejor por el costo que tiene, se podria usar diferentes sorting methods pero cada uno tiene sus ventajes. Bianry debe de estar ordenado para que funcione bien
 * bubble sorth compara elementos vecinos, si estan en el orden que no es, los intercambia. Selkection Sort busqua el valor mas pequeño y lo coloca en su posicion correcta, no intercambia a cada rato como bubble sort
 * Linear search (O(n)) lo usaria para busquedas de datos desordenados y consiideraria ordear primero(si son muchos numeros y es consultado muchas veces)
 * 
 *
 */