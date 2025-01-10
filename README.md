# 42-So-Long 🎮
So-Long es un proyecto de la escuela 42 que consiste en crear un juego simple utilizando la biblioteca gráfica **MLX**.
En mi caso he usado la libreria <a href="https://github.com](https://github.com/codam-coding-college/MLX42">MLX42</a> que contiene bastante buena documentación y está actualizada.
Opté por realizar un pequeño juego perspectiva 2D, siendo el objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.

Para mover al personaje, se puede hacer uso de las teclas **`W | ⬆️`**, **`A | ⬅️`**, **`S | ⬇️`** y **`D | ➡️`** y la tecla **`ESC`** para cerrar el programa limpiamente.

El programa leerá un archivo .ber con información sobre el mapa que va a desplegar en la ventana para poder jugarlo. 
En el mismo repositorio en la ruta assets/maps se encuentran una gran cantidad de mapas tanto válidos como invalidos para que probar el proyecto.

![image](https://github.com/user-attachments/assets/7382862a-2e95-4a0e-806b-13319979135b)

## Cómo ejecutar 🖥️

Los siguientes comandos deben ser ejecutados en la terminal, dentro del directorio de tu proyecto:

- **`make all`**: Compila el proyecto, genera la biblioteca estática `so_long.a`, y genera un ejecutable llamado `so_long`.

- **`make clean`**: Elimina los archivos objeto (`.o`) generados durante la compilación.
  
- **`make fclean`**: Ejecuta el comando `clean` y, además, elimina el archivo `push_swap.a` y cualquier ejecutable generado.

- **`make re`**: Ejecuta los comandos `fclean` y `all`, recompilando todo el proyecto desde cero.

- **`make bonus`**: Compila el proyecto pero con el apartado bonus del mismo, en el que se incluyen nuevas funcionalidades y genera un ejecutable llamado `so_long_bonus`

## Uso del programa 🏃

Una vez generado el ejecutable, se puede ejecutar por terminal pasandole la ruta al archivo .ber del mapa que va a generar: 

![image](https://github.com/user-attachments/assets/868d2d27-3ed3-4b8a-9eba-e06f5ec67a5b)

![image](https://github.com/user-attachments/assets/21c11c1c-2b5f-4eef-80eb-feb4095113b8)

![image](https://github.com/user-attachments/assets/ca69d43b-612f-44fc-b1c8-82608a4604af)

### Casos de error ⚠️
Ten en cuenta que el programa devolverá Error si no cumple con las siguientes reglas
- El archivo del mapa debe de existir y tener como extensión `.ber`.
- Se utilizarán cinco caracteres: **`0`** para espacio vacío, **`1`** para muro, **`C`** para coleccionable, **`E`** para salida y **`P`** para la posición inicial del jugador. En el caso de ser el bonus, se añadirá **`I`** para representar la posición del enemigo.
- El mapa debe tener una salida, al menos un objeto y una posición inicial.
- Si hay caracteres duplicados (salida o posición inicial), se mostrará un mensaje de error.
- El mapa debe ser rectangular.
- El mapa debe estar cerrado/rodeado de muros, de lo contrario, se devolverá un error.
- Debe ser posible que el jugador acceda a todas los colecccionables así como a la entrada para poder jugar.

Ejemplo de un mapa válido:
```sh
1111111111111
10010000000C1
1000011111001
1P0I11E0000I1
1111111111111
```
Si hay cualquier error en la configuración del archivo, el programa devolvera “Error\n” con un mensaje explícito.

## Configuración ⚙️

Puedes ajustar las opciones de compilación en el Makefile según tus necesidades específicas.

## Autor 👨‍💻
  <br/>
  <br/>
  <br/>

</div>
<div align="center">
  <img src="https://avatars.githubusercontent.com/u/102600920?v=4" alt="Logo" width="200"/>
  <br/>
  <br/>
  <div style="margin: 20px 0 30px;">
  <a href="https://github.com/jfercode">Javier Fernández Correa</a>
  </div>
</div>
  <br/>
<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVInHuUPtp3uiEuvF0aYAkFBUzpnr65b2CDA&s" alt="Logo"/>
</div>
<br/>
</div>
