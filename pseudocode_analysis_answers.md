PROCEDURE FindAndCountActive(sortedIds, isActive, count, targetId)
    first = 0
    last = count - 1
    found = false

    WHILE first <= last AND found is false
        middle = (first + last) / 2

        IF sortedIds[middle] = targetId
            found = true
        ELSE IF sortedIds[middle] < targetId
            first = middle + 1
        ELSE
            last = middle - 1
        END IF
    END WHILE

    activeCount = 0
    FOR index = 0 TO count - 1
        IF isActive[index] is true
            activeCount = activeCount + 1
        END IF
    END FOR

    RETURN found, activeCount
END PROCEDURE

..................................................

PROCEDURE CountPotentialConflicts(startTimes, count)
    conflictCount = 0

    FOR first = 0 TO count - 1
        second = first + 1

        WHILE second < count
            IF startTimes[first] = startTimes[second]
                conflictCount = conflictCount + 1
            END IF

            second = second + 1
        END WHILE
    END FOR

    RETURN conflictCount
END PROCEDURE

..................................................
# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode
**Answer:**
n = count, la cantidad de eventos.
La búsqueda usa búsqueda binaria, así que trabaja cada vez con menos elementos y su complejidad es O(log n).
Luego el programa revisa todas las posiciones de isActive para contar las actividades activas. Como mira cada elemento una vez ,su complejidad es O(n). La complejidad total es O(n) porque primero hace la búsqueda y después el conteo. No se multiplican los costos porque los procesos no están uno dentro del otro. Se hacen por separado, así que se suman:
O(log n) + O(n) = O(n)
## D2 — Potential-conflict pseudocode
**Answer:**
n = count, la cantidad de elementos en startTimes.second comienza en first + 1 para evitar comparar una actividad consigo misma y para que cada par se revise solo una vez.La operación representativa es la comparación:
startTimes[first] = startTimes[second].
El algoritmo compara cada elemento con los que están después de él. Por eso, en el caso de más trabajo, realiza muchas comparaciones entre pares de elementos y su complejidad es O(n²). Si count se duplica, el número de comparaciones aumenta aproximadamente cuatro veces. Esto demuestra un crecimiento cuadrático, por lo que la clasificación final es O(n²).