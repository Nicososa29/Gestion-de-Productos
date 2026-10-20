# 🛒 Gestión de Ventas de Productos (C)

Programa en **lenguaje C** que permite cargar una lista de productos, actualizar sus
ventas y generar un informe con el total recaudado por cada uno.

Desarrollado como trabajo práctico académico.

## ¿Qué hace?

1. **Carga de productos:** se ingresan hasta 80 productos, cada uno con:
   - Código (entre 1 y 999, sin duplicados)
   - Descripción (hasta 29 caracteres)
   - Precio unitario (entre 1.00 y 100.00)
   - Unidades vendidas (entre 0 y 1000)

   La carga termina al ingresar el código `0`. Si se intenta cargar un código que ya
   existe, el programa lo rechaza y pide otro.

2. **Actualización de ventas:** permite sumar unidades vendidas a un producto
   existente, indicando su código. El total recaudado se recalcula
   automáticamente. Si el código no existe, se informa "Producto no encontrado".
   Termina al ingresar `0` como cantidad.

3. **Informe final:** muestra una tabla con cada producto, sus unidades
   vendidas y el total recaudado (`precio × unidades`).
   
## Conceptos aplicados

- Estructuras (`struct`) y `typedef`
- Vectores de estructuras
- Funciones y prototipos
- Validación de datos de entrada
- Búsqueda secuencial
- Memoria dinámica (`malloc` / `free`)
- Manejo de cadenas (`fgets`, `strcspn`)
  
## Autor

Nicolás Sosa
