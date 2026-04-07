*Este proyecto ha sido creado como parte del currículo de 42 por jreyes-s, tide-oli.*

## Descripción

**Push_swap** es un proyecto de ordenación de datos que consiste en ordenar una lista de enteros usando dos stacks (`a` y `b`) y un conjunto limitado de operaciones. El objetivo es encontrar la secuencia de operaciones **más corta posible** que deje el stack `a` ordenado de menor a mayor (con el número más pequeño en la cima).

El programa implementa **cuatro estrategias de ordenación** seleccionables en función del tamaño y el nivel de desorden de la entrada, optimizando el número de operaciones según el caso. En la práctica, el proyecto está organizado alrededor de tres algoritmos principales: **insertion sort** para el caso simple, **chunk sort** para el caso intermedio y **radix sort** para el caso complejo.

### Operaciones disponibles

| Operación | Descripción 											|
|-----------|-------------------------------------------------------|
| `sa`      | Swap de los dos primeros elementos del stack `a`  	|
| `sb`      | Swap de los dos primeros elementos del stack `b`  	|
| `ss`  	| `sa` y `sb` simultáneamente 							|
| `pa`  	| Push del primer elemento de `b` a `a` 				|
| `pb`  	| Push del primer elemento de `a` a `b` 				|
| `ra`  	| Rotate `a`: el primer elemento pasa al final 			|
| `rb`  	| Rotate `b`: el primer elemento pasa al final 			|
| `rr`  	| `ra` y `rb` simultáneamente 							|
| `rra` 	| Reverse rotate `a`: el último elemento pasa al inicio |
| `rrb` 	| Reverse rotate `b`: el último elemento pasa al inicio |
| `rrr` 	| `rra` y `rrb` simultáneamente 						|

---

## Instrucciones

### Compilación

```bash
make        # Compila el binario push_swap
make clean  # Elimina objetos intermedios
make fclean # Elimina objetos y binario
make re     # Recompila desde cero
```

### Ejecución

```bash
# Uso básico (modo adaptativo por defecto)
./push_swap 4 67 3 87 23

# Forzar estrategia
./push_swap --simple   5 4 3 2 1
./push_swap --medium   5 4 3 2 1
./push_swap --complex  5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Contar operaciones
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verificar corrección con checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# Modo benchmark (métricas a stderr)
./push_swap --bench 4 67 3 87 23

# Input desde archivo
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Manejo de errores

El programa imprime `Error` seguido de `\n` en `stderr` ante:
- Argumentos no enteros
- Valores fuera del rango de `int`
- Números duplicados

```bash
./push_swap 0 one 2 3   # → Error
./push_swap 3 2 3        # → Error
```

---

## Algoritmos

El programa implementa cuatro estrategias de ordenación. La selección automática (`--adaptive`) elige la más eficiente en función del **índice de desorden** del input.

---

### Justificación de los umbrales (modo `--adaptive`)

El modo adaptativo mide el **índice de desorden** como el porcentaje de inversiones sobre el total de pares posibles. Los umbrales que definen qué algoritmo usar son:

| Rango de desorden | Estrategia seleccionada | Justificación |
|-------------------|------------------------|---------------|
| 0 % – ~5 % | Simple O(n²) | Pocas inversiones: el coste cuadrático es despreciable con pocos intercambios reales necesarios. Insertion sort encaja bien en casos casi ordenados. |
| ~5 % – ~40 % | Intermedia O(n√n) | Desorden moderado: chunk sort divide el problema en bloques y reduce el coste medio de movimientos frente al enfoque simple. |
| ~40 % – 100 % | Compleja O(n log n) | Alto desorden: radix sort aprovecha la normalización a índices para reducir el problema a pasadas por bits. |

> Estos umbrales fueron determinados empíricamente midiendo el número promedio de operaciones en conjuntos de 100 y 500 enteros aleatorios, comparando las tres estrategias en distintos rangos de desorden.

---

### Estrategia Simple — O(n²)

**Descripción:** Insertion sort adaptado a dos stacks.

**Técnica:**
1. Se toma el elemento más pequeño de `a`.
2. Se rota `a` hasta llevarlo a la cima con el mínimo número de movimientos.
3. Se hace `pb` para apartarlo temporalmente en `b`.
4. Se repite hasta dejar `a` reducido a un caso base de 2 o 3 elementos.
5. Se ordena el caso base con operaciones directas y luego se recuperan los elementos desde `b` con `pa`.

**Complejidad:**
- Tiempo: O(n²) — por cada elemento se recorre `b` entero en el peor caso.
- Espacio: O(n) — ambos stacks suman n elementos en todo momento.

**Cuándo usarla:** Inputs pequeños o casi ordenados (pocas inversiones).

---

### Estrategia Intermedia — O(n√n)

**Descripción:** Chunk sort adaptado a dos stacks.

**Técnica:**
1. Se normalizan los valores a índices para trabajar por rangos.
2. Se divide el rango total en chunks (bloques) de tamaño aproximado `√n`.
3. Se empujan a `b` los elementos de cada chunk con rotaciones para minimizar desplazamientos.
4. Se reconstruye `a` recuperando desde `b` en orden correcto.

**Complejidad:**
- Tiempo: O(n√n) en enfoque por chunks, con coste dependiente del tamaño de bloque y del desorden inicial.
- Espacio: O(n).

**Cuándo usarla:** Desorden moderado, tamaños intermedios (50–300 elementos).

---

### Estrategia Compleja — O(n log n)

**Descripción:** Radix sort adaptado a operaciones de stack.

**Técnica (radix LSD sobre bits):**
1. Se normalizan los valores a índices 0..n-1.
2. Para cada bit (de menos significativo a más), se recorre `a`:
   - Si el bit del elemento es 0 → `pb`.
   - Si el bit es 1 → `ra`.
3. Al terminar el bit, se devuelven todos los elementos de `b` a `a` con `pa`.
4. Se repiten los pasos para ⌈log₂(n)⌉ bits.

**Complejidad:**
- Tiempo: O(n log n) — log₂(n) pasadas, cada una O(n) operaciones.
- Espacio: O(n).

**Cuándo usarla:** Alto desorden, inputs grandes (500+ elementos).

---

### Estrategia Adaptativa — selección automática

Calcula el índice de desorden antes de ordenar y delega al algoritmo óptimo según los umbrales descritos arriba. Es el comportamiento por defecto (`--adaptive` o sin flag).

---

## Rendimiento objetivo

| Input       | Mínimo       | Bueno      | Excelente  |
|-------------|--------------|------------|------------|
| 100 números | < 2000 ops   | < 1500 ops | < 700 ops  |
| 500 números | < 12000 ops  | < 8000 ops | < 5500 ops |

---

## Recursos

### Referencias

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*. Base teórica de algoritmos de ordenación.
- Cormen et al. — *Introduction to Algorithms (CLRS)*. Referencia de complejidad y análisis de cotas.
- [Visualgo — Sorting Algorithms](https://visualgo.net/en/sorting) — Visualización interactiva de insertion sort y radix sort (base conceptual de las estrategias usadas).
- [Push_swap — Medium (explicación general de estrategias con stacks)](https://medium.com/@jamierobertdawson/push-swap-the-least-number-of-moves-with-two-stacks-d1e76a71789a) — Referencia conceptual útil para ordenar con dos stacks.
- [42 Docs — Push_swap subject](https://cdn.intra.42.fr) — Enunciado oficial del proyecto.

### Uso de IA

Durante el desarrollo de este proyecto se utilizó IA (Claude, Anthropic) como apoyo en las siguientes tareas:

- **Generación de este README**: estructura, redacción y formato.
- **Revisión de análisis de complejidad**: verificación de las cotas O(n²), O(n√n) y O(n log n) en el modelo de Push_swap.
- **Depuración conceptual**: aclaración de dudas sobre la adaptación de radix sort a operaciones de stack.

La implementación del código fuente fue realizada íntegramente por jreyes-s y tide-oli.